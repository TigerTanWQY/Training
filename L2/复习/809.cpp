#include <iostream>
#include <string>
using namespace std;

char lowercase(char ch) {
	if('A' <= ch && ch <= 'Z')
		ch += 'a' - 'A';
	return ch;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	string s;
	cin >> n >> s;
	string t;
	t += s.front();
	for(int i = 1; i < n; ++i)
		if(!t.empty() && lowercase(s[i]) == lowercase(t.back()) && s[i] != t.back())
			t.pop_back();
		else
			t += s[i];
	cout << t << endl;
	return 0;
}