#include <iostream>
using namespace std;

int a[1003], tot = 1;

int dis(const int x, const int y) {
	int res = 0;
	for(int z = x ^ y; z; z >>= 1)
		res += (z & 1);
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, b, d;
	cin >> n >> b >> d;
	for(int i = 1; i <= 1 << b; ++i)
		if(dis(a[tot], i) >= d) {
			bool flag = true;
			for(int j = 1; j < tot; ++j)
				if(dis(a[j], i) < d) {
					flag = false;
					break;
				}
			if(flag)
				a[++tot] = i;
			if(tot >= n)
				break;
		}
	for(int i = 1; i <= tot; ++i) {
		cout << a[i];
		if(i % 10)
			cout.put(' ');
		else
			cout.put('\n');
	}
	cout.flush();
	return 0;
}