#pragma once

#include <Windows.h>

namespace Encrypt
{
    class Key
    {
    public:
        ULARGE_INTEGER freeDiskSpace;
        ULARGE_INTEGER totalDiskSpace;
    };

}