//
// server.h
// created by Marilia Sampaio on 11/22/21
//

#ifndef server_h
#define server_h

#include <sys/socket.h>
#include <netinet/in.h>

// functions prototype
struct Server server_constructor(int domain, int service, int protocol, u_long interface, int port, int backlog, void(*launch)(void));

struct Server
{
    int domain;
    int service;
    int protocol;
    u_long interface;
    int port;
    int backlog;
    
    struct sockaddr_in address;

    int socket;    

    void (*lauch)(void);
};

#endif /* server_h */

