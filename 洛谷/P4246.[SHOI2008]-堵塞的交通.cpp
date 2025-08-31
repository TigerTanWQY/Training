#include<bits/stdc++.h>
using namespace std;

const int N=4e5 + 3;
#define lson u<<1,l,mid
#define rson u<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))

struct node{
	int lft,rig;
	bool l,r,u,d,p,q;
}seg[N];
int n;
bool conn[N][2];
void pushup(node &x,node l,node r){
	x.lft=l.lft;
	x.rig=r.rig;
	x.l=l.l|(l.u&conn[l.rig][0]&r.l&conn[l.rig][1]&l.d);
	x.r=r.r|(r.u&conn[l.rig][0]&l.r&conn[l.rig][1]&r.d);
	x.u=(l.u&conn[l.rig][0]&r.u)|(l.p&conn[l.rig][1]&r.q);
	x.d=(l.d&conn[l.rig][1]&r.d)|(l.q&conn[l.rig][0]&r.p);
	x.p=(l.u&conn[l.rig][0]&r.p)|(l.p&conn[l.rig][1]&r.d);
	x.q=(l.d&conn[l.rig][1]&r.q)|(l.q&conn[l.rig][0]&r.u);
}
void build(int u,int l,int r){
	if(l==r){
		seg[u].lft=seg[u].rig=l;
		seg[u].u=seg[u].d=1;
		return;
	}
	int mid=(l+r)>>1;
	build(lson);build(rson);
	pushup(seg[u],seg[u<<1],seg[u<<1|1]);
}
void modify1(int u,int l,int r,int p,int row,bool val){
	int mid=(l+r)>>1;
	if(mid==p){
		conn[mid][row]=val;
		pushup(seg[u],seg[u<<1],seg[u<<1|1]);
		return;
	}
	if(mid>=p) modify1(lson,p,row,val);
	else modify1(rson,p,row,val);
	pushup(seg[u],seg[u<<1],seg[u<<1|1]);
}
void modify2(int u,int l,int r,int p,bool val){
	if(l==r){
		seg[u].l=seg[u].r=seg[u].p=seg[u].q=val;
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=p) modify2(lson,p,val);
	else modify2(rson,p,val);
	pushup(seg[u],seg[u<<1],seg[u<<1|1]);
}
node query(int u,int l,int r,int ql,int qr){
	if(l>=ql && r<=qr) return seg[u];
	int mid=(l+r)>>1;
	if(mid<ql) return query(rson,ql,qr);
	if(mid>=qr) return query(lson,ql,qr);
	node ans;
	pushup(ans,query(lson,ql,qr),query(rson,ql,qr));
	return ans;
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n; char op[10];
	build(1,1,n);
	while(cin >> op && op[0]!='E'){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		switch(op[0]){
			case 'C':
				if(a==c) modify1(1,1,n,min(b,d),a-1,0);
				else modify2(1,1,n,b,0);
				break;
			case 'O':
				if(a==c) modify1(1,1,n,min(b,d),a-1,1);
				else modify2(1,1,n,b,1);
				break;
			case 'A':
				if(b>d) swap(a,c),swap(b,d);
				node ans1=query(1,1,n,b,d),ans2=query(1,1,n,1,b),ans3=query(1,1,n,d,n);
				bool flag=false;
				if(a==1)
					if(c==1){
						if(ans1.u) flag=true;
						if(ans2.r&ans1.d&ans3.l) flag=true;
					}else{
						if(ans1.p) flag=true;
						if(ans2.r&ans1.d) flag=true;
						if(ans3.l&ans1.u) flag=true;
					}
				else
					if(c==1){
						if(ans1.q) flag=true;
						if(ans2.r&ans1.u) flag=true;
						if(ans3.l&ans1.d) flag=true;
					}else{
						if(ans1.d) flag=true;
						if(ans2.r&ans1.u&ans3.l) flag=true;
					}
			cout.put(flag?'Y':'N').put('\n');
		}
	}
	cout.flush();
	return 0;
}
