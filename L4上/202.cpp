#include <iostream>
#include <unordered_map>
using namespace std;

struct Student {
	int a, b, c;
	Student() = default;
	Student(const int& _a, const int& _b, const int& _c)
	: a(_a), b(_b), c(_c)
	{ }
};
unordered_map<string, Student> mp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 1, a, b, c; i <= n; ++i) {
		string name;
		cin >> name >> a >> b >> c;
		mp[name] = {a, b, c};
	}
	for(string name; m--; ) {
		cin >> name;
		if(mp.count(name))
			cout << mp[name].a << ' ' << mp[name].b << ' ' << mp[name].c << '\n';
		else
			cout << "-1 -1 -1\n";
	}
	return 0;
}