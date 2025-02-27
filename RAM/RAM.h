#ifndef RAM_H
#define RAM_H

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class RAM
{
private:
    // Min-heap to store processes: {priority, pid, steps}, Lower Number = Higher Priority
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> process_queue;
    int total_process = 0;
    int max_process = 20;

    int pid_counter = 0;

public:
    int add_process(int priority, int steps)
    {
        int pid = pid_counter;
        ++pid_counter;

        if (total_process <= max_process)
        {
            process_queue.push({priority, pid, steps}); // Adds a process to RAM (priority queue)
            ++total_process;
            return 1; // Space Allocated to Process
        }
        else
            return -1; // No Space For New Task
    }

    bool is_empty()
    {
        return process_queue.empty();
    }

    tuple<int, int, int> get_process()
    {
        if (!process_queue.empty())
        {
            auto process = process_queue.top();
            process_queue.pop();
            --total_process;
            return process;
        }
        return {-1, -1, -1}; // No process left
    }
};

#endif