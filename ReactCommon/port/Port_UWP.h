#ifndef _PORT_UWP_H_
#define _PORT_UWP_H_

#ifndef NOMINMAX
# define NOMINMAX
#endif
#include <windows.h>
#include <io.h>

#define __attribute__(x)
#define UWP
#define dup _dup
#define close _close

inline int getpagesize (void)
{
  SYSTEM_INFO system_info;
  GetSystemInfo (&system_info);
  return system_info.dwPageSize;
}

#endif