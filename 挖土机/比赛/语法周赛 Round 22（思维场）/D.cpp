#include <iostream>
using namespace std;
#define int long long

const int a[]{0, 10, 10, 30, 20, 10, 30, 70, 40, 90};

int log(int x) {
	int res = 0;
	for(; x; x /= 10)
		++res;
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for(int L, R; n--; ) {
		cin >> L >> R;
		int _L = (L / k + !!(L % k)) * k, _R = R / k * k;
		int tota = 0, totb = (R - L + 1) / 10;
		if(_L <= _R)
			tota = (_R - _L) / k + 1;
		if(L % k == 0 && R % k == 0)
			++totb;
		cout << tota + totb - (R - L + 1) / a[k] - (_L % 10 == k || _R % 10 == k) + (L == k) - (L % k == 0) + (R == k) - (R % k == 0) << '\n';
	}
	cout << flush;
	return 0;
}
/*
你是一名 C++14 专家，请编写规范正确的代码来完成这道题。

# D. K 的倍数或个位是 K

时间限制: 1 sec / 空间限制：256 MiB

## 题目描述

33DAI 喜欢整数 $k$。他遇到了 $n$ 个问题。

每个问题给定两个数 $L,R$，请你判断 $L$~$R$ 之间有多少个整数满足“**是 $k$ 的倍数或者个位是 $k$**”。

## 输入格式

第一行两个整数 $n,k$。

接下来 $n$ 行，每行两个整数 $L,R$，即当前问题。

## 输出格式

输出 $n$ 行，每行分别是每个问题的答案。

## 样例数据

### 样例输入 1

```
5 3
1 10
11 1000
111 10000
1111 100000
11111 1000000
```

### 样例输出 1

```
3
396
3956
39555
395556
```

## 数据规模与约定

对于 $100\%$ 的数据，$1\le n\le 1000$，$1\le k\le 9$，$1\le L\le R\le 10^9$。
*/