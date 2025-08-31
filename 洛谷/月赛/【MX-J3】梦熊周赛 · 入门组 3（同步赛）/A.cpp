#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a;
	cin >> a;
	a *= 37;
	string s = to_string(a);
	unordered_set<char> st;
	for(const auto& ch: s)
		st.insert(ch);
	if(st.size() == 1)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	return 0;
}