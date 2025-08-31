#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e4 + 3;
int pre[N], weight[N], xp[N], n;

int fnd(int x) {
	if(x != pre[x]) {
		int fx = pre[x];
		pre[x] = fnd(pre[x]);
		weight[x] ^= weight[fx];
	}
	return pre[x];
}

int mix(int x, int y, int z) {
	int fx = fnd(x);
	int fy = fnd(y);
	if(fx  == fy) {
		if((weight[x] ^ weight[y]) != z)
			return 0;
		return 1;
	}
	if(fx == n) fx ^= fy ^= fx ^= fy;
	pre[fx] = fy;
	weight[fx] = weight[x] ^ weight[y] ^ z;
	return 1;
}

int solv(int key) {
	int index[N]{};
	int ans = 0;
	for(int i = 0; i < key ; i++)
	{
		if(index[i]) continue;
		int fi = fnd(xp[i]);
		int cnt = 0;
		for(int j = i ; j < key; j++)
		{
			int fj = fnd(xp[j]);
			if(index[j] == 0 && fi == fj)
			{
				cnt++;
				index[j] = 1;
				ans ^= weight[xp[j]];
			}
		}
		if((cnt&1) && fi != n)
			return -1;
	}
	return ans;
}

int main() {
//	freopen("out.out", "w", stdout);
	for(int kas = 1, Q; scanf("%d%d", &n, &Q) && n && Q; putchar('\n')) {
		printf("Case %d:\n", kas++);
		for(int i = 0; i <= N; i++) {
			pre[i] = i;
			weight[i] = 0;
		}
		int facts = 0, flag = 0;
		while(Q--) {
			char order[2]{};
			scanf("%s",order);
			int p,q,v;
			if(order[0] == 'I') {
				facts++;
				getchar();
				char str[7]{};
				gets(str);
				int k = 0;
				for(int i = 0; str[i] != '\0'; i++)
					if(str[i] == ' ') k++;
				if(k == 1) {
					sscanf(str,"%d%d",&p,&v);
					q = n;
				} else
					sscanf(str,"%d%d%d",&p,&q,&v);
				if(flag) continue;
				if(mix(p,q,v) == 0) {
					printf("The first %d facts are conflicting.\n",facts);
					flag = 1;
				}
			} else if(order[0] == 'Q') {
				int k;
				scanf("%d",&k);
				memset(xp,0,sizeof(xp));
				for(int i = 0; i < k; i++)
					scanf("%d",&xp[i]);
				if(flag) continue;
				int ans = solv(k);
				if(ans == -1)
					printf("I don't know.\n");
				else
					printf("%d\n",ans);
			}
		}
	}
	return 0;
}
