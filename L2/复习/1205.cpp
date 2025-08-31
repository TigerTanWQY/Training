#include <iostream>
#include <cstring>
using namespace std;

char s[13], t[1000003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> s;
	int n = strlen(s), m = 0;
	char ch = cin.get();
	while((ch = cin.get()) != EOF && ch != '\n')
		t[m++] = ch;
	for(int i = 0; i < n; ++i)
		if('A' <= s[i] && s[i] <= 'Z')
			s[i] += 'a' - 'A';
	for(int i = 0; i < m; ++i)
		if('A' <= t[i] && t[i] <= 'Z')
			t[i] += 'a' - 'A';
	int cnt = 0, pos = -1;
	for(int i = 0; i < m; ++i) {
		if(i + n - 1 >= m)
			break;
		bool flag = true;
		for(int j = 0; j < n; ++j)
			if(t[i + j] != s[j]) {
				flag = false;
				break;
			}
		if(i != 0 && t[i - 1] != ' ')
			flag = false;
		if(i + n < m && t[i + n] != ' ')
			flag = false;
		if(flag) {
			++cnt;
			if(pos == -1)
				pos = i;
		}
	}
	if(cnt == 0)
		cout << "-1";
	else
		cout << cnt << ' ' << pos;
	cout << endl;
	return 0;
}