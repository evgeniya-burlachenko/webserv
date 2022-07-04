#include "header.hpp"

int main(int argc, char *argv[]) 
{
    if (argc == 1)
    {
        std::cout << "type message\n" ;
        return 0;
    }

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in socket_address;
    int addr_len = sizeof(socket_address);

    inet_aton(LOOPBACK, &socket_address.sin_addr);
    socket_address.sin_family = AF_INET;
    socket_address.sin_port = htons(PORT);

    char * msg = argv[1];
    size_t len = strlen(msg);

    if (!(connect(socket_fd, (struct sockaddr *)&socket_address, addr_len))) 
    {
        std::cout << "connect success" << std::endl;
        send(socket_fd, msg, len , 0);
    }

}