---
layout: default
title: Search
permalink: /artificial-intelligence/search/insearch
---

# Informed Search Strategies

Strategies that uses problem-specific knowledge in order to find solutions more efficiently.

Problem-specific knowledge is represented as a **heuristic function**, which estimates how close a state is to a goal.

For a shortest path problem, a good heuristic could be: Euclidean distance and/or Manhattan distance.

<div style="text-align:center">
  <img src ="/cstopics/assets/img/AI/introAI/heuristic_ex.jpg" style="width:50%"/>  
  <span style="font-size:70%">http://apprize.info/game/algorithms/10.html</span>
</div>

## Greedy best-first search

**Strategy:** expand the node that seems closest...

**Implementation:** fringe is a priority queue in terms of estimated cost o heuristic function

<div style="text-align:center">
  <img src ="/cstopics/assets/img/AI/introAI/greedy_good_heuristic.png" style="width:40%"/>  
  <span style="font-size:70%">http://ai.berkeley.edu/search.html</span>  
</div>

Remember our agent in the city of Arad, Romania. He wanted to go to Bucharest, traveling the shortest path as possible.

<div style="text-align:center">
  <img src ="/cstopics/assets/img/AI/introAI/insearch_map.png" style="width:80%"/>  
  <span style="font-size:70%"> Russerl, Norvig. Artificial Intelligence, a modern approach. 2010</span>  
</div>

Review this [Python notebook](https://github.com/cstopics/cstopics/blob/gh-pages/assets/notebooks/introAI/insearch.ipynb) to check an example of Greedy best-first search

But, .... what can go wrong?

If someone designs a bad heuristic, this can happen:

<div style="text-align:center">
  <img src ="/cstopics/assets/img/AI/introAI/greedy_bad_heuristic.png" style="width:40%"/>  
  <span style="font-size:70%">http://ai.berkeley.edu/search.html</span>  
</div>

## A* search

**Strategy:** combining UCS and Greedy search.

**Implementation:** fringe is a priority queue in terms of the sum of real and estimated costs:
<div style="text-align:center">
<a href="https://www.codecogs.com/eqnedit.php?latex=f(n)=g(n)+h(n)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?f(n)=g(n)+h(n)" title="f(n)=g(n)+h(n)" /></a>
</div>

### When should A*  terminate?
<div style="text-align:center">
  <img src ="/cstopics/assets/img/AI/introAI/aStar_terminate.png" style="width:70%"/>    
</div>

Only when we dequeue a goal

Review this [Python notebook](https://github.com/cstopics/cstopics/blob/gh-pages/assets/notebooks/introAI/insearch.ipynb) to check an example of A* search

### Is A* optimal?

<div style="text-align:center">
  <img src ="/cstopics/assets/img/AI/introAI/aStar_optimal.png" style="width:70%"/>    
</div>

What went wrong?

The heuristic was **not optimistic**, and that's why actual bad goal cost was less than the estimated good goal cost.

<p><font color="blue">We need: </font> actual cost > estimates</p>

#### Admissible heuristics

Admissible (optimistic) heuristics slow down bad plans but never outweigh true costs.

A heuristic _h_ is admissible if:
<div style="text-align:center">
<a href="https://www.codecogs.com/eqnedit.php?latex=0 \leq h(n) \leq h^{*}(n)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?0 \leq h(n) \leq h^{*}(n)" title="0 \leq h(n) \leq h^{*}(n)" /></a>
</div>

Where <a href="https://www.codecogs.com/eqnedit.php?latex=h^{*}(n)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?h^{*}(n)" title="h^{*}(n)" /></a> is the true cost to a nearest goal.

<font color="blue">Proof of optimality of A*: </font>
- A is an optimal goal and B is a suboptimal goal
- h() is admissible
- _B_ in on the fringe
- Some ancestor _n_ of _A_ is on the fringe
- **Hint:** _n_ will be expanded before _B_

<div style="text-align:center">
  <img src ="/cstopics/assets/img/AI/introAI/aStar_proof.png" style="width:40%"/>  
  <span style="font-size:70%">http://ai.berkeley.edu/search.html</span>  
</div>

1. f(n) = g(n) + h(n)

   The admissibility of h(n) ensures f(n)<=g(A)

   If h(A)=0, then g(A)=f(A)


2.  If B is suboptimal, then g(A) < g(B)

    If h() at goal = 0, then f(A) < f(B)

3. Therefore, <a href="https://www.codecogs.com/eqnedit.php?latex=f(n) \leq f(A) < f(B)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?f(n) \leq f(A) < f(B)" title="f(n) \leq f(A) < f(B)" /></a>

<div style="text-align:center">
<font color="blue"> A expands before B </font>
</div>

## Guess the search algorithm ...

<div style="text-align:center">
<video width="479" height="509" controls>
  <source src="/cstopics/assets/videos/introAI/insearch.mp4" type="video/mp4">
</video>
</div>
