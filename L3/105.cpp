#include <bits/stdc++.h>
using namespace std;

string f(const int &n)
{
	if(n == 1)
		return "a";
	string str = f(n - 1);
	int len = str.length();
	for(int i = 0; i < len; ++i)
		if(str[i] == 'a')
			str[i] = 'b';
		else
			str[i] = 'a';
	return f(n - 1) + str;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%s", f(n).c_str());
	return 0;
}