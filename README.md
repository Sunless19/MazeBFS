# Maze Solver using Breadth-First Search Algorithm
### This application is designed to solve mazes by finding the shortest paths to all exits using the breadth-first search (BFS) algorithm. It is built using the Qt framework.
### Features:
## 1. Reading Maze Matrix from Input File:

- The application reads the maze matrix from an input file named "inputMatrix.txt".
- The matrix represents a maze where:
  - "1" denotes a path that can be traversed,
  - "0" denotes a wall,
  - "3" denotes the entry point to the maze, and
  - "2" denotes the exit points.
## 2. Transforming Matrix into a Graph:

- The application transforms the maze matrix into a graph.
- Nodes corresponding to maze walls are excluded from the graph.
## 3. Graph Visualization:

- The graph obtained from the maze matrix is displayed in the main window.

## 4. Breadth-First Search (BFS) Algorithm:

- The application implements the BFS algorithm to traverse the graph.
## 5. Finding Shortest Paths to Exits:

- After traversing the graph, the application determines the shortest paths to all exits.
## 6. Visualizing Paths on Graph:

- The shortest paths to exits are visualized on the graph using a different color.
## 7. Maze Visualization:

- Additionally, the application visualizes the original maze along with the identified paths to exits.
## How to Use:

- Ensure that the maze matrix is correctly formatted in the "inputMatrix.txt" file.
- Run the application to visualize the maze and paths to exits.
