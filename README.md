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

### How OS Uses Data Structures and Algorithms ?
Data structures play a crucial role in operating systems by enabling efficient storage and retrieval of data. They are fundamental components that help the operating system perform various tasks such as job scheduling, memory management, storing instructions, and managing resources effectively. Operating systems rely on different data structures to organize and manipulate data efficiently, enhancing performance and optimizing resource utilization.


### Segment Trees in Operating System Functionalities:

In operating system functionalities, Segment Trees can be used in various scenarios where efficient range queries and updates are required. The construction of segment tree has time complexity of O(n), querying and updating takes O(logn) time. Segment trees can be used in the following functions:
1. Memory Management
2. File System
3. Process Scheduling

   
Here is my code for segment tree construction as well as query to fined sum between a given range.
[Segment Trees](https://github.com/PragatiDBhat/Portfolio/blob/main/dynamicrangequeries.cpp)


### Operating System Applications of Red-Black Trees:

Red-Black tress are preferred for balanced height, complexity in operation and less rotaions compared to AVL trees.Red-Black trees can be used in operating systems for various purposes such as:
1. File Systems
2. Memory Management
3. Process Scheduling

Time complexit: O(logn)
Space complexity: O(n)
   Here is my code for red-black trees.
   [Red-Black Tree](https://github.com/PragatiDBhat/Portfolio/blob/main/red-black.cpp)


### First Fit

First-Fit Allocation can be used for memory allocation purposes.The First-Fit technique involves searching through a list of free memory blocks from the beginning until a block large enough to accommodate the memory request is found. Once a suitable block is identified, it is split into two parts: one part allocated to the process and the other remaining as free memory.

#### Advantages of Using First-Fit Allocation in Operating Systems:

1. Simple and efficient search algorithm
2. Minimizes memory fragmentation
3. Fast allocation of memory

Here is my code for first-fit allocation.
[First Fit](https://github.com/PragatiDBhat/Portfolio/blob/main/hotelquery.cpp)

### Dijkstra Algorithm

In operating systems, Dijkstra's algorithm is utilized for tasks such as network routing and resource allocation. It determines the shortest path between nodes in a network, facilitating efficient packet transmission. Moreover, it aids in distributing resources like memory and CPU time optimally among processes, thereby improving system performance and resource utilization.
1. Network Routing: In an operating system, when a packet needs to be sent from one node to another in a network, Dijkstra's algorithm can be used to determine the shortest path through the network. The kernel or network stack maintains a routing table, and Dijkstra's algorithm helps update this table with the shortest paths to different network destinations based on various metrics like hop count or link cost.
2. Resource Allocation: Operating systems often need to allocate resources efficiently. Dijkstra's algorithm can be adapted to allocate resources such as memory or CPU time based on certain criteria, ensuring that the resources are distributed optimally and fairly among competing processes or tasks.

Here is my code for Dijkstra's algorithm.
[Dijkstra's Algorithm](https://github.com/PragatiDBhat/Portfolio/blob/main/dijkstra.c)
### Skip List

Operating systems can utilize skip lists for various purposes, primarily in data structures and algorithms for efficient searching, indexing, and managing dynamic data. 
1. File System Indexing: Skip lists aid in efficiently indexing and searching files within the file system hierarchy.
2. Process Scheduling: They facilitate quick sorting and management of processes based on priority or other criteria for efficient scheduling.
3. Memory Management: Skip lists enable fast retrieval and allocation of memory blocks, enhancing memory management.
4. Caching: Utilized for storing frequently accessed data, skip lists help in rapid identification and management of cache entries.
5. Kernel Data Structures: Integrated into various kernel data structures, they optimize storage and retrieval of information, enhancing overall system performance.

Here us my code for skip list.
[Skip List](https://github.com/PragatiDBhat/Portfolio/blob/main/skiplist.cpp)

### B+ Trees

Operating systems can leverage B+ trees for efficient storage and retrieval of data in various scenarios, especially in file systems and database management systems.
1. File System Indexing: B+ trees enable fast lookup and organization of file metadata, enhancing file system efficiency.
2. Database Management Systems (DBMS): They facilitate efficient storage and retrieval of data records in DBMS, supporting quick search and manipulation operations.
3. Disk Space Management: B+ trees aid in tracking free disk space and managing disk block allocation, optimizing storage resource utilization.
4. Virtual Memory Management: They help manage page tables efficiently in virtual memory systems, ensuring rapid translation of virtual addresses to physical addresses.
5. Kernel Data Structures: Integrated into kernel data structures, B+ trees optimize storage and retrieval of information, enhancing overall system performance.

Here is my code for B+ Tree.
[B+ Tree](https://github.com/PragatiDBhat/Portfolio/blob/main/bplusstree.cpp)

### Bin-Packing Algorithm

Operating systems can employ various bin packing algorithms, such as first-fit, best-fit, and worst-fit, for memory allocation and management. 

1. First-Fit Algorithm:
In memory management, the first-fit algorithm assigns incoming memory requests to the first available memory block that is large enough to accommodate the request.
Operating systems use first-fit to quickly find a suitable memory block for a process or data structure, reducing search time.
However, it may lead to memory fragmentation, as smaller leftover memory chunks may not be efficiently utilized.

Here is my code for First-Fit Algorithm.
[First-Fit 2](https://github.com/PragatiDBhat/Portfolio/blob/main/firstfit.cpp)

2. Best-Fit Algorithm:
The best-fit algorithm allocates memory to the smallest available block that is large enough to satisfy the request.
Operating systems use best-fit to minimize wasted memory by selecting the most appropriately sized block for each request.
While it reduces fragmentation compared to first-fit, it requires more extensive searching, potentially impacting performance.

Here is my code for Best-Fit Algorithm.
[Best-Fit](https://github.com/PragatiDBhat/Portfolio/blob/main/bestfit.cpp)

3. Worst-Fit Algorithm:
The worst-fit algorithm allocates memory to the largest available block that can accommodate the request.
Operating systems use worst-fit to minimize the creation of large, unusable memory fragments.
However, it tends to produce more fragmentation compared to first-fit and best-fit, as it leaves behind smaller leftover memory chunks.

Here is my code for Worst-Fit algorithm
[Worst-Fit](https://github.com/PragatiDBhat/Portfolio/blob/main/worstfit.cpp)
