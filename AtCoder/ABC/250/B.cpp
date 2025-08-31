#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a, b;
	cin >> n >> a >> b;
	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= a; ++i) {
			for(int l = 1; l <= n; ++l)
				for(int j = 1; j <= b; ++j)
					if((k & 1) ^ (l & 1))
						cout << '#';
					else
						cout << '.';
			cout << '\n';
		}
	return 0;
}