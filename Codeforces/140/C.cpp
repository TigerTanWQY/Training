#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;

const int N=100010;
struct node{
	int val,cnt;
	bool operator<(const node&b)const&{
		return cnt<b.cnt;
	}
}a[N];
bool cmp(node x,node y){return x.val<y.val;}
__gnu_pbds::priority_queue<node>q;
int n,ans[N][3],k;

void init(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].val,
		a[i].cnt=1;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		if(a[k].val!=a[i].val)a[++k]=a[i];
		else a[k].cnt++;
	n=k;
	k=0;
	for(int i=1;i<=n;i++)q.push(a[i]);
}
signed main(){
	init();
	while(q.size()>=3){
		node t[3];
		k++;
		for(int i=0;i<3;i++)
			t[i]=q.top(),
			ans[k][i]=t[i].val,
			q.pop();
		for(int i=2;i>=0;i--)
			if(t[i].cnt>1)q.push({t[i].val,t[i].cnt-1});
	}
	cout<<k<<endl;
	for(int i=1;i<=k;i++)
		sort(ans[i],ans[i]+3),
		cout<<ans[i][2]<<' '<<ans[i][1]<<' '<<ans[i][0]<<endl;
	return 0;
}
