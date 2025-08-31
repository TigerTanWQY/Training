#include<bits/stdc++.h>
#define mid ((l+r)>>1)
#define int long long
#define pb push_back
using ll = long long;
const int N = 3e5 + 10 ;
const int M = 1e6 + 10 ;
const ll inf = 9e18 ;
const int mod = 998244353 ;
using namespace std ;
template <typename T>
inline void read(T&x){
	x = 0 ; bool flg = 1 ; char c = getchar() ;
	while(c > '9' || c < '0'){
		if(c == '-')
		flg = 0 ;
		c = getchar() ;
	}
	while(c >= '0' && c <= '9'){
		x = (x << 1) + (x << 3) + (c ^ 48) ;
		c = getchar() ;
	}
	x = flg ? x : -x ;
}
int rt[N<<2],n ;
ll ans[N] ;
vector<int>vc[N<<2] ;
struct qs{int pos,k;};
vector<qs>q[N<<2] ;
struct node{
	int id,ls,rs ;
	inline void clear(){id=ls=rs=0;}
}tr[N*10] ;
int trn,stk[N],top ;
int newnode(){if(top)return tr[stk[top]].clear(),stk[top] ; else return ++trn ;}
struct line{
	ll k,b,l,r ;
	ll val(int x){return k * x + b ;}
}L[N] ;
void chg2(int &x,int l,int r,int id){
	if(!x)x = ++trn , tr[x].clear() ;
	if(!tr[x].id)return tr[x].id=id,void() ;
	else{
		int pid = tr[x].id ;
		if(L[pid].val(mid) < L[id].val(mid)){
			tr[x].id = id ;
			if(L[pid].val(l) > L[id].val(l))chg2(tr[x].ls,l,mid,pid) ;
			if(L[pid].val(r) > L[id].val(r))chg2(tr[x].rs,mid+1,r,pid) ;
		}
		else{
			if(L[id].val(l) > L[pid].val(l))chg2(tr[x].ls,l,mid,id) ;
			if(L[id].val(r) > L[pid].val(r))chg2(tr[x].rs,mid+1,r,id) ;
		}
	}
}
ll qry2(int x,int l,int r,int pos){
	if(!tr[x].id)return -inf ;
	if(pos <= mid)return max(L[tr[x].id].val(pos),qry2(tr[x].ls,l,mid,pos)) ;
	else return max(L[tr[x].id].val(pos),qry2(tr[x].rs,mid+1,r,pos)) ;
}
#define ls x << 1
#define rs x << 1 | 1
void chg1(int x,int l,int r,int L,int R,int k){
	if(L <= l && r <= R)return vc[x].pb(k),void() ;
	if(L <= mid)chg1(ls,l,mid,L,R,k) ;
	if(mid < R)chg1(rs,mid+1,r,L,R,k) ;
}
void add(int x,int l,int r,int pos,int k){
	q[x].pb({pos,k}) ;
	if(l == r)return ;
	if(pos <= mid)add(ls,l,mid,pos,k) ;
	else add(rs,mid+1,r,pos,k) ;
}
void qry1(int x,int l,int r){
	if(!q[x].size())return ;
	int tmp = trn ;
	for(int i = 0 ; i < (int)vc[x].size() ; i++)chg2(rt[x],-1e9,1e9,vc[x][i]) ;
	for(int i = 0 ; i < (int)q[x].size() ; i++)ans[q[x][i].pos] = max(ans[q[x][i].pos],qry2(rt[x],-1e9,1e9,q[x][i].k)) ;
	if(l == r){if(ans[l]==-inf)puts("EMPTY SET");else printf("%lld\n",ans[l]); return;}
	qry1(ls,l,mid),qry1(rs,mid+1,r) ;
	trn = tmp ;
}
#undef ls
#undef rs
signed main(){
	read(n) ;
	for(int i = 1 , opt , k , b ; i <= n ; i++){
		read(opt) ;
		if(opt == 1)read(k),read(b),L[i].k = k,L[i].b=b,L[i].l=i,L[i].r=n ;
		else if(opt == 2)read(k),L[k].r = i - 1 ;
		else read(k),add(1,1,n,i,k),ans[i]=-inf ;
	}
	for(int i = 1 ; i <= n ; i++)if(L[i].l==i)chg1(1,1,n,L[i].l,L[i].r,i) ;
	qry1(1,1,n) ;
	return 0 ;
}
