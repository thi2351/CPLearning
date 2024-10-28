//Problem: 1462F
//Platform: 
//Difficulty: 1800

#include <bits/stdc++.h>
using namespace std;

int UpperBound(int target, vector<int>& list) {
    int low = 0;
    int high = list.size();
    int mid;
    while (low < high) {
        mid = low + (high - low) / 2;
        if (list[mid] <= target) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int LowerBound(int target, vector<int>& list) {
    int low = 0;
    int high = list.size();
    int mid;
    while (low < high) {
        mid = low + (high - low) / 2;
        if (list[mid] < target) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int main() {
    int t;
    cin >> t;
    vector<int> result;
    while (t--) {
        int n;
        cin >> n;
        vector<int> L;
        vector<int> R;
        vector<pair<int, int>> point;
        for (int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            point.push_back({r, l});
            L.push_back(l);
            R.push_back(r);
        }
        sort(L.begin(), L.end());
        sort(R.begin(), R.end());
        int minimize = 1000000;
        for (int i = 0; i < n; i++) {
            int l = LowerBound(point[i].second, R);
            int r = max(0, n - UpperBound(point[i].first, L));
            minimize = min(minimize, l + r);
        }
        result.push_back(minimize);
    }
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
}
