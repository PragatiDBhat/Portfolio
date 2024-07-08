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

<div style="display: flex; align-items: center;">
  <img src="https://github.com/PragatiDBhat/Portfolio/assets/163662545/f7c6fe71-47c5-4e60-9e0a-1e5b0e631748" alt="Operating systems" style="width: 50%; height: auto; margin-right: 50px; margin-left:50px;"/>
  <p>An operating system is like the manager of a computer. It handles everything the computer does, from running programs to using its hardware like the screen and keyboard. It's the link between the software like apps, and the physical parts inside the computer. Examples include Windows, Linux, and Mac OS. Overall, it's essential software that keeps your computer running smoothly and makes sure everything works together.</p>
</div>



### Functionalities of Operating System

<table style="background-color: transparent; border-collapse: collapse; width: 100%;">
  <tr>
    <td style="padding: 20px; width: 50%; vertical-align: top;">
      <img src="https://github.com/PragatiDBhat/Portfolio/assets/163662545/d997c647-0eb9-4335-b7b8-28d1e4aeaf33" alt="Functionalities" style="max-width: 100%; height: auto; border-radius: 8px;">
    </td>
    <td style="padding: 20px; width: 50%; vertical-align: top;">
      <ul>
        <li>Memory management</li>
        <li>Process scheduling</li>
        <li>Error detection and handling</li>
        <li>I/O management</li>
        <li>Device management</li>
        <li>File management</li>
        <li>Security</li>
        <li>System monitoring</li>
        <li>Network management</li>
        <li>User Interface</li>
        <li>Resource allocation</li>
        <li>Accounting</li>
      </ul>
    </td>
  </tr>
</table>



### How OS Uses Data Structures and Algorithms ?
Data structures play a crucial role in operating systems by enabling efficient storage and retrieval of data. They are fundamental components that help the operating system perform various tasks such as job scheduling, memory management, storing instructions, and managing resources effectively. Operating systems rely on different data structures to organize and manipulate data efficiently, enhancing performance and optimizing resource utilization.

## Following Business cases are identified and presented.

### Resource management
Efficiently allocating CPU, memory, and I/O resources ensures that business applications run smoothly without interference, maximizing productivity. Some of the algorithms that can be used for this functionality are:
1. Segment Trees - Useful for range queries and updates, optimizing resource allocation in real-time.
   [Segment Tress](https://github.com/PragatiDBhat/Portfolio/blob/main/Codes/dynamicrangequeries.cpp)
2. Red-Black Trees - Balances resource management data structures for efficient insertion, deletion, and lookup operations. [Red-black Tress](https://github.com/PragatiDBhat/Portfolio/blob/main/Codes/red-black.cpp)
3. Bin-Packing Algorithm
   - **First-fit** - Quickly allocates resources to the first available slot, enhancing allocation speed. [First-Fit](https://github.com/PragatiDBhat/Portfolio/blob/main/Codes/firstfit.cpp)
   - **Best-fit** - Minimizes wasted resources by placing them in the tightest available slot. [Best-Fit](https://github.com/PragatiDBhat/Portfolio/blob/main/Codes/bestfit.cpp)
   - **Worst-fit** - Distributes resources to the largest available slot to balance load over time. [Worst-Fit](https://github.com/PragatiDBhat/Portfolio/blob/main/Codes/worstfit.cpp)


### Security
Operating systems provide security features such as access control, encryption, and firewall management to protect sensitive business data and systems from unauthorized access and cyber threats. Data structures and algorithms leveraged for this are:
1. Aho-Corasick Algorithm - Efficiently detects patterns in large datasets, aiding in intrusion detection systems. [Aho-Corasick](https://github.com/PragatiDBhat/Portfolio/blob/main/Codes/Aho-Corasick.cpp)
2. Binary Search Tree - Provides quick access and management of security keys and certificates.[BST](https://github.com/PragatiDBhat/Portfolio/blob/main/Codes/binarysearchtree.c)

   
### Network management
Facilitating network routing and data transmission ensures reliable connectivity between business units, remote offices, and clients, supporting seamless communication and collaboration. The following least path algorithms can be used:
1. Dijkstra's Algorithm - Finds the shortest path in a network, optimizing data routing. [Dijsktra](https://github.com/PragatiDBhat/Portfolio/blob/main/Codes/dijkstra.c)
2. Ant Colony Optimization Algorithm - Mimics the behavior of ants to find optimal paths and manage network traffic dynamically. [Ant Colony](https://github.com/PragatiDBhat/Portfolio/blob/main/Codes/antcolony.cpp)
3. A* Search Algorithm* - Combines heuristics and path cost to find the most efficient route in a network. [A* ](https://github.com/PragatiDBhat/Portfolio/blob/main/Codes/astar.cpp)
4. Bellman-Ford Algorithm - Handles routing in networks with negative weight edges, ensuring reliable connectivity.[Bellman-Ford](https://github.com/PragatiDBhat/Portfolio/blob/main/Codes/bellman.c)


### File management
Organizing and managing files across storage devices ensures quick access to business-critical data, supporting efficient workflows and decision-making. The following algorithms can be applied for this functionality:
1. Trie Data Structure - Efficiently stores and retrieves large sets of strings, aiding in file search and organization. [Trie](https://github.com/PragatiDBhat/Portfolio/blob/main/Codes/trie.cpp)
2. B+ Trees - Provides balanced and efficient access to file records, enhancing database performance.[B+](https://github.com/PragatiDBhat/Portfolio/blob/main/Codes/bplusstree.cpp)


### Virtualization
Operating systems support virtualization technologies, enabling businesses to consolidate servers, optimize resource utilization, and reduce hardware costs while maintaining performance and scalability.
1. Segment Trees - Efficiently manages resources allocated to virtual machines, enabling dynamic allocation. [Segment Tress](https://github.com/PragatiDBhat/Portfolio/blob/main/Codes/dynamicrangequeries.cpp)
2. Binary Search Trees (BST) - Organizes virtual machine resources for efficient allocation and retrieval. [BST](https://github.com/PragatiDBhat/Portfolio/blob/main/Codes/binarysearchtree.c)

### Application support
Providing compatibility and support for various business applications ensures employees can use essential tools for tasks ranging from accounting and customer management to creative design and data analysis.
1. Hash Tables - Offers fast access to application data and configurations.[Hash](https://github.com/PragatiDBhat/Portfolioablob/main/Codes/hash.cpp)
2. BFS and DFS - Traverses application dependencies and structures, ensuring efficient execution. [BFS](https://github.com/PragatiDBhat/Portfolio/blob/main/Codes/bfs.c)  [DFS](https://github.com/PragatiDBhat/Portfolio/blob/main/Codes/dfs.c)

### Backup and recovery
Operating systems facilitate automated backup processes and recovery procedures, safeguarding against data loss due to hardware failures, human error, or malicious activities.
1. Skip List - Provides efficient access and update operations for backup indices. [Skip List](https://github.com/PragatiDBhat/Portfolio/blob/main/Codes/skiplist.cpp)
2. Union-Find - Manages backup versions and relationships, simplifying recovery processes. [Union Find](https://github.com/PragatiDBhat/Portfolio/blob/main/Codes/unionfind.cpp)

### Compliance and governance
Ensuring operating systems adhere to industry regulations and standards (such as HIPAA, GDPR) helps businesses avoid legal liabilities and reputational damage related to data privacy and security breaches.
1. Stable Marriage Problem - Ensures fair resource allocation and compliance processes. [Stable Marriage](https://github.com/PragatiDBhat/Portfolio/blob/main/Codes/stablemarriage.cpp)
2. Topological Sorting - Orders tasks and dependencies to comply with regulations. [topological Sorting](https://github.com/PragatiDBhat/Portfolio/blob/main/Codes/topologicalsorting.cpp)
3. Kruskal's Algorithm - Builds minimal compliance networks ensuring all requirements are met efficiently. [Kruskal](https://github.com/PragatiDBhat/Portfolio/blob/main/Codes/kruskal.c)


### Real-time processing
Operating systems with real-time capabilities support industries like finance, manufacturing, and telecommunications, where timely data processing and response are critical for operations and customer service.
1. Heap Data Structure - Manages real-time task scheduling with efficient priority queue operations. [Max Heap](https://github.com/PragatiDBhat/Portfolio/blob/main/Codes/heap.cpp)
2. Fenwick Trees - Provides efficient updates and queries for real-time data processing. [Fenwick Tree](https://github.com/PragatiDBhat/Portfolio/blob/main/Codes/rangeupdateandsums.cpp)


### Facilitating management and logistics
Identifying the shortest paths or least-cost routes for transporting goods between warehouses, distribution centers, and retail outlets. Optimizing the layout of manufacturing plants or warehouses to minimize transportation costs and maximize operational efficiency.
1. Floyd-Warshall Algorithm - Computes shortest paths between all pairs of locations, optimizing logistics routes.[Floy-Warshall](https://github.com/PragatiDBhat/Portfolio/blob/main/Codes/floyd-warshall.c)
2. Traveling Salesman Problem - Finds the most efficient route for goods transportation, minimizing travel cost and time. [TSP](https://github.com/PragatiDBhat/Portfolio/blob/main/Codes/tsp.cpp)


## Bonus
These days, everyone is focused on optimization, whether it involves VNF scheduling and consolidation or any machine learning project.

### Whale Optimization Algorithm
<table style="background-color: transparent; border-collapse: collapse; width: 100%;">
  <tr>
    <!-- Image Column -->
    <td style="padding: 20px; width: 50%; vertical-align: top;">
      <img src="https://github.com/PragatiDBhat/Portfolio/assets/163662545/cc783bfa-5f44-496a-8ced-8acfee28c8bf" alt="Whale Optimization" style="max-width: 100%; height: auto; border-radius: 8px;">
    </td>
    <!-- Text Column -->
    <td style="padding: 20px; width: 50%; vertical-align: top;">
      <p>The Whale Optimization Algorithm (WOA) is a nature-inspired optimization technique developed by Seyedali Mirjalili and Andrew Lewis in 2016. It mimics the hunting behavior of humpback whales, particularly their unique bubble-net feeding strategy.</p>
    </td>
  </tr>
</table>


### Key Features of the Whale Optimization Algorithm 

1. **Encircling Prey:** Whales identify the location of prey and encircle it. In WOA, this behavior is modeled mathematically to update the positions of search agents.

2. **Bubble-Net Attacking Method:**
   - **Shrinking Encircling Mechanism:** The distance between the whale and the prey is reduced over iterations, allowing the algorithm to explore the search space more effectively.
   - **Spiral Updating Position:** Whales follow a spiral-shaped path towards the prey, which helps in refining the search process and enhances exploitation capabilities.

3. **Search for Prey (Exploration):** To ensure a balance between exploration and exploitation, WOA randomly selects between shrinking encircling and spiral updating positions. This stochastic behavior helps in diversifying the search agents' movements, avoiding local optima.

### Applications

WOA has been successfully applied to various fields, including:
- Engineering design optimization
- Feature selection in machine learning
- VNF scheduling and consolidation
- Image processing
- Robotics

The algorithm's simplicity, flexibility, and efficiency make it a popular choice for solving complex optimization problems.[WOA](https://github.com/PragatiDBhat/Portfolio/blob/main/Codes/whaleoptimisation.cpp)


### Time and Space Complexities

| **Algorithm**                         | **Time Complexity**                            | **Space Complexity**                          |
|---------------------------------------|------------------------------------------------|-----------------------------------------------|
| **Segment Trees**                     | Build: O(n log n), Query/Update: O(log n)      | O(n)                                          |
| **Red-Black Trees**                   | Insert/Delete/Search: O(log n)                 | O(n)                                          |
| **First-fit (Bin-Packing)**           | O(n log n)                                     | O(n)                                          |
| **Best-fit (Bin-Packing)**            | O(n log n)                                     | O(n)                                          |
| **Worst-fit (Bin-Packing)**           | O(n log n)                                     | O(n)                                          |
| **Aho-Corasick Algorithm**            | Build: O(m), Search: O(n + z)                  | O(m)                                          |
| **Binary Search Tree**                | Insert/Delete/Search: O(log n) avg, O(n) worst | O(n)                                          |
| **Dijkstra's Algorithm**              | O((V + E) log V)                               | O(V^2)                                        |
| **Ant Colony Optimization Algorithm** | O(n^3) per iteration                           | O(n^2)                                        |
| **A* Search Algorithm**               | O(E)                                           | O(E)                                          |
| **Bellman-Ford Algorithm**            | O(VE)                                          | O(V)                                          |
| **Trie Data Structure**               | Insert/Search: O(m)                            | O(m) per node                                 |
| **B+ Trees**                          | Insert/Delete/Search: O(log n)                 | O(n)                                          |
| **Hash Tables**                       | Insert/Delete/Search: O(1) avg                 | O(n)                                          |
| **BFS and DFS**                       | O(V + E)                                       | O(V)                                          |
| **Skip List**                         | Insert/Delete/Search: O(log n)                 | O(n)                                          |
| **Union-Find**                        | Union/Find: O(α(n))                            | O(n)                                          |
| **Stable Marriage Problem**           | O(n^2)                                         | O(n^2)                                        |
| **Topological Sorting**               | O(V + E)                                       | O(V)                                          |
| **Kruskal's Algorithm**               | O(E log E)                                     | O(E + V)                                      |
| **Heap Data Structure**               | Insert/Delete/Extract-Min: O(log n)            | O(n)                                          |
| **Fenwick Trees**                     | Build: O(n log n), Update/Query: O(log n)      | O(n)                                          |
| **Floyd-Warshall Algorithm**          | O(V^3)                                         | O(V^2)                                        |
| **Traveling Salesman Problem**        | O(n^2 * 2^n)                                   | O(n * 2^n)                                    |

## References
1. Chen, X., Cheng, L., Liu, C., Liu, Q., Liu, J., Mao, Y. and Murphy, J., 2020. A WOA-based optimization approach for task scheduling in cloud computing systems. IEEE Systems journal, 14(3), pp.3117-3128.
2. Sultana, N., Paira, S., Chandra, S. and Alam, S.S., 2017, February. A brief study and analysis of different searching algorithms. In 2017 second international conference on electrical, computer and communication technologies (ICECCT) (pp. 1-4). IEEE.
3. Gen, M. and Lin, L., 2023. Genetic algorithms and their applications. In Springer handbook of engineering statistics (pp. 635-674). London: Springer London.
4. Kanda, S., Akabe, K. and Oda, Y., 2023. Engineering faster double‐array Aho–Corasick automata. Software: Practice and Experience, 53(6), pp.1332-1361.
5. Pocchiola, A. (2015) 'Aho-Corasick Algorithm', Toptal. Available at: https://www.toptal.com/algorithms/aho-corasick-algorithm#:~:text=The%20Aho%2DCorasick%20algorithm%20is,%2FDNA%20sequence%20searching%2C%20etc.
6. GeeksforGeeks (2024) 'Introduction of B-Tree'. Available at: https://www.geeksforgeeks.org/introduction-of-b-tree/
