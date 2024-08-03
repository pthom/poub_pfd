Demonstrates a serious issue in Windows GitHub runners: any exe that uses std::unique_lock<std::mutex> is unreliable!


This "hello mutex" program will produce a perfectly valid executable, when compiled on a standard windows machine.

```cpp
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
```

However, when downloading and running the exe produced by GitHub runners, the program will fail when creating the lock!!!

Executables produced by GitHub runner can be found inside the artifacts of the repository:
https://github.com/pthom/poub_pfd/actions

