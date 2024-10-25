//
//
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; 
    cin >> t;

    while (t--) { 
        int h, n;
        cin >> h >> n;
        
        vector<int> dmg(n);
        vector<int> cd(n);
        
        for (int i = 0; i < n; i++) {
            cin >> dmg[i];
        }
        
        for (int i = 0; i < n; i++) {
            cin >> cd[i];
        }

        if (h == 0) {
            cout << 0 << endl;
            continue; 
        }
        
        long long low = 0;
        long long high = 1e12; 
        
        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long total_dmg = 0;

            for (int i = 0; i < n; i++) {
                // Kiểm tra overflow trước khi cộng
                if (mid / cd[i] > 0) {
                    long long damage = (mid / cd[i]) * dmg[i];
                    if (total_dmg + damage >= h) { 
                        total_dmg = h; 
                        break;
                    }
                    total_dmg += damage;
                }
            }
            for (int i = 0; i < n; i++) {
                if (mid % cd[i] >= 0) {
                    total_dmg += dmg[i];
                    if (total_dmg >= h) {
                        total_dmg = h; 
                        break;
                    }
                }
            }

            if (total_dmg >= h) {
                high = mid; 
            } else {
                low = mid + 1;
            }
        }

        cout << high + 1 << endl;
    }

    return 0;
}
