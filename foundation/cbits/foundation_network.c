#include "foundation_system.h"

int foundation_network_get_h_errno(void)
{
#if defined(FOUNDATION_SYSTEM_WASI)
    // WASI has no networking
    return -1;

#elif defined(FOUNDATION_SYSTEM_WINDOWS)
    #include <winsock2.h>
    return WSAGetLastError();

#else
    #include <netdb.h>
    return h_errno;
#endif
}
