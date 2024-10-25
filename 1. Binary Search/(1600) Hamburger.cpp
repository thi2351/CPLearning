//Problem: 371C. Hamburger
//Platform: Codeforce
//Difficulty: 1600

#include <bits/stdc++.h>
using namespace std;

bool BinarySearch(long long target, long long budget, vector<int>& recipe, vector<int>& prices, vector<int>& init_state) {
    long long total_prices = 0;
    for (int i = 0; i < recipe.size(); i++) {
        if (init_state[i] < target*recipe[i]) {
        total_prices += (target*recipe[i] - init_state[i])*prices[i];
            if (total_prices > budget) {
                return false;
            }
        }
    }
    // cout << "Target: " << target << " Total Price: " << total_prices << endl;
    return (total_prices <= budget);
}
int main() {
    string s;
    cin >> s;
    vector<int>recipe(3,0);
    vector<int>init_state(3,0);
    vector<int>prices(3,0);
    long long budget;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'B') {
            recipe[0]++;
        }
        if (s[i] == 'S') {
            recipe[1]++;
        }
        if (s[i] == 'C') {
            recipe[2]++;
        }
    }
    cin >> init_state[0] >> init_state[1] >> init_state[2];
    cin >> prices[0] >> prices[1] >> prices[2];
    cin >> budget;
    
    long long low = 0;
    long long high = 1e13;
    if (!BinarySearch(0,budget,recipe,prices,init_state)) {
        cout << 0;
        return 0;
    }
    long long mid = low + (high-low + 1)/2;
    while (low < high) {
        mid = low + (high-low + 1)/2;
        if (BinarySearch(mid,budget,recipe,prices,init_state)) {
            low = mid;
        }
        else {
            high = mid - 1;
        }
    }
    cout << low;
    return 0;
}

//Tip: Bà nội này handle cái high cũng mệt mỏi trong người á má.
