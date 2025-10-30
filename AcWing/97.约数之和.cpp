#include <iostream>
using namespace std;
typedef long long LL;

const int P = 9901;

int qpow(int a, int b) {
	int res = 1;
	while(b) {
		if(b & 1) res = (LL) res * a % P;
		a = (LL)a * a % P;
		b >>= 1;
	}
	return res;
}
int sum(int p, int k) {
	if(k == 1) return 1;
	if(k & 1) return (qpow(p, k - 1) + sum(p, k - 1)) % P;
	return (1 + qpow(p, k / 2)) * sum(p, k / 2) % P;
}
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	int res = 1;
	for(int i = 2; i <= a / i; ++ i) {
		if(a % i == 0) {
			int s = 0;
			while(a % i == 0) a /= i, ++ s;
			res = (LL) res * sum(i, b * s + 1) % P;
		}
	}
	if(a > 1) res = (LL) res * sum(a, b + 1) % P;
	if(a == 0) res = 0;
	printf("%d\n", res);
	return 0;
}
