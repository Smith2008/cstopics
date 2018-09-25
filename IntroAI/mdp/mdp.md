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

## MDP Solution: a policy
We are looking for an **optimal policy** <img src="https://latex.codecogs.com/gif.latex?  \pi^{*}: \mathcal{S} \rightarrow \mathcal{A} "/>.

- A policy <img src="https://latex.codecogs.com/gif.latex?  \pi "/> gives an action for each state

- An optimal policy <img src="https://latex.codecogs.com/gif.latex?  \pi^{*} "/>  gives, for each state,  the action that maximizes the expected utility if followed.

Notice that: expectimax didn’t computes entire policies. It computed the action for a single state only.

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

Rewards are associated to the tuple _(s,a,s')_

# Utilities of Sequences
Preference of an agent over sequence of rewards
- [1,2,2] or [2,3,4] -> The agent wants to maximize its rewards
- [0,0,1] or [1,0,0] -> The agent would prefer to have information sooner than later (but this is not a rule)

## Discounting
- It’s reasonable to maximize the sum of rewards
- It’s also reasonable to prefer rewards now to rewards later
- One solution: values of rewards decay exponentially

<div style="text-align:center">
  <img src ="/cstopics/assets/img/AI/introAI/discounting.png" style="width:70%"/>  
</div>

Where: <img src="https://latex.codecogs.com/gif.latex?  \gamma \in (0,1) "/>

Higher the exponential (usually in terms of _t_), less worth is the reward

Each time we descend a level, we multiply in the discount once:
<div style="text-align:center">
  <img src ="/cstopics/assets/img/AI/introAI/discounting2.png" style="width:60%"/>  
</div>

_Why discount?:_ sooner rewards probably do have higher utility than later rewards. Also helps our algorithms converge.

### Example:
You have the reward's sequence [1,2,3], and your discounting rate is 0.5. What is your utility in _t=3_?

<img src="https://latex.codecogs.com/gif.latex?  U([1,2,3]) = (1*1)+(0.5*2)+(0.5^2*3)=2.75 "/>

### Exercises:

| 10 	|   	|   	|   	| 1 	|
|----	|:-:	|---	|--:	|---	|
| a  	| b 	| c 	| d 	| e 	|

- Actions: East, West, and Exit (only available in exit states a, e)
- Transitions: deterministic
- Rewards 0 for _(b,c,d)_, 10 for _a_ and 1 for _e_

**1. For <img src="https://latex.codecogs.com/gif.latex?  \gamma=1.0 "/>, what is the optimal policy?**

Answer: west in any state non-terminal states

**2. For <img src="https://latex.codecogs.com/gif.latex?  \gamma=0.1 "/>, what is the optimal policy?**


| From 	|                                           To a                                           	| To e                                                                                     	|
|------	|:----------------------------------------------------------------------------------------:	|------------------------------------------------------------------------------------------	|
| b    	|             <img src="https://latex.codecogs.com/gif.latex?  0+(0.1*10)=1 "/>            	| <img src="https://latex.codecogs.com/gif.latex?  0+(0.1*0)+(0.1^2*0)+(0.1^3*1)=0.001 "/> 	|
| c    	| <img src="https://latex.codecogs.com/gif.latex?  0+(0.1*0)+(0.1^2*10)=0.1 "/>            	| <img src="https://latex.codecogs.com/gif.latex?  0+(0.1*0)+(0.1^2*1)=0.01 "/>            	|
| d    	| <img src="https://latex.codecogs.com/gif.latex?  0+(0.1*0)+(0.1^2*0)+(0.1^3*10)=0.01 "/> 	| <img src="https://latex.codecogs.com/gif.latex?  0+(0.1*1)+=0.1 "/>                      	|

**3. For which <img src="https://latex.codecogs.com/gif.latex?  \gamma"/> are West and East equally good when the agent is in state d?**

<img src="https://latex.codecogs.com/gif.latex?  10\gamma^3 = \gamma"/>

<img src="https://latex.codecogs.com/gif.latex?  \gamma = \frac{1}{\sqrt{10}}"/>

## What if the game lasts forever?  Do we get infinite rewards?
No, because:
- We force a finite horizon: terminate episodes after a fixed T steps.
- We use discounting rewards:
<img class="eq" src="https://latex.codecogs.com/gif.latex?  U([r_0, \dots, r_\infty])=\sum_{t=0}^{\infty}\gamma^t r_t \leq R_{max}/(1-\gamma)"/>

# Solving MDPs
- **The value (utility) of a state s:** <img src="https://latex.codecogs.com/gif.latex?  V^{*}(s)"/> expected utility starting in _s_ and acting optimally.

- **The value (utility) of a q-state (s,a):** <img src="https://latex.codecogs.com/gif.latex?  Q^{*}(s,a)"/> expected utility starting out having taken action _a_ from state _s_ and (thereafter) acting optimally-

- **The optimal policy:** <img src="https://latex.codecogs.com/gif.latex?  \pi^{*}(s)"/> optimal action from state _s_.

## The Bellman Equations
How to be optimal:
- Step 1: take correct first action
- Step 2: keep being optimal

Bellman equations can be derived via expectimax recurrence:
<div style="text-align:center">
  <img src ="/cstopics/assets/img/AI/introAI/val_iter.png" style="width:70%"/>  
</div>

To solve de MDP, is necessarily to know the optimal utility values for each state <img src="https://latex.codecogs.com/gif.latex?  V^{*}(s)"/>. To do so, there are two methods:
- Value iteration
- Policy iteration

## Value iteration algorithm
Method to solve systems of non-linear equations, though Bellman update rule:
<img class="eq" src="https://latex.codecogs.com/gif.latex?  V_{k+1}(s) \leftarrow R(s) + \gamma \max_{a \in \mathcal{A}(s)} \sum_{s\prime}P(s\prime|s,a)V_{k}(s\prime)"/>

<div style="text-align:center">
  <img src ="/cstopics/assets/img/AI/introAI/val_iter_alg.png" style="width:70%"/>
  <span style="font-size:70%">http://aima.eecs.berkeley.edu/algorithms.pdf</span>  
</div>
