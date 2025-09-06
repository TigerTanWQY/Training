#include<iostream>
using namespace std;
int f,nfeed[30],type,t[30][30],m=20,mx[30],ans[30];
bool cz(int x) {
	for(int i=1;i<=f;i++) {
		int he=0;
		for(int j=1;j<=x;j++)
			he+=t[ans[j]][i];
		if(he<nfeed[i]) return false;
	}
	return true;
}
void dfs(int pos,int z) {
	if(pos>type) {
		if(cz(z) && z<m) {
			m=z;
			for(int i=1;i<=z;i++)
				mx[i]=ans[i];
		}
		return;
	}
	ans[z+1]=pos;
	dfs(pos+1,z+1);
	dfs(pos+1,z);
}
int main() {
	cin>>f;
	for(int i=1;i<=f;i++)
		cin>>nfeed[i];
	cin>>type;
	for(int i=1;i<=type;i++)
		for(int j=1;j<=f;j++)
			cin>>t[i][j];
	dfs(1,0);
	cout<<m<<" ";
	for(int i=1;i<=m;i++)
		cout<<mx[i]<<" ";
	cout<<endl;
	return 0;
}
