#include <iostream>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
void solve() {
    int n , q ;cin >> n  >> q ;
    vector < int > v(n , -1) ;
    vector < int > ans(n,0) ;
    int curr = -1  ; 
    int curr_val = -1 ;
    while(q--){
        string s ;cin >> s ;
        
        if (s == "SET"){
            int a ; cin >> a ; 
            a-- ;
            int b ;  cin >> b  ;
            v[a] = curr; 
            ans[a] =b ;  



        }else {
            int x ; cin >> x ; 
            if (s == "PRINT"){
                x-- ; 
                if (curr == v[x]){
                    cout << ans[x] << endl ;
                }else cout << curr_val << endl; 
            }else {
                curr ++ ;
                curr_val = x  ;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}