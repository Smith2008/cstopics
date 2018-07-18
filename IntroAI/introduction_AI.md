---
layout: default
title: Introduction and History Review of Artificial Intelligence
permalink: /artificial-intelligence/introduction_AI
---

# Introduction - History Review

## What is AI?

> The science of making machines?

<div style="text-align:center">
  <iframe width="420" height="345" src="https://www.youtube.com/embed/b-bW0xcrsOo">
  </iframe>
</div>



Four main approaches:

| **Thinking Humanly** 	| **Thinking Rationally** 	|
|:----------------------------------------------------------------------------------------------------------------------------:	|:---------------------------------------------------------------------------------------------------:	|
| "The exciting new effort to make computers think ... _machines with minds_,  in the full and literal sense"(Haugeland, 1985) 	| "The study of the computations that make it possible to perceive, reason and act."(Winston, 1992) 	|
| **Acting Humanly** 	| **Acting Rationally** 	|
| "The study of how to make computers do things at which, at the moment, people are better."(Rich and Knight, 1991) 	| "AI...is concerned with intelligent behavior in artifacts."(Nilsson, 1998) 	|

### Acting humanly: The Turing test approach

Turing test (Alan Turing, 1950) --> _Imitation Game:_ can a human interrogator tell the difference between human's or computer's response?

<div style="text-align:center">
  <img src ="/cstopics/IntroAI/figures/turingtest.png" />
  <span style="font-size:70%">http://aima.eecs.berkeley.edu/slides-pdf/chapter01.pdf</span>
</div>

Intelligent systems would need the following capabilities:
* Natural language processing
* Knowledge representation
* Automated reasoning
* Machine learning

### Thinking humanly: The cognitive modeling approach
Given a program that thinks like a human, we must have some way of determining how humans think. Then,  we need to get _inside_ the human mind in order to obtain its abstraction and make better AI systems.

Requires scientific theories of internal activities of the brain:
- What level of abstraction? "Knowledge" or "Circuits"?
- How to validate the model?
  - Psychological: output of computer program matches human behaviors
  - Cognitive science: identification from neurological data

Brains are not as modular as software, so hard to reverse engineer!


### Thinking rationally: The "Laws of thought" approach
Search for argument structures to yield correct conclusions when given correct premises.

Based on **logicist** tradition: statements or rules or derivation.

<div style="text-align:center">
  <img src ="/cstopics/IntroAI/figures/think_rational.jpg" />
  <span style="font-size:70%">https://www.tutorialspoint.com/artificial_intelligence/artificial_intelligence_expert_systems.htm</span>
</div>

Main obstacles:
- It is not easy to take informal knowledge and state it in logical notation
- _What is the purpose  of thinking?_   Thoughts that I **should** have out of all the thoughts that I **could** have?

### Acting rationally: The rational agent approach
**Agent:** just something that acts.

However, intelligent agents must do more, such as:
   - Operate autonomously
   - Perceive their environment
   - Adapt to change
   - Create and pursue goals

But, there are also ways to act rationally without involving inference -e.g: _blinking reflex_

#### Rational agents
* A rational agent acts to **maximize** chances to achieve pre-defined goals.
* Only concerns with the actions taken (not the thought process)
* Effectiveness of actions can be assess based on utility functions
<div style="text-align:center"> Being rational means <b>maximize your expected utility</b> </div>

> "Every art and every inquiry, and similarly every action and pursuit, is thought to aim at some good",
> Nicomachean Ethics, Aristotle

## The (short) history of Artificial Intelligence
<div style="text-align:center">
  <iframe width="420" height="345" src="https://www.youtube.com/embed/aygSMgK3BEM">
  </iframe>
</div>

- <font color="orange">1940-1950: Early days </font>
  - (1943) McCulloch & Pitts: brain model with Boolean logic
  - (1950) Minsky and Edmonds: build of first neural network computer (SNARC) [read more](http://cyberneticzoo.com/mazesolvers/1951-maze-solver-minsky-edmonds-american/)
  <div style="text-align:center">
    <img src ="/cstopics/IntroAI/figures/neuronSNAC.jpg" style="width:30%"/>
    <span style="font-size:70%">http://cyberneticzoo.com/mazesolvers/1951-maze-solver-minsky-edmonds-american/</span>
  </div>
  - (1950) Turing Test: article "Computing Machinery and Intelligence" [read more](http://phil415.pbworks.com/f/TuringComputing.pdf)

- <font color="orange">1950-1970: Great expectations: "Look, Ma, no hands!" </font>
  - (1952) Early demonstrations about "machines can do X" (Samuel's checkers program, Galernter's Geometry Theorem Prover)
  - (1956) Dartmouth meeting: birthplace of AI
  - (1962) Widrow and Hoff: perceptron convergence Theorem

- <font color="orange">1966-1973: A dose of reality" </font>
  >It is not my aim to surprise or shock you--but the simplest way I can summarize is to say that there are now in the word machines that think, that learn and that create. Moreover, their ability to do these things is going to increase rapidly until--in a visible future--the range of problems they can handle will be coextensive with the range to which the human mind has been applied. Herbert Simon, 1957

  - Early programs knew nothing of their subject matter. No background knowledge
  - Most early AI programmers solved problems by trying out different combinations until solution was found. <font color="red">Combinatorial explosion!</font>
  - Limitations on the basic structures being used to generate intelligent behavior. (Perceptrons by itself can represent very little)
  - (1969) Bryson and Ho: proposed back-propagation algorithm for multilayer NN

- <font color="orange">1969-1990: Knowledge-based systems: The key to power? </font>
  - Early development of knowledge-intensive systems: its expertise derived from large numbers of special-purpose rules
  - Expert systems: MYCIN to diagnose blood infections with 450 rules
  - (1982) Expert systems in industry: specialized for commercial, vision, robotics purposes
  - AI winter

- <font color="orange">1990-Present: The emergence of intelligent systems </font>
  - (mid 1980) Resurgence of back-propagation learning algorithm
  - Increase in technical depth: approaches based on Hidden Markov Models and statistical approaches (Bayesian network formalism)
  - Main subject of study: algorithm or data?

  <div style="text-align:center">
    <img src ="/cstopics/IntroAI/figures/historyAI.jpg" />
    <span style="font-size:70%">Google</span>
  </div>
