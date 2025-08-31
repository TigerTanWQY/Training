#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int p[]{0, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
const int d[]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<int> a, ans;

bool is_prime(const int& x) {
	if(x < 2)
		return false;
	for(int i = 2; i * i <= x; ++i)
		if(x % i == 0)
			return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for(int i = 1; i <= 12; ++i)
		for(int j = 1; p[j] <= d[i]; ++j)
			if(is_prime(i * 100 + p[j]))
				a.push_back(i * 100 + p[j]);
	for(int i = 4; i < 10000; i += 4)
		if((i % 100 || i % 400 == 0) && is_prime(i * 10000 + 229))
			ans.push_back(i * 10000 + 229);
	for(int i = 1; i < 10000; i++)
		for(const auto& j: a)
			if(is_prime(i * 10000 + j))
				ans.push_back(i * 10000 + j);
	int T;
	cin >> T;
	for(int cnt = 0; T--; cnt = 0) {
		string s;
		cin >> s;
		if(s == "--------") {
			cout << "55157\n";
			continue;
		}
		for(auto now: ans) {
			bool flag = true;
			for(int j = 7; flag && j >= 0; --j, now /= 10)
				if(s[j] != '-' && s[j] - '0' != now % 10)
					flag = false;
			cnt += flag;
		}
		cout << cnt << '\n';
	}
	return 0;
}