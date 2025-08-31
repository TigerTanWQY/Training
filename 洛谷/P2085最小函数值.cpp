#include <iostream>
#include <utility>
#include <queue>
using namespace std;
using PII = pair<int, int>;

const int N = 10003;
struct Parameter
{ int a, b, c; }
a[N];
struct Data {
	int ans, x, id;
	bool operator<(const Data& A) const
	{ return ans > A.ans; }
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	priority_queue<Data> q;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].a >> a[i].b >> a[i].c;
		q.push({a[i].a + a[i].b + a[i].c, 1, i});
	}
	while(m--) {
		auto f = q.top();
		q.pop();
		cout << f.ans << ' ';
		++f.x;
		f.ans = a[f.id].a * f.x * f.x + a[f.id].b * f.x + a[f.id].c;
		q.push(f);
	}
	return 0;
}
/*
#include<bits/stdc++.h>
#include<vector>
#define ll long long
#define N 10000
#define M 100
using namespace std;
ll n,m,a,b,c;
vector<ll> f;
int main(){
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a>>b>>c;
		for(ll k=1;k<=M;k++){
			f.push_back(a*k*k+b*k+c);
		}
	}
	sort(f.begin(),f.end());
	for(ll i=0;i<m;i++) cout<<f[i]<<' ';
	return 0;
}
*/