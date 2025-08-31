#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
using namespace std;

__gnu_pbds::gp_hash_table<string, int> idx;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m, n, p;
	cin >> m >> n >> p;
	string s;
	for(int i = 1; i <= m; ++i) {
		cin >> s;
		idx[s] = i;
	}
	for(cin.get(); p--; ) {
		getline(cin, s);
		const int id = idx[s.substr(0, s.find(':'))];
		s = s.substr(s.find(':') + 2);
		if(s == "I am guilty.") {
			;
		} else if(s == "I am not guilty.") {
			;
		} else if(s.find("is guilty.") != string::npos) {
			;
		} else if(s.find("is not guilty.") != string::npos) {
			;
		} else if(s.find("Today is") != string::npos) {
			;
		}
//		cout << s.substr(0, s.find(':')) << ' ' << id << '\n';
	}
	cout << endl;
	return 0;
}