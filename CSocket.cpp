/*Socket.cpp for Windows*/

#include <cstdlib>
#include <WinSock2.h>
#include <io.h>
#include <iostream>
#include "CSocket.h"

using namespace std;

// Konstruktor 
CSocket::CSocket() : m_sock(0)
{
    WORD VersionRequested;
    WSADATA wsaData;
    VersionRequested = MAKEWORD(2, 2);
    if (WSAStartup(VersionRequested, &wsaData) != 0)
        exit(1);
}

// Destructor 
CSocket::~CSocket()
{
    if (is_valid)
        ::closesocket(m_sock);    
}


// Create Socket - TCP 
bool CSocket::tcp_create()
{
    m_sock = ::socket(AF_INET, SOCK_STREAM, 0);
    if (m_sock < 0)
    {
        exit(1);
    }
    return true;
}

// Create Socket - UDP
bool CSocket::udp_create()
{
    m_sock = ::socket(AF_INET, SOCK_DGRAM, 0);
    if (m_sock < 0)
    {
        exit(1);
    }
    return true;
}

// Create binding to serveradress, specific Port
bool CSocket::bind(const int port)
{
    if (!is_valid())
    {
        return false;
    }

    m_addr.sin_family = AF_INET;
    m_addr.sin_addr.s_addr = INADDR_ANY;
    m_addr.sin_port = htons(port);

    int bind_return = ::bind(m_sock, (struct sockaddr *) &m_addr, sizeof(m_addr));
    if (bind_return == -1)
        return false;
    return true;
}

// 
bool CSocket::listen() const
{
    if (!is_valid)
        return false;

    int listen_return = ::listen(m_sock, MAXCONNECTIONS);
    if (listen_return == -1)
        return false;
    return true;
}