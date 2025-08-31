/*
ID: tatingw1
TASK: ride
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
//#define fin cin
//#define fout cout

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ifstream fin("ride.in");
	ofstream fout("ride.out");
	string s, t;
	fin >> s >> t;
	auto hsh = [](const string& a) {
		constexpr const int P = 47;
		int res = 1;
		for(const auto& ch: a)
		{ res *= ch - 'A' + 1; res %= P; }
		return res;
	};
	if(hsh(s) == hsh(t))
		fout << "GO";
	else
		fout << "STAY";
	fout << endl;
	return 0;
}
