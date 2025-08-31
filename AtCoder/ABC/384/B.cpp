#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, R;
	cin >> n >> R;
	for(int tp, w; n--; ) {
		cin >> tp >> w;
		if(tp == 1) {
			if(1600 <= R && R <= 2799)
				R += w;
		} else {
			if(1200 <= R && R <= 2399)
				R += w;
		}
	}
	cout << R << endl;
	return 0;
}
