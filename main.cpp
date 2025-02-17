#include <iostream>
#include "./RAM/RAM.h"
#include "./CPU/CPU.h"
#include "./RESOURCES/RESOURCE_MANAGER.h"

using namespace std;

int main()
{
    RAM ram;
    ResourceManager resourceManager(2, 2); // 2 Resources, 2 Instance Each
    CPU cpu(3, resourceManager);           // Quantum is 3 steps before switching

    // Adding processes to RAM (pid, priority, steps)
    ram.add_process(1, 2, 6); // Process 1, Priority 2, Needs 6 steps
    ram.add_process(2, 1, 4); // Process 2, Priority 1, Needs 4 steps (higher priority)
    ram.add_process(3, 3, 8); // Process 3, Priority 3, Needs 8 steps
    ram.add_process(4, 3, 6); // Process 3, Priority 3, Needs 8 steps
    ram.add_process(5, 3, 4); // Process 3, Priority 3, Needs 8 steps
    ram.add_process(6, 3, 2); // Process 3, Priority 3, Needs 8 steps

    // Execute processes
    int num_cores = 2; // Simulating a dual-core cpu
    cpu.start_multicore_execution(ram, num_cores);

    return 0;
}