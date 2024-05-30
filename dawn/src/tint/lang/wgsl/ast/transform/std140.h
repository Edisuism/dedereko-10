// Copyright 2022 The Dawn & Tint Authors
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its
//    contributors may be used to endorse or promote products derived from
//    this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef SRC_TINT_LANG_WGSL_AST_TRANSFORM_STD140_H_
#define SRC_TINT_LANG_WGSL_AST_TRANSFORM_STD140_H_

#include "src/tint/lang/wgsl/ast/transform/transform.h"

namespace tint::ast::transform {

/// Std140 is a transform that forks types used in the uniform address space that contain
/// `matNx2<f32>` matrices into `N`x`vec2<f32>` column vectors, and `matNxM<f16>` matrices into
/// `N`x`vecM<f16>` column vectors. Types that transitively use these forked types are also forked.
/// `var<uniform>` variables will use these forked types, and expressions loading from these
/// variables will do appropriate conversions to the regular WGSL types. As `matNx2<f32>` and
/// `matNxM<f16>` matrices are the only type that violate std140-layout, this transformation is
/// sufficient to have any WGSL structure be std140-layout conformant.
///
/// @note This transform requires the PromoteSideEffectsToDecl transform to have been run first.
class Std140 final : public Castable<Std140, Transform> {
  public:
    /// Constructor
    Std140();
    /// Destructor
    ~Std140() override;

    /// @copydoc Transform::Apply
    ApplyResult Apply(const Program& program,
                      const DataMap& inputs,
                      DataMap& outputs) const override;

  private:
    struct State;
};

}  // namespace tint::ast::transform

#endif  // SRC_TINT_LANG_WGSL_AST_TRANSFORM_STD140_H_