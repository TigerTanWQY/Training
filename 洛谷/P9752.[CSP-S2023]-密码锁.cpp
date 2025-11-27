#include <iostream>
using namespace std;

constexpr const int P = 10;
int f[P+3][P+3][P+3][P+3][P+3];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int a, b, c, d, e; n--; ) {
		cin >> a >> b >> c >> d >> e;
		for(int j = 1; j < 10; ++j) {
			++f[(a+j)%P][b][c][d][e];
			++f[a][(b+j)%P][c][d][e];
			++f[a][b][(c+j)%P][d][e];
			++f[a][b][c][(d+j)%P][e];
			++f[a][b][c][d][(e+j)%P];
			++f[(a+j)%P][(b+j)%P][c][d][e];
			++f[a][(b+j)%P][(c+j)%P][d][e];
			++f[a][b][(c+j)%P][(d+j)%P][e];
			++f[a][b][c][(d+j)%P][(e+j)%P];
		}
	}
	int ans = 0;
	for(int a = 0; a < 10; ++a)
		for(int b = 0; b < 10; ++b)
			for(int c = 0; c < 10; ++c)
				for(int d = 0; d < 10; ++d)
					for(int e = 0; e < 10; ++e)
						if(f[a][b][c][d][e] == n)
							++ans;
	cout << ans << endl;
	return 0;
}
