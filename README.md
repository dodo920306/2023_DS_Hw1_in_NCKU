# 2023_DS_Hw1_in_NCKU
This is a duplication of the original DS Hw1 repo in 2023, NCKU.

The original one can't be set as public and isn't a repo of mine since it's a github classroom repo. Therefore, here is the public duplication.

## Execution environment and Constraint.
* CPU core: 1
* Memory: 2 GB
* Execution time limit: 1 second
* C Compiler: GCC
    * compiled with -O3 -std=c11 -Wall
* C Standard: C11
* Use header file only from C Standard Library
* OS: Ubuntu 22.04.1 LTS

## Problem 1 : Prefix, Infix and Postfix (2%)
Write two C functions. The first one transforms an infix expression into a postfix one, and the second one transforms a postfix expression into a prefix one. 

The function should be stored in a different file, such as hw1_p1-1.c and hw1_p1-2.c. 

## Problem 2 : Disjoint Sets (2%) 
Write a C function heightUnion that uses the height rule for union operations instead of the weight rule. The following is the definition of this rule.

> Definition [Height Rule]:
> If the height of tree i is less than that of tree j, then make j the parent of i.
> Your function must run in O(1) time and should maintain the height of each tree as a negative number in the parent field of the root.

### Input Format
The first line is the number of test cases.

In each test case, a line with 2 integers n and ops is given.

n is the number of elements in the full set. Elements are labeled from 0 to (n−1).

ops is the number of operations that you need to do.

There are 3 operations as follows.
1. union a1 b1
2. find a2
3. same a3 b3

(Note: If two sets with same height perform union, the first set a1 be the parent)

### Output Format
* Each time you get the operation find, output the root of the set.
* Each time you get the operation same, output true if they are in the same set. Output false if they are not in the same set.

### Constraints
* 1 ≤ n ≤ 10^4
* 1 ≤ ops ≤ 10^4

## Problem 3 : Graphs (3%) 
Write a C function that finds a minimum cost spanning tree using Kruskal’s algorithm.

### Input Format
The first line shows V and E. V represents the vertex number while E is the edge number. The rest shows the edge detail. Each line contains s, t and c, which means there is an edge between s and v with cost c.

### Output Format
The output consists of one number, C. It represents the sum of all edge cost in the minimum spanning tree in terms of the given graph.

### Constraints
* 1 < V ≤ 10^6
* V^-1 ≤ E ≤ min(V(V - 1) / 2, 2 * 10^6)
* 1 < c, s, t < 10^6
