/*
#include <cstdio>
using namespace std;

int pm[]{2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97, 101, 107, 113, 131, 149, 151, 157, 167, 179, 181, 191, 199, 311, 313, 337, 347, 353, 359, 373, 383, 389, 701, 709, 727, 733, 739, 743, 751, 757, 761, 769, 787, 797, 907, 919, 929, 937, 941, 953, 967, 971, 983, 991};

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < 56; ++i)
		if(pm[i] <= n)
			printf("%d\n", pm[i]);
	return 0;
}
*/
#include <cstdio>
#include <cmath>
using namespace std;

bool is_prime(const int &x)
{
	if(x < 2)
		return false;
	for(int i = 2; i <= sqrt(x); ++i)
		if(x % i == 0)
			return false;
	return true;
}

int turn(const int &x)
{
	int a = x / 1000, b = x / 100 % 10, c = x / 10 % 10, d = x % 10;
	int ret = d * 1000 + c * 100 + b * 10 + a;
	for(; ret % 10 == 0; ret /= 10);
	return ret;
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		if(is_prime(i) && is_prime(turn(i)))
			printf("%d\n", i);
	return 0;
}