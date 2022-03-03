Iterative BFS using Topological Sort / Kahn's Algorithm plus keeping a visited to check and add to number of courses completed
if numCourses == completed course return true else return false ;
https://www.geeksforgeeks.org/detect-cycle-in-a-directed-graph-using-bfs/?ref=rp
Method 2 Using in and out degree
https://www.geeksforgeeks.org/detect-cycle-in-the-graph-using-degrees-of-nodes-of-graph/?ref=rp
​
Method 3 : I have implented using 2 vectors for path and visited / pathVisited and backtrack when the current path does not have a cycle and return false
in case of a cycle the recursive call
```dfsCycle(it , visited , pathVisited , graph)```
will evaluate to true thus sending true up the chain of recursive functions
​
Method 4:
​
https://www.geeksforgeeks.org/detect-cycle-in-directed-graph-using-topological-sort/?ref=rp
This is the standard TopoSort approach