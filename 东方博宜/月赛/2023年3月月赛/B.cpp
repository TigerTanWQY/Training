#include <bits/stdc++.h>
using namespace std;

string s;

string my_unique(string::iterator start, string::iterator last)
{
	string ret(1, *start);
	for(string::iterator it = start + 1; it != last; ++it)
		if(*it != *(it - 1))
			ret += *it;
	return ret;
}

int main()
{
	int n;
	scanf("%d", &n);
	cin >> s;
	sort(s.begin(), s.end());
	s = my_unique(s.begin(), s.end());
	printf("%llu", s.length());
	return 0;
}