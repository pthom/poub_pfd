#include <iostream>
#include "portable_file_dialogs/portable_file_dialogs.h"


int main()
{
    std::cout << "1\n"; 
    auto dlg = pfd::open_file("File Dialog");
    std::cout << "2\n"; 
    auto res = dlg.result();
    std::cout << "3\n"; 
    if (res.size() > 0)
        std::cout << res[0] << "\n";
    std::cout << "4\n"; 
}
