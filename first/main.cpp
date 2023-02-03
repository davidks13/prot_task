#include <thread>   
#include "thread_obj.hpp"


int main() {
    ThreadObject A;
    std::thread th1(&ThreadObject::first_thread, &A);
    std::thread th2(&ThreadObject::second_thread, &A);

    th1.join();
    th2.join();
}


