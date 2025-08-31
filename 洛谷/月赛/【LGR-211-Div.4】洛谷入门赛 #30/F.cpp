#include <bits/stdc++.h>
using namespace std;

struct Prob {
	int tid, pid, t;
	bool tp, val, st;
} a[1003];
bitset<103> vis[103];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int q, k;
	cin >> q >> k >> k >> k;
	for(int i = 0; i < q; ++i) {
		cin >> a[i].tid >> a[i].pid >> a[i].tp;
		a[i].t = i;
		if(a[i].tp && !vis[a[i].tid][a[i].pid]) {
			a[i].val = vis[a[i].tid][a[i].pid] = true;
			if(vis[a[i].tid].count() == 1)
				a[i].st = true;
		}
	}
	sort(a, a + q, [](const Prob& A, const Prob& B) -> bool {
			if(A.tp != B.tp)
				return A.tp;
			else
				return A.t > B.t;
		});
	if(a[0].tp)
		cout << a[0].tid;
	else
		cout << "-1";
	cout.put(' ');
	sort(a, a + q, [](const Prob& A, const Prob& B) -> bool{
			if(A.val != B.val)
				return A.val;
			else
				return A.t > B.t;
		});
	if(a[0].val)
		cout << a[0].tid;
	else
		cout << "-1";
	cout.put(' ');
	bool flag = true;
	for(int i = 0; flag && i < q; ++i)
		if(a[i].val && vis[a[i].tid].count() < k) {
			cout << a[i].tid;
			flag = false;
		}
	if(flag)
		cout << "-1";
	cout.put(' ');
	sort(a, a + q, [](const Prob& A, const Prob& B) -> bool {
			if(A.st != B.st)
				return A.st;
			else
				return A.t > B.t;
		});
	if(a[0].st)
		cout << a[0].tid;
	else
		cout << "-1";
	cout << endl;
	return 0;
}
