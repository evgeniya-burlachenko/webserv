#include "header.hpp"

int main() 
{
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in socket_address;
    int addr_len = sizeof(socket_address);

    inet_aton(LOOPBACK, &socket_address.sin_addr);
    socket_address.sin_family = AF_INET;
    socket_address.sin_port = htons(PORT);

    if (!(connect(socket_fd, (struct sockaddr *)&socket_address, addr_len)))
        std::cout << "connect success" << std::endl;

}