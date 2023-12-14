#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        std::cout << "This is the child process." << std::endl;

    } else if (pid > 0) {

        std::cout << "This is the parent process" << std::endl;
    } else {
        std::cerr << "Fork failed." << std::endl;
        return 1;
    }

    return 0;
}
