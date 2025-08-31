#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int a[7], cnt[14]{};
	for(int i = 0; i < 7; ++i)
	{ cin >> a[i]; ++cnt[a[i]]; }
	for(int i = 1; i <= 13; ++i)
		for(int j = 1; j <= 13; ++j)
			if(i != j && cnt[i] >= 3 && cnt[j] >= 2)
			{ cout << "Yes" << endl; return 0; }
	cout << "No" << endl;
	return 0;
}
