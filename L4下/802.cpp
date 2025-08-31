#include <iostream>
#include <bitset>
using namespace std;

const int N = 2003;
bitset<N> A, B;
int a[N], b[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n1, n2, m;
	cin >> n1 >> n2 >> m;
	for(int i = 1; i <= n1; ++i)
		cin >> a[i];
	for(int i = 1; i <= n2; ++i)
		cin >> b[i];
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n1; ++j)
			if(i >= a[j] && !B[i - a[j]]) {
				A[i] = true;
				break;
			}
		for(int j = 1; j <= n2; ++j)
			if(i >= b[j] && !A[i - b[j]]) {
				B[i] = true;
				break;
			}
		if(A[i])
			cout << "Alice\n";
		else
			cout << "Bob\n";
	}
	cout.flush();
	return 0;
}