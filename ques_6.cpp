#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#define BUFFER_SIZE 4096
int main() {
    const char* sourceFile = "file1.txt";
    const char* destinationFile = "file2.txt";
    int sourceFd = open(sourceFile, O_RDONLY);
    if (sourceFd == -1) {
        std::cerr << "Error opening source file." << std::endl;
        return 1;
    }
    int destinationFd = open(destinationFile, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (destinationFd == -1) {
        std::cerr << "Error opening or creating destination file." << std::endl;
        close(sourceFd);
        return 1;
    }
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead, bytesWritten;
    while ((bytesRead = read(sourceFd, buffer, BUFFER_SIZE)) > 0) {
        bytesWritten = write(destinationFd, buffer, bytesRead);
        if (bytesWritten != bytesRead) {
            std::cerr << "Error writing to destination file." << std::endl;
            close(sourceFd);
            close(destinationFd);
            return 1;
        }
    }
    if (bytesRead == -1) {
        std::cerr << "Error reading from source file." << std::endl;
        close(sourceFd);
        close(destinationFd);
        return 1;
    }
    close(sourceFd);
    close(destinationFd);
    std::cout << "File copied successfully." << std::endl;
    return 0;
}
