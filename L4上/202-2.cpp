#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ULL = unsigned long long;

const int P = 109673;
struct Student {
	string name;
	int a, b, c;
	Student() = default;
	Student(const string& _s, const int& _a, const int& _b, const int& _c)
	: name(_s), a(_a), b(_b), c(_c)
	{ }
};
vector<Student> h[P];

ULL Hash(const string& str) {
	ULL res = 0, base = 1;
	for(const auto& c: str) {
		res = res * base + c;
		base *= 383;
	}
	return res % P;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 1, a, b, c; i <= n; ++i) {
		string s;
		cin >> s >> a >> b >> c;
		h[Hash(s)].push_back({s, a, b, c});
	}
	for(string s; m--; ) {
		cin >> s;
		bool flag = true;
		for(const auto& x: h[Hash(s)])
			if(x.name == s) {
				cout << x.a << ' ' << x.b << ' ' << x.c << '\n';
				flag = false;
				break;
			}
		if(flag)
			cout << "-1 -1 -1\n";
	}
	return 0;
}