#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int INF=1e9,N=5e5+3;
struct node{
  int l,r,x,id,v;
  bool operator <(const node &tmp)const
  { return x<tmp.x; }
}s1[N],s2[N];
int n,m,p1,p2;
int k[N],q[N],top;
int L[N],R[N];
LL ans[N],c1[N],c2[N];
int lb(int x)
{ return x&(-x); }
void add(int x,int y)
{ if(x) for(int i=x;i<=n;i+=lb(i)) c1[i]+=y,c2[i]+=(LL)x*y; }
LL sum(int x) {
  LL num=0;
  for(int i=x;i>0;i-=lb(i)) num+=(x+1)*c1[i]-c2[i];
  return num;
}
int main() {
  scanf("%d%d%d%d",&n,&m,&p1,&p2);
  k[0]=k[n+1]=n+1;q[++top]=0;
  for(int i=1;i<=n;i++) scanf("%d",&k[i]);
  for(int i=1;i<=n+1;i++) {
      while(k[q[top]]<k[i]) R[q[top]]=i,top--;
      L[i]=q[top];q[++top]=i;
    }
  int x,y;
  for(int i=1;i<=m;i++) {
      scanf("%d%d",&x,&y);ans[i]+=(y-x)*p1;
      s1[i]={x,y,x-1,i,-1};s1[i+m]={x,y,y,i,1};
    }
  sort(s1+1,s1+2*m+1);int tot=0;
  for(int i=1;i<=n;i++) {
      if(1<=L[i]&&R[i]<=n) s2[++tot]={L[i],L[i],R[i],0,p1};
      if(1<=L[i]&&R[i]>i+1) s2[++tot]={i+1,R[i]-1,L[i],0,p2};
      if(L[i]+1<i&&R[i]<=n) s2[++tot]={L[i]+1,i-1,R[i],0,p2};
    }
  sort(s2+1,s2+tot+1);int n1=1,n2=1;
  while(!s1[n1].x) n1++;
  for(int i=1;n1<=m*2&&i<=n;i++) {
      while(n2<=tot&&s2[n2].x==i){
    add(s2[n2].r+1,-s2[n2].v);
    add(s2[n2].l,s2[n2].v);
    n2++;
      }
      while(n1<=m*2&&s1[n1].x==i){
    ans[s1[n1].id]+=s1[n1].v*(sum(s1[n1].r)-sum(s1[n1].l-1));
    n1++;
      }
    }
  for(int i=1;i<=m;i++) printf("%lld\n",ans[i]);
  return 0;
}
