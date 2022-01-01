#include <Windows.h>
#include <iostream>

#include "Global.h"

using namespace Encrypt; 

void _Main() {

	GetDiskFreeSpaceEx(
		"C:\\",
		&Key::freeDiskSpace,
		&Key::totalDiskSpace,
		NULL
	);
}
