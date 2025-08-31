#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string ans;
	for(string s; n--; ) {
		cin >> s;
		if(s == "<bs>") {
			if(!ans.empty())
				ans.pop_back();
		}
		else
			ans += s;
	}
	cout << ans;
	return 0;
}