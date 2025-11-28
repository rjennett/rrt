# rrt
Implementation of the Rapidly-exploring Random Tree algorithm in C++.

### Overview
RRT is a generally effective algorithm for pathfinding from a start point to a goal point. It is commonly used to guide robots by discovering a viable path through an unknown configuration space.

The main algorithm has a time complexity of --- and a space complexity of ---. This is because 

### Instructions to Run

### Demonstration of the Project Running

### Development Decisions
This implementation was developed around a graph data structure. It uses a simplified graph, because not all of the functionality of a fully implemented graph is necessary here. Nodes must be added, store coordinate information, and have access to their predecessors. 