#pragma once

#include <windows.h>
#include <stdio.h>
#include "log.h"

namespace Maplestory
{
	//void DisableExceptionOnClose();
	bool EnableMultiMS();
	bool DisableInternalHackdetection();
	bool DisableCrc();
}