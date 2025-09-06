#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 28;
bitset<N> b;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	for(const auto& ch: s)
		b[ch] = true;
	for(char ch = 'a'; ch <= 'z'; ++ch)
		if(!b[ch])
		{ cout.put(ch); break; }
	cout << endl;
	return 0;
}
