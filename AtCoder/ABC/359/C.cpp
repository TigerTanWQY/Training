#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
using LL = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	LL sx, sy, ex, ey;
	cin >> sx >> sy >> ex >> ey;
	LL dx = llabs(ex - sx), dy = llabs(ey - sy);
	if(sy > ey) {
		swap(sx, ex);
		swap(ex, ey);
	}
	if(sx < ex) {
		if((sx & 1) ^ (sy & 1))
			++dx;
		else if(!((ex & 1) ^ (ey & 1)))
			++dx;
	} else
		if((sx & 1) ^ (sy & 1)) {
			if((ex & 1) ^ (ey & 1))
				++dx;
		}
		else
			++dx;
	cout << max(0LL, dx - dy) / 2 + dy;
	return 0;
}