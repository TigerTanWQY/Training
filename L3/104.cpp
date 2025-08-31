#include <bits/stdc++.h>
using namespace std;

string f(const int &n)
{
	if(n == 1)
		return "a";
	if(n == 2)
		return "b";
	return f(n - 1) + f(n - 2);
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%s", f(n).c_str());
	return 0;
}