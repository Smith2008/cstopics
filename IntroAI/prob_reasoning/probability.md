---
layout: default
title: Probability
permalink: /artificial-intelligence/prob_reasoning/probability
---

# Probabilistic Reasoning
- **Diagnosis:** physician measuring all kind of symptoms in a patient. Infer posterior distribution over the possible diseases causing those symptoms.
- **Speech recognition:** from noise signal, infer the word that was pronounce
- **Tracking objects:** infer orientation an position of a rocket with some measurements.

## Uncertainty
### General situation
- **Observed variables (evidence):** the agent knows certain things about the state of the world.
- **Unobserved variables:** the agent needs to reason about other aspects.
- **Model:** the agent can build a model that relates his knowledge about the known variables with the unknown ones.

### Probabilistic reasoning gives us a framework for managing our beliefs and knowledge

## Random Variables
A random variable is some aspect of the world about which we have uncertainty. We denote random variables with capital letters:
- R = is it raining?
- T = is it hot or cold?
- W = how is the weather?
- D = how long will it take to drive to work?
- L = where is the ghost?

As in CSP, random variables have domains:
- R ∈ {true, false} or {+r, -r}
- T ∈ {hot, cold}
- W ∈ {sun, rain, fog, meteor}
- D ∈ [0, ∞)
- L ∈ {(0,0), (0,1), ...}

## Probability Distributions
Associate a probability to each value of the domain for an unobserved random variable.

Here, a distribution is a table of probabilities of values in a domain:

| P(T) 	|  	|  	| P(W) 	|  	|
|------	|-----	|---	|--------	|-----	|
| T 	| P 	|  	| W 	| P 	|
| hot 	| 0.5 	|  	| sun 	| 0.6 	|
| cold 	| 0.5 	|  	| rain 	| 0.1 	|
|  	|  	|  	| fog 	| 0.3 	|
|  	|  	|  	| meteor 	| 0.0 	|

For every distribution, we must have: <img src="https://latex.codecogs.com/gif.latex?  \forall x P(X=x)\geq 0"/> and <img src="https://latex.codecogs.com/gif.latex?  \sum_x P(X=x)=1"/>

## Joint Distributions
Infer something about unobserved variables based on measurements of observed variables.

A joint distribution involves more than one random variable.
<img src="https://latex.codecogs.com/gif.latex?  P(X_1=x_1, X_2=x_2, \dots, X_n=x_n)"/>

| P(T,W) 	|  	|  	|
|--------	|------	|-----	|
| T 	| W 	| P 	|
| hot 	| sun 	| 0.4 	|
| hot 	| rain 	| 0.1 	|
| cold 	| sun 	| 0.2 	|
| cold 	| rain 	| 0.3 	|

Must obey:
- <img src="https://latex.codecogs.com/gif.latex?  P(x_1, x_2, \dots, x_n)\geq 0"/>
- <img src="https://latex.codecogs.com/gif.latex?  \sum_{(x_1,x_2,\dots,x_n)}P(x_1, x_2, \dots, x_n)=1"/>

## Probabilistic Model
A probabilistic model is a joint distribution over a set of random variable. It has:
- Random variable with domains
- Assignments are called _outcomes_
- Joint distribution say whether assignments are likely
- Normalized: sum to 1.0

## Events
An event is a set E of outcomes. For example, the set of outcomes where x1=True.
<img src="https://latex.codecogs.com/gif.latex?  P(E)=\sum_{(x_1, x_2, \dots, x_n)\in E}P(x_1, x_2, \dots, x_n)"/>

From a joint distribution, we can calculate the probability of any event:
- Probability that it’s hot AND sunny?
- Probability that it’s hot?
- Probability that it’s hot OR sunny?

## Marginal Distributions
Are sub-tables from joint distributions, which eliminates some variables.
- Marginalization (summing out): Combine collapsed rows by adding

<div style="text-align:center">
  <img src ="/cstopics/assets/img/AI/introAI/marg_dis.png" style="width:80%"/>
  <span style="font-size:70%">http://ai.berkeley.edu/course_schedule.html</span>  
</div>

### Exercise
<div style="text-align:center">
  <img src ="/cstopics/assets/img/AI/introAI/marg_dis_quiz.png" style="width:80%"/>
  <span style="font-size:70%">http://ai.berkeley.edu/course_schedule.html</span>  
</div>

## Conditional probabilities
<img src="https://latex.codecogs.com/gif.latex?  P(a|b)=\frac{P(a,b)}{P(b)}"/>

<div style="text-align:center">
  <img src ="/cstopics/assets/img/AI/introAI/cond_prob.png" style="width:40%"/>
  <span style="font-size:40%">http://ai.berkeley.edu/course_schedule.html</span>  
</div>

| P(T,W) 	|  	|  	|
|--------	|------	|-----	|
| T 	| W 	| P 	|
| hot 	| sun 	| 0.4 	|
| hot 	| rain 	| 0.1 	|
| cold 	| sun 	| 0.2 	|
| cold 	| rain 	| 0.3 	|

¿Which is the probability of having a sunny day if the environment feels cold?

<img class="eq" src="https://latex.codecogs.com/gif.latex?  P(W=s|T=c)=\frac{P(W=s, T=c)}{P(T=c)}=\frac{0.2}{0.5}=0.4"/>

## Conditional Distributions
Conditional distributions are probability distributions over some variables given fixed values of others

There are a set of tables for all possible values for some random variables
<div style="text-align:center">
  <img src ="/cstopics/assets/img/AI/introAI/cond_dis.png" style="width:70%"/>
  <span style="font-size:40%">http://ai.berkeley.edu/course_schedule.html</span>  
</div>

## Probabilistic Inference
To compute a desired probability from other known probabilities

**We generally compute conditional probabilities:** these represent the agent’s beliefs given the evidence

Observing new evidence causes beliefs to be updated

- P(on time | no accidents) = 0.9
- P(on time | no accidents, 5am) = 0.95
- P(on time | no accidents, 5am, raining) = 0.8
