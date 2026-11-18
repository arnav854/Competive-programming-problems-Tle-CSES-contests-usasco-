#include <iostream>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long int ;
vector < int > pal ;
vector < ll > dp(4*1e4+1) ;
ll MOD = 1e9 +7  ;
bool check (int i) {
    string s = to_string(i) ;
    for (int i =0 ; i<s.size()/2 ;i++ ){
        if(s[i]!=s[s.size()-i-1]) {
            return false ;
        }
    }
    return true ;
}
void calc (){
    for (int i = 1 ; i <= 4*1e4 ; i++){
        if (check(i)){
            pal.push_back(i) ;
        }
    }
}
void calc_2() {
    dp[0] = 1;

    for (int j = 0; j < pal.size(); j++) {
        for (int i = pal[j]; i <= 4*1e4; i++) {
            dp[i] = (dp[i] + dp[i-pal[j]]) % MOD;
        }
    }
}

void solve() {
    int n ; cin >> n ; 
    cout << dp[n] << endl ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    calc() ;
    calc_2() ; 
    int t ; cin >> t ;  while(t--)
    solve();
    return 0;
}