---
layout: default
title: Search
permalink: /artificial-intelligence/search
---

# Search

## Problem-Solving Agents
Based on a goal that must be achieved, the agent formulates a **problem**, in which he has to decide what actions and states should be consider to get the goal.

If the environment is:
- __Observable:__ the agent always knows the current state.
- __Discrete:__ there are only finite many actions to choose from.
- __Known:__ the agent knows which states are reached by each action.
- __Deterministic:__ each action has exactly one outcome.

<font color="orange">Under this features, the solution to any problem is a sequence of actions </font>

The process of looking for a sequence of actions that reaches a goal is called **search**.

<div style="text-align:center">
<font color="blue">Formulate</font> &#8594; <font color="red">Search</font> &#8594; <font color="green">Execute</font>
</div>

Keep in mind that, while the agent is executing the sequence of actions, he ignores his perception of the environment &#8594; **open-loop system**.

### Defining problems
A problem can be defined formally by five components:

- **Initial state:** where the agent starts in his environment
- **Set of actions:** given a particular state _s_,  a set of actions that can be execute in _s_
- **Transition model:** a function that returns the state that results from doing action _a_ in state _s_
- **Goal test:** a function that determines whether a given state is a goal state
- **Step cost:** function that computes the cost of taking action _a_ in state _s_ to reach _s'_

The initial state, actions and transition model defines the **state space**, which is the set of all reachable states from the initial state by any sequence of actions.

<font color="orange"><i>Example</i></font>
Imagine an agent in the city of Arad, Romania. He wants to go to Bucharest, traveling the shortest path as possible.

<div style="text-align:center">
  <img src ="/cstopics/IntroAI/figures/romania.png" />
  <span style="font-size:70%">Russerl, Norvig. Artificial Intelligence, a modern approach. 2010</span>
</div>

- <p><font color="blue"><i>Initial state:</i></font> In(Arad)</p>
- <p><font color="blue"><i>Set of actions:</i></font> Go(Sibiu), Go(Timisoara), ... , Go(Zerind)</p>
- <p><font color="blue"><i>Transition model:</i></font> <i>f </i>(In(Arad), Go(Zerind)) = In(Zerind)</p>
- <p><font color="blue"><i>Goal test:</i></font> In(x)==In(Bucharest)? </p>
- <p><font color="blue"><i>Step cost:</i></font> <i>c</i> (In(Arad), Go(Zerind), In(Zerind)) = 75 </p>


<font color="orange"><i>Exercise</i></font>
The 8-puzzle is a 3x3 board with eight numbered tiles an a blank space. A tile adjacent to the blank space can slide into the space. The objective is to reach a specified a goal state, like this:

<div style="text-align:center">
  <img src ="/cstopics/IntroAI/figures/8puzzle.png" />
  <span style="font-size:70%">Russerl, Norvig. Artificial Intelligence, a modern approach. 2010</span>
</div>

- <p><font color="blue"><i>Initial state:</i></font> </p>
- <p><font color="blue"><i>Set of actions:</i></font> </p>
- <p><font color="blue"><i>Transition model:</i></font> </p>
- <p><font color="blue"><i>Goal test:</i></font> </p>
- <p><font color="blue"><i>Step cost:</i></font>  </p>

#### What about state space sizes?
Consider this PACMAN game:
<div style="text-align:center">
  <img src ="/cstopics/IntroAI/figures/pacman1.png" />
  <span style="font-size:70%">http://ai.berkeley.edu/search.html</span>
</div>

- <p><font color="blue"><i>Set of actions:</i></font> NSEW </p>
- <p><font color="blue"><i>World state:</i></font> </p>
  - Possible agent positions: 120
  - Food count: 30

**State space size for the whole world?**
<a href="https://www.codecogs.com/eqnedit.php?latex=120*(2^{30})*4" target="_blank"><img src="https://latex.codecogs.com/gif.latex?120*(2^{30})*4" title="120*(2^{30})*4" /></a>

**State space size for a pathing problem?**
<a href="https://www.codecogs.com/eqnedit.php?latex=120" target="_blank"><img src="https://latex.codecogs.com/gif.latex?120" title="120" /></a>

**State space size for a eat-all-dots problem**
<a href="https://www.codecogs.com/eqnedit.php?latex=120*(2^{30})" target="_blank"><img src="https://latex.codecogs.com/gif.latex?120*(2^{30})" title="120*(2^{30})" /></a>


### Searching for solutions
<p><font color="blue"><i>What is a solution?:</i></font> a sequence of actions </p>

**Search trees**

They are representations of possible action sequences, with some initial state as its root.
- Branches: are actions
- Nodes: are states in the space state of the problem

<font color="orange"><i>Example: Arad to Bucharest</i></font>
The _root node_ of the search tree corresponds to Arad, because is our initial city or state. But, are we in Bucharest? No, that's why we have to _expand_ the current state, generating a new set of states or _child nodes_.

<div style="text-align:center">
  <img src ="/cstopics/IntroAI/figures/search_tree1.png" />
  <span style="font-size:70%">http://aima.eecs.berkeley.edu/slides-pdf/chapter03.pdf</span>
</div>

The expanding leads to three new child nodes: Sibiu, Timisoara and Zerind. Now we must choose which of these possibilities consider further.

<div style="text-align:center">
  <img src ="/cstopics/IntroAI/figures/search_tree2.png" />
  <span style="font-size:70%">http://aima.eecs.berkeley.edu/slides-pdf/chapter03.pdf</span>
</div>

Suppose we choose Sibiu first. Again, are we in Bucharest? No! Let's expand the parent node:

<div style="text-align:center">
  <img src ="/cstopics/IntroAI/figures/search_tree3.png" />
  <span style="font-size:70%">http://aima.eecs.berkeley.edu/slides-pdf/chapter03.pdf</span>
</div>

To keep seaching, we can choose between Arad, Fagaras, Oradea and Rimnicu Vilcea, or go back to explore Timisoara or Zerind. Note thas these nodes haven't been explore yet, that means they do not have children. They are _leaf nodes_ and conform our _frontier_ or _fringe_.

<font color="blue"><i>What's tricky in this search tree?...</i></font>

The search tree has a repeated state (Arad) an that can cause a _loopy path_. That means that the complete search tree for this problem in infinite.

Consider this state space graph:
<div style="text-align:center">
  <img src ="/cstopics/IntroAI/figures/search_tree4.png" />
  <span style="font-size:70%">https://www.youtube.com/watch?v=bSv4CWMTeR0</span>
</div>

How deep is the search tree?...

<font color="blue"><i>Do we have to worry about loopy paths?...</i></font>

By intuition, no. Because path cost are additive and step cost are nonnegative, a loopy path to any given state is never better that the same path with the loop removed.

In summary:

<div style="text-align:center">
  <img src ="/cstopics/IntroAI/figures/algTreeSearch.png" />
  <span style="font-size:70%">http://aima.eecs.berkeley.edu/slides-pdf/chapter03.pdf</span>
</div>

**Data structures for search trees**

The fringe needs to be store in a way such that the search algorithm can easily choose the next node to expand. Some appropriate data structures are:
- Queue: Python
- Stack:
- Priority queue:
