#include <bits/stdc++.h>
using namespace std;

struct Segment
{ int A, B; };
class SegTree {
public:
    vector<vector<int>> tree;
    int size;
    SegTree(const vector<int>& B) {
        int n = B.size();
        size = 1;
        while (size < n) size <<= 1;
        tree.resize(2 * size);
        for (int i = 0; i < n; ++i)
            tree[size + i].push_back(B[i]);
        for (int i = size - 1; i >= 1; --i) {
            merge(tree[2 * i].begin(), tree[2 * i].end(),
                  tree[2 * i + 1].begin(), tree[2 * i + 1].end(),
                  back_inserter(tree[i]));
        }
    }
    int query(int l, int r, int y) {
        int res = 0;
        l += size;
        r += size;
        while (l <= r) {
            if (l % 2 == 1) {
                res += tree[l].end() - upper_bound(tree[l].begin(), tree[l].end(), y);
                ++l;
            }
            if (r % 2 == 0) {
                res += tree[r].end() - upper_bound(tree[r].begin(), tree[r].end(), y);
                --r;
            }
            l >>= 1;
            r >>= 1;
        }
        return res;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<Segment> segs(M);
    for (int i = 0; i < M; ++i)
        cin >> segs[i].A >> segs[i].B;
    sort(segs.begin(), segs.end(), [](const Segment& a, const Segment& b) {
        return a.A < b.A;
    });
    vector<int> A(M), B(M);
    for (int i = 0; i < M; ++i) {
        A[i] = segs[i].A;
        B[i] = segs[i].B;
    }
    SegTree mt(B);
    int Q;
    cin >> Q;
    while (Q--) {
        int C, D;
        cin >> C >> D;
        int k_c = -1;
        {
            int left = 0, right = M - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (A[mid] < C) {
                    k_c = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        int c_count = 0;
        if (k_c >= 0)
            c_count = mt.query(0, k_c, C);
        int k_d = -1;
        {
            int left = 0, right = M - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (A[mid] < D) {
                    k_d = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        int d_count = 0;
        if (k_d >= 0)
            d_count = mt.query(0, k_d, D);
        int both = 0;
        if (k_c >= 0)
            both = mt.query(0, k_c, D);
        int ans = c_count + d_count - 2 * both;
        cout << ans << '\n';
    }
    cout.flush(); return 0;
}
