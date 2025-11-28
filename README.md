# rrt
Implementation of the Rapidly-exploring Random Tree algorithm in C++.

## Overview
RRT is a generally effective algorithm for pathfinding from a start point to a goal point. It is commonly used to guide robots by discovering a viable path through an unknown configuration space.

The main algorithm has a time complexity of --- and a space complexity of ---. This is because 

## Instructions to Run
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

## Demonstration of the Project Running

## Development Decisions
This implementation was developed around a graph data structure. It uses a simplified graph, because not all of the functionality of a fully implemented graph is necessary here. Nodes must be added, store coordinate information, and have access to their predecessors. 

This program was heavily structured around the pseudocode for RRT found [here](https://en.wikipedia.org/wiki/Rapidly_exploring_random_tree) and using this [project description](https://www.youtube.com/watch?v=OXikozpLFGo) as reference.

A big conceptual shift happened late in the project. I had originally belived that I would need an "array space" to serve as the configuration space in which the tree would be searching. There were a lot of issues with that, especially if the user were allowed to configure the size of the space. It wasn't until later that I realized that the goal could be anywhere. Much the same way a graph of tree has a visualization only if you make one, the configuration space didn't actually need to have a structured existence. The coordinates bounding the generation of the search points simply needed to include the goal set by the user. This allowed the removal of a lot of 2d array definition and passing around the program and simplified things nicely.

This algorithm should normally be able to handle navigating around obstacles. Given what I have so far, I believe I have an idea of how I would implement this functionality. Obstacles would be stored as a list of boundary coordinates. When a random point is generated, a check would occur to see if the point was within an obstacle space: `(qNewX < boundMinX || qNewX > boundMaxX || qNewY < boundMinY || qNewY > boundMaxY)` [source](https://stackoverflow.com/questions/217578/how-can-i-determine-whether-a-2d-point-is-within-a-polygon). If it is, the boundary of the obstacle should be iterated and the point moved to the nearest edge of the obstacle. This would function similarly to the method that searches the tree for the nearest point to the randomly chosen point.

