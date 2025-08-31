#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>

struct Node
{ int L, R, w; }
T[103];
__gnu_pbds::gp_hash_table<int, int> idx;
int cnt = 0;

void ist(int u, int x) {
	if(T[u].w == 0) {
		T[u].w = x;
		return;
	} else if(x < T[u].w) {
		if(!T[u].L)
			T[u].L = idx[x];
		ist(T[u].L, x);
	} else if(x > T[u].w) {
		if(!T[u].R)
			T[u].R = idx[x];
		ist(T[u].R, x);
	}
}

void pre(int u) {
	cout << T[u].w << ' ';
	if(T[u].L)
		pre(T[u].L);
	if(T[u].R)
		pre(T[u].R);
}

void mid(int u) {
	if(T[u].L)
		mid(T[u].L);
	cout << T[u].w << ' ';
	if(T[u].R)
		mid(T[u].R);
}

void post(int u) {
	if(T[u].L)
		post(T[u].L);
	if(T[u].R)
		post(T[u].R);
	cout << T[u].w << ' ';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		if(idx[x])
			continue;
		else {
			idx[x] = ++cnt;
			ist(1, x);
		}
	}
	pre(1); cout.put('\n');
	mid(1); cout.put('\n');
	post(1); cout << endl;
	return 0;
}
