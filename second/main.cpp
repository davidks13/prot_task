// #include <iostream>
// #include <cstring>
// #include <unistd.h>
// #include <sys/socket.h>
// #include <sys/un.h>
// #include <cerrno>
// #include <signal.h>
#include "server_obj.hpp"

int main() {
    ServerObj A;
    return 0;
}

//rabotayushi kod
// int server_fd = socket(AF_UNIX, SOCK_STREAM, 0); 
//     if (server_fd < 0) {
//         std::cerr << "Error creating socket: " << strerror(errno) << std::endl;
//         return 1;
//     }
//     //client_fd;

//     server_fd = socket(AF_UNIX, SOCK_STREAM, 0);
//     struct sockaddr_un server_address = {AF_UNIX, "/tmp/socket"};
//     //server_address.sun_family = {AF_UNIX, "/tmp/socket"};
//     //strcpy(server_address.sun_path, "socket_file");
    
//     unlink(server_address.sun_path);
//     if (bind(server_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
//         std::cerr << "Error binding socket: " << strerror(errno) << std::endl;
//         return 1;
//     }

//     listen(server_fd, 5);

//     int client_fd = accept(server_fd, (struct sockaddr *) NULL, NULL);
//     if (client_fd < 0) {
//         std::cerr << "Error accepting connection: " << strerror(errno) << std::endl;
//         return 1;
//     }
//     std::cout << "Connected!" << std::endl;    
//     if (signal(SIGINT, signal_callback_handler)){
//         exit(0);
//     }
//     while(!isInterrupted){
//         char buffer[10];
//         write(client_fd, "Hello client!", 13);
//         ssize_t bytes_read = read(client_fd, buffer, sizeof(buffer));
//         if (bytes_read > 0) {
//             buffer[bytes_read] = '\0';
//             std::cout << is_correct_input(atoi(buffer)) << std::endl;
//         } else {
//             listen(server_fd, 5);
//             std::cout << "Reconnecting..." << std::endl;
//             client_fd = accept(server_fd, nullptr, nullptr);
//             std::cout << "Connected!" << std::endl;
//         }
//     }
//     write(client_fd, "Bye client!", 11);
    

//     close(server_fd);
//     return 0;















// int main() {
//     int socket_fd = socket(AF_UNIX, SOCK_STREAM, 0);
//     if (socket_fd < 0) {
//         std::cerr << "Error creating socket: " << strerror(errno) << std::endl;
//         return 1;
//     }

//     struct sockaddr_un addr = {AF_UNIX, "/tmp/socket"};
//     unlink(addr.sun_path);
//     if (bind(socket_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
//         std::cerr << "Error binding socket: " << strerror(errno) << std::endl;
//         return 1;
//     }

//     std::cout << "Waiting for the first program to connect..." << std::endl;
//     listen(socket_fd, 5);
    
//     int client_socket = accept(socket_fd, nullptr, nullptr);
//     std::cout << "Connected!" << std::endl;

//     std::cout << socket_fd << " " << client_socket << std::endl;
    
//     if (client_socket < 0) {
//         std::cerr << "Error accepting connection: " << strerror(errno) << std::endl;
//         return 1;
//     }

//     signal(SIGINT, signal_callback_handler);
//     while(!isInterrupted){
//         char buffer[10];
//         ssize_t bytes_read = read(client_socket, buffer, sizeof(buffer));
//         if (bytes_read > 0) {
//             buffer[bytes_read] = '\0';
//             std::cout << is_correct_input(atoi(buffer)) << std::endl;
//         } else {
//             listen(socket_fd, 5);
//             std::cout << "Reconnecting..." << std::endl;
//             client_socket = accept(socket_fd, nullptr, nullptr);
//             std::cout << "Connected!" << std::endl;
//         }
//     }

//     std::cout << "end\n";
//     close(socket_fd);
//     return 0;
// }

//client
// int socket_fd = socket(AF_UNIX, SOCK_STREAM, 0);
//   if (socket_fd < 0) {
//     std::cerr << "Error creating socket: " << strerror(errno) << std::endl;
//     return 1;
//   }

//   struct sockaddr_un addr = {AF_UNIX, "/tmp/socket"};
//   if (connect(socket_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
//     std::cerr << "Error connecting to socket: " << strerror(errno) << std::endl;
//     return 1;
//   }

//   const char message[] = "Hello from the client!";
//   write(socket_fd, message, sizeof(message));

//   close(socket_fd);
//   return 0;




// std::string is_correct_input(const int &sum) {
//     if ((sum / 10) < 1 || (sum % 32 != 0)) {
//         return "Input is incorrect, waiting for the proper input...";
//     }
//     return "Input is correct!\nWaiting for the next input...";
// }

// bool isInterrupted = false;
// void signal_callback_handler(int signum) {
//    std::cout << "Caught signal " << signum << std::endl;
//    isInterrupted=true;
//    //exit(signum);
// }

// std::string is_correct_input(const int &sum) {
//     if ((sum / 10) < 1 || (sum % 32 != 0)) {
//         return "Input is incorrect, waiting for the proper input...";
//     }
//     return "Input is correct!\nWaiting for the next input...";
// }