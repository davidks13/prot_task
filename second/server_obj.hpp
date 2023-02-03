#ifndef SERVER_OBJ_HPP
#define SERVER_OBJ_HPP


#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <sys/un.h>
#include <cerrno>
#include <csignal>


class ServerObj{
    public:
        ServerObj();
        ~ServerObj();
    private:
        int server_fd;
        int client_fd;
        static int static_client_fd;
        struct sockaddr_un server_address;
        bool server_config();
        void server_work();
        static void set_client_fd(int fd);
        static void signal_callback_handler (int signum);
        std::string is_correct_input(const int &sum);
};

#endif
