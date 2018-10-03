---
layout: default
title: Reinforcement Learning
permalink: /artificial-intelligence/RL/rl
---

# Reinforcement Learning

## The intuition about RL
<div style="text-align:center">
  <img src ="/cstopics/assets/img/AI/introAI/RL_intro.jpg" style="width:70%"/>
  <span style="font-size:70%">https://www.marutitech.com/businesses-reinforcement-learning/</span>  
</div>

- The agent receives feedback in the for of **rewards**
- Agent's utility is defined by the reward function
- Must (learn to) act so as to **maximize expected rewards**
- All learning is based on observed samples of outcomes!

<div style="text-align:center">
  <img src ="/cstopics/assets/img/AI/introAI/rl_blocks.jpg" style="width:70%"/>
  <span style="font-size:70%">https://www.kdnuggets.com/2018/03/5-things-reinforcement-learning.html</span>  
</div>

### Some examples
<div style="text-align:center">
  <iframe width="600" height="400" src="https://www.youtube.com/embed/e3Jy2vShroE">
  </iframe>
</div>

<div style="text-align:center">
  <iframe width="600" height="400"
  src="https://www.youtube.com/embed/W_gxLKSsSIE">
  </iframe>
</div>

## The basics
Our agent is in an environment that can be characterized by a MDP:
- A set of states <img src="https://latex.codecogs.com/gif.latex?  s \in \mathcal{S} "/>
- A set of actions <img src="https://latex.codecogs.com/gif.latex?  a \in \mathcal{A} "/>
- A transition model <img src="https://latex.codecogs.com/gif.latex?  T(s,a,s\prime) "/>
- A reward function <img src="https://latex.codecogs.com/gif.latex?  R(s,a,s\prime) \in \mathbb{R} "/>

And, we are looking for a policy <img src="https://latex.codecogs.com/gif.latex?  \pi(s) "/>

**BUT**, in many cases, we don't have information about the environment <img src="https://latex.codecogs.com/gif.latex?  T(s,a,s\prime) "/>

**What to do in this case?** if we don't know which states are good or bad or what the actions do, we need to:
- Learn the transition model of the environment, or
- Learn a policy, trying out actions and evaluating how good they were with the reward function

## Offline (solving MDPs) Vs. Online (RL)
### Offline planing
Given the MDP, you plan offline, than means, you find the optimal policy <img src="https://latex.codecogs.com/gif.latex?  \pi^\star"/> taking actions in a simulated environment.

You get the optimal policy through the optimal values of the states, by value iteration or policy iteration. You only interact with the real environment when you already have the optimal policy.

### Online planing
Basically, you learn a policy through trial and error. You only know:
- Which actions are available to you
- Your current state

Then, you choose one of your actions and sees what happens: next state and reward. You improve the current policy based on what you have learnt about the environment: which actions are good or bad for every state.

# Let's start learning!
## Model-based learning
The general idea is to learn and approximate model of the environment <img src="https://latex.codecogs.com/gif.latex?  T(s,a,s\prime) "/> and <img src="https://latex.codecogs.com/gif.latex?  R(s,a,s\prime)"/> based on experience, to do later offline planning based on it.


### Step 1. Learn empirical MDP Model
- Count outcomes <img src="https://latex.codecogs.com/gif.latex? s\prime"/> for earch <img src="https://latex.codecogs.com/gif.latex? s,a"/>
- Normalize to give an estimate of <img src="https://latex.codecogs.com/gif.latex?  \hat{T}(s,a,s\prime) "/>
- Discover each <img src="https://latex.codecogs.com/gif.latex?  \hat{R}(s,a,s\prime)"/> for every <img src="https://latex.codecogs.com/gif.latex?  (s,a,s\prime)"/>

### Step 2. Solve the learned MDP
- Use value iteration or policy iteration to get a good policy

### Example
<div style="text-align:center">
  <img src ="/cstopics/assets/img/AI/introAI/model_based_learning_example.png" style="width:70%"/>
  <span style="font-size:70%">http://ai.berkeley.edu/course_schedule.html</span>  
</div>
