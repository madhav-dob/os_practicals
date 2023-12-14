#include <iostream>
#include <unistd.h>

int main() {
    std::cout << "Inside the second executable." << std::endl;
    for (int i = 1; i <= 5; ++i) {
        std::cout << std::string(5 - i, ' ') << std::string(i, '*') << " child process " << std::string(i, '*') << std::string(5 - i, ' ') << "\n";
    }
    std::cout << "" << std::endl;
    std::cout << "Child process finished." << std::endl;


    return 0;
}
