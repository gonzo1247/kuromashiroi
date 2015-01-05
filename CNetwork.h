#ifndef __CNETWORK
#define __CNETWORK

#include <stdio.h>
#include <errno.h>

#ifdef _WIN32
/* Headerfiles für Windows */
#include <winsock.h>
#include <io.h>
#define in_addr_t unsigned long

#else
/* Headerfiles für Unix/Linux */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#define closesocket(s) close(s)
#endif

class CNetwork
{
    public:
        CNetwork();
        ~CNetwork();
        void CreateConnect();

};








#endif __CNETWORK