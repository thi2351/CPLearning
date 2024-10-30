//
//Platform: Codeforce
//Difficulty: 1800


//First version: TLE at Testcase 31
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    unordered_map<int, queue<int>> map;
    unordered_map<int, int> set;
    vector<int> day(n);

    for (int i = 0; i < n; i++) {
        cin >> day[i];
        map[day[i]].push(i); 
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        if (set.find(day[i]) != set.end()) {
          
        } else {
            result++; 

            if (set.size() < k) {
                set[day[i]] = 1;
            } else {
            
                int maxObserve = -1;
                int maxObserveIndex = -1;
                bool foundEmpty = false;

                for (auto it = set.begin(); it != set.end(); it++) {
                    int sock = it->first;

                    if (map[sock].empty()) {
                        
                        maxObserveIndex = sock;
                        foundEmpty = true;
                        break;
                    }

                    if (map[sock].front() > maxObserve) {
                        maxObserve = map[sock].front();
                        maxObserveIndex = sock;
                    }
                }

                set.erase(maxObserveIndex);
                set[day[i]] = 1; 
            }
        }

       
        if (!map[day[i]].empty()) {
            map[day[i]].pop();
        }
    }

    cout << result << endl;
    return 0;
}

2nd Version: MLE at Testcase 50
#include <bits/stdc++.h>
using namespace std;
struct CompareBySecond {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;  // Max-heap based on second value
    }
};
int main() {
    int n,k;
    cin >> n >> k;
    unordered_map<int,queue<int>> map;
    unordered_set<int> set;
    priority_queue<pair<int,int>,vector<pair<int, int>>,CompareBySecond> heap;
    vector<int> day(n);
    for (int i = 0; i < n; i++) {
        cin >> day[i];
        map[day[i]].push(i);
    }
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (set.find(day[i]) != set.end()) {
        }
        else {
            result++;
            if (set.size() < k) {
                set.insert(day[i]);
            }
            else {
                pair<int,int> ele = heap.top();
                heap.pop();
                
                set.erase(ele.first);
                set.insert(day[i]);
            }
        }
        map[day[i]].pop();
        if (!map[day[i]].empty()) {
            heap.push({day[i],map[day[i]].front()});
        }
        else {
            heap.push({day[i],10000000});
        }
    }
    cout << result;
}


3rd Version: AC
#include <bits/stdc++.h>
using namespace std;
struct CompareBySecond {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;  // Max-heap based on second value
    }
};
int main() {
    int n,k;
    cin >> n >> k;
    if (n == k) {
        cout << n;
        return 0;
    }
    unordered_map<int,queue<int>> map;
    bitset<400001> was;
    priority_queue<pair<int,int>,vector<pair<int, int>>,CompareBySecond> heap;
    vector<int> day(n);
    for (int i = 0; i < n; i++) {
        cin >> day[i];
        map[day[i]].push(i);
    }
    int result = 0;
    int curr_size = 0;
    for (int i = 0; i < n; i++) {
        if (!was[day[i]]) {
            result++;
            if (curr_size >= k) {
                pair<int,int> ele = heap.top();
                heap.pop();
                was[ele.first] = 0;
                curr_size--;
            }
            was[day[i]] = 1;
            curr_size++;
        }
        map[day[i]].pop();
        if (!map[day[i]].empty()) {
            heap.push({day[i],map[day[i]].front()});
        }
        else {
            heap.push({day[i],10000000});
        }
    }
    cout << result;
}
