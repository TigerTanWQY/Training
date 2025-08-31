#include <iostream>
#include <string>
using namespace std;

const int N = 33;
long long f[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	long long k;
	cin >> a >> b >> k;
	f[0][0] = 1;
	for(int i = 0; i <= a; ++i)
		for(int j = 0; j <= b; ++j) {
			if(i)
				f[i][j] += f[i - 1][j];
			if(j)
				f[i][j] += f[i][j - 1];
		}
	while(a && b)
		if(k <= f[a - 1][b]) {
			cout << 'a';
            --a;
        } else {
            k -= f[a - 1][b];
            cout << 'b';
            --b;
        }
    cout << string(a, 'a') << string(b, 'b');
    cout << endl;
    return 0;
}