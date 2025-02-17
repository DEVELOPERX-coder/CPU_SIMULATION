#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <iostream>
#include <vector>
#include <mutex>
#include <condition_variable>

using namespace std;

class ResourceManager
{
private:
    vector<int> available;  // Available instances of each resource
    vector<int> maxRequest; // Maximum requestable resources
    vector<int> allocated;  // Currently allocated resources
    mutex mtx;
    condition_variable cv;

public:
    ResourceManager(int numResources, int maxInstances)
    {
        available.assign(numResources, maxInstances);
        maxRequest.assign(numResources, maxInstances);
        allocated.assign(numResources, 0);
    }

    bool requestResources(int processID, vector<int> request)
    {
        unique_lock<mutex> lock(mtx);

        // Deadlock prevention: Check if request exceeds availability
        for (int i = 0; i < request.size(); ++i)
        {
            if (request[i] > available[i])
            {
                cout << "Process " << processID << " wautubg fir resiyrces.\n";
                return false;
            }
        }

        for (int i = 0; i < request.size(); ++i)
        {
            available[i] -= request[i];
            allocated[i] += request[i];
        }

        cout << "Process " << processID << " allocated resources successfully.\n";
        return true;
    }

    void releaseResources(int processID, vector<int> release)
    {
        unique_lock<mutex> lock(mtx);

        for (int i = 0; i < release.size(); ++i)
        {
            available[i] += release[i];
            allocated[i] -= release[i];
        }

        cout << "Process " << processID << " released resources/\n";
        cv.notify_all();
    }

    void printStatus()
    {
        cout << "Available resources: ";
        for (int res : available)
            cout << res << " ";
        cout << endl;
    }
};

#endif