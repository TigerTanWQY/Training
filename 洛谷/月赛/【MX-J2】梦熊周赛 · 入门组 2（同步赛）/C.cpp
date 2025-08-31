#include <iostream>
using namespace std;

constexpr const int N = 1'000'003;
char s[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(int n; _T--; ) {
		cin >> n >> (s + 1);
	}
	cout.flush();
	return 0;
}