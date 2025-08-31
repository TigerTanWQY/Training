#include <bits/stdc++.h>
using namespace std;

char s[103];
struct Node
{
	char name[13];
	int len, income[103];
	bool operator>(const Node& x)
	{
		if(len != x.len)
			return len > x.len;
		for(int i = 1; i <= len; ++i)
			if(income[i] != x.income[i])
				return income[i] > x.income[i];
		return false;
	}
} a[103];

void swap(Node& x, Node& y)
{
	Node tmp = x;
	x = y;
	y = tmp;
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%s%s", a[i].name + 1, s + 1);
		int len = strlen(s + 1);
		a[i].len = len;
		for(int j = 1; j <= len; ++j)
			a[i].income[j] = s[j] - '0';
	}
	for(int i = 1; i < n; ++i)
		for(int j = 1; j <= n - i; ++j)
			if(a[j + 1] > a[j])
				swap(a[j], a[j + 1]);
	for(int i = 1; i <= n; ++i)
		printf("%s\n", a[i].name + 1);
	return 0;
}