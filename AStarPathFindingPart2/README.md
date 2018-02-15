## Learning outcomes
At the end of this lab you should be able to:
-Using the SFML library, draw your graph structure to approximate scale by using circles for nodes. For the
above graph, consider the distances as pixel values. This is important as later the A* heuristic will use the
Euclidean distance between nodes. You may wish to add additional information to the nodes text file such
that each node contains the screen coordinates of where it should be drawn, e.g.: 

### where:
-Inside each circle, show the name of each city, along with the current path cost i.e. g(n) (initially, this will
be unknown). 
-Draw edges between nodes to show the relevant connections. Assume the graph is undirected, so a single
edge is bi-directional. You may wish to use a similar approach for drawing the edges as for the nodes, i.e.
store the screen coordinates in the arcs text file: 
-The weight (path cost) should be illustrated above each edge. 
-Allow the user select an origin node and a destination node. Use colouring or shading to highlight the
selection 
- it should not be possible to select more than two nodes and the origin and destination must be
different. 
- Once the origin and destination nodes are selected, compute the heuristic h(n) value for each node in the
graph as the Euclidean distance from the centre of a node’s circle to the centre of the destination node’s
circle. Display the h(n) value below the g(n) value at each node. 
- Provide a start button and a reset button. The start button will initiate the search, and show what nodes are
expanded by A* between the origin and destination (again highlight the relevant nodes using colour). As
each node is expanded, show the updated g(n) values. Once the destination is found, set each node/circle to
a specific colour along the optimal search path (if the destination is not reachable, do nothing). 
-The reset button will reset the graph state so the user can select new origin and destination nodes. 