//Problem: 1399C. Boats Competition
//Platform: Codeforce
//Difficulty: 1200


#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        vector<int> participants(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> participants[i];
        }
        sort(participants.begin(), participants.end());
        int ans = 0;
        
        for (int s = 2 * participants[0]; s <= 2 * participants[n - 1]; s++) {
            int left = 0;
            int right = n - 1;
            int teams = 0;
 
            while (left < right) {
                int total = participants[left] + participants[right];
                if (total == s) {
                    teams++;
                    left++;
                    right--;
                } 
                else if (total < s) {
                    left++;
                } 
                else {
                    right--;
                }
            }
            ans = max(ans, teams);
        }
        
        cout << ans << endl;
    }
    return 0;
}
//Tưởng code fail ai dè AC má?
