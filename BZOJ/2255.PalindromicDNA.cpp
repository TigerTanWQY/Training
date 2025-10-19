#include <bits/stdc++.h>
using namespace std;

const int N=100010,M=N*4,E=2000000;
int n,m,i,j,k,cnt,a[N][2],b[N][2],p[N],g[2][M],v[2][E],nxt[2][E],ed,q[M],t,f[M];
bool vis[M];char s[N];

void read(int&a){char c;while(!(((c=getchar())>='0')&&(c<='9')));a=c-'0';while(((c=getchar())>='0')&&(c<='9'))(a*=10)+=c-'0';}
int getid(char x){
  if(x=='A')return 0;
  if(x=='G')return 1;
  if(x=='T')return 2;
  return 3;
}
void add(int x,int y){
  v[0][++ed]=y;nxt[0][ed]=g[0][x];g[0][x]=ed;
  v[1][ed]=x;nxt[1][ed]=g[1][y];g[1][y]=ed;
}
void add2(int x,int y){add(x,y),add(y,x);}
void check(int x,int y){
  if(s[x]<s[y])swap(x,y);
  int w=s[x]-s[y];
  if(w==3)w=1,swap(x,y);
  if(!w){
    add2(a[x][0],a[y][0]);
    add2(a[x][1],a[y][1]);
    add2(b[x][0],b[y][0]);
    add2(b[x][1],b[y][1]);
    return;
  }
  if(w==1){
    add2(a[x][0],a[y][1]);
    add2(a[x][1],a[y][0]);
    add(a[x][1],b[x][0]);
    add(b[x][1],a[x][0]);
    add(a[y][1],b[y][1]);
    add(b[y][0],a[x][0]);
    return;
  }
  add(a[x][0],a[x][1]);
  add(a[y][0],a[y][1]);
  add2(b[x][0],b[y][1]);
  add2(b[x][1],b[y][0]);
}
void dfs1(int x){
  vis[x]=1;
  for(int i=g[0][x];i;i=nxt[0][i])if(!vis[v[0][i]])dfs1(v[0][i]);
  q[++t]=x;
}
void dfs2(int x,int y){
  vis[x]=0;f[x]=y;
  for(int i=g[1][x];i;i=nxt[1][i])if(vis[v[1][i]])dfs2(v[1][i],y);
}
int main(){
  while(~scanf("%d%d",&n,&m)){
    if(!n)return 0;
    scanf("%s",s);
    for(i=0;i<n;i++)s[i]=getid(s[i]);
    for(cnt=i=0;i<n;i++)for(j=0;j<2;j++)a[i][j]=++cnt,b[i][j]=++cnt;
    for(ed=0,i=1;i<=cnt;i++)g[0][i]=g[1][i]=0;
    for(i=0;i<n;i++){
      if(i)add(a[i][1],a[i-1][0]);
      if(i+1<n)add(a[i][1],a[i+1][0]);
    }
    while(m--){
      read(k);
      for(i=0;i<k;i++)read(p[i]);
      for(i=0,j=k-1;i<j;i++,j--)check(p[i],p[j]);
    }
    for(t=0,i=1;i<=cnt;i++)if(!vis[i])dfs1(i);
    for(i=cnt;i;i--)if(vis[q[i]])dfs2(q[i],q[i]);
    for(i=0;i<n;i++)if(f[a[i][0]]==f[a[i][1]])break;
    puts(i<n?"NO":"YES");
  }
  return 0;
}
