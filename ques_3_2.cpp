#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        std::cout << "Child process executing a different executable." << std::endl;

        execlp("/home/madhav/work/os_practicals/second_exec", "second_exec", nullptr);
    } else if (pid > 0) {

        std::cout << "Parent process executing some sample code." << std::endl;
        for (int i = 1; i <= 5; ++i) {
        std::cout << std::string(5 - i, ' ') << std::string(i, '*') << " Parent process " << std::string(i, '*') << std::string(5 - i, ' ') << "\n";
        }

    } else {
        std::cerr << "Fork failed." << std::endl;
        return 1;
    }

    return 0;
}
