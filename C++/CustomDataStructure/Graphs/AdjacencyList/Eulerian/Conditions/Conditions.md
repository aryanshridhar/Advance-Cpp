## Circuit

#### Undirected Graph

* All nodes are having even degrees.

#### Directed Graph

* All nodes are having `indegrees == outdegrees`


## Path

#### Undirected Graph

* Either the condition for eculidean circuit in undirected graph.
* OR, (n-2) vertex are having even degrees and remanining 2 are having odd degrees.

#### Directed Graph

* Either the condition for eculidean path in directed graph.
* OR, (n-2) vertex are having even degrees and remanining 2 are having with conditions - 
    * One node with `indegree = outdegree+1`
    * Other node with `outdegree = indegree+1`