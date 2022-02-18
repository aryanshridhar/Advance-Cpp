### Algorithms

#### Undirected Graph:

<ul>

<li>Cycle detection:</li>
<ul>
<li>BFS - Check if that node has been already been visited by some other parent edge.</li>
<li>DFS - Logic similar to BFS.</li>
</ul>

<li>Shortest path:</li>
<ul>
<li>BFS - Easy BFS for all nodes with unit edge weight.</li>
<li>DFS - Assign minimum of current and vector value.</li>

<li>In cases of weighted graph - Dijkstra algorithm.</li>
<li>Why not BFS - https://stackoverflow.com/questions/30409493/using-bfs-for-weighted-graphs.</li>
</ul>

</ul>



#### Directed Graph:

<ul>

<li>Cycle detection:</li>
<ul>
<li>BFS - Kahn's Algorithm (Check if Topological sort exists).</li>
<li>DFS - Logic similar to DFS of undirected graph. But make another vector similar to visi which only marks the nodes traversed in that recursion traversal.</li>
</ul>

<li>Shortest path:</li>
<ul>
<li> BFS - Store the topo sort in stack and apply same logic as undirected BFS.</li>
<li> DFS - Highly inefficient backtracking solution.</li>
</ul>


</ul>


#### Miscellaneous

<ul>
<li>If a graph is DAG, it's topological sort must exists.</li>
<li>It is also implied that if topo sort doesn't exists, the graph must be cyclic at some point.</li>
<li>We can apply Dijkstra in case of DAG but the weights must be non negative.</li>
</ul>