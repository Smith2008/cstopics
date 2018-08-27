---
layout: default
title: Search
permalink: /artificial-intelligence/CSP/csp
---

# Constraint Satisfaction Problems

A CSP consist of three components:
- X is a set of variables, {X1, X2, ..., Xn}
- D is a set of domains, {D1, D2, ..., Dn }, one for each variable
- C is a set of constraints for assignments

Each **domain Di** consist of a set of allowable values {v1, v2, ..., vn} for variable Xi.

A **constraint** can be represented as an explicit list of all tuples of values that satisfy the constraint,  or as an abstract relation.

For example, if variables X1 and X2 have the domain {A,B}, then the constraint saying the two variables must have different values can be written as:
- (X1,X2) = { (A,B) , (B,A) }  
- X1 ≠ X2

Each state in a CSP is defined by an **assignment** of values to some of all variables. An assignment that does not violate any constraints is called a **consistent** assignment.

<font color="blue"><i>Example: map coloring</i></font>
Color each region, either red, green or blue, in such a way that no neighboring regions have the same color.

Formulate the problem as a CSP.
<div style="text-align:center">
  <img src ="/cstopics/assets/img/AI/introAI/map_coloring.gif" style="width:50%"/>  
</div>

- Variables: X = {WA, NT, Q, NSW, V, SA, T}
- Domain: Di = {red, green, blue}
- Constraints: C = {SA≠WA,  SA≠NT,  SA≠Q,  SA≠NSW,  SA≠V,  WA≠NT,  NT≠Q,  Q≠NSW,  NSW≠V}

A solution for the CSP problem could be:

{WA=blue, NT=green SA=red, Q=blue, NSW=green, V=blue, T=green}

<div style="text-align:center">
  <img src ="/cstopics/assets/img/AI/introAI/map_coloring_solved.png" style="width:50%"/>  
</div>

**Constraint graph**

Allows to visualize a CSP. The nodes of the graph are the variables of the problem, an a link connects any two variables that participate in a constraint.

<div style="text-align:center">
  <img src ="/cstopics/assets/img/AI/introAI/csp_graph.png" style="width:40%"/>  
</div>

**Why formulate a problem as a CSP**

To solve a CSP problem you can use a search procedure, but you would not take advantage of constraint propagation.

For the map coloring problem, once you have chosen {SA=blue}, a search procedure would have to consider 3⁵=243 assignments for the five neighboring variables, although you already know that they cannot be blue. With constraint propagation methods, you never have to consider blue as a value, so there is only 2⁵=32 possible assignments, a reduction of 87%.

## Variations on the CSP formalism

### Varieties of variables
#### Discrete variables
- **Finite domains:** each variable has a fixed number of possible values in its domain. If there are _n_ variables and _d_ elements in each domain, the number of possible complete assignments is O(d^n).

- **Infinite domains:** variables can take values from a set of integers or strings. For example, in job scheduling, the variables are start/end days for each job. CSP with these variables needs a constraint language, such as T1+5 < T2.

#### Continuous variables
Linear constraints solvable in polynomial time in the number of variables by Linear Programming methods

### Varieties of constraints
- **Unary:** restricts the value of a single variable. E.g. SA ≠ blue
- **Binary:** a constraint relates only two variables. A **binary CSP** only has binary constraints. E.g. SA≠WA
- **Higher-order:** involves 3 or more variables. E.g. X+Y<Z


# Solving CSPs

## Constraint propagation: inference in CSPs
In CSPs is a good idea that the algorithm uses the constraints to reduce the number of legal values for a variable. This is a specific type of inference called _Constraint Propagation_.

The key idea is to enforce **local consistency** in each part of the graph.

### Arc consistency
Xi is arc-consistent with respect to another variable Xj if, for every value in the current domain Di there is some value in the domain Dj that satisfies the binary constraint on the graph (Xi, Xj).

For example, consider the constraint Y=X², where the domain for each variable is the set of integers from 0 to 9. The constrain can be explicitly written as:

(X,Y) = {(0,0), (1,1), (2,4), (3,9)}

- To make X arc-consistent with respect to Y, we reduce X's domain to {0,1,2,3}
- To make Y arc-consistent with respect to X, we reduce Y's domain to {0,1,4,9}

With these domains, the whole CSP is arc-consistent


<font color="blue"><i>Example: map coloring</i></font>
<div style="text-align:center">
  <img src ="/cstopics/assets/img/AI/introAI/arc_consistency.png" style="width:80%"/>  
</div>

**The most popular algorithm for arc consistency is AC-3**

## Backtracking search for CSPs
Backtracking search is a variation of DFS which chooses values for one variable at a time and backtracks when a variable has no legal values left to assign.

- States: partial assignment
- Actions: adding _var=value_ to the assignment

<div style="text-align:center">
  <img src ="/cstopics/assets/img/AI/introAI/backtracking.png" style="width:90%"/>  
</div>

- Backtracking-Search repeatedly chooses and unassigned variable ans tries all values in its domain.
- If an inconsistency is detected, then the algorithm returns _failure_, causing the previous call to try another value.

<div style="text-align:center">
  <img src ="/cstopics/assets/img/AI/introAI/backtrack_example.png" style="width:80%"/>  
</div>

### Which variable should be assigned first?
For example, after the assignments WA=red and NT=green, there is only one possible value for SA, so it makes sense to assign SA=blue. In fact, after SA is assigned, the choices for Q, NSW ad V are all forced.

**Intuitive idea:** choose "the most constrained variable".

This is, choose the variable with the **minimum-remaining-values** (MRV heuristic)


### In what order should variable's values be tried?
The **least-constrainig-value** heuristic can be effective, preferring the value that rules out the fewest choices for the neighboring variables in the constraint graph. The heuristic tries to leave the maximum flexibility for subsequent variables assignments.

For example, if the next variable is Q in the partial assignment WA=red and NT=green, the heuristic would prefer red over blue, because blue eliminates the last legal assignment for SA.

# Exercise: can you tell the difference in this backtrack-search?
## Video 1
<div style="text-align:center">
<video width="486" height="508" controls>
  <source src="/cstopics/assets/videos/introAI/backtracking.mp4" type="video/mp4">
</video>
</div>

## Video 2
<div style="text-align:center">
<video width="486" height="508" controls>
  <source src="/cstopics/assets/videos/introAI/backtracking_mac.mp4" type="video/mp4">
</video>
</div>

# Additional material
You can download this material for further study:
- [Book chapter](http://aima.cs.berkeley.edu/newchap05.pdf)
- [CSP code implementation](/cstopics/assets/code/introAI/csp_example.zip)

# Exercise
You are a famous entrepreneur of USTAcapital. You are opening a new dependency, which requires the development  of a supply chain. You have defined five workstations, which needs the good/service from the previous one. The workstations are: farming, design, manufacturing, packaging, and transportation.

 You have 5 people available to be the chief of each workstation. However, they can be extremely arrogant with some of each other. You, as president of USTAcapital, want to guarantee harmonious relationships between consecutive workstations. The head of human resources have brought you the following chart that shows the level of compatibility between your personal:
 
