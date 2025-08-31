#include <iostream>
#include <cmath>
#include <utility>
using namespace std;
using PII = pair<int, int>;
#define x first
#define y second

PII a[103];

int dis(const PII& u, const PII& v)
{ return (u.x - v.x) * (u.x - v.x) + (u.y - v.y) * (u.y - v.y); }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].x >> a[i].y;
	for(int i = 1; i <= n; ++i) {
		int ansid = 0, ansd = 0;
		for(int j = 1; j <= n; ++j)
			if(i != j && dis(a[i], a[j]) > ansd) {
				ansd = dis(a[i], a[j]);
				ansid = j;
			}
		cout << ansid << '\n';
	}
	return 0;
}