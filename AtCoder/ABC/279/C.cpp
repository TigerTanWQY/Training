#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 400003;
string s[N], t[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int h, w;
	cin >> h >> w;
	for(int i = 0; i < h; ++i)
		cin >> s[i];
	for(int i = 0; i < h; ++i)
		cin >> t[i];
	vector<string> ts(w), tt(w);
	for(int i = 0; i < h; ++i)
		for(int j = 0; j < w; ++j) {
			ts[j].push_back(s[i][j]);
			tt[j].push_back(t[i][j]);
		}
	sort(ts.begin(), ts.end());
	sort(tt.begin(), tt.end());
	if(ts == tt)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}
