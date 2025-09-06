#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int n = 1000001;
ll cnt[n], total_sum[n], total_cnt[n];

void update(int pos, ll val) {
    cnt[pos] += val;
    for(int i = pos; i < n; i += i & -i)
        total_cnt[i] += val, total_sum[i] += pos*val;
}

ll getsum(int pos) {
    ll ret = 0;
    while(pos > 0) ret += total_sum[pos], pos -= pos & -pos;
    return ret;
}

int calc(int n) {
	int ret = 0;
	while((1<<ret) + 1 < n) ret++;
	return ret;
}

pair<int, ll> find(ll t) {
	static int upper = calc(n);
	int ret1 = 0;
	for(int i = upper; i >= 0; i--) {
		ret1 += 1 << i;
		if(ret1 >= n || total_cnt[ret1] >= t) ret1 -= 1 << i;
		else t -= total_cnt[ret1];
	}
	return {ret1, t};
}

int main() {
	char str[7];
	int num;
	ll price;
	while(scanf("%s%d%lld", str, &num, &price) > 0) {
		if(*str == 'A')
			update(price, num);
		else {
			pair<int, ll> ret = find(num);
			ll sum = getsum(ret.first);
			if(ret.first + 1 < n && sum + (ret.first+1)*ret.second <= price) {
				puts("HAPPY");
				while(num) {
					int pos = find(1).first + 1, d = min((ll)num, cnt[pos]);
					update(pos, -d);
					num-=d;
				}
			} else {
				puts("UNHAPPY");
			}
		}
	}
	return 0;
}
