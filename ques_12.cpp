#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct MemoryBlock {
    int id;
    int size;
    bool allocated;

    MemoryBlock(int _id, int _size) : id(_id), size(_size), allocated(false) {}
};
class MemoryManager {
private:
    vector<MemoryBlock> memory;
public:
    MemoryManager(vector<int> blockSizes) {
        for (int i = 0; i < blockSizes.size(); ++i) {
            memory.emplace_back(i, blockSizes[i]);
        }
    }
    void firstFit(int processSize) {
        for (auto &block : memory) {
            if (!block.allocated && block.size >= processSize) {
                block.allocated = true;
                cout << "Process of size " << processSize << " allocated to block " << \
                 block.id << " using First-Fit strategy.\n";
                return;
            }
        }
        cout << "Process of size " << processSize << " cannot be allocated using First-Fit strategy.\n";
    }
    void bestFit(int processSize) {
        auto bestFitBlock = memory.end();
        for (auto it = memory.begin(); it != memory.end(); ++it) {
            if (!it->allocated && it->size >= processSize) {
                if (bestFitBlock == memory.end() || bestFitBlock->size > it->size) {
                    bestFitBlock = it;
                }
            }
        }
        if (bestFitBlock != memory.end()) {
            bestFitBlock->allocated = true;
            cout << "Process of size " << processSize << " allocated to block " << bestFitBlock->id \
             << " using Best-Fit strategy.\n";
        } else {
            cout << "Process of size " << processSize << " cannot be allocated using Best-Fit strategy.\n";
        }
    }
    void worstFit(int processSize) {
        auto worstFitBlock = memory.end();
        for (auto it = memory.begin(); it != memory.end(); ++it) {
            if (!it->allocated && it->size >= processSize) {
                if (worstFitBlock == memory.end() || worstFitBlock->size < it->size) {
                    worstFitBlock = it;
                }
            }
        }
        if (worstFitBlock != memory.end()) {
            worstFitBlock->allocated = true;
            cout << "Process of size " << processSize << " allocated to block " << worstFitBlock->id \
             << " using Worst-Fit strategy.\n";
        } else {
            cout << "Process of size " << processSize << " cannot be allocated using Worst-Fit strategy.\n";
        }
    }
    void printMemoryStatus() {
        cout << "Memory Block Status:\n";
        for (const auto &block : memory) {
            cout << "Block " << block.id << ": Size = " << block.size << ", Allocated = " << \
            (block.allocated ? "Yes" : "No") << "\n";
        }
        cout << "-----------------------\n";
    }
};
int main() {
    vector<int> blockSizes = {100, 200, 50, 300, 150};
    MemoryManager memoryManager(blockSizes);
    memoryManager.printMemoryStatus();
    memoryManager.firstFit(120);
    memoryManager.bestFit(120);
    memoryManager.worstFit(120);
    memoryManager.printMemoryStatus();
    return 0;
}
