#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s1, s2;
	cin >> s1 >> s2;
	cout << ((min(abs(s1[0] - s1[1]), 5 - abs(s1[0] - s1[1])) == min(abs(s2[0] - s2[1]), 5 - abs(s2[0] - s2[1]))? "Yes": "No"));
	return 0;
}
