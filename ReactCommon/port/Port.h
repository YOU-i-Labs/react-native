#ifndef _PORT_H_
#define _PORT_H_

#define YI_CLOSE_FILE_FUNCTION close

#if defined(_MSC_VER)
#include <winapifamily.h>
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
#define UWP
#define YI_RC_UWP
#include "Port_UWP.h"
#else 
#define YI_RC_WINDOWS
#include "Port_UWP.h"
#endif
#endif

#ifndef RN_EXPORT
#define RN_EXPORT
#endif

#endif
