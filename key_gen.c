#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>

#include ".\include\key.h"
#include ".\include\log.h"

#define HW_PROFILE_GRAB_FAILURE 3

unsigned int randomValue(int randUpperBound)
{
    HW_PROFILE_INFO hwProfileInfo;

    if (GetCurrentHwProfile(&hwProfileInfo))
		{
      char charProfileGUID[0x400];

      snprintf(charProfileGUID,
        sizeof(charProfileGUID),
        "%s",
        hwProfileInfo.szHwProfileGuid);

      int profileGuidVal;
      for (size_t i = 0; i < 4; ++i) {
          int x = strtol(&charProfileGUID[i], NULL, 10);
          profileGuidVal = 10 * profileGuidVal + x;
      };

      /* not REALLY random, but good enough for this scope */
      unsigned int randomGeneratedValue = (rand() % randUpperBound) * profileGuidVal;

      return randomGeneratedValue;

    } else
		{
        char errorMessage[] = "Failed to obtain hardware profile info.";
        raiseError(errorMessage, HW_PROFILE_GRAB_FAILURE);
    }

    return 0;

}
