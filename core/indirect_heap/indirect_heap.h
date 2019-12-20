/*
 * Copyright (C) 2017-2019 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#pragma once
#include "core/command_stream/linear_stream.h"
#include "core/helpers/aligned_memory.h"
#include "core/helpers/basic_math.h"
#include "core/helpers/ptr_math.h"
#include "core/memory_manager/graphics_allocation.h"
#include "core/memory_manager/memory_constants.h"

namespace NEO {
class GraphicsAllocation;

constexpr size_t defaultHeapSize = 64 * KB;

class IndirectHeap : public LinearStream {
    typedef LinearStream BaseClass;

  public:
    enum Type {
        DYNAMIC_STATE = 0,
        INDIRECT_OBJECT,
        SURFACE_STATE,
        NUM_TYPES
    };

    IndirectHeap(void *graphicsAllocation, size_t bufferSize) : BaseClass(graphicsAllocation, bufferSize){};
    IndirectHeap(GraphicsAllocation *graphicsAllocation) : BaseClass(graphicsAllocation) {}
    IndirectHeap(GraphicsAllocation *graphicsAllocation, bool canBeUtilizedAs4GbHeap)
        : BaseClass(graphicsAllocation), canBeUtilizedAs4GbHeap(canBeUtilizedAs4GbHeap) {}

    // Disallow copy'ing
    IndirectHeap(const IndirectHeap &) = delete;
    IndirectHeap &operator=(const IndirectHeap &) = delete;

    void align(size_t alignment);
    uint64_t getHeapGpuStartOffset() const;
    uint64_t getHeapGpuBase() const;
    uint32_t getHeapSizeInPages() const;

  protected:
    bool canBeUtilizedAs4GbHeap = false;
};

inline void IndirectHeap::align(size_t alignment) {
    auto address = alignUp(ptrOffset(buffer, sizeUsed), alignment);
    sizeUsed = ptrDiff(address, buffer);
}

inline uint32_t IndirectHeap::getHeapSizeInPages() const {
    if (this->canBeUtilizedAs4GbHeap) {
        return MemoryConstants::sizeOf4GBinPageEntities;
    } else {
        return (static_cast<uint32_t>(getMaxAvailableSpace()) + MemoryConstants::pageMask) / MemoryConstants::pageSize;
    }
}

inline uint64_t IndirectHeap::getHeapGpuStartOffset() const {
    if (this->canBeUtilizedAs4GbHeap) {
        return this->graphicsAllocation->getGpuAddressToPatch();
    } else {
        return 0llu;
    }
}

inline uint64_t IndirectHeap::getHeapGpuBase() const {
    if (this->canBeUtilizedAs4GbHeap) {
        return this->graphicsAllocation->getGpuBaseAddress();
    } else {
        return this->graphicsAllocation->getGpuAddress();
    }
}
} // namespace NEO