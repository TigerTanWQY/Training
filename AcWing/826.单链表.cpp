#include <iostream>
using namespace std;

const int N = 100003;
int h[N], v[N], nxt[N], head = -1, idx = 0;

void add_head(const int& x) {
	v[idx] = x;
	nxt[idx] = head;
	head = idx++;
}

void add(const int& k, const int& x) {
	v[idx] = x;
	nxt[idx] = nxt[k];
	nxt[k] = idx++;
}

void rmv(const int& k) {
	if(~k)
		nxt[k] = nxt[nxt[k]];
	else
		head = nxt[head];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin >> m;
	for(char s; m--; ) {
		cin >> s;
		if(s == 'H') {
			int x;
			cin >> x;
			add_head(x);
		} else if(s == 'D') {
			int k;
			cin >> k;
			rmv(k - 1);
		}
		if(s == 'I') {
			int k, x;
			cin >> k >> x;
			add(k - 1, x);
		}
	}
	for(int i = head; ~i; i = nxt[i])
		cout << v[i] << ' ' ;
	return 0;
}