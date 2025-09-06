#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n;
int a[N],g[N];
int f[N][18],Log[N];
void init(){
	for(int i=2;i<=n;i++) Log[i]=Log[i>>1]+1;
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			f[i][j]=__gcd(f[i][j-1],f[i+(1<<j-1)][j-1]);
		}
	}
}
int rmq(int l,int r){
	int Lg=Log[r-l+1];
	return __gcd(f[l][Lg],f[r-(1<<Lg)+1][Lg]);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		f[i][0]=a[i];
	}
	init();
	if(a[1]==1) g[1]=1;
	printf("%d ",g[1]);
	for(int i=2;i<=n;i++){
		int l=1,r=i,ans=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(rmq(mid,i)==i-mid+1){
				ans=mid;
				break;
			}
			if(rmq(mid,i)<i-mid+1) l=mid+1;
			else r=mid-1;
		}
		if(ans) g[i]=max(g[i-1],g[ans-1]+1);
		else g[i]=g[i-1];
		printf("%d ",g[i]);
	}
	return 0;
}
