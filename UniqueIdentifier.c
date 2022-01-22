
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>

#include ".\include\key.h"
#include ".\include\log.h"

unsigned int hardwareGUID()
{
    HW_PROFILE_INFO hwProfileInfo;

    if (GetCurrentHwProfile(&hwProfileInfo) != NULL)
		{
      int result = atoi(hwProfileInfo.szHwProfileGuid);
      return (unsigned int) result;
    } else
		{
        char errorMessage[] = "Failed to obtain hardware profile info.";
        unsigned int errorCode = 3;
        raiseError(errorMessage, errorCode);
    }
}
