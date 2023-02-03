#include <thread>   
#include "thread_obj.hpp"


int main() {
    ThreadObject A;
    std::thread th1(&ThreadObject::first_thread, &A);
    std::thread th2(&ThreadObject::second_thread, &A);

    th1.join();
    th2.join();
}


// std::string buf;
// std::mutex m;
// std::condition_variable cond;

// void first_thread() {
//     std::cout << "Enter a string containing digits only\n";
//     while (true) {
//         std::string str;
//         std::cin >> str;
//         if (!is_digits(str) || !is_correct_size(str)) {
//             std::cout << "Error\nEnter a new one\n";
//             continue;
//         }
//         sort_string(str);
//         change_even_digits(str);
//         std::unique_lock<std::mutex> ulock(m);
//         cond.wait(ulock, [] { return (buf.size() == 0) ? true : false; });
//         buf = str;
//         std::cout << buf.size() << std::endl;
//         cond.notify_one();
//     }
// }

// void second_thread() {
//     while (true) {
//         std::unique_lock<std::mutex> ulock(m);
//         cond.wait(ulock, [] { return (buf.size() > 0) ? true : false; });
//         std::string str = buf;
//         buf.clear();
//         cond.notify_one();
//         std::cout << "Received buffer from first thread: " << str << std::endl;
//         std::cout << sum_of_digits(str) << std::endl;
//     }
// }

// int main() {
//     buf.clear();
//     std::thread t1(first_thread);
//     std::thread t2(second_thread);
    
//     t1.join();
//     t2.join();
// }