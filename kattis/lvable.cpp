#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
void solve() {
    int n ; cin >> n ;
    string s ;  cin >> s ;
    int ans = 0 ;
    for ( int i =0  ; i < s.size() ; i++ ){
        if (i + 1 < n &&(s[i]=='l'&& s[i+1]=='v')){
            cout << 0 ;
            return ;
        }else if (s[i]=='l'||s[i]=='v'){
            ans = 1 ;
        }
    }
    if (ans == 1 ) cout << ans ;
    else cout << 2 ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}