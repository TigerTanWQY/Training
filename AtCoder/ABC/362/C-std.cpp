#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<long long, long long>> ranges(n);
    long long min_sum = 0, max_sum = 0;
    bool has_positive = false, has_negative = false;

    for (int i = 0; i < n; ++i) {
        cin >> ranges[i].first >> ranges[i].second;
        min_sum += ranges[i].first;
        max_sum += ranges[i].second;
        if (ranges[i].first > 0) has_positive = true;
        if (ranges[i].second < 0) has_negative = true;
    }

    if (min_sum > 0 && !has_negative || max_sum < 0 && !has_positive) {
        cout << "No\n";
        return 0;
    }

    vector<long long> result(n);
    long long current_sum = 0;
    for (int i = 0; i < n; ++i) {
        if (current_sum + ranges[i].first > 0 && has_negative) {
            result[i] = ranges[i].second;
            current_sum += ranges[i].second;
        } else if (current_sum + ranges[i].first < 0 && has_positive) {
            result[i] = ranges[i].first;
            current_sum += ranges[i].first;
        } else {
            result[i] = ranges[i].first;
            current_sum += ranges[i].first;
        }
    }

    if (current_sum != 0) {
        long long diff = -current_sum;
        if (diff <= ranges.back().second && diff >= ranges.back().first) {
            result.back() += diff;
            current_sum = 0;
        } else {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    for (long long x : result) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}