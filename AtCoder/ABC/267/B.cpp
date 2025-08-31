#include <iostream>
#include <string>
using namespace std;

bool column[7];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	s = '$' + s;
	if(s[1] == '1') {
		cout << "No";
		return 0;
	}
	column[0] = s[7] - '0';
	column[1] = s[4] - '0';
	column[2] = s[2] - '0' || s[8] - '0';
	column[3] = s[1] - '0' || s[5] - '0';
	column[4] = s[3] - '0' || s[9] - '0';
	column[5] = s[6] - '0';
	column[6] = s[10] - '0';
	for(int i = 0; i < 7; ++i)
		for(int j = 0; j < i; ++j)
			if(column[i] && column[j])
				for(int k = j + 1; k < i; ++k)
					if(!column[k]) {
						cout << "Yes";
						return 0;
					}
	cout << "No";
	return 0;
}
