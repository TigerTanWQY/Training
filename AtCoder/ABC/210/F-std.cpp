#include <iostream>
using std::cin;
using std::cout;
#include <utility>
using std::pair;
#include <vector>
using std::vector;
#include <unordered_map>
using std::unordered_map;
#include <atcoder/twosat>
using atcoder::two_sat;

const int N = 2000000;
int dvs[N + 3];

vector<int> mkprm(int n) {
	vector<int> res;
	for(int p = dvs[n]; n != 1; p = dvs[n]) {
		res.push_back(p);
		for(; dvs[n] == p; n /= p);
	}
	return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	dvs[1] = 1;
	for(int i = 2; i <= N; ++i)
		if(!dvs[i])
			for(int j = i; j <= N; j += i)
				if(!dvs[j])
					dvs[j] = i;
	int n;
	cin >> n;
	unordered_map<int, vector<pair<int, bool>>> vec;
	int m = 0;
	for(int i = 0, x; i < n; ++i)
		for(int j = 0; j < 2; ++j) {
			cin >> x;
			for(const auto& p: mkprm(x)) {
				vec[p].push_back({i, j});
				++m;
			}
		}
	two_sat s(m + n);
	m = n;
	int k = 0;
	for(const auto& p: vec) {
		auto a = p.second;
		for(int i = 0; i < a.size(); ++i) {
			s.add_clause(a[i].first, !a[i].second, m + k, true);
			if(i) {
				s.add_clause(m + k - 1, false, m + k, true);
				s.add_clause(a[i].first, !a[i].second, m + k - 1, false);
			}
			++k;
		}
	}
	if(s.satisfiable())
		cout << "Yes";
	else
		cout << "No";
	return 0;
}