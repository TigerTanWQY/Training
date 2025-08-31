#include <iostream>
#include <string>
using namespace std;

const int N = 100003;
int ls[N], L[N], R[N], idx;

void rmv(const int& k) {
	R[L[k]] = R[k];
	L[R[k]] = L[k];
}

void add(const int k, const int x) {
	ls[idx] = x;
	R[idx] = R[k];
	L[idx] = k;
	L[R[k]] = idx;
	R[k] = idx++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int head = 0, tail = N - 1;
	R[head] = tail;
	L[tail] = head;
	idx = 1;
	int m;
	cin >> m;
	for(string op; m--; ) {
		cin >> op;
		if(op == "R") {
			int x;
			cin >> x;
			add(L[tail], x);
		} else if(op == "D") {
			int k;
			cin >> k;
			rmv(k);
		} else if(op == "L") {
			int x;
			cin >> x;
			add(head, x);
		} else if(op == "IL") {
			int k, x;
			cin >> k >> x;
			add(L[k], x);
		} else if(op == "IR") {
			int k, x;
			cin >> k >> x;
			add(k, x);
		}
	}
	for(int i = R[head]; i != tail; i = R[i])
		cout << ls[i] << ' ';
	return 0;
}