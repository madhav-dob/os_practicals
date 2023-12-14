#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {

        std::cout << "Child process executing..." << std::endl;
        execlp("/home/madhav/work/os_practicals/second_exec", "second_exec", nullptr);
    } else if (pid > 0) {

        std::cout << "Parent process executing..." << std::endl;
        wait(nullptr); 
        std::cout << "Parent process finished waiting." << std::endl;
    } else {
        std::cerr << "Fork failed." << std::endl;
        return 1;
    }

    return 0;
}
