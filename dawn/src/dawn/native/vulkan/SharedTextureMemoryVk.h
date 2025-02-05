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

#ifndef SRC_DAWN_NATIVE_VULKAN_SHAREDTEXTUREMEMORYVK_H_
#define SRC_DAWN_NATIVE_VULKAN_SHAREDTEXTUREMEMORYVK_H_

#include "dawn/common/vulkan_platform.h"
#include "dawn/native/Error.h"
#include "dawn/native/SharedTextureMemory.h"
#include "dawn/native/vulkan/RefCountedVkHandle.h"

namespace dawn::native::vulkan {

class Device;

class SharedTextureMemory final : public SharedTextureMemoryBase {
  public:
    static ResultOrError<Ref<SharedTextureMemory>> Create(
        Device* device,
        const char* label,
        const SharedTextureMemoryDmaBufDescriptor* descriptor);

    RefCountedVkHandle<VkDeviceMemory>* GetVkDeviceMemory() const;
    RefCountedVkHandle<VkImage>* GetVkImage() const;
    uint32_t GetQueueFamilyIndex() const;

  private:
    SharedTextureMemory(Device* device,
                        const char* label,
                        const SharedTextureMemoryProperties& properties);
    void DestroyImpl() override;

    ResultOrError<Ref<TextureBase>> CreateTextureImpl(const TextureDescriptor* descriptor) override;
    MaybeError BeginAccessImpl(TextureBase* texture, const BeginAccessDescriptor*) override;
    ResultOrError<FenceAndSignalValue> EndAccessImpl(TextureBase* texture,
                                                     EndAccessState* state) override;

    Ref<RefCountedVkHandle<VkImage>> mVkImage;
    Ref<RefCountedVkHandle<VkDeviceMemory>> mVkDeviceMemory;
    uint32_t mQueueFamilyIndex;
};

}  // namespace dawn::native::vulkan

#endif  // SRC_DAWN_NATIVE_VULKAN_SHAREDTEXTUREMEMORYVK_H_
