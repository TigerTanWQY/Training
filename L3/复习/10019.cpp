#include <iostream>
#include <vector>
using namespace std;

constexpr const int N = 13;
int a[N][N], b[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n1, n2, m1, m2;
	cin >> n1 >> m1;
	for(int i = 1; i <= n1; ++i)
		for(int j = 1; j <= m1; ++j)
			cin >> a[i][j];
	cin >> n2 >> m2;
	for(int i = 1; i <= n2; ++i)
		for(int j = 1; j <= m2; ++j)
			cin >> b[i][j];
	for(int i = 0; i < 1 << n1; ++i)
		for(int j = 0; j < 1 << m1; ++j) {
			vector<int> ah, aw;
			for(int k = 1; k <= n1; ++k)
				if(!(i >> (k - 1) & 1))
					ah.push_back(k);
			for(int k = 1; k <= m1; ++k)
				if(!(j >> (k - 1) & 1))
					aw.push_back(k);
			if(ah.size() != n2 || aw.size() != m2)
				continue;
			bool flag = true;
			for(int k = 1; k <= n2; ++k)
				for(int l = 1; l <= m2; ++l)
					if(a[ah[k - 1]][aw[l - 1]] != b[k][l]) {
						flag = false;
						break;
					}
			if(flag) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	cout << "No" << endl;
	return 0;
}