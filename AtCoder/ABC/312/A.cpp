#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	cin >> str;
	if(str == "ACE" || str == "BDF" || str == "CEG" || str == "DFA" || str == "EGB" || str == "FAC" || str == "GBD")
		cout << "Yes";
	else
		cout << "No";
	return 0;
}