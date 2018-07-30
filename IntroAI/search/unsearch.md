---
layout: default
title: Search
permalink: /artificial-intelligence/search/unsearch
---

# Uninformed Search Strategies

## Depth First Search (DFS)
**Strategy:** expand the deepest node first in the current fringe of the search tree.

**Implementation:** fringe is a LIFO stack

Review this [Python notebook](https://github.com/cstopics/cstopics/blob/gh-pages/assets/notebooks/introAI/search_methods.ipynb) to check an example of DFS

<font color="orange"><i>Exercise</i></font>
Find the path from state S to G in the following space-state graph.
<div style="text-align:center">
  <img src ="/cstopics/assets/img/AI/introAI/exDFS.png" style="width:80%"/>  
</div>

### Problem-solving performance
- **Completeness:** is the algorithm guarantee to find a solution if one exists?

  Yes, under some assumptions: if the graph does not present cycles or redundant paths.
  - DFS is complete if implemented with the _graph-search_ version
  - DFS is not complete if _tree-search_ version is used

- **Optimality:** does the strategy find the optimal path (the least cost path)?

  No, just the left most path.

- **Time complexity:** how long does it take to find a solution?

  In the worst case, where the solution is at the end of the tree in the right side:

  <div style="text-align:center">
    <img src ="/cstopics/assets/img/AI/introAI/complexityDFS.png" style="width:70%"/>  
  </div>

  _Number of nodes in the entire tree?_

  <a href="https://www.codecogs.com/eqnedit.php?latex=120*(2^{30})*4" target="_blank"><img src="https://latex.codecogs.com/gif.latex?1+b+b^2+ \ldots +b^m \approx O(b^m) \rightarrow" title="1+b+b^2+ \ldots +b^m \approx O(b^m)" /></a> Very large!

- **Space complexity:** how much memory is needed to perform the search?

  If all fringe has _b_ leafs and the tree has _m_ levels, DFS requieres storage of only
  <a href="https://www.codecogs.com/eqnedit.php?latex=120*(2^{30})*4" target="_blank"><img src="https://latex.codecogs.com/gif.latex?O(bm)" title="O(bm)" /></a> nodes.


## Breadth First Search (BFS)
  **Strategy:** expand the shallowest node first in the current fringe of the search tree.

  **Implementation:** fringe is a FIFO queue

  Review this [Python notebook](https://github.com/cstopics/cstopics/blob/gh-pages/assets/notebooks/introAI/search_methods.ipynb) to check an example of BFS

### Problem-solving performance
  - **Completeness:** yes, if the goal node is at some finite depth.
  - **Optimality** no necessarily, only if the cost for all actions is the same
  - **Time complexity:**

  <div style="text-align:center">
    <img src ="/cstopics/assets/img/AI/introAI/complexityBFS.png" style="width:50%"/>  
  </div>

  BFS processes all nodes above shallowest solution.

  If _s_ is the depth of the shallowest solution, it has to explore
  <a href="https://www.codecogs.com/eqnedit.php?latex=120*(2^{30})*4" target="_blank"><img src="https://latex.codecogs.com/gif.latex?O(b^m)" title="O(b^m)" /></a> nodes.

  - **Space complexity:** the fringe needs to save information, in the worst case, of
    <a href="https://www.codecogs.com/eqnedit.php?latex=O(b^s)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?O(b^s)" title="O(b^s)" /></a> nodes.

## Uniform cost search
  **Strategy:** expand the cheapest node first in the current fringe of the search tree.

  **Implementation:** fringe is a priority queue in terms of cumulative cost

  Review this [Python notebook](https://github.com/cstopics/cstopics/blob/gh-pages/assets/notebooks/introAI/search_methods.ipynb) to check an example of uniform cost search

### Problem-solving performance
  - **Completeness:** yes, if all arc cost are positive and the best solution has a finite cost
  - **Optimality:** yes!
  - **Time complexity:**

  <div style="text-align:center">
    <img src ="/cstopics/assets/img/AI/introAI/complexityUC.png" style="width:35%"/>  
  </div>

  If cheapest solution has a cost
  <a href="https://www.codecogs.com/eqnedit.php?latex=C^*" target="_blank"><img src="https://latex.codecogs.com/gif.latex?C^*" title="C^*" /></a>, then it processes all nodes with <a href="https://www.codecogs.com/eqnedit.php?latex=c<C^*" target="_blank"><img src="https://latex.codecogs.com/gif.latex?c<C^*" title="c<C^*" /></a>

  If the minimum arc cost is <a href="https://www.codecogs.com/eqnedit.php?latex=\epsilon" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\epsilon" title="\epsilon" /></a>, then the "effective depth" is roughly <a href="https://www.codecogs.com/eqnedit.php?latex=C^*/\epsilon" target="_blank"><img src="https://latex.codecogs.com/gif.latex?C^*/\epsilon" title="C^*/\epsilon" /></a>

  Takes in the worst case <a href="https://www.codecogs.com/eqnedit.php?latex=O(b^{C^*/\epsilon})" target="_blank"><img src="https://latex.codecogs.com/gif.latex?O(b^{C^*/\epsilon})" title="O(b^{C^*/\epsilon})" /></a>


<p><font color="blue">The good: </font> UCS is optimal and complete</p>

<p><font color="blue">The bad: </font> explores options in every direction. Does not have any information about the goal.</p>

<div style="text-align:center">
<video width="478" height="505" controls>
  <source src="/cstopics/assets/videos/introAI/ucs_allcostequal.mp4" type="video/mp4">
</video>
</div>

## Guess the search algorithm ...

<div style="text-align:center">
<video width="486" height="508" controls>
  <source src="/cstopics/assets/videos/introAI/unsearch.mp4" type="video/mp4">
</video>
</div>
