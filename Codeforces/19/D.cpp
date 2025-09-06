#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e5 + 3;
int n;
vector<int>X,Y;
struct cmd{
	char opt[7];
	int x,y;
}q[N];
int d[N<<2];
set<int>b[N];

void modify(int l,int r,int o,const int&pos,const int&ch){
	if(l==r)d[o]=ch;else{
		const int mid=l+r>>1;
		if(pos<=mid)modify(l,mid,o<<1,pos,ch);else
		modify(mid+1,r,o<<1|1,pos,ch);
		d[o]=max(d[o<<1],d[o<<1|1]);
	}
}
void query(int l,int r,int o,const int&X,const int&Y,int&x){
	if(l==r){
		if(d[o]>=Y)
		x=l;return;
	}
	const int mid=l+r>>1;
	if(X<=mid&&d[o<<1]>=Y)query(l,mid,o<<1,X,Y,x);
	if(~x)return;
	if(d[o<<1|1]>=Y)query(mid+1,r,o<<1|1,X,Y,x);
}
void build(int l,int r,int o){
	d[o]=-1;
	if(l<r){
		const int mid=l+r>>1;
		build(l,mid,o<<1),build(mid+1,r,o<<1|1);
	}
}
int main(){
	X.emplace_back(-1),Y.emplace_back(-1);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n;
	build(1,n,1);
	for(int i=1;i<=n;++i){
		cin>>q[i].opt>>q[i].x>>q[i].y;
		if(*q[i].opt=='f')++q[i].x,++q[i].y;
		X.emplace_back(q[i].x),Y.emplace_back(q[i].y);
		b[i].insert(-1);
	}
	sort(X.begin(),X.end());
	sort(Y.begin(),Y.end());
	X.erase(unique(X.begin(),X.end()),X.cend());
	Y.erase(unique(Y.begin(),Y.end()),Y.cend());
	for(int i=1;i<=n;++i){
		q[i].x=lower_bound(X.cbegin(),X.cend(),q[i].x)-X.cbegin();
		q[i].y=lower_bound(Y.cbegin(),Y.cend(),q[i].y)-Y.cbegin();
		if(*q[i].opt=='a'){
			int mx=*b[q[i].x].crbegin();
			if(mx<q[i].y)modify(1,n,1,q[i].x,q[i].y);
			b[q[i].x].insert(q[i].y);
		}else
		if(*q[i].opt=='r'){
			b[q[i].x].erase(b[q[i].x].find(q[i].y));
			modify(1,n,1,q[i].x,*b[q[i].x].crbegin());
		}else{
			int x=-1;
			query(1,n,1,q[i].x,q[i].y,x);
			if(x==-1)cout<<"-1\n";else
			cout<<X[x]<<' '<<Y[*b[x].lower_bound(q[i].y)]<<'\n';
		}
	}
	return 0;
}
