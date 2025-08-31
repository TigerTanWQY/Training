#include <iostream>
#include <utility>
#include <vector>
#include <map>
using namespace std;
using LL = long long;

const int N = 200003;
struct
{ int t, a, x; }
op[N];
bool f[N], g[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, q;
	cin >> n >> m >> q;
	LL tx = n, ty = m;
	for(int i = 1; i <= q; ++i)
		cin >> op[i].t >> op[i].a >> op[i].x;
	map<int, LL> cnt;
	for(int i = q; i; --i)
		if(op[i].t == 1) {
			if(!f[op[i].a]) {
				--tx;
				f[op[i].a] = true;
				cnt[op[i].x] += ty;
			}
		} else
			if(!g[op[i].a]) {
				--ty;
				g[op[i].a] = true;
				cnt[op[i].x] += tx;
			}
	cnt[0] += tx * ty;
	for(auto cit = cnt.cbegin(); cit != cnt.cend(); )
		if(!cit->second) {
			auto it = cit;
			++cit;
			cnt.erase(it);
		} else
			++cit;
	cout << cnt.size() << '\n';
	for(const auto& p: cnt)
		cout << p.first << ' ' << p.second << '\n';
	return 0;
}