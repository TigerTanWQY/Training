#include <cstdio>
#include <cstring>
using namespace std;

char s[103];

int main() {
	int _;
	scanf("%d", &_);
	while(_--) {
		scanf("%s", s + 1);
		int cntu = 0, cntl = 0, n = strlen(s + 1);
		for(int i = 1; i <= n; ++i)
			if('A' <= s[i] && s[i] <= 'Z')
				++cntu;
			else if('a' <= s[i] && s[i] <= 'z')
				++cntl;
		if(cntu > cntl)
			for(int i = 1; i <= n; ++i)
				if('a' <= s[i] && s[i] <= 'z')
					putchar(s[i] - 32);
				else
					putchar(s[i]);
		else
			for(int i = 1; i <= n; ++i)
				if('A' <= s[i] && s[i] <= 'Z')
					putchar(s[i] + 32);
				else
					putchar(s[i]);
		putchar('\n');
	}
	return 0;
}