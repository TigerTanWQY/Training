#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	string s;
	cin >> n >> s;
	string stk;
	for(const auto& ch: s)
		if(!stk.empty() && ch == stk.back())
			stk.pop_back();
		else
			stk += ch;
	cout << stk << endl;
	return 0;
}