#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

string s;
int n, ex, ey;

void upd(PII& pos, char op, int d) {
	switch(op) {
		case 'U':
			pos.second += d;
			break;
		case 'D':
			pos.second -= d;
			break;
		case 'L':
			pos.first -= d;
			break;
		case 'R':
			pos.first += d;
			break;
	}
}

bool _chk(const PII& u, PII&& v, int len) {
	int d = abs(u.first - v.first) + abs(u.second - v.second);
	if((d & 1) ^ (len & 1))
		return false;
	else
		return len >= d;
}

bool chk(int len) {
	PII pos;
	for(int i = len; i < n; ++i)
		upd(pos, s[i], 1);
	int L = 0, R = len;
	while(true) {
		if(_chk(pos, {ex, ey}, len))
			return true;
		if(R == n)
			break;
		upd(pos, s[L++], 1);
		upd(pos, s[R++], -1);
	}
	return false;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> s >> ex >> ey;
	if(!chk(n)) {
		cout << "-1" << endl;
		return 0;
	}
	int L = -1, R = n;
	while(L + 1 < R) {
		int M = (L + R) >> 1;
		if(chk(M))
			R = M;
		else
			L = M;
	}
	cout << R << endl;
	return 0;
}
