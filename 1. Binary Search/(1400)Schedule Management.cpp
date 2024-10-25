//Problem: 1701C. Schedule Management
//Platform: Codeforce
//Difficulty: 1400


#include <bits/stdc++.h>
using namespace std;
bool BinarySearch(int time, vector<int>& task) {
    long long remain_task = 0;
    for (int i = 0; i < task.size(); i++) {
        if (task[i] >= time) {
            remain_task += (time - task[i]); //Phải nhờ
        }
        else {
            remain_task += (time - task[i])/2; //Làm phụ
        }
    }
    return (remain_task >= 0);
}
int main() {
    int test;
    cin >> test;
    while (test--) {
        int n, m;
        cin >> n >> m;
        vector<int> task(n,0);
        for (int i = 0; i < m; i++) {
            int k;
            cin >> k;
            task[k-1]++;
        }
        int low = 0;
        int high = 2*m;
        int mid = low + (high-low)/2;
        while (low < high) {
            mid = low + (high-low)/2;
            if (BinarySearch(mid, task)) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        cout << high << endl;
    }
}
