#include "header.hpp"


int main(int argc, char *argv[])
{
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in socket_address;
    int addr_len = sizeof(socket_address);

    inet_aton(LOOPBACK, &socket_address.sin_addr);
    socket_address.sin_family = AF_INET;
    socket_address.sin_port = htons(PORT);

    bind(socket_fd, (struct sockaddr *)&socket_address, addr_len);

    listen(socket_fd, 1);

    while(1) 
    { 
        int socket_new = accept(socket_fd, (struct sockaddr *)&socket_address, (socklen_t *)&addr_len);
        std::cout << socket_new << std::endl;
        close(socket_new);
    }

}