#include <iostream>
#include <vector>
#include<iterator>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
void solve() {
   int n , s , m ; cin >> n >> s >> m  ;
   s-- ; 
   vector < int > v (n) ;
   for ( int i = 0 ; i < n ; i++ ) cin >> v[i] ; 
   vector <int> vis(n,-1) ; 
   int calc = 0 ; 
   while (vis[s]!=1){
        vis[s] = 1 ;
        if (v[s] == m){
            cout << "magic" << endl ; 
            cout << calc << endl ;
            return ;
        } 
        calc ++ ; 
        int r = v[s]+s ; 
        if (r >=n) {
            cout << "right" << endl ; 
            cout << calc << endl ;
            return ;
        }else if (r < 0 ){
            cout << "left" << endl ; 
            cout << calc << endl ;
            return ;
        }
        s = r ;
   }
   cout << "cycle" << endl ; 
   cout << calc << endl ; 

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
