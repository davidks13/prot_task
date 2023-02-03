#ifndef THREAD_OBJ_HPP
#define THREAD_OBJ_HPP


#include <mutex>
#include <condition_variable>
#include <string>
#include <sys/socket.h>
#include <sys/un.h>


class ThreadObject {
    public:
        ThreadObject();
        void first_thread();
        void second_thread();
    private:
        std::string buf;
        std::mutex m;
        std::condition_variable cond;
        
        struct Socket {
            int client_fd;
            struct sockaddr_un server_address;
            ~Socket();
        };
        Socket sock;
        
        bool is_connected();
        void request(const std::string &str);
        bool is_digits(const std::string &str);
        bool is_correct_size(const std::string &str);
        void sort_string(std::string &str);
        void change_even_digits(std::string &str);
        std::string sum_of_digits(const std::string &str);
};

#endif