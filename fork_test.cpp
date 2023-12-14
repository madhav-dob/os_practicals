#include <iostream>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        std::cout << "This is the child process." << std::endl;
    } else if (pid > 0) {
        // Parent process
        std::cout << "This is the parent process." << std::endl;
    } else {
        // Fork failed
        std::cerr << "Fork failed." << std::endl;
        return 1;
    }

    return 0;
}
