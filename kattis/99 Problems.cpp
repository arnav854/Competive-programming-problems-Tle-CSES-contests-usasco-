#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
void solve() {
    int n ; cin >> n ; 
    
    int x = n % 100 ;
    if ( n <=99 ) {
        cout << 99 << endl ; 
        return ;
    }
    
    
    if ( x >= 49) {
        
        cout << ((n/100)*100)+ 99 << endl ;
    }
    else {
        int r = 0 ;
        if ( n/100 != 0){
            r = ((n/100) - 1 )*100 ; 
        }else {
            r = 0 ; 
        }
        cout << r + 99 << endl ; 
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}