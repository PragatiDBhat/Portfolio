# Portfolio.github.io
# Operating System

<dl>
<dt>Course Name</dt>
<dd>Algorithmic Problem Solving</dd>
<dt>Course Code</dt>
<dd>23ECSE309</dd>
<dt>Name</dt>
<dd>Pragati D Bhat</dd>
<dt>University</dt>
<dd>KLE Technological University, Hubballi-31</dd>
</dl>

## Introduction
Operating system (OS), program that manages a computer’s resources, especially the allocation of those resources among other programs. Typical resources include the central processing unit (CPU), computer memory, file storage, input/output (I/O) devices, and network connections. Management tasks include scheduling resource use to avoid conflicts and interference between programs. Unlike most programs, which complete a task and terminate, an operating system runs indefinitely and terminates only when the computer is turned off.

Modern multiprocessing operating systems allow many processes to be active, where each process is a “thread” of computation being used to execute a program. One form of multiprocessing is called time-sharing, which lets many users share computer access by rapidly switching between them. Time-sharing must guard against interference between users’ programs, and most systems use virtual memory, in which the memory, or “address space,” used by a program may reside in secondary memory (such as on a magnetic hard disk drive) when not in immediate use, to be swapped back to occupy the faster main computer memory on demand. This virtual memory both increases the address space available to a program and helps to prevent programs from interfering with each other, but it requires careful control by the operating system and a set of allocation tables to keep track of memory use. Perhaps the most delicate and critical task for a modern operating system is allocation of the CPU; each process is allowed to use the CPU for a limited time, which may be a fraction of a second, and then must give up control and become suspended until its next turn. Switching between processes must itself use the CPU while protecting all data of the processes.

### Functionalities of Operating System
1. Memory management
2. Process scheduling
3. Error detection and handling
4. I/O management
5. Device management
6. File management
7. Security
8. System monitoring
9. Network management
10. User Interface
11. Resource allocation
12. Accounting

### How OS Uses Data Structures and Algorithms to Manage Everything?
Operating Systems (OS) rely heavily on data structures and algorithms to efficiently manage various aspects of the system. Here are some key ways in which data structures and algorithms are utilized by an OS:

#### Process Scheduling:
Data Structure: The OS uses data structures like queues, priority queues, or lists to manage processes waiting to be executed.
Algorithm: Various scheduling algorithms such as Round Robin, Shortest Job Next, or Priority Scheduling are implemented to decide the order in which processes are executed.
#### Memory Management:
Data Structure: Data structures like page tables, memory pools, or linked lists are used to keep track of allocated memory blocks.
Algorithm: Memory allocation algorithms like First Fit, Best Fit, or Worst Fit determine how memory is allocated and deallocated.
#### File System Management:
Data Structure: File systems use tree-like structures such as B-trees or hash tables to organize and store file metadata efficiently.
Algorithm: Algorithms like indexing methods (e.g., B+ trees for indexing file blocks) are employed for fast file retrieval.
#### Device Management:
Data Structure: The OS maintains data structures like queues or buffers to manage I/O requests from devices.
Algorithm: Disk scheduling algorithms (e.g., SCAN, C-SCAN) optimize the order in which disk requests are serviced.
#### Virtual Memory Management:
Data Structure: Page tables and TLBs (Translation Lookaside Buffers) are used to map virtual addresses to physical addresses.
Algorithm: Paging algorithms like LRU (Least Recently Used) help in efficient page replacement strategies.
#### Network Communication:
Data Structure: Data packets are often managed using queues or buffers before transmission.
Algorithm: Routing algorithms such as Dijkstra’s algorithm or Bellman-Ford algorithm determine the best path for packet delivery.
#### Security and Encryption:
Data Structure: Cryptographic algorithms utilize data structures like hash tables or trees for secure key management.
Algorithm: Encryption algorithms such as AES (Advanced Encryption Standard) ensure data security during transmission and storage.


###Segment Trees in Operating System Functionalities:

In operating system functionalities, Segment Trees can be used in various scenarios where efficient range queries and updates are required. Here are some areas where Segment Trees can be beneficial:
1. Memory Management
2. File System
3. Process Scheduling

   
Here is my code for segment tree construction as well as query to fined sum between a given range.
[Segment Trees](https://github.com/PragatiDBhat/Portfolio/blob/main/dynamicrangequeries.cpp)


###Operating System Applications of Red-Black Trees:

Red-Black trees can be used in operating systems for various purposes such as:
1. File Systems
2. Memory Management
3. Process Scheduling

   Here is my code for red-black trees.
   [Red-Black Tree]


###First Fit

First-Fit Allocation can be used for memory allocation purposes.The First-Fit technique involves searching through a list of free memory blocks from the beginning until a block large enough to accommodate the memory request is found. Once a suitable block is identified, it is split into two parts: one part allocated to the process and the other remaining as free memory.

####Advantages of Using First-Fit Allocation in Operating Systems:

1. Simple and efficient search algorithm
2. Minimizes memory fragmentation
3. Fast allocation of memory

Here is my code for first-fit allocation.
[First Fit] 
