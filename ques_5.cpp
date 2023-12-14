#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <optional>

struct MemoryInfo {
    long totalMem = 0;
    long freeMem = 0;
    long usedMem = 0;
};
std::optional<long> getMemoryValue(const std::string& filePath, const std::string& targetLabel) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error opening " << filePath << std::endl;
        return std::nullopt;
    }
    std::string line;
    while (std::getline(file, line)) {
        if (line.find(targetLabel) != std::string::npos) {
            std::istringstream iss(line);
            std::string label, memoryValue;
            iss >> label >> memoryValue;
            return std::stol(memoryValue);
        }
    }
    return std::nullopt;
}
MemoryInfo getMemoryInfo() {
    MemoryInfo memoryInfo;
    const std::string totalMemLabel = "MemTotal:";
    const std::string freeMemLabel = "MemFree:";

    std::optional<long> totalMem = getMemoryValue("/proc/meminfo", totalMemLabel);
    std::optional<long> freeMem = getMemoryValue("/proc/meminfo", freeMemLabel);

    if (totalMem && freeMem) {
        memoryInfo.totalMem = *totalMem;
        memoryInfo.freeMem = *freeMem;
        memoryInfo.usedMem = memoryInfo.totalMem - memoryInfo.freeMem;
    }
    return memoryInfo;
}
int main() {
    std::cout << "This is current memory usage status :\n\n";

    MemoryInfo memoryInfo = getMemoryInfo();

    std::cout << "Total Memory: " << memoryInfo.totalMem / 1024 << " MB\n";
    std::cout << "Free Memory: " << memoryInfo.freeMem / 1024 << " MB\n";
    std::cout << "Used Memory: " << memoryInfo.usedMem / 1024 << " MB\n";

    return 0;
}
