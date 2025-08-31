#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string s;
	cin >> n >> s;
	for(int i = 0; i < n; ++i)
		if(s[i] == '1') {
			if(i & 1)
				cout << "Aoki";
			else
				cout << "Takahashi";
			break;
		}
	return 0;
}