---
layout: default
title: Adversarial Search
permalink: /artificial-intelligence/adv_search/expectimax
---

# EXPECTIMAX AND UTILITIES
MINIMAX algorithm search for a policy in the worst-case of the game. _What if we are playing against an imperfect opponent?_

<div style="text-align:center">
  <img src ="/cstopics/assets/img/AI/introAI/expectimax2.png" style="width:80%"/>  
</div>

### Why wouldn’t we know what the result of an action will be?
- Explicit randomness
- The opponent responds randomly
- Actions can fail

**Values should now reflect average-case (expectimax) outcomes, not worst-case (minimax) outcomes**

## Expectimax Search
Idea: compute average score under optimal play
- Max nodes behaves as in minimax search
- Chance nodes are like MIN nodes but the outcome is uncertain
- To find expected utilities: <a href="https://www.codecogs.com/eqnedit.php?latex==p_1 v_1()+p_2 v_2() + \dots + p_n v_n(s)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?=p_1 v_1()+p_2 v_2() + \dots + p_n v_n(s)" title="=p_1 v_1()+p_2 v_2() + \dots + p_n v_n(s)" /></a>

<div style="text-align:center">
  <img src ="/cstopics/assets/img/AI/introAI/expectimax3.png" style="width:80%"/>  
</div>

## Expectimax Pseudocode
``` sh
def value(state):
	if the state is a terminal state: return the state’s utility
	if the next agent is MAX: return max_value(state)
	if the next agent is EXP: return exp_value(state)
```

``` sh
def max_value(state):
	initialize v=-inf
        for each successor of state:
          v = max(v, value(successor))
        return v
```

``` sh
def exp_value(state):
	initialize v=0
        for each successor of state:
          p = probability(successor)
          v += p*value(successor)
        return v
```
### Exercise:
<div style="text-align:center">
  <img src ="/cstopics/assets/img/AI/introAI/expectimax4.png" style="width:80%"/>  
</div>

### Question 1: can we do pruning with Expectimax?
<div style="text-align:center">
  <img src ="/cstopics/assets/img/AI/introAI/expectimax5.png" style="width:50%"/>  
</div>
No, unless we have idea about bounds of the values/utilities of the bottom nodes

## Expectations
- A **random variable** represents an event whose outcome is unknown
- A **probability distribution** is an assignment of weights to outcomes
- The **expected value** of a function of a random variable is the average, weighted by the probability distribution over outcomes


### Exercise: How long to get to the university?

|-------------	|:-----:	|-------	|------:	|
| Time        	| 20min 	| 30min 	| 60min 	|
| Probability 	|  0.25 	|  0.5  	|  0.25 	|


### What Probabilities to Use?
We need a probabilistic model of how the opponent will behave in any state:
- Could be a simple uniform distribution
- Could be sophisticated and require a great deal of computation

_For now, assume each chance node magically comes along with probabilities that specify the distribution over its outcomes_

### Exercise
Let’s say you know that your opponent is actually running a depth 2 minimax, using the result 80% of the time, and moving randomly otherwise. What tree search should you use?  

<div style="text-align:center">
  <img src ="/cstopics/assets/img/AI/introAI/expectimax6.png" style="width:50%"/>  
</div>
