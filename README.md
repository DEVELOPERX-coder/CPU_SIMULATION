# CPU_SIMULATION

# **Multithreaded CPU-RAM Resource Allocation & Process Scheduling Simulation**

## 📌 Overview

This project is a **C++-based simulation** of a **multithreaded CPU process scheduling system** with **RAM management** and **resource allocation using semaphores**. It replicates real-world **operating system behavior**, handling process execution, priority-based scheduling, and resource contention, while ensuring **deadlock prevention**.

The implementation uses **multi-threading (`std::thread`)**, **priority queues**, **semaphores (`std::mutex`)**, and **synchronization techniques**, making it ideal for research in **OS scheduling, real-time computing, and process synchronization**.

---

## 🚀 Features

✔ **Multithreaded Execution:** Simulates multiple CPU cores executing tasks in parallel.  
✔ **Priority-Based Scheduling:** Executes processes based on assigned priority.  
✔ **Quantum-Based CPU Scheduling:** Implements **Round Robin** scheduling.  
✔ **Shared Resource Management:** Uses **semaphores** to allocate shared resources.  
✔ **Deadlock Prevention:** Implements a controlled **wait-and-signal mechanism**.  
✔ **Dynamic Process Handling:** Supports runtime process addition.  
✔ **Realistic RAM Utilization:** Ensures efficient memory management.

---

## 🛠️ System Architecture

This project consists of **three main components**:

### **1️⃣ RAM Management (`ram.h`)**

- Stores processes in a **priority queue**.
- Retrieves and removes processes dynamically as they are executed.

### **2️⃣ CPU Execution (`cpu.h`)**

- Uses **multithreading** to simulate **multiple CPU cores**.
- Implements **Round-Robin scheduling** with **quantum execution**.

### **3️⃣ Resource Manager (`resource_manager.h`)**

- Uses **semaphores (`std::mutex`)** to prevent deadlocks.
- Controls resource allocation and ensures safe access.

---

## 🔧 Technical Details & Implementation

### **🔹 Process Structure**

Each process has:

- **Process ID (`pid`)** – Unique identifier.
- **Priority (`priority`)** – Higher values indicate higher importance.
- **Steps (`steps`)** – Number of execution cycles.

### **🔹 RAM Management**

- Uses a **min-heap priority queue** for efficient scheduling.
- Ensures **fair execution order** for processes.

### **🔹 CPU Execution**

- Implements **Round-Robin scheduling**.
- Uses **multithreading (`std::thread`)** for parallel execution.

### **🔹 Resource Allocation**

- Uses **semaphores (`std::mutex`)** to manage shared resources.
- Ensures **deadlock prevention** using **safe resource allocation**.

---

## 📌 Process Execution Flow

1. **Processes are stored in RAM** with priority-based scheduling.
2. **CPU cores fetch processes** and execute for `q` quantum time.
3. **Processes request shared resources** using a semaphore lock.
4. **Completed processes release resources**, allowing other processes to execute.
5. **Threads execute concurrently**, ensuring efficient execution.

---

## 📈 Research & Applications

This simulation provides **realistic OS behavior** and is valuable for:  
✔ **Operating System Research** – Study of scheduling algorithms.  
✔ **Real-Time Systems** – Simulations of deadline-based execution.  
✔ **Embedded Systems** – Execution under resource constraints.  
✔ **Parallel Computing** – Performance testing of multi-threaded execution.

---

## 🔍 Possible Enhancements

🔹 **Priority Aging:** Prevents starvation by dynamically increasing process priority.  
🔹 **Dynamic Process Addition:** Allows adding processes at runtime.  
🔹 **I/O Bound & CPU Bound Tasks:** Simulates different execution behaviors.  
🔹 **Machine Learning-Based Scheduling:** Optimizes execution dynamically.  
🔹 **Cloud-Based Resource Allocation:** Simulates distributed computing environments.

---

## 💻 Setup & Execution

### **🔹 Prerequisites**

- **C++ Compiler** (`g++`, `MSVC`, `Clang`)
- **C++ Standard Library** (`<thread>`, `<mutex>`, `<queue>`, `<iostream>`)

### **🔹 Compilation & Execution**

```sh
g++ -std=c++17 main.cpp -o simulation -lpthread
./simulation
```
