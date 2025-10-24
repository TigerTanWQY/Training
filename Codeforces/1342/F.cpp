#include <bits/stdc++.h>
using namespace std;

struct Node
{ int i,p,s; }
fa[15][15][1<<15];
int A[15], sum[1<<15], F[16][16][1<<15],id[15],T,N;

void upd(Node u,Node v,int k) {
	F[v.i][v.p][v.s]=min(F[v.i][v.p][v.s],k);
	if(F[v.i][v.p][v.s]==k) fa[v.i][v.p][v.s]=u;
}

int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		for(int i=0; i<N; ++i)
			scanf("%d",&A[i]);
		for(int s=0; s<(1<<N); s++) {
			sum[s]=0;
			for(int i=0; i<N; ++i)
				if((s&(1<<i))!=0)
					sum[s]+=A[i];
		}
		for(int i=0; i<=N; ++i)
			for(int p=0; p<=N; p++)
				for(int s=0; s<(1<<N); s++)
					F[i][p][s]=0x3f3f3f3f;
		F[0][0][0]=0;
		for(int i=0; i<N; ++i)
			for(int p=0; p<N; p++)
				for(int s=0; s<(1<<N); s++)
					if(F[i][p][s]!=0x3f3f3f3f) {
						Node u{i,p,s};
						int ns=((1<<N)-1)^s;
						for(int s0=ns; s0; s0=(s0-1)&ns) if(sum[s0]>F[i][p][s]&&(s0>>p)!=0) {
								Node v{i+1,p+1+__builtin_ctz(s0>>p),s|s0};
								upd(u,v,sum[s0]);
							}
					}

		Node ans{-1,-1,-1};
		for(int i=N; i>=1; i--) {
			for(int p=1; p<=N; p++)
				if(F[i][p][(1<<N)-1]!=0x3f3f3f3f) {
					ans = {i,p,(1<<N)-1};
					break;
				}
			if(ans.i!=-1)
				break;
		}
		printf("%d\n",N-ans.i);
		for(int i=0; i<N; ++i)
			id[i]=i+1;
		while(ans.i!=0) {
			Node par=fa[ans.i][ans.p][ans.s];
			int s0=par.s^ans.s;
			for(int i=0; i<N; ++i)
				if((s0&(1<<i))!=0&&i!=ans.p-1) {
					printf("%d %d\n",id[i],id[ans.p-1]);
					for(int j=i+1; j<N; j++)
						--id[j];
				}
			ans=par;
		}
	}
	return 0;
}
