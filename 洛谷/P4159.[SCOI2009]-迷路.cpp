#include<bits/stdc++.h>
using namespace std;
const int N=128, mo=2009;
int n,T;
struct mat{
	int a[N][N];
	void clr(){
		memset(a,0,sizeof(a));
	}
}a;
mat operator *(mat a,mat b){
	mat re;
	re.clr();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				re.a[i][j]=(re.a[i][j]+a.a[i][k]*b.a[k][j]%mo)%mo;
	return re;
}
mat operator ^(mat a,int b){
	mat re;re.clr();
	for(int i=1;i<=n;i++)re.a[i][i]=1;
	while(b){
		if(b&1)re=re*a;
		a=a*a;
		b>>=1;
	}
	return re;
}
int main(){
	scanf("%d%d",&n,&T);
	int n1=n;
	n=n*9;
	for(int i=1;i<=n1;i++)
		for(int j=1;j<=8;j++)
			a.a[9*(i-1)+j][9*(i-1)+j+1]=1;
	char s[32];
	for(int i=1;i<=n1;i++){
		scanf("%s",s+1);
		for(int j=1;j<=n1;j++)
			if(s[j]>'0')
				a.a[9*(i-1)+s[j]-'0'][9*(j-1)+1]=1;
	}
	a=a^T;
	printf("%d",a.a[1][n1*9-8]);
	return 0;
}
