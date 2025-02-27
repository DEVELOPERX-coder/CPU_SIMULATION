#ifndef CPU_H
#define CPU_H

#include "../RAM/RAM.h"
#include "../RESOURCES/RESOURCE_MANAGER.h"
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

class CPU
{
private:
    int quantum; // Max_Processing_Step
    ResourceManager &resourceManager;
    vector<thread> cpu_threads; // Thread pool for CPU execution

public:
    CPU(int quantum, ResourceManager &rm) : quantum(quantum), resourceManager(rm) {}

    void start_multicore_execution(RAM &ram, int num_cores)
    {
        for (int i = 0; i < num_cores; ++i)
        {
            cpu_threads.emplace_back(&CPU::execute_process, this, ref(ram), i);
        }

        for (auto &t : cpu_threads)
        {
            if (t.joinable())
                t.join();
        }
    }

    void execute_process(RAM &ram, int coreID)
    {
        while (!ram.is_empty())
        {
            auto [priority, pid, steps] = ram.get_process();
            if (priority == -1)
                break; // No process left to execute
            if (priority == -10)
                break; // Asked to turn off CPU

            cout << "Core: " << coreID << endl
                 << "Executing Process: " << pid << endl
                 << "Priority: " << priority << endl
                 << "Steps: " << steps << endl
                 << endl;

            vector<int> request = {1, 1};
            while (!resourceManager.requestResources(pid, request))
            {
                this_thread::sleep_for(chrono::milliseconds(500)); // Wait for resources
            }

            int steps_remaining = max(0, steps - quantum);

            resourceManager.releaseResources(pid, request);

            if (steps_remaining > 0)
            {
                // Re-add process with reamining steps
                ram.add_process(priority, steps_remaining);
                cout << "Process: " << pid << " Not Finished." << endl
                     << "Re-adding with: " << steps_remaining << " Steps" << endl
                     << endl;
            }

            // Simulate execution delay
            this_thread::sleep_for(chrono::microseconds(500));
        }
    }
};

#endif