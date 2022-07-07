#include "header.h"


int main(int argc, char *argv[])
{
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in socket_address;
    int addr_len = sizeof(socket_address);

    char socket_buff[BUFF_SZIE];
    int recv_status;
    int socket_accept;

    inet_aton(LOOPBACK, &socket_address.sin_addr);
    socket_address.sin_family = AF_INET;
    socket_address.sin_port = htons(PORT);

    bind(socket_fd, (struct sockaddr *)&socket_address, addr_len);
    listen(socket_fd, 100); //100?

    while(1) 
    {
        
        socket_accept = accept(socket_fd, (struct sockaddr *)&socket_address, (socklen_t *)&addr_len);
        std::cout << socket_accept << std::endl;

        recv_status = recv(socket_accept, socket_buff, BUFF_SZIE, 0);
        printf("%s\n %d\n %s\n", socket_buff, recv_status, strerror(errno));

        close(socket_accept);
    }
}