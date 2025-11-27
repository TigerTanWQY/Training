#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e4 + 3;
struct node
{ int u, v, w1, w2, num; }
road[N];
struct nodee
{ int bh, gl; }
ans[N];
int flag=0, book[N], father[N], n, k, m, minn=0;
bool cmp1(node x, node y)
{ return x.w1<y.w1; }
bool cmp2(node x, node y)
{ return x.w2<y.w2; }
bool cmp3(nodee x, nodee y)
{ return x.bh<y.bh; }
int fnd(int x) {
	if(x==father[x])
		return x;
	else {
		father[x]=fnd(father[x]);
		return father[x];
	}
}
bool mrge(int x, int y) {
	int f1=fnd(x), f2=fnd(y);
	if(f1==f2)
		return false;
	else {
		father[f2]=f1;
		return true;
	}
}
void kruskal1() {
	int step=0;
	for(int i=1; i<=m-1; i++) {
		if(book[road[i].num]==0)
			if(mrge(road[i].u, road[i].v)) {
				book[road[i].num]=1;
				flag++;
				step++;
				minn=max(minn, road[i].w1);
				ans[flag].bh=road[i].num;
				ans[flag].gl=1;
			}
		if(step==k)
			return ;
	}
}
void kruskal2() {
	int step=0;
	for(int i=1; i<=m-1; i++) {
		if(book[road[i].num]==0)
			if(mrge(road[i].u, road[i].v)) {
				book[road[i].num]=1;
				flag++;
				step++;
				minn=max(minn, road[i].w2);
				ans[flag].bh=road[i].num;
				ans[flag].gl=2;
			}
		if(step==n-1-k)
			return ;
	}
}

int main() {
	scanf("%d%d%d", &n, &k, &m);
	memset(book, 0, sizeof(book));
	for(int i=1; i<=n; i++)
		father[i]=i;
	for(int i=1; i<=m-1; i++) {
		scanf("%d%d%d%d", &road[i].u, &road[i].v, &road[i].w1, &road[i].w2);
		road[i].num=i;
	}
	sort(road+1, road+m, cmp1);
	kruskal1();
	sort(road+1, road+m, cmp2);
	kruskal2();
	sort(ans+1, ans+n, cmp3);
	printf("%d\n", minn);
	for(int i=1; i<=n-1; i++)
		printf("%d %d\n", ans[i].bh, ans[i].gl);
	return 0;
}
