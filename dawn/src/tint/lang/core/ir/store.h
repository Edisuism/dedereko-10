// Copyright 2023 The Dawn & Tint Authors
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

#ifndef SRC_TINT_LANG_CORE_IR_STORE_H_
#define SRC_TINT_LANG_CORE_IR_STORE_H_

#include <string>

#include "src/tint/lang/core/ir/operand_instruction.h"
#include "src/tint/utils/rtti/castable.h"

namespace tint::core::ir {

/// A store instruction in the IR.
class Store final : public Castable<Store, OperandInstruction<2, 0>> {
  public:
    /// The offset in Operands() for the `to` value
    static constexpr size_t kToOperandOffset = 0;

    /// The offset in Operands() for the `from` value
    static constexpr size_t kFromOperandOffset = 1;

    /// Constructor
    /// @param to the value to store too
    /// @param from the value being stored from
    Store(Value* to, Value* from);
    ~Store() override;

    /// @copydoc Instruction::Clone()
    Store* Clone(CloneContext& ctx) override;

    /// @returns the value being stored too
    Value* To() { return operands_[kToOperandOffset]; }

    /// @returns the value being stored too
    const Value* To() const { return operands_[kToOperandOffset]; }

    /// @returns the value being stored
    Value* From() { return operands_[kFromOperandOffset]; }

    /// @returns the value being stored
    const Value* From() const { return operands_[kFromOperandOffset]; }

    /// @returns the friendly name for the instruction
    std::string FriendlyName() const override { return "store"; }
};

}  // namespace tint::core::ir

#endif  // SRC_TINT_LANG_CORE_IR_STORE_H_
