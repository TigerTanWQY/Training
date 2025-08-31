#include <cstdio>
#include <algorithm>
using namespace std;

const char t[] = "atcoder";
char s[2][200003];
int cnt[2][256];

int main() {
	scanf("%s%s", s[0], s[1]);
	for(int i = 0; s[0][i]; ++i) {
		++cnt[0][s[0][i]];
		++cnt[1][s[1][i]];
	}
	for(int i = 0; i < 7; ++i) {
		int x = max(cnt[0][t[i]], cnt[1][t[i]]);
		for(int j = 0; j < 2; ++j) {
			cnt[j]['@'] -= x - cnt[j][t[i]];
			cnt[j][t[i]] = x;
		}
	}
	bool ans = cnt[0]['@'] >= 0;
	for(int i = 0; i < 256; ++i)
		ans &= cnt[0][i] == cnt[1][i];
	printf(ans? "Yes": "No");
	return 0;
}
