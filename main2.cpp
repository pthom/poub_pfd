#include <iostream>
#include <future>
#include "portable_file_dialogs/portable_file_dialogs.h"


inline void start_func()
{
    printf("start_func enter\n");
    printf("start_func 2\n");
    std::mutex m_mutex;
    std::future<int> m_future;
    std::condition_variable m_cond;

    auto trampoline = [&m_cond]()
    {
        printf("trampoline 1\n");
        m_cond.notify_one();
        printf("trampoline 2\n");
        return 0;
    };
    printf("start_func 3\n");

    std::unique_lock<std::mutex> lock(m_mutex);
    printf("start_func 3\n");
    m_future = std::async(std::launch::async, trampoline);
    printf("start_func 4\n");
    m_cond.wait(lock);
    printf("start_func 5\n");
}


int main()
{
    std::cout << "1\n"; 
    start_func();
    std::cout << "4\n"; 
}
