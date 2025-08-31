#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string n;
	cin >> n;
	for(int i = 1; i < n.size(); ++i)
		if(n[i] == n[i - 1]) {
			cout << "Bad";
			return 0;
		}
	cout << "Good";
	return 0;
}