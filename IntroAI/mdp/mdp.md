---
layout: default
title: Markov Decision Processes
permalink: /artificial-intelligence/mdp/mdp
---

Now, we are interested in **non-deterministic search:** with some probability, the actions are not executed.

## Example:
We have the following grid-world, where our agent has to reach one of the goal states:

<div style="text-align:center">
  <img src ="/cstopics/assets/img/AI/introAI/grid1.png" style="width:40%"/>  
</div>
But our actions do not always go as planned:
- 80% of the time, the action North takes the agent North (if there is no wall there)
- 10% of the time, North takes the agent West; 10% East
- If there is a wall in the direction the agent would have been taken, the agent stays put

Our agent receives rewards each time step:
- Small rewards each step (can be negative) or
- Big rewards that come at the end(good or bad)

<center><font color="red">We want to maximize sum of rewards</font></center>

In a deterministic environment:
<div style="text-align:center">
  <img src ="/cstopics/assets/img/AI/introAI/det_sol.png" style="width:40%"/>  
</div>

However, in a non-deterministic environment some randomness comes to play. That can be represented as a chance node in expectimax trees:
<div style="text-align:center">
  <img src ="/cstopics/assets/img/AI/introAI/nondet_sol.png" style="width:60%"/>  
</div>

We can formalize the problem as a MDP.

# MARKOV DECISION PROCESSES
A MDP is defined by:
- A set of states <img src="https://latex.codecogs.com/gif.latex?  s \in \mathcal{S} "/>
- A set of actions <img src="https://latex.codecogs.com/gif.latex?  a \in \mathcal{A} "/>
- A transition function of terms of the probability that _a_ from _s_ leads to _s'_  <img src="https://latex.codecogs.com/gif.latex?  P(s\prime | s,a) "/>
- A reward function <img src="https://latex.codecogs.com/gif.latex?  R(s) \in \mathbb{R} "/>
- A start state
- A terminal state (not necessarily)

A process is Markovian if, in order to know the probability to reach the next state _s'_, is enough with the present state _s_ and it is not necessarily the history of earlier ones.

<img class="eq" src="https://latex.codecogs.com/gif.latex?  P(S_{t+1} = s\prime | S_t = s_t, A_t=a_t, S_{t-1} = s_{t-1}, A_{t-1}=a_{t-1}, \dots, S_0=s_0) "/>

<img class="eq" src="https://latex.codecogs.com/gif.latex?  = P(S_{t+1} = s\prime | S_t = s_t, A_t=a_t) "/>

# MDP Solution: a policy
We are looking for an **optimal policy** <img src="https://latex.codecogs.com/gif.latex?  \pi^{*}: \mathcal{S} \rightarrow \mathcal{A} "/>.

- A policy <img src="https://latex.codecogs.com/gif.latex?  \pi "/> gives an action for each state

- An optimal policy <img src="https://latex.codecogs.com/gif.latex?  \pi^{*} "/>  gives, for each state,  the action that maximizes the expected utility if followed.

Notice that: expectimax didn’t compute entire policies. It computed the action for a single state only.

<div style="text-align:center">
  <img src ="/cstopics/assets/img/AI/introAI/optimal_policies.png" style="width:60%"/>  
</div>

1. It looks for long and safe paths, due to the obtained cumulative reward is much lower than the positive goal state. _What about the cell between the wall and the negative goal state?_ Because step cost is low, it prefers to keep jumping to the wall until, the non-deterministic feature of the environment, take him to the west/east state.

2. It keeps looking for long and safe paths. _What about the cell between the wall and the negative goal state?_ in this case, it is not good idea to jump to the wall, because the cumulative reward can increase quicker. Therefore, the action that maximizes the expected utility  is go to North.

3. It is looking for the shortest paths in the grid.

4. Because the penalty is to high, the agent prefers to go quickly to the worst goal state.

## MDP search trees
Each MDP state projects an expectimax-like search tree:
<div style="text-align:center">
  <img src ="/cstopics/assets/img/AI/introAI/mdp_tree.png" style="width:70%"/>  
</div>
