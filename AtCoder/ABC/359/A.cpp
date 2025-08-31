#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int ans = 0;
	for(string s; n--; ) {
		cin >> s;
		if(s == "Takahashi")
			++ans;
	}
	cout << ans;
	return 0;
}