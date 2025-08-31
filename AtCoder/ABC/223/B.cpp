#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

char str[1003];

int main()
{
	scanf("%s", str + 1);
	int n = strlen(str + 1);
	string mins = "~}|{zyxwvutsrqponmlkjihgfedcba`_^]\\[ZYXWVUTSRQPONMLKJIHGFEDCBA@?>=<;:9876543210/.-,+*)('&%$#\"! ", maxs;
	for(int k = 1; k <= n; ++k)
	{
		str[0] = str[n];
		for(int i = n; i > 1; --i)
			str[i] = str[i - 1];
		str[1] = str[0];
		if(string(str + 1) < mins)
			mins = string(str + 1);
		else if(string(str + 1) > maxs)
			maxs = string(str + 1);
	}
	for(int k = 1; k <= n; ++k)
	{
		str[0] = str[1];
		for(int i = 1; i < n; ++i)
			str[i] = str[i + 1];
		str[n] = str[0];
		if(string(str + 1) < mins)
			mins = string(str + 1);
		else if(string(str + 1) > maxs)
			maxs = string(str + 1);
	}
	printf("%s\n%s", mins.c_str(), maxs.c_str());
	return 0;
}