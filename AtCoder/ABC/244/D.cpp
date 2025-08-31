#include <iostream>
#include <string>
using namespace std;

bool check(const string &s)
{ return s == "R G B" || s == "G B R" || s == "B R G"; }

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s, t;
	getline(cin, s);
	getline(cin, t);
	if(check(s) == check(t))
		cout << "Yes";
	else
		cout << "No";
	return 0;
}