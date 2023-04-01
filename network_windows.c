#include <stdio.h>
#include <winsock2.h>
#include <windows.h>
#include "network_windows.h"

#pragma comment(lib, "ws2_32.lib")

// PF_INET, AF_INET
int *is_socket_available(int family) {
    SOCKET sock = socket(family, SOCK_STREAM, 0);

    if (sock == INVALID_SOCKET) {
        return 0;
    }

    return (int *)1;
}

int *is_pf_socket_available() {
    return is_socket_available((int)PF_INET);
}

int *is_af_socket_available() {
    return is_socket_available((int)AF_INET);
}

int *winsocket_startup() {
    int ready;
    WSADATA wsa;

    ready = WSAStartup(MAKEWORD(2, 2), &wsa);

    if (ready != 0) {
        return 0;
    }

    return (int *)1;
}

char *http_send_raw_and_receive(int family, char *name, int port, char *data) {
    if (winsocket_startup() == 0) {
        return 0;
    }

    static char msg[1024];

    int connected = 0;

    struct in_addr inaddr;
    struct hostent *host;

    SOCKET sock = socket(family, SOCK_STREAM, 0);
    SOCKADDR_IN addr;

    if (sock == INVALID_SOCKET) {
        return 0;
    }

    host = gethostbyname(name);

    inaddr = *(struct in_addr*)*host->h_addr_list; // List of addresses from name server

    addr.sin_family = family;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(inet_ntoa(inaddr));

    connected = connect(sock, (SOCKADDR*) &addr, sizeof(addr));

    if (connected == SOCKET_ERROR) {
        return 0;
    }

    send(sock, data, strlen(data), 0);

    recv(sock, msg, 1024, 0);

    closesocket(sock);

    WSACleanup(); // Terminate Winsock 2 DLL

    return msg;
}

int *http_send_raw(int family, char *name, int port, char *data) {
    int connected = 0;

    struct in_addr inaddr;
    struct hostent *host;

    SOCKET sock = socket(family, SOCK_STREAM, 0);
    SOCKADDR_IN addr;

    if (sock == INVALID_SOCKET) {
        return 0;
    }

    host = gethostbyname(name);

    inaddr = *(struct in_addr*)*host->h_addr_list; // List of addresses from name server

    addr.sin_family = family;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(inet_ntoa(inaddr));

    connected = connect(sock, (SOCKADDR*) &addr, sizeof(addr));

    if (connected == SOCKET_ERROR) {
        return 0;
    }

    send(sock, data, strlen(data), 0);
    closesocket(sock);

    return (int *)1;
}