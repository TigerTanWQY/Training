#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;

constexpr const int N = 5003;
bool vis[N];
int x[N], y[N], n;
double dis[N];

double calc(int x1, int y1, int x2, int y2)
{ return sqrt(1LL*(x1-x2)*(x1-x2) + 1LL*(y1-y2)*(y1-y2)); }

double Prim() {
	dis[1] = 0;
	double res = 0;
	for(int _ = 1; _ <= n; ++_) {
		int id = -1;
		for(int i = 1; i <= n; ++i)
			if(!vis[i] && (id == -1 || dis[i] < dis[id]))
				id = i;
		if(id == -1)
			break;
		vis[id] = true;
		res += dis[id];
		for(int i = 1; i <= n; ++i)
			dis[i] = min(dis[i], calc(x[id], y[id], x[i], y[i]));
	}
	return res;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i];
		dis[i] = 1e12;
	}
	cout << fixed << setprecision(2) << Prim() << endl;
	return 0;
}
