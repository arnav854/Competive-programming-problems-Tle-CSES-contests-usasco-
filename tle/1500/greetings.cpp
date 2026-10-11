#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

using ordered_multiset = tree<
    pair<int, int>,
    null_type,
    less<pair<int, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;





#define out_v(v) \
 for (auto &x : v) \
    cout << x << " "; \
 cout << '\n';

#define take_v(v) \
 for (auto &x : v) \
    cin>> x ; \

void solve() {
    int n ; cin >> n ;
    ordered_multiset st;
    int uid = 0 ;
    vector < vector < int >> v (n , vector < int >(2)) ;    for (int i = 0 ; i <  n; i++){
        for ( int j =0 ; j < 2 ; j++ ){
            cin >> v[i][j] ;
        }
        st.insert({v[i][1] , uid}) ;
        uid++ ;
    }  
    sort(v.begin() , v.end());
    long long int  ans = 0 ; 
    for ( int i = 0 ; i < n ; i++ ){
        int x = v[i][1] ;
        auto it = st.lower_bound({x, INT_MIN});
        if (it != st.end() && it->first == x) {
            int idx = st.order_of_key(*it);
            if ( idx > 0 ){
                ans += idx ;
            }


            st.erase(it);
        }
    }
    cout << ans << endl ;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t ; cin >> t ;  while(t--)
    solve();
    return 0;
}