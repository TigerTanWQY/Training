#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int y;
	cin >> y;
	if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
		cout << "366";
	else
		cout << "365";
	cout.flush();
	return 0;
}