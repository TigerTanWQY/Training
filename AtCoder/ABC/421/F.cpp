#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
using namespace std;

struct Node {
    int w;
    Node *pre, *nxt;
    Node(int v)
    : w(v), pre(nullptr), nxt(nullptr)
    { }
};

int read() {
	int res = 0;
	char ch = getchar_unlocked();
	for(; '0' > ch || ch > '9'; ch = getchar_unlocked());
	for(; '0' <= ch && ch <= '9'; ch = getchar_unlocked())
		res = res * 10 + ch - '0';
	return res;
}

int main() {
	int m = read();
	Node* head = new Node(0);
	__gnu_pbds::gp_hash_table<int, Node*> mp;
	mp[0] = head;
	vector<long long> ans;
	for(int i = 1, tp, x, y; i <= m; ++i) {
		tp = read();
		if(tp == 1) {
			x = read();
			Node *itx = mp[x], *nw = new Node(i);
			nw->pre = itx;
			nw->nxt = itx->nxt;
			if(itx->nxt)
				itx->nxt->pre = nw;
			itx->nxt = nw;
			mp[i] = nw;
		} else if(tp == 2) {
			x = read(); y = read();
			Node *itx = mp[x], *ity = mp[y], *cur = itx->nxt;
			bool flg = false;
			for(; cur != nullptr; cur = cur->nxt)
				if(cur == ity) {
					flg = true;
					break;
				}
			long long tot = 0;
			if(flg) {
				Node *p = itx->nxt;
				while(p != ity) {
					tot += p->w;
					Node *tmp = p;
					p = p->nxt;
					mp.erase(tmp->w);
					delete tmp;
				}
				itx->nxt = ity;
				ity->pre = itx;
			} else {
				cur = itx->pre;
				for(; cur != nullptr; cur = cur->pre)
					if(cur == ity)
						break;
				if(cur == ity) {
					Node *p = ity->nxt;
					while(p != itx) {
						tot += p->w;
						Node *tmp = p;
						p = p->nxt;
						mp.erase(tmp->w);
						delete tmp;
					}
					ity->nxt = itx;
					itx->pre = ity;
				} else
					tot = 0;
			}
			ans.push_back(tot);
		}
	}
	for(const auto& x: ans)
		printf("%lld\n", x);
	Node *p = head;
	while(p) {
		Node *nxt = p->nxt;
		delete p;
		p = nxt;
	}
	return 0;
}
