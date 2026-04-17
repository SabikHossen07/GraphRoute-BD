# GraphRoute-BD
# 🇧🇩 Graph Route Bangladesh

> A shortest-path analysis project for Bangladesh’s district road network using **Dijkstra**, **Bellman-Ford**, and **Floyd-Warshall** algorithms.

This project models the districts of Bangladesh as a **weighted graph**, where districts are treated as nodes and roads are treated as edges with distances/costs. It allows users to select a **source** and **destination** district and then computes the shortest route using multiple graph algorithms. :contentReference[oaicite:0]{index=0}

---

## ✨ Features

- Show all available districts in the network
- Find shortest path using **Dijkstra’s Algorithm**
- Find shortest path using **Bellman-Ford Algorithm**
- Find shortest path using **Floyd-Warshall Algorithm**
- Compare different shortest path approaches
- Display total distance and reconstructed route
- Use a graph-based road network model for Bangladesh :contentReference[oaicite:1]{index=1} :contentReference[oaicite:2]{index=2}

---

## 🎯 Project Objectives

This project was developed to:

- Model Bangladesh’s districts as a graph
- Apply shortest path algorithms
- Compute optimal routes efficiently
- Demonstrate the real-world relevance of graph theory :contentReference[oaicite:3]{index=3}

---

## 🧠 Algorithms Used

### 1. Dijkstra’s Algorithm
A greedy shortest-path algorithm for graphs with **non-negative edge weights**.

- Best for single-source shortest path
- Uses a priority queue / min-heap
- Time Complexity: `O((V + E) log V)`
- Space Complexity: `O(V)` :contentReference[oaicite:4]{index=4}

### 2. Bellman-Ford Algorithm
A dynamic-programming-based shortest-path algorithm that can also handle **negative edge weights**.

- Works for single-source shortest path
- Can detect negative-weight cycles
- Time Complexity: `O(V × E)`
- Space Complexity: `O(V)` :contentReference[oaicite:5]{index=5}

### 3. Floyd-Warshall Algorithm
An all-pairs shortest-path algorithm using **dynamic programming**.

- Computes shortest paths between every pair of nodes
- Useful for route pre-processing and analysis
- Time Complexity: `O(V³)`
- Space Complexity: `O(V²)` :contentReference[oaicite:6]{index=6}

---

## 🏗️ System Design

The project follows a modular graph-based design. Important components include:

- `cityToIndex` → maps district names to integer indices
- `indexToCity` → maps indices back to district names
- `adjacent_list` → stores graph connections
- `edges` → stores edge list for Bellman-Ford and Floyd-Warshall

Core functions:

- `addCity()`
- `addEdge()`
- `loadFromFile()`
- `dijkstra()`
- `bellmanFord()`
- `floydWarshall()` :contentReference[oaicite:7]{index=7}

---

## 🛠️ Tech Stack

- **Language:** C++
- **Libraries:** `iostream`, `fstream`, `cstring`, `bits/stdc++.h`
- **Compiler:** MinGW / Visual Studio
- **Main Source File:** `Project.cpp` :contentReference[oaicite:8]{index=8}

---

## 🚀 How It Works

1. Load the district and road connection data
2. Display available districts
3. Take source and destination input from the user
4. Run the selected shortest path algorithm
5. Show the shortest distance
6. Print the route step by step :contentReference[oaicite:9]{index=9}

---

## 📋 Menu Preview

```text
Graph Route Bangladesh

1. Show all districts
2. Find shortest path (Dijkstra)
3. Find shortest path (Bellman-Ford)
4. Find shortest path (Floyd-Warshall)
5. Exit

The report’s results section shows this console menu and an example route query. In the sample shown, the shortest route from Dhaka to Faridpur using Dijkstra has a total distance of 128 km, going through Manikganj.

📊 Dataset / Network Information

The transportation graph in the report includes:

64 districts
279 bidirectional routes
Average degree: 6.25 connections per district
Distance range: 10 km to 323 km
📈 Performance Insights
Dijkstra
Fast and efficient for non-negative weighted graphs
Good for interactive route queries
Memory efficient compared to heavier approaches
Bellman-Ford
Useful when negative weights need to be supported
Can detect invalid graph conditions like negative cycles
Slower on large graphs
Floyd-Warshall
Best when many route queries are needed on the same graph
Computes all-pairs shortest paths
More expensive in both time and memory

The visual comparison charts in the report’s results section also show the relative complexity difference among the three algorithms, with Floyd-Warshall having the highest relative cost.

⚠️ Limitations

Current limitations of the project:

Uses static graph data
No real-time traffic or road condition updates
Route calculation is based only on distance/cost
Does not consider weather, transport modes, or live incidents
Requires manual data updates when roads change
🔮 Future Improvements

Possible future upgrades include:

Interactive web-based UI
Mobile application support
Live traffic data integration
Google Maps API / OpenStreetMap integration
Real-time route customization
Emergency-response route planning support
🏆 Project Achievements

This project successfully:

Implemented three classical shortest path algorithms
Built a graph model of Bangladesh’s district network
Added input validation and error handling
Demonstrated practical applications of graph theory
Improved understanding of algorithm optimization and real-world implementation

📁 Project Structure
Graph-Route-Bangladesh/
├── Project.cpp
├── README.md
└── input-data-files

Update the structure above if your repository contains additional files or folders.

🎓 Academic Information
Course: CSE246 - Algorithms
Section: 02
Semester: Fall 2025
Project Title: Graph Route Bangladesh
Group No: 05

👨‍💻 Team Members
Md. Sabik Hossen
Hadiul Alam Hredoy


👨‍🏫 Supervisor
Dr. Md. Tauhid Bin Iqbal
Assistant Professor
Department of CSE, East West University

✅ Conclusion

Graph Route Bangladesh is a practical graph-theory-based route analysis project that applies shortest path algorithms to a real transportation problem in Bangladesh. By implementing and comparing Dijkstra, Bellman-Ford, and Floyd-Warshall, the project highlights both algorithmic trade-offs and their usefulness in real-world route planning systems.

📌 License

This project was developed for academic purposes as part of the CSE246 Algorithms course.
