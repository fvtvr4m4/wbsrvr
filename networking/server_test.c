//
// server_test.c
// test for server.c
//

#include <stdio.h>
#include "server.h"

void launch()
{
    // estimate for now
    char buffer[30000];
    printf("o_o ##### WAITING FOR CONNECTION ##### o_o\n");

    printf("*_* ##### DONE ##### *_*\n");
}

int main()
{
    struct Server server = server_constructor(AF_INET, SOCK_STREAM, 0, INADDR_ANY, 80, 10);
}
