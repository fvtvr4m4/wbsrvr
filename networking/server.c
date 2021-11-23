//
// server.h
// created by Marilia Sampaio on 11/22/21
//
// creates and returns a server object

#include "server.h"
#include <stdio.h>
#include <stdlib.h>

struct Server server_constructor(int domain, int service, int protocol, u_long, interface, int port, int backlog, void(*launch)(void))
{
    struct Server server;

    server.domain = domain;
    server.service = service;
    server.protocol = prtocol;
    server.interface = interface;
    server.port = port;
    server.backlog = backlog;

    // define parameters for addr

    server.address.sin_family = domain;

    // htons converts int port to bytes that refer to network port
    server.address.sin_port = htons(port);

    server.address.sin_addr.s_addr = hton(interface);


    // use above addr params to create socket for server
    // creates socket connection to network
    // remember that socket is what allows OS to communicate with network
    // returns address where socket it located
    server.socket = socket(domain, service, protocol);

    // test server socket connection
    if (server.socket == 0)
    {
        perror("Failed to connect to socket\n");
        exit(1);
    }

    // bind socket to network
    // passing in socket address pointer by casting socket.address as sockaddr pointer
    // test binding
    if ((bind(server.socket, (struct sockaddr *)&server.address, sizeof(server.address))) < 0)
    {
        perror("Failed to bind socket\n");
        exit(1);
    }

    // tells server it should be listening by waiting on incoming connection on specified port
    if((listen(server.socket, server.backlog)) < 0)
    {
        perror("Failed to start listening\n");
        exit(1);
    }

    // define launch function
    server.launch = launch;

    return server;
}

