#include <iostream>
using namespace std;

const int N = 2003;
int a[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int ans = 0;
	for(int x = 1, x1, y1, x2, y2; x <= 3; ++x){
		cin >> x1 >> y1 >> x2 >> y2;
		for(int y = x1 + 1000; y < x2 + 1000; ++y)
			for(int z = y1 + 1000; z < y2 + 1000; ++z) {
				if(x < 3) {
					++a[y][z];
					++ans;
				}
				if(a[y][z] && x == 3)
					--ans;
			}
	}
	cout << ans;
	cout << endl;
	return 0;
}