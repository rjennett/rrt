# rrt
Implementation of the Rapidly-exploring Random Tree algorithm in C++.

### Overview
RRT is a generally effective algorithm for pathfinding from a start point to a goal point. It is commonly used to guide robots by discovering a viable path through an unknown configuration space.

The main algorithm has a time complexity of --- and a space complexity of ---. This is because 

### Instructions to Run
This project was developed and tested in the JupyterHub environment. It should be possible to compile and run the project in JupyterHub by cloning this repo.

Once cloned, open the project directory in VSCode. Use the integrated runner/debugger to either run the tests with Run Tests or run the app in the CLI using Run App.

The user will be prompted to enter six values:
- startX: Value for the root of the tree to begin at (X)
- startY: Value for the root of the tree to begin at (Y)
- goalX: Value for the graph to pursue discovering (X)
- goalY: Value for the graph to pursue discovering (Y)
- max nodes: The max number of nodes for the tree to create while searching
- step distance: The linear distance for each new node to move away from an existing node

The app will return a failure message if the tree does not encounter the goal coordinate within the provided number of node extensions.

The app will print out the coordinates of the nodes that lead to the goal if the goal was found.

### Demonstration of the Project Running

### Development Decisions
This implementation was developed around a graph data structure. It uses a simplified graph, because not all of the functionality of a fully implemented graph is necessary here. Nodes must be added, store coordinate information, and have access to their predecessors. 