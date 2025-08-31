#include <iostream>
#include <string>
#include <cassert>

using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;
    int j = 0; // index for string t
    bool possible = true;

    for (char &c : s) {
        if (c == '?') {
            if (j < t.size() && t[j] >= 'a' && t[j] <= 'z') {
                c = t[j];
                ++j;
            }
        } else if (c == t[j]) {
            ++j;
        }

        if (j == t.size()) {
            break;
        }
    }

    // Check if we were able to form the subsequence
    if (j != t.size()) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << s << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    assert(1 <= t && t <= 10000);

    while (t--) {
        solve();
    }

    return 0;
}