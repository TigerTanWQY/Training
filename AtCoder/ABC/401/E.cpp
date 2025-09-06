/*
## E - Reachable Set

 Time Limit: 2 sec / Memory Limit: 1024 MB

 ### Problem Statement

You are given an undirected graph with $N$ vertices and $M$ edges. The vertices are numbered $1,2,\ldots,N$, and the $i$‑th edge $(1 \le i \le M)$ connects vertices $u_i$ and $v_i$.

For each $k = 1,2,\ldots,N$, solve the following problem:

> Consider the following operation.
>
> -   Choose one vertex, and delete that vertex together with all edges incident to it.
>
> Determine whether one can repeat this operation to satisfy the following condition:
>
> -   The set of vertices reachable from vertex $1$ by traversing edges consists exactly of the $k$ vertices $1,2,\ldots,k$.
>
> If it is possible, find the minimum number of operations required to do so.

### Constraints

-   $1 \le N \le 2 \times 10^{5}$
-   $0 \le M \le 3 \times 10^{5}$
-   $1 \le u_i &lt; v_i \le N\ (1 \le i \le M)$
-   $(u_i,v_i) \ne (u_j,v_j)\ (1 \le i &lt; j \le M)$
-   All input values are integers.

### Input

The input is given from Standard Input in the following format:

```
$N$ $M$
$u_1$ $v_1$
$u_2$ $v_2$
$\vdots$
$u_M$ $v_M$
```

### Output

Print $N$ lines. On the $i$\-th line $(1 \le i \le N)$, if one cannot satisfy the condition for $k=i$, print `-1`; otherwise, print the minimum number of operations required to satisfy the condition.

### Sample Input 1

```
6 7
1 2
1 5
2 3
2 4
2 5
3 6
5 6
```

### Sample Output 1

```
2
3
3
2
1
0
```

For example, for $k = 2$, deleting the three vertices $3, 4, 5$ makes the set of vertices reachable from vertex $1$ equal to the two vertices $1, 2$. It is impossible with two or fewer deletions, so print `3` on the 2nd line.

For $k = 6$, deleting zero vertices makes the set of vertices reachable from vertex $1$ equal to the six vertices $1,2,\ldots,6$, so print `0` on the 6th line.

### Sample Input 2

```
5 4
1 5
2 3
3 4
4 5
```

### Sample Output 2

```
1
-1
-1
-1
0
```

### Sample Input 3

```
2 0
```

### Sample Output 3

```
0
-1
```

There may be no edges.

### Sample Input 4

```
11 25
6 9
5 9
2 3
1 9
10 11
4 5
9 10
8 9
7 8
3 5
1 7
6 10
4 7
7 9
1 10
4 11
3 8
2 7
3 4
1 8
2 8
3 7
2 10
1 6
6 11
```

### Sample Output 4

```
5
-1
-1
-1
-1
-1
4
3
2
1
0
```
*/
