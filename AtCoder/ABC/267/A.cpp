#include <iostream>
#include <string>
#include <map>
using namespace std;

map<const string, const unsigned short> a{{"Monday", 5}, {"Tuesday", 4}, {"Wednesday", 3}, {"Thursday", 2}, {"Friday", 1}};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	cout << a[s];
	return 0;
}
