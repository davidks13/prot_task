#include <iostream>
#include <cstring>
#include <algorithm>
#include <unistd.h>
#include "thread_obj.hpp"

ThreadObject::ThreadObject() {}

ThreadObject::Socket::~Socket() {
    close(client_fd);
}

bool ThreadObject::is_connected() {
    sock.client_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sock.client_fd < 0) {
        std::cerr << "Error creating socket: " << strerror(errno) << std::endl;
        return false;
    }

    sock.server_address.sun_family = AF_UNIX;
    strcpy(sock.server_address.sun_path, "/tmp/socket");
    if (connect(sock.client_fd, (struct sockaddr *)&sock.server_address, sizeof(sock.server_address)) < 0) {
        std::cerr << "Error connecting to socket: " << strerror(errno) << std::endl;
        return false;
    } 
    return true;
} 

void ThreadObject::request(const std::string &str) {
    char buffer[100];
    int bytes_read = read(sock.client_fd, buffer, 100);
    if (bytes_read == 13) {
        char buff[str.length() + 1]; 
	    strcpy(buff, str.c_str());
        write(sock.client_fd, buff, sizeof(buff));  
    } else {
        is_connected();
    }
}

void ThreadObject::first_thread() {
    is_connected();
    std::cout << "Enter a string containing maximum of 64 digits only" << std::endl;
    while (true) {
        std::string str;
        std::cin >> str;

        if (!is_digits(str) || !is_correct_size(str)) {
            std::cout << "Error: Enter a proper string!" << std::endl;
            continue;
        }

        sort_string(str);
        change_even_digits(str);
        std::unique_lock<std::mutex> ulock(m);
        cond.wait(ulock, [this] { return (buf.size() == 0) ? true : false; });
        buf = str;
        cond.notify_one();
    }
}

void ThreadObject::second_thread() {
    while (true) {
        std::unique_lock<std::mutex> ulock(m);
        cond.wait(ulock, [this] { return (buf.size() > 0) ? true : false; });
        std::string str = buf;
        buf.clear();
        cond.notify_one();
        std::cout << "Received buffer from the first thread: " << str << std::endl;
        std::string sum = sum_of_digits(str);
        std::cout << "The sum of digits is equal to: " << sum << std::endl << std::endl;
        request(sum);
        std::cout << "Enter the next string!" << std::endl;
    }
}
  
bool ThreadObject::is_digits(const std::string &str) {
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

bool ThreadObject::is_correct_size(const std::string &str) {
    return (str.size() <= 64);
}

void ThreadObject::sort_string(std::string &str) {
    std::sort(str.begin(), str.end());
    std::reverse(str.begin(), str.end());
}

void ThreadObject::change_even_digits(std::string &str) {
    std::string new_str;
    for (auto i : str) {
        if (i % 2 == 0) {
            new_str.push_back('K');
        new_str.push_back('B');
        } else {
            new_str.push_back(i);
        }
    }
    str = new_str;
}

std::string ThreadObject::sum_of_digits(const std::string &str) {
    int sum = 0;
    for (auto i : str) {
        if (std::isdigit(i)) {
            sum += (i - '0');
        }
    }
    return std::to_string(sum);
}