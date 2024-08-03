#include <iostream>
#include <future>
#include "portable_file_dialogs/portable_file_dialogs.h"


inline void start_func()
{
    printf("start_func enter\n");
    std::mutex m_mutex;
    std::future<int> m_future;
    //std::condition_variable m_cond;

    auto trampoline = []()
    {
        printf("trampoline 1\n");
        //m_cond.notify_one();
        printf("trampoline 2\n");
        return 0;
    };
    printf("start_func 3\n");

    std::unique_lock<std::mutex> lock(m_mutex);
    printf("start_func 3\n");
    m_future = std::async(std::launch::async, trampoline);
    printf("start_func 4\n");
    //m_cond.wait(lock);
    m_future.get();
    printf("start_func 5\n");
}


int main()
{
    std::cout << "main enter\n"; 
    start_func();
    std::cout << "main end\n"; 
}
