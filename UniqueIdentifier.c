
#include <Windows.h>
#include <stdio.h>

#include ".\include\key.h"
#include ".\include\log.h"

unsigned int hardwareGUID
{
    HW_PROFILE_INFO hwProfileInfo;

    if (GetCurrentHwProfile(&hwProfileInfo) != NULL)
		{
        printf("Hardware GUID: %s\n",     hwProfileInfo.szHwProfileGuid);
        printf("Hardware Profile: %s\n", hwProfileInfo.szHwProfileName);
    } else
		{

        return 0;
    }

    getchar();
}
