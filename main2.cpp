#include "stdio.h"
#include <future>

int main()
{
    printf("main enter\n");
    std::mutex m_mutex;
    printf("Created mutex\n");
    std::unique_lock<std::mutex> lock(m_mutex);
    printf("Instantiated lock\n");
    printf("main exit\n");
}
