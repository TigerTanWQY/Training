#include<bits/stdc++.h>
using namespace std;
const int N = 10101010;

int n,m,k,fa[N],height[N],top;
struct E{int x,y;}e[N];
struct Stack{int x,y,add;}st[N];
vector<int> t[N];

int findfa(int x) {
	while(x != fa[x]) x = fa[x];
	return fa[x];
}
void merge(int x,int y){
	int fx = findfa(x),fy = findfa(y);
	if(height[fx] > height[fy]) swap(fx,fy);
	st[++top] = (Stack){fx,fy,height[fx] == height[fy]};
	fa[fx] = fy;
	if(height[fx] == height[fy]) height[fy]++;
}
void update(int u,int l,int r,int L,int R,int x){
	if(l > R || r < L) return;
	if(L <= l && r <= R) {t[u].push_back(x);return;}
	int mid = l + r >> 1;
	update(u<<1,l,mid,L,R,x);
	update(u<<1|1,mid+1,r,L,R,x);
}
void solve(int u,int l,int r){
	int ans = 1;
	int lasttop = top;
	for(int i = 0;i < t[u].size();i++){
		int a = findfa(e[t[u].at(i)].x);
		int b = findfa(e[t[u].at(i)].y);
		if(a == b){
			for(int k = l;k <= r;k++)
				printf("No\n");
			ans = 0;
			break;
		}
		merge(e[t[u].at(i)].x,e[t[u].at(i)].y+n);
		merge(e[t[u].at(i)].y,e[t[u].at(i)].x+n);
	}
	if(ans){
		if(l==r) printf("Yes\n");
		else{
			int mid = l+r>>1;
			solve(u<<1,l,mid);
			solve(u<<1|1,mid+1,r);
		}
	}
	while(top > lasttop){
		height[fa[st[top].x]] -= st[top].add;
		fa[st[top].x] = st[top].x;
		top--;
	}
	return;
}
int main(){
	cin >> n >> m >> k;
	for(int i = 1,l,r;i <= m;i++){
		cin >> e[i].x >> e[i].y >> l >> r; ++l;
		update(1,1,k,l,r,i);
	}
	for(int i = 1;i <= 2*n;i++) fa[i] = i,height[i] = 1;
	solve(1,1,k);
	return 0;
}
