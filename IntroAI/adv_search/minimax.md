---
layout: default
title: Adversarial Search
permalink: /artificial-intelligence/adv_search/minimax
---

# ADVERSARIAL SEARCH

## Game playing State-of-the-Art

{% include tables/artificial_intelligence/introAI/games.md %}

## Types of games
- <p><font color="red">Deterministic</font> or stochastic</p>
- <p>One, <font color="red">two</font> or more players </p>
- <p><font color="red">Zero-sum</font> or non zero-sum </p>
- <p><font color="red">Perfect</font> or imperfect information </p>

In AI, the most common games are deterministic, turn-taking, two-player, zero-sum games of perfect information.

This means, deterministic, fully observable environments in which two agents act alternately an in which the utility values at the end of the game are always equal and opposite.

<div style="text-align:center">
  <img src ="/cstopics/assets/img/AI/introAI/win_lose.jpg" style="width:20%"/>  
</div>

## Deterministic games
One possible formalization is:
- States (initial state <a href="https://www.codecogs.com/eqnedit.php?latex=s_o" target="_blank"><img src="https://latex.codecogs.com/gif.latex?s_o" title="s_o" /></a>)
- Players:  <a href="https://www.codecogs.com/eqnedit.php?latex=P=\{1 \dots N\}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?P=\{1 \dots N\}" title="P=\{1 \dots N\}" /></a>
- Actions (may depend on player/state)
- Transition function <a href="https://www.codecogs.com/eqnedit.php?latex=S \times A \rightarrow S" target="_blank"><img src="https://latex.codecogs.com/gif.latex?S \times A \rightarrow S" title="S \times A \rightarrow S" /></a>
- Terminal test <a href="https://www.codecogs.com/eqnedit.php?latex=t(s)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?t(s)" title="t(s)" /></a>
- Utility: <a href="https://www.codecogs.com/eqnedit.php?latex=S \times P \rightarrow \mathbb{R}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?S \times P \rightarrow \mathbb{R}" title="S \times P \rightarrow \mathbb{R}" /></a>   final numeric value for a game that ends in terminal state for a player _p_

We are looking for a solution that can map every game state to the best action, taking into account the strategy of the opponent. This solution will be called the **Policy**

## Zero-sum games
- Agents have opposite utilities
- Think it as a single value that one player is trying to maximize and the opponent to minimize.
- Pure competition ----> Adversarial game
<div style="text-align:center">
<img src ="/cstopics/assets/img/AI/introAI/zsg1.jpeg" style="width:20%"/> 	 <img src ="/cstopics/assets/img/AI/introAI/zsg2.jpeg" style="width:20%"/> 	
</div>

## General games
- Agents have independent utilities
- Cooperation, indifference, competition, and more are all possible

## Adversarial Game Trees
**Value of a state V(s):** the best achievable outcome (utility) from that state
<div style="text-align:center">
<img src ="/cstopics/assets/img/AI/introAI/triqui.png" style="width:80%"/>
<span style="font-size:70%">http://aima.eecs.berkeley.edu/slides-pdf/chapter06.pdf</span>
</div>

## Adversarial Search (Minimax)
- A state-space search trees
- Two players alternating turns
- One player wants to maximize its result (utility)
- The other player wants to minimize that result
- **Strategy:** compute each node’s <font color="red">minimax value</font>: the best achievable utility against a rational (optimal) adversary

The minimax value of a node is the utility of being in the corresponding state, _assuming that both players play optimally_ from there to the end of the game.

<div style="text-align:center">
<img src ="/cstopics/assets/img/AI/introAI/minimax2.png" style="width:40%"/>
<span style="font-size:70%">http://ai.berkeley.edu</span>
</div>
### Exercise: what policy does Pacman should follow?
<div style="text-align:center">
<img src ="/cstopics/assets/img/AI/introAI/minimax1.png" style="width:100%"/>
<span style="font-size:70%">http://ai.berkeley.edu</span>
</div>

### The algorithm
``` sh
def value(state):
	if the state is a terminal state: return the state’s utility
	if the next agent is MAX: return max_value(state)
	if the next agent is MIN: return min_value(state)
```

``` sh
def max_value(state):
	initialize v=-inf
        for each successor of state:
          v = max(v, value(successor))
        return v
```

``` sh
def min_value(state):
	initialize v=+inf
        for each successor of state:
          v = min(v, value(successor))
        return v
```

<div style="text-align:center">
<img src ="/cstopics/assets/img/AI/introAI/minimax3.png" style="width:100%"/>
<span style="font-size:70%">http://ai.berkeley.edu</span>
</div>
<div style="text-align:center">
<img src ="/cstopics/assets/img/AI/introAI/minimax4.png" style="width:100%"/>
<span style="font-size:70%">http://ai.berkeley.edu</span>
</div>

### Minimax Efficiency
Minimax is just like exhaustive DFS, with a time complexity of O(b^m)

BUT, for real and interesting games, building the whole search tree is completely infeasible.

For example, chess has an average branching factor of about 35 and games often go to 50 moves by each player, so the search tree has about 35^100 nodes!!


## Resource limits
**Problem:** in real games, we cannot build the entire search tree to get the values of the leaves (terminal states)

**Solution:** Depth-limited search
- Search only to a limited depth in the tree
- Replace terminal utilities with an <font color="blue">evaluation function</font> for non-terminal positions

**However:** Guarantee of optimal play is gone because evaluation functions are always imperfect

### Evaluation functions
In practice, an evaluation function is the weighted linear sum of features that we know can have some effect in the game. This function can return real numbers.

<a href="https://www.codecogs.com/eqnedit.php?latex=Eval(s)=w_1 f_1(s)+w_2 f_2(s) + \dots + w_n f_n(s)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?Eval(s)=w_1 f_1(s)+w_2 f_2(s) + \dots + w_n f_n(s)" title="Eval(s)=w_1 f_1(s)+w_2 f_2(s) + \dots + w_n f_n(s)" /></a>

<div style="text-align:center">
<img src ="/cstopics/assets/img/AI/introAI/eval_fun.png" style="width:100%"/>
<span style="font-size:70%">http://ai.berkeley.edu</span>
</div>

## Game tree pruning: Alpha-Beta pruning
**Idea:** obtain the same move that minimax would, but pruning away branches that cannot possibly influence the final decision.

Consider a node _n_ somewhere in the tree, such that MAX has a choice of moving to that node. If MAX has a better choice _a_ along the current path from the root, then _n will never be reached in actual play_, so we can stop considering _n's_ children.

<div style="text-align:center">
<img src ="/cstopics/assets/img/AI/introAI/ab.png" style="width:30%"/>
<span style="font-size:70%">http://ai.berkeley.edu</span>
</div>

### The algorithm

<div style="text-align:center">
<img src ="/cstopics/assets/img/AI/introAI/alpha_beta_alg.jpeg" style="width:100%"/>
<span style="font-size:70%">http://ai.berkeley.edu</span>
</div>

Example Alpha-Beta pruning [here](/cstopics/assets/code/introAI/alpha_beta_example.pdf)

Animation of Alpha-Beta pruning [here](http://inst.eecs.berkeley.edu/~cs61b/fa14/ta-materials/apps/ab_tree_practice/)
