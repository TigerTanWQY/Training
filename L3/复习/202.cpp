#include <iostream>
#include <utility>
using namespace std;
#define L first
#define R second

pair<int, int> a[100003];

void TLR(const int& p) {
	cout << p << ' ';
	if(a[p].L)
		TLR(a[p].L);
	if(a[p].R)
		TLR(a[p].R);
}

void LTR(const int& p) {
	if(a[p].L)
		LTR(a[p].L);
	cout << p << ' ';
	if(a[p].R)
		LTR(a[p].R);
}

void LRT(const int& p) {
	if(a[p].L)
		LRT(a[p].L);
	if(a[p].R)
		LRT(a[p].R);
	cout << p << ' ';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].L >> a[i].R;
	TLR(1);
	cout << '\n';
	LTR(1);
	cout << '\n';
	LRT(1);
	return 0;
}