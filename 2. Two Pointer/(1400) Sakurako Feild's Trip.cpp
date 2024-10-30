//Problem:
//Platform: Codeforce
//Difficulty: 1400


#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    vector<int> result;
    while (t--) {
        int n;
        cin >> n;
        vector<int> line(n);
        for (int i = 0; i < n; i++) {
            cin >> line[i];
        }
        int left = 1;
        int right = n - 2;
        while (left < right) {
            if (line[left] == line[left-1] || line[right] == line[right + 1]) {
                swap(line[left],line[right]);
            }
            left++;
            right--;
        }
        int r = 0;
        for (int i = 1; i < n; i++) {
            if (line[i] == line[i-1]) {
                r++;
            }
        }
        result.push_back(r);
    }
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}
