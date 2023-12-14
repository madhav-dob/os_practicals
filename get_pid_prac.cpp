#include <iostream>
#include <unistd.h>

int main() {
    pid_t pid = getpid();

    std::cout << "Process ID (PID): " << pid << std::endl;
    return 0;
}

