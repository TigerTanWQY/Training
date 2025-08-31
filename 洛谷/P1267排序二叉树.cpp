#include<bits/stdc++.h>
using namespace std;

long long n,mp[5][20][40],f[2022][4];
long long vis[2022][4][2022],ans,tot[2022];
bool e[2022][2022];

long long read() {
    long long x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {
        if(ch=='-')y=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9') {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*y;
}

void add_edge(long long u,long long v) {
    if(!e[u][v]) {
        e[u][v]=1;
        f[u][++tot[u]]=v;
    }
    if(!e[v][u]) {
        e[v][u]=1;
        f[v][++tot[v]]=u;
    }
}

long long dp(long long u,long long ll,long long rr) {
    long long fa=1;
    while(f[u][fa]!=rr) fa++;
    if(vis[u][fa][ll]>0) return vis[u][fa][ll];
    long long l,r;
    if(ll<=rr) l=ll,r=rr-1;
    else l=rr+1,r=ll;
    long long lson=0,rson=0;
    for(long long k=1; k<=3; k++)
        if(k!=fa&&l<=f[u][k]&&f[u][k]<=r)
            if(f[u][k]<u) lson=max(lson,dp(f[u][k],l,u));
            else rson=max(rson,dp(f[u][k],r,u));
    vis[u][fa][ll]=lson+rson+1;
    return vis[u][fa][ll];
}

void dfs() {
    for(long long i=1; i<=4*n*n; i++) {
        long long lson=0,rson=0;
        for(long long j=1; j<=3; j++) {
            if(f[i][j]<i) lson=max(lson,dp(f[i][j],1,i));
            else rson=max(rson,dp(f[i][j],4*n*n,i));
        }
        ans=max(ans,lson+rson+1);
    }
}

int main() {
    n=read();
    for(long long k=1; k<=4; k++)
        for(long long i=1; i<=n; i++)
            for(long long j=1; j<=i*2-1; j++)
                mp[k][i][j]=read();

    for(long long k=1; k<=4; k++)
        for(long long i=2; i<n; i++)
            for(long long j=2; j<i*2-1; j++) {
                add_edge(mp[k][i][j],mp[k][i][j-1]);
                add_edge(mp[k][i][j],mp[k][i][j+1]);
                if(j&1) add_edge(mp[k][i][j],mp[k][i+1][j+1]);
                else add_edge(mp[k][i][j],mp[k][i-1][j-1]);
            }
    for(long long k=1; k<=4; k++)
        for(long long i=2; i<=n*2-1; i+=2) {
            add_edge(mp[k][n][i],mp[k][n][i-1]);
            add_edge(mp[k][n][i],mp[k][n][i+1]);
            add_edge(mp[k][n][i],mp[k][n-1][i-1]);
        }
    for(long long i=1; i<=n*2-1; i++) {
        add_edge(mp[1][n][i],mp[4][n-i/2][1]);
        add_edge(mp[2][n][i],mp[4][i/2+1][(i/2+1)*2-1]);
        add_edge(mp[3][n][i],mp[4][n][n*2-i]);
    }
    for(long long i=1,j=1; i<=n; i++,j++) {
        add_edge(mp[1][i][1],mp[3][i][i*2-1]);
        add_edge(mp[2][i][1],mp[1][i][i*2-1]);
        add_edge(mp[3][i][1],mp[2][i][i*2-1]);
    }
    dfs();
    printf("%lld\n",ans);
    return 0;
}
