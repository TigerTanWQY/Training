#include <iostream>
#include <string>
using namespace std;

constexpr const int P = 11;
int a[11];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	for(int i = 0, j = 0; i < s.size(); ++i)
		if('0' <= s[i] && s[i] <= '9')
			a[++j] = s[i] - '0';
		else if(s[i] == 'X')
			a[++j] = 10;
	int chk = 0;
	for(int i = 1; i <= 9; ++i)
		chk = (chk + a[i] * i % P) % P;
	if(chk == a[10])
		cout << "Right";
	else {
		s.pop_back();
		cout << s;
		if(chk == 10)
			cout.put('X');
		else
			cout.put('0' + chk);
	}
	cout << endl;
	return 0;
}