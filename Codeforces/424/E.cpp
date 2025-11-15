#include <bits/stdc++.h>
using namespace std;
using ULL = unsigned long long;

int n, a[100][5], t[100];
struct Node {
	ULL w;
	double p;
	int nxt;
} c[5000000];
int hd[5000000], cnt;

ULL gethash() {
	for(int i=1; i<=n; i++) {
		t[i]=0;
		if(i!=n&&(!a[i][2]||(!a[i][1]&&!a[i][3])))continue;
		bool flag=false;
		if(a[i][1]>a[i][3])
			swap(a[i][1], a[i][3]), flag=true;
		for(int j=1; j<=3; j++)
			t[i]|=a[i][j]<<(j-1<<1);
		if(flag)swap(a[i][1], a[i][3]);
	}
	sort(t+1, t+n);
	ULL tmp=0;
	for(int i=1; i<=n; i++)
		if(t[i])
		{ tmp<<=6; tmp|=t[i]; }
	return tmp;
}

int getid(ULL val) {
	int hdid=val%5000000;
	for(int i=hd[hdid]; i; i=c[i].nxt)
		if(c[i].w==val)return i;
	c[++cnt]= {val, -1, hd[hdid]};
	hd[hdid]=cnt;
	return cnt;
}

double dfs(ULL now) {
	int id=getid(now);
	if(c[id].p>=0)return c[id].p;
	double error=1/6.0, sum=0;
	for(int color=1; color<=3; color++) {
		double p=1.0/(color==1?6:3), minn=1e10;
		for(int i=1; i<n; i++)
			for(int j=1; j<=3; j++) {
				if(a[i][j]!=color)continue;
				if(j==2&&(!a[i][1]||!a[i][3]))continue;
				if(j!=2&&!a[i][2])continue;
				a[i][j]=0;
				bool flag=false;
				if(a[n][1]&&a[n][2]&&a[n][3])n++, flag=true;
				for(int k=1; k<=3; k++) {
					if(a[n][k])continue;
					a[n][k]=color;
					minn=min(minn, dfs(gethash())+1.0);
					a[n][k]=0;
				}
				if(flag)n--;
				a[i][j]=color;
			}
		if(minn>1e9)error+=p;
		else sum+=p*minn;
	}
	if(error>0.99)return c[id].p=0;
	else return c[id].p=(sum+error*1.0)/(1-error);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= 3; ++j) {
			char ch;
			cin >> ch;
			if(ch == 'R')
				a[i][j] = 1;
			else if(ch == 'G')
				a[i][j] = 2;
			else if(ch == 'B')
				a[i][j] = 3;
		}
		if(a[i][1] > a[i][3])
			swap(a[i][1], a[i][3]);
	}
	cout << fixed << setprecision(9) << dfs(gethash()) << endl;
	return 0;
}
