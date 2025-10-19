#include<stdio.h>
#include<bitset>
#define rev(x) (x>n? (x-n):(x+n))
using namespace std;
const int maxn=1005;
int n;
struct two_sat{
	int m,ok;
	int fixed[maxn<<1];
	bitset<maxn<<1>g[maxn<<1];
	void get(int x){
		fixed[x]=1,fixed[rev(x)]=0;
		for(int i=1;i<=2*n;i++)
			if(g[x][i]&&fixed[i]==-1)
				get(i);
	}
	void build(){
		for(int i=1;i<=2*n;i++)
			g[i].reset(),g[i][i]=1,fixed[i]=-1;
		for(int i=1;i<=m;i++){
			int x,y;
			scanf("%d%d",&x,&y),x=x>0? x:rev(-x),y=y>0? y:rev(-y);
			g[rev(x)][y]=1,g[rev(y)][x]=1;
		}
		for(int k=1;k<=2*n;k++)
			for(int i=1;i<=2*n;i++)
				if(g[i][k])
					g[i]|=g[k];
		for(int i=1;i<=n;i++)
			if(g[i][n+i]&&g[n+i][i]){
				ok=0;
				return ;
			}
		ok=1;
		for(int i=1;i<=n;i++){
			if(fixed[i]==-1&&fixed[n+i]==-1&&g[i][n+i])
				get(n+i);
			if(fixed[i]==-1&&fixed[n+i]==-1&&g[n+i][i])
				get(i);
		}
	}
	void solve(){
		for(int i=1;i<=2*n;i++)
			if(fixed[i]==-1)
				get(i);
		for(int i=1;i<=n;i++)
			printf("%d%c",fixed[i],i==n? '\n':' ');
	}
}A,B;
int main(){
	scanf("%d%d%d",&n,&A.m,&B.m),A.build(),B.build();
	if(A.ok==0&&B.ok==0){
		puts("SIMILAR");
		return 0;
	}
	if(A.ok==0||B.ok==0){
		if(A.ok)
			A.solve();
		if(B.ok)
			B.solve();
		return 0;
	}
	for(int i=1;i<=2*n;i++){
		if(A.fixed[i]!=-1&&B.fixed[i]!=-1&&A.fixed[i]!=B.fixed[i]){
			A.solve();
			return 0;
		}
		if((A.fixed[i]==-1)+(B.fixed[i]==-1)==1){
			if(A.fixed[i]==-1)
				A.get(B.fixed[i]==0? i:rev(i)),A.solve();
			if(B.fixed[i]==-1)
				B.get(A.fixed[i]==0? i:rev(i)),B.solve();
			return 0;
		}
	}
	for(int i=1;i<=2*n;i++)
		for(int j=1;j<=2*n;j++){
			if(A.g[i][j]&&B.g[i][j]==0&&B.fixed[i]==-1&&B.fixed[i]==-1){
				B.get(i),B.get(rev(j)),B.solve();
				return 0;
			}
			if(B.g[i][j]&&A.g[i][j]==0&&A.fixed[i]==-1&&A.fixed[j]==-1){
				A.get(i),A.get(rev(j)),A.solve();
				return 0;
			}
		}
	puts("SIMILAR");
	return 0;
}
