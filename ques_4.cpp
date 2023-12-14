#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <string_view>
#include <sys/utsname.h>
void readCPUInfo() {
    std::ifstream cpuinfoFile("/proc/cpuinfo");
    std::string line;

    if (cpuinfoFile.is_open()) {
        std::string processorType, processorModel, cores;
        while (std::getline(cpuinfoFile, line)) {
            std::string_view lineView(line);
            if (lineView.substr(0, 10) == "model name") {
                processorModel = lineView.substr(line.find(":") + 2);
            } else if (lineView.substr(0, 9) == "processor") {
                cores = lineView.substr(line.find(":") + 2);
            } else if (lineView.substr(0, 7) == "cpu MHz") {
                processorType = lineView.substr(line.find(":") + 2);
                break;
            }
        }

        std::cout << "CPU Type: " << processorType << std::endl;
        std::cout << "CPU Model: " << processorModel << std::endl;
        std::cout << "Number of Cores: " << cores << std::endl;

    } else {
        std::cout << "Unable to open /proc/cpuinfo" << std::endl;
    }
}
int main() {
    struct utsname unameData;
    if (uname(&unameData) == 0) {
        std::cout << "Kernel Version: " << unameData.release << std::endl;
    } else {
        std::cerr << "Error getting kernel information" << std::endl;
    }
    readCPUInfo();

    return 0;
}
