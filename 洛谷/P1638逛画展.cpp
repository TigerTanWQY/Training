#include <iostream>
#include <deque>
#include <unordered_map>
using namespace std;

const int N = 1000003;
int a[N], n, m;

bool check(const int& len) {
	deque<int> q;
	unordered_map<int, int> cnt;
	for(int i = 1; i <= n; ++i) {
		if(q.size() >= len) {
			--cnt[a[q.front()]];
			if(!cnt[a[q.front()]])
				cnt.erase(a[q.front()]);
			q.pop_front();
		}
		q.push_back(i);
		++cnt[a[i]];
		if(cnt.size() == m)
			return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	int L = 1, R = n;
	for(int M = (L + R) / 2; L + 1 < R; M = (L + R) / 2)
		if(check(M))
			R = M;
		else
			L = M;
	deque<int> q;
	unordered_map<int, int> cnt;
	for(int i = 1; i <= n; ++i) {
		if(q.size() >= R) {
			--cnt[a[q.front()]];
			if(!cnt[a[q.front()]])
				cnt.erase(a[q.front()]);
			q.pop_front();
		}
		q.push_back(i);
		++cnt[a[i]];
		if(cnt.size() == m) {
			cout << q.front() << ' ' << q.back();
			break;
		}
	}
	return 0;
}