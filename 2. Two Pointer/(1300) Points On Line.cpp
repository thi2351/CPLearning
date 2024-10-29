//Problem: 251A
//Platform: Codeforce
//Difficult: 1300

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, d;
    cin >> n >> d;
    vector<int> list(n);
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }
    long long left = 0;
    long long right = 2;
    long long result = 0;
    while (right < n) {
        while (left < right && list[right] - list[left] > d) {
            left++;
        }
        long long size = right - left;
        result += (size*(size-1)/2);
        right++;
    }
    cout << result;
}
