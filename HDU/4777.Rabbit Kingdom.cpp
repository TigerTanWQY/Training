#include <bits/stdc++.h>
using namespace std;
constexpr const int N=2e5 + 3;
//bool pri[N];
bitset<N> pri;
int n,m,r[N],l[N],a[N],tree[N],mark[N],ans[N];
vector<int>p[N],vt[N];
struct st
{ int l,r,id; }
q[N];
void prime() {
	for(int i = 2; i <= 200000; i++)
		if(!pri[i]){
			p[i].push_back(i);
			for(int j = i+i; j <= 200000; j+=i) {
				pri[j]=1;
				p[j].push_back(i);
			}
		}
}
void pre() {
	memset(mark,0,sizeof(mark));
	for(int i = 0; i <= n; i++) {
		tree[i]=0;
		vt[i].clear();
		l[i]=0;
		r[i]=n+1;
	}
	for(int i= 1; i <= n; i++) {
		int lv=p[a[i]].size();
		for(int j= 0; j < lv; j++) {
			int x = p[a[i]][j];
			if(!mark[x]) {
				mark[x] = i;
				continue;
			}
			if(r[mark[x]] == n+1)
				r[mark[x]] = i;
			l[i] = max(l[i],mark[x]);
			mark[x]=i;
		}
		vt[l[i]].push_back(i);
	}
}
bool cmp(st x,st y)
{ return x.l<y.l; }
void add(int k , int num) {
	while(k <= n) {
		tree[k] += num;
		k += k&(-k);
	}
}
int Sum(int k) {
	int sum = 0;
	while(k > 0) {
		sum += tree[k];
		k -= k&(-k);
	}
	return sum;
}
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	prime();
	while(cin >> n >> m) {
		if(n == m&&m == 0)
			break;
		int i,j;
		for(i = 1; i <= n; i++)
			cin >> a[i];
		for(i = 1; i <= m; i++) {
			cin >> q[i].l >> q[i].r;
			q[i].id=i;
		}
		pre();
		sort(q,q+1+n,cmp);
		int cnt=1;
		for(i = 0; i <= n; i++) {
			while(q[cnt].l == i) {
				ans[q[cnt].id] = Sum(q[cnt].r)-Sum(q[cnt].l-1);
				cnt++;
			}
			int x=vt[i].size();
			for(j = 0;j < x;j++) {
				int v=vt[i][j];
				add(v,1);
				add(r[v],-1);
			}
			if(r[i]!=n+1)
				add(r[i],1);
		}
		for(i = 1;i <= m;i++)
			cout<<ans[i]<<'\n';
	}
	cout.flush(); return 0;
}
