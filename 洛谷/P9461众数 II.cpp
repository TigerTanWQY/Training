#include <iostream>
#include <algorithm>
using namespace std;
using LL = long long;

const int P = 998244353;
const int N = 1000003;
struct Data {
	LL a;
	int id;
	bool operator<(const Data& x) const
	{ return a < x.a; }
} p[N];
int f[N], v[N];
LL tot[N], siz[N], now = 0, ji = 0, ci = 0, ans = 0;

int find(const int& x) {
	if(f[x] == x)
		return x;
	else
		return f[x] = find(f[x]);
}

void uni(int x, int y) {
	if(siz[x] > siz[y])
		swap(x, y);
	f[x] = y;
	siz[y] += siz[x];
	tot[y] = (tot[y] + tot[x]) % P;
}

LL lon(const LL& x) {
	if(x & 1)
		return x * ((x + 1) >> 1) % P;
	else
		return (x >> 1) * (x + 1) % P;
}

void hb(const int& x, const int& y) {
	ji = (ji - lon(siz[x]) % P - lon(siz[y]) % P + lon(siz[x] + siz[y]) % P + 2 * P) % P;
	now = (now + tot[y] * siz[x]) % P;
	uni(x, y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> p[i].a;
		p[i].id = i;
		f[i] = i;
		siz[i] = 1;
	}
	sort(p + 1, p + n + 1);
	int j = n;
	for(LL i = 1e6; i > 1; --i) {
		for(; p[j].a == i; --j) {
			v[p[j].id] = 1;
			tot[p[j].id] = p[j].a;
			ji = (ji + 1) % P;
			now = (now + p[j].a) % P;
			if(v[p[j].id - 1])
				hb(find(p[j].id - 1), find(p[j].id));
			if(v[p[j].id + 1])
				hb(find(p[j].id), find(p[j].id + 1));
		}
		ci = (ci + now - ji * (i - 1) % P + P) % P;
		ans = (ans + (now - ji * (i - 1) % P + P) % P * i) % P;
	}
	LL cnt = 0;
	for(int i = 1; i <= n; ++i)
		cnt = (cnt + p[i].a) % P;
	cnt = lon(cnt);
	ans = (ans + cnt - ci + P) % P;
	cout << ans;
	return 0;
}