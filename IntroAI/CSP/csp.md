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
