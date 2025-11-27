#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
constexpr const int N = 5e5 + 3;
struct Place
{ int val, l, r; }
p[N];
struct Node {
	int val, id;
	bool operator <(const Node& it) const {
		return val>it.val;
	}
};
int n, m, ans, last;
bool vis[N];
__gnu_pbds::priority_queue<Node> q;
void Del(int x) {
	p[x].l=p[p[x].l].l;
	p[x].r=p[p[x].r].r;
	p[p[x].l].r=x;
	p[p[x].r].l=x;
}

int main() {
	scanf("%d%d%d", &n, &m, &last);
	for(int i=1; i<n; ++i) {
		int in;
		scanf("%d", &in);
		p[i].val=in-last;
		last=in;
		p[i].l=i-1;
		p[i].r=i+1;
		q.push({p[i].val, i});
	}
	p[0].val=p[n].val=0x3f3f3f3f;
	for(int i=1; i<=m; ++i) {
		while(vis[q.top().id])
			q.pop();
		Node now=q.top();
		q.pop();
		ans+=now.val;
		vis[p[now.id].l]=vis[p[now.id].r]=1;
		p[now.id].val=p[p[now.id].l].val+p[p[now.id].r].val-p[now.id].val;
		q.push({p[now.id].val, now.id});
		Del(now.id);
	}
	printf("%d\n", ans);
	return 0;
}
