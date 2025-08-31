#include <iostream>
#include <cstring>
using namespace std;

constexpr const int N = 200'003;
char s[N], t[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(; _T--; ) {
		cin >> (s + 1) >> (t + 1);
		int n = strlen(s + 1), m = strlen(t + 1);
		int i = 1;
		for(int j = 1; i <= n && j <= m; ++j) {
			if(s[i] == '?')
				s[i] = t[j];
			if(s[i] == t[j])
				++i;
		}
		if(i == m + 1) {
			cout << "YES\n";
			for(i = 1; i <= n; ++i)
				if(s[i] == '?')
					cout.put('a');
				else
					cout.put(s[i]);
			cout.put('\n');
		} else
			cout << "NO\n";
	}
	cout.flush();
	return 0;
}
/*
你是一名 C++14 专家，请编写规范正确的代码来完成这道题。

# D. Slavic's Exam

time limit per test: 2 seconds

memory limit per test: 256 megabytes

input: standard input

output: standard output

## Problem Statement

Slavic has a very tough exam and needs your help in order to pass it. Here is the question he is struggling with:

There exists a string $s$, which consists of lowercase English letters and possibly zero or more "?".

Slavic is asked to change each "?" to a lowercase English letter such that string $t$ becomes a subsequence (not necessarily continuous) of the string $s$.

Output any such string, or say that it is impossible in case no string that respects the conditions exists.

## Input

The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases.

The first line of each test case contains a single string $s$ ($1 \leq |s| \leq 2 \cdot 10^5$, and $s$ consists only of lowercase English letters and "?"-s)  – the original string you have.

The second line of each test case contains a single string $t$ ($1 \leq |t| \leq |s|$, and $t$ consists only of lowercase English letters)  – the string that should be a subsequence of string $s$.

The sum of $|s|$ over all test cases doesn't exceed $2 \cdot 10^5$, where $|x|$ denotes the length of the string $x$.

## Output

For each test case, if no such string exists as described in the statement, output "NO" (without quotes).

Otherwise, output "YES" (without quotes). Then, output one line — the string that respects all conditions.

You can output "YES" and "NO" in any case (for example, strings "yEs", "yes", and "Yes" will be recognized as a positive response).

If multiple answers are possible, you can output any of them.

## Example

### Input

```plain
5
?????
xbx
ab??e
abcde
ayy?x
a
ab??e
dac
paiu
mom
```

### Output

```plain
YES
xabax
YES
abcde
YES
ayyyx
NO
NO
```
*/