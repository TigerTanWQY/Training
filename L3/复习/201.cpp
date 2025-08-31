#include <iostream>
using namespace std;

int n;

void TLR(const int& p) {
	cout << p << ' ';
	if(p + p <= n)
		TLR(p + p);
	if(p + p + 1 <= n)
		TLR(p + p + 1);
}

void LTR(const int& p) {
	if(p + p <= n)
		LTR(p + p);
	cout << p << ' ';
	if(p + p + 1 <= n)
		LTR(p + p + 1);
}

void LRT(const int& p) {
	if(p + p <= n)
		LRT(p + p);
	if(p + p + 1 <= n)
		LRT(p + p + 1);
	cout << p << ' ';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	TLR(1);
	cout << '\n';
	LTR(1);
	cout << '\n';
	LRT(1);
	return 0;
}