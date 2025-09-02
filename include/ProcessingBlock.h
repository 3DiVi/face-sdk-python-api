#pragma once

#include <pbio/ProcessingBlock.h>

#include "Context.h"

namespace face_sdk_3divi
{
    class ProcessingBlock
    {
    private:
        pbio::ProcessingBlock implementation;

    public:
        ProcessingBlock(const Context& config);

        ProcessingBlock(const py::dict& dict);

        ProcessingBlock(ProcessingBlock&& other) = default;

        ProcessingBlock& operator =(ProcessingBlock&& other) = default;

        void operator ()(Context& config);

        ~ProcessingBlock() = default;
    };
}
