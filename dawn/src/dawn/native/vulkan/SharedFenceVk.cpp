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

#include "dawn/native/vulkan/SharedFenceVk.h"

#include <utility>

#include "dawn/native/ChainUtils_autogen.h"
#include "dawn/native/vulkan/DeviceVk.h"

namespace dawn::native::vulkan {

// static
ResultOrError<Ref<SharedFence>> SharedFence::Create(
    Device* device,
    const char* label,
    const SharedFenceVkSemaphoreZirconHandleDescriptor* descriptor) {
    DAWN_INVALID_IF(descriptor->handle == 0, "Zircon handle (%d) was invalid.", descriptor->handle);

    SystemHandle handle;
    DAWN_TRY_ASSIGN(handle, SystemHandle::Duplicate(descriptor->handle));
    auto fence = AcquireRef(new SharedFence(device, label, std::move(handle)));
    fence->mType = wgpu::SharedFenceType::VkSemaphoreZirconHandle;
    return fence;
}

// static
ResultOrError<Ref<SharedFence>> SharedFence::Create(
    Device* device,
    const char* label,
    const SharedFenceVkSemaphoreSyncFDDescriptor* descriptor) {
    DAWN_INVALID_IF(descriptor->handle < 0, "File descriptor (%d) was invalid.",
                    descriptor->handle);
    SystemHandle handle;
    DAWN_TRY_ASSIGN(handle, SystemHandle::Duplicate(descriptor->handle));
    auto fence = AcquireRef(new SharedFence(device, label, std::move(handle)));
    fence->mType = wgpu::SharedFenceType::VkSemaphoreSyncFD;
    return fence;
}

// static
ResultOrError<Ref<SharedFence>> SharedFence::Create(
    Device* device,
    const char* label,
    const SharedFenceVkSemaphoreOpaqueFDDescriptor* descriptor) {
    DAWN_INVALID_IF(descriptor->handle < 0, "File descriptor (%d) was invalid.",
                    descriptor->handle);
    SystemHandle handle;
    DAWN_TRY_ASSIGN(handle, SystemHandle::Duplicate(descriptor->handle));
    auto fence = AcquireRef(new SharedFence(device, label, std::move(handle)));
    fence->mType = wgpu::SharedFenceType::VkSemaphoreOpaqueFD;
    return fence;
}

SharedFence::SharedFence(Device* device, const char* label, SystemHandle handle)
    : SharedFenceBase(device, label), mHandle(std::move(handle)) {}

void SharedFence::DestroyImpl() {
    mHandle.Close();
}

const SystemHandle& SharedFence::GetHandle() const {
    return mHandle;
}

MaybeError SharedFence::ExportInfoImpl(SharedFenceExportInfo* info) const {
    info->type = mType;

#if DAWN_PLATFORM_IS(FUCHSIA)
    DAWN_TRY(ValidateSingleSType(info->nextInChain,
                                 wgpu::SType::SharedFenceVkSemaphoreZirconHandleExportInfo));

    SharedFenceVkSemaphoreZirconHandleExportInfo* exportInfo = nullptr;
    FindInChain(info->nextInChain, &exportInfo);

    if (exportInfo != nullptr) {
        exportInfo->handle = mHandle;
    }
#elif DAWN_PLATFORM_IS(LINUX)
    switch (mType) {
        case wgpu::SharedFenceType::VkSemaphoreSyncFD:
            DAWN_TRY(ValidateSingleSType(info->nextInChain,
                                         wgpu::SType::SharedFenceVkSemaphoreSyncFDExportInfo));
            {
                SharedFenceVkSemaphoreSyncFDExportInfo* exportInfo = nullptr;
                FindInChain(info->nextInChain, &exportInfo);

                if (exportInfo != nullptr) {
                    exportInfo->handle = mHandle.Get();
                }
            }
            break;
        case wgpu::SharedFenceType::VkSemaphoreOpaqueFD:
            DAWN_TRY(ValidateSingleSType(info->nextInChain,
                                         wgpu::SType::SharedFenceVkSemaphoreOpaqueFDExportInfo));
            {
                SharedFenceVkSemaphoreOpaqueFDExportInfo* exportInfo = nullptr;
                FindInChain(info->nextInChain, &exportInfo);

                if (exportInfo != nullptr) {
                    exportInfo->handle = mHandle.Get();
                }
            }
            break;
        default:
            DAWN_UNREACHABLE();
    }
#else
    DAWN_UNREACHABLE();
#endif
    return {};
}

}  // namespace dawn::native::vulkan
