#include <iostream>
#include <future>
#include "portable_file_dialogs/portable_file_dialogs.h"


int main()
{
    printf("main enter\n");
    std::mutex m_mutex;
    //std::future<int> m_future;

    //auto trampoline = []()
    //{
    //    printf("trampoline 1\n");
    //    return 0;
    //};
    printf("main 2\n");

    std::unique_lock<std::mutex> lock(m_mutex);
    printf("main 3\n");
    //m_future = std::async(std::launch::async, trampoline);
    //printf("main 4\n");
    //m_future.get();
    printf("main exit\n");
}
