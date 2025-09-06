#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int P = 1e9 + 7, N = 2e5 + 3;
vector<int> G[N];
bitset<N> vis, col; bool flg;
int c[N], f[2], g[2];
LL fac[N], inv[N];

LL qpow(LL a, LL b = P - 2) {
	LL res = 1;
	for(; b; a = a * a % P, b >>= 1)
		if(b & 1)
			res = res * a % P;
	return res;
}

LL C(int x, int y) {
	if(x < 0 || y < 0 || y > x)
		return 0;
	return fac[x] * inv[y] % P * inv[x - y] % P;
}

void dfs(int u, bool d) {
	if(vis[u]) {
		flg &= (col[u] == d);
		return;
	}
	vis[u] = true;
	col[u] = d;
	++f[d]; g[d] += c[u];
	for(const auto& v: G[u])
		dfs(v, d ^ true);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = inv[0] = fac[0] = 1; i <= n; ++i)
		inv[i] = qpow(fac[i] = fac[i - 1] * i % P);
	for(int i = 1; i <= n; ++i)
		cin >> c[i];
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	LL ans = 1;
	for(int u = 1; u <= n; ++u)
		if(!vis[u]) {
			f[0] = f[1] = g[0] = g[1] = 0; flg = true;
			dfs(u, false);
			LL tot = 0;
			if(flg)
				for(int i = 0; i <= f[1]; ++i)
					tot = (tot + C(f[0], i + g[0] - g[1]) * C(f[1], i)) % P;
			else {
				int s = f[0] + f[1];
				for(int i = g[1] % 2; i <= s; i += 2)
					tot = (tot + C(s, i)) % P;
			}
			ans = ans * tot % P;
		}
	cout << ans << endl;
	return 0;
}
/*
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=2e5+5,MOD=1e9+7;
ll ksm(ll a,ll b=MOD-2) { ll s=1; for(;b;a=a*a%MOD,b>>=1) if(b&1) s=s*a%MOD; return s; }
ll fac[MAXN],ifac[MAXN];
ll C(int x,int y) {
	if(x<0||y<0||y>x) return 0;
	return fac[x]*ifac[y]%MOD*ifac[x-y]%MOD;
}
int n,m,f[2],g[2],w[MAXN];
bool vis[MAXN],col[MAXN],flg;
vector <int> G[MAXN];
void dfs(int u,int c) {
	if(vis[u]) return flg&=(col[u]==c),void();
	vis[u]=true,col[u]=c,++f[c],g[c]+=w[u];
	for(int v:G[u]) dfs(v,c^1);
}
signed main() {
	scanf("%d%d",&n,&m);
	for(int i=ifac[0]=fac[0]=1;i<=n;++i) ifac[i]=ksm(fac[i]=fac[i-1]*i%MOD);
	for(int i=1;i<=n;++i) scanf("%d",&w[i]);
	for(int i=1,u,v;i<=m;++i) scanf("%d%d",&u,&v),G[u].push_back(v),G[v].push_back(u);
	ll ans=1;
	for(int u=1;u<=n;++u) if(!vis[u]) {
		f[0]=f[1]=g[0]=g[1]=0,flg=1,dfs(u,0);
		ll sum=0;
		if(flg) {
			for(int i=0;i<=f[1];++i) {
				sum=(sum+C(f[0],i+g[0]-g[1])*C(f[1],i))%MOD;
			}
		} else {
			int s=f[0]+f[1];
			for(int i=g[1]%2;i<=s;i+=2) {
				sum=(sum+C(s,i))%MOD;
			}
		}
		ans=ans*sum%MOD;
	}
	printf("%lld\n",ans);
	return 0;
}
*/
