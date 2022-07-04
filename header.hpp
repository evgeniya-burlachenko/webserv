#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

#include <cstring>

#define PORT 8080
#define LOOPBACK "127.0.0.1"