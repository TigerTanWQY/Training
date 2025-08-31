#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace chrono;

constexpr const int N = 500'003;
int n,m,q,cd[N],cd1;
vector<pair<int,bool>> g[N];

inline int read(){
	char c;
	while(c=getchar(),c<'0'||c>'9');
	int x=c^'0';
	while(c=getchar(),c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^'0');
	return x;
}
#define add(u) (!cd[u]?++cd1:(cd[u]==1?--cd1:0)),++cd[u]
#define del(u) --cd[u],(!cd[u]?--cd1:(cd[u]==1?++cd1:0))

int main(){
    auto start = steady_clock::now();
	n=read(),m=read();
	for(int i=1,u,v;i<=m;++i) u=read(),v=read(),g[v].push_back({u,1}),add(u);
	for(int i=1;i<=n;++i) if(g[i].size()>1) sort(g[i].begin(),g[i].end());
	q=read();
	while(q--){
		int mod=read(),u=read(),v;
		if(mod&1){
			v=read();
			auto l=g[v].begin(),r=g[v].end();
			while(r-l>1){
				auto mid=l+((r-l)>>1);
				(*mid).first<=u? l=mid:r=mid;
			}
			if(mod>>1) (*l).second=1,add(u);
			else (*l).second=0,del(u);
		}else if(mod==2){
			for(auto &x:g[u]) if(x.second) x.second=0,del(x.first);
		}else{
			for(auto &x:g[u]) if(!x.second) x.second=1,add(x.first);
		}
		puts(cd1==n?"YES":"NO");
		auto end = steady_clock::now();
		duration<double> elapsed_seconds = end - start;
		if(elapsed_seconds.count() >= 1.96) break;
	}
	if(q>0) while(q--) puts("NO");
	return 0;
}