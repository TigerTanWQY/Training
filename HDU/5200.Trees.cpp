#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 5e4 + 3;
struct tree{
	int h,id;
	bool operator<(const tree &tmp) const
	{ return h>tmp.h; }
}p[N];
struct query{
	int h,id;
	bool operator<(const query &tmp) const
	{ return h<tmp.h; }
}q[N];
bitset<N> vis;
int ans[N];

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<n;i++){
			scanf("%d",&p[i].h);
			p[i].id=i+1;
		}
		sort(p,p+n);
		for(int i=0;i<m;i++){
			scanf("%d",&q[i].h);
			q[i].id=i+1;
		}
		sort(q,q+m);
		int tot = 0;
		vis.reset();
		for(int i = 0,j = m-1;j>=0;j--){
			for(;i<n;i++){
				if(p[i].h<=q[j].h)
					break;
				vis[p[i].id]=1;
				if(!vis[p[i].id-1]&&!vis[p[i].id+1]) tot++;
				else if(vis[p[i].id-1]&&vis[p[i].id+1]) tot--;
			}
			ans[q[j].id]=tot;
		}
		for(int i=0;i<m;i++)
			printf("%d\n",ans[i+1]);
	}
	return 0;
}
