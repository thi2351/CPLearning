//Problem: 1613C. Poison Dagger
//Platform: Codeforce
//Difficulty: 1200


#include <bits/stdc++.h>
using namespace std;
long long evaluatedmg(long long k, long long n, vector<long long>&times) {
    long long dmg = 0;
    for  (int i = 1; i < n; i++) {
              dmg += min(times[i] - times[i-1], k); 
          }
          dmg += k; 
    return dmg;
}
int main() {
  int test;
  long long n, h;
  vector<long long> result;
  cin >> test;
  while (test--) {
      //Input
      cin >> n >> h;
      vector<long long> times;
      for (int i = 0; i < n; i++) {
         long long k;
         cin >> k;
         times.push_back(k);
      }
      //Process
      long long low = 1;
      long long high = h;
      while (low < high) {
          long long mid = low + (high-low)/2;
          long long dmg = evaluatedmg(mid,n,times);
          if (dmg >= h) {
              high = mid;
          }
          else {
              low = mid + 1;
          }
      }
      //Output
      result.push_back(low);
  }
  for (int i = 0; i < result.size(); i++) {
      cout << result[i] << endl;
  }
}

//Tips: Focus on data type: It's maybe overflow!!
//Tips: Focus on quick Binary search implementation!!
