#include <bits/stdc++.h>
using namespace std;

int a[400003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; long long S, tot = 0;
	cin >> n >> S;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i + n] = a[i];
		tot += a[i];
	}
	S %= tot;
	long long cnt = 0;
	for(int i = 1, j = 1; j <= 2 * n; ++j) {
		cnt += a[j];
		if(j - i + 1 > n)
			cnt -= a[i++];
		for(; cnt > S; cnt -= a[i++]);
		if(cnt == S) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
/*
请你用 C++20 编写规范正确的代码来完成这道题。

## D - Repeated Sequence

Time Limit: 2 sec / Memory Limit: 1024 MB

### Problem Statement

You are given the first $N$ terms $A _ 1,A _ 2,\dotsc,A _ N$ of an infinite sequence $A=(A _ 1,A _ 2,A _ 3,\dotsc)$ that has period $N$.

Determine if there exists a non-empty contiguous subsequence of this infinite sequence whose sum is $S$.

Here, an infinite sequence $A$ has period $N$ when $A _ i=A _ {i-N}$ for every integer $i&gt;N$.

### Constraints

-   $1\leq N\leq2\times10 ^ 5$
-   $1\leq A _ i\leq 10 ^ 9$
-   $1\leq S\leq 10 ^ {18}$
-   All input values are integers.

### Input

The input is given from Standard Input in the following format:

```
$N$ $S$
$A _ 1$ $A _ 2$ $\dotsc$ $A _ N$
```

### Output

If there exists a contiguous subsequence $(A _ l,A _ {l+1},\dotsc,A _ r)$ of $A$ for which $A _ l+A _ {l+1}+\dotsb+A _ r=S$, print `Yes`. Otherwise, print `No`.

### Sample Input 1

```
3 42
3 8 4
```

### Sample Output 1

```
Yes
```

The sequence $A$ is $(3,8,4,3,8,4,3,8,4,\dotsc)$.

For the subsequence $(A _ 2,A _ 3,A _ 4,A _ 5,A _ 6,A _ 7,A _ 8,A _ 9)=(8,4,3,8,4,3,8,4)$, we have $8+4+3+8+4+3+8+4=42$, so print `Yes`.

### Sample Input 2

```
3 1
3 8 4
```

### Sample Output 2

```
No
```

All elements of $A$ are at least $3$, so the sum of any non-empty contiguous subsequence is at least $3$.

Thus, there is no subsequence with sum $1$, so print `No`.

### Sample Input 3

```
20 83298426
748 169 586 329 972 529 432 519 408 587 138 249 656 114 632 299 984 755 404 772
```

### Sample Output 3

```
Yes
```

### Sample Input 4

```
20 85415869
748 169 586 329 972 529 432 519 408 587 138 249 656 114 632 299 984 755 404 772
```

### Sample Output 4

```
No
```
*/
