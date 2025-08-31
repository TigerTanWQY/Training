#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5;
const int MAXB=380;
const int MOD=1e9+7;
int n,m;
struct lbase{
	int a[5];
	lbase(){memset(a,0,sizeof(a));}
	bool insert(int x){
		for(int i=4;~i;i--) if(x>>i&1){
			if(a[i]) x^=a[i];
			else{
				a[i]=x;
				for(int j=0;j<i;j++) if(a[i]>>j&1) a[i]^=a[j];
				for(int j=i+1;j<=4;j++) if(a[j]>>i&1) a[j]^=a[i];
				return 1;
			}
		} return 0;
	}
	int hash(){return (a[4]<<10)|(a[3]<<6)|(a[2]<<3)|(a[1]<<1)|a[0];}
} b[MAXB+5],c[MAXN+5];
int rid[MAXN+5],num=0;
void dfsfind(lbase cur){
	int hs=cur.hash();if(rid[hs]) return;
	else rid[hs]=++num,b[num]=cur;
	for(int i=1;i<=31;i++){
		lbase nxt=cur;
		if(nxt.insert(i)) dfsfind(nxt);
	}
}
int trs[MAXB+5][MAXB+5];
void init_trs(){
	for(int i=1;i<=num;i++) for(int j=1;j<=num;j++){
		lbase tmp=b[i];bool ok=1;
		for(int k=0;k<=4;k++) if(b[j].a[k]) ok&=tmp.insert(b[j].a[k]);
		if(ok) trs[i][j]=rid[tmp.hash()];
	}
}
int hd[MAXN+5],to[MAXN*2+5],val[MAXN*2+5],nxt[MAXN*2+5],ec=0;
void adde(int u,int v,int w){to[++ec]=v;val[ec]=w;nxt[ec]=hd[u];hd[u]=ec;}
int bel[MAXN+5],dis[MAXN+5],ok[MAXN+5],cmp=0,con[MAXN+5],fst[MAXN+5];
bool is[MAXN+5];int dfn[MAXN+5],tim=0;
void dfs(int x,int f){
	bel[x]=cmp;dfn[x]=++tim;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e],z=val[e];if(y==1) continue;
		if(!bel[y]) dis[y]=dis[x]^z,dfs(y,x);
		else if(y!=f&&dfn[x]>dfn[y]) ok[cmp]&=c[cmp].insert(dis[x]^dis[y]^z);
	}
}
int dp[MAXN+5][MAXB+5];
int main(){
	scanf("%d%d",&n,&m);dfsfind(*new(lbase));init_trs();
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		adde(u,v,w);adde(v,u,w);
	} //printf("%d\n",num);
	for(int e=hd[1];e;e=nxt[e]){
		int y=to[e],z=val[e];
		if(!bel[y]){
			cmp++;ok[cmp]=1;con[cmp]=z;
			fst[cmp]=y;dfs(y,-1);
		} else {
			for(int ee=hd[y];ee;ee=nxt[ee]){
				int v=to[ee],w=val[ee];
				if(v==fst[bel[y]]){
					is[bel[y]]=1;con[bel[y]]^=w^z;
					break;
				}
			}
		}
	}
	dp[0][rid[0]]=1;
	for(int i=1;i<=cmp;i++){
		for(int j=1;j<=num;j++) dp[i][j]=dp[i-1][j];
		if(!ok[i]) continue;
		if(!is[i]){
			int id=rid[c[i].hash()];
			for(int j=1;j<=num;j++) if(trs[j][id]){
				dp[i][trs[j][id]]=(dp[i][trs[j][id]]+dp[i-1][j])%MOD;
			}
		} else {
			int id1=rid[c[i].hash()];
			bool ok=c[i].insert(con[i]);
			int id2=rid[c[i].hash()];
			for(int j=1;j<=num;j++){
				if(trs[j][id1]) dp[i][trs[j][id1]]=(dp[i][trs[j][id1]]+2*dp[i-1][j]%MOD)%MOD;
				if(ok&&trs[j][id2]) dp[i][trs[j][id2]]=(dp[i][trs[j][id2]]+dp[i-1][j]%MOD)%MOD;
			}
		}
	} int ans=0;
	for(int i=1;i<=num;i++) ans=(ans+dp[cmp][i])%MOD;
	printf("%d\n",ans);
	return 0;
}
