#include "server_obj.hpp"

ServerObj::ServerObj() {
    std::cout << "Waiting for the first program..." << std::endl;
    server_config();
    server_work();
}

ServerObj::~ServerObj() {
    write(client_fd, "Bye client!", 11);
    close(server_fd);
}

bool ServerObj::server_config() {
    server_fd = socket(AF_UNIX, SOCK_STREAM, 0); 
    if (server_fd < 0) {
        std::cerr << "Error creating socket: " << strerror(errno) << std::endl;
        return false;
    }

    //server_address = {AF_UNIX, "/tmp/socket"};
    server_address.sun_family = AF_UNIX;
    strcpy(server_address.sun_path, "/tmp/socket");
    
    unlink(server_address.sun_path);
    if (bind(server_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        std::cerr << "Error binding socket: " << strerror(errno) << std::endl;
        return false;
    }

    listen(server_fd, 5);

    client_fd = accept(server_fd, (struct sockaddr *) NULL, NULL);
    if (client_fd < 0) {
        std::cerr << "Error accepting connection: " << strerror(errno) << std::endl;
        return false;
    }
    std::cout << "Connected!" << std::endl; 
    return true;
}

void ServerObj::signal_callback_handler (int signum) {
   write(static_client_fd, "Bye client!", 11);
   exit(0);
}

int ServerObj::static_client_fd;

void ServerObj::set_client_fd(int fd) {
    static_client_fd = fd;
}


void ServerObj::server_work() {
    set_client_fd(client_fd);
    signal(SIGINT, signal_callback_handler);
    while(true){
        char buffer[10];
        write(client_fd, "Hello client!", 13);
        ssize_t bytes_read = read(client_fd, buffer, sizeof(buffer));
        if (bytes_read > 0) {
            buffer[bytes_read] = '\0';
            std::cout << is_correct_input(atoi(buffer)) << std::endl;
        } else {
            listen(server_fd, 5);
            std::cout << "Reconnecting..." << std::endl;
            client_fd = accept(server_fd, nullptr, nullptr);
            set_client_fd(client_fd);
            std::cout << "Connected!" << std::endl;
        }
    }
}

std::string ServerObj::is_correct_input(const int &sum) {
    if ((sum / 100) < 1 || (sum % 32 != 0)) {
        return "Input is incorrect, waiting for the proper input...";
    }
    return "Input is correct!\nWaiting for the next input...";
}
