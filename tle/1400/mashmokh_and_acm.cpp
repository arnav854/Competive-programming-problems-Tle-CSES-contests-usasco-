#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long int ll;
#define F first 
#define S second   
#define vi vector<int>
#define dvi vector<vector < int >>
#define vill vector<ll>
#define dvill vector<vector <ll>>
#define all(v) sort(v.begin(),v.end())
#define rev_all(v) sort(v.begin(),v.end(), greater<int>())
# define v_min(v) *min_element(v.begin() , v.end())
#define v_max *max_element(v.begin() , v.end())
# define v_min_f_idx min_element(v.begin() , v.end()) -v.begin()
# define v_max_f_idx max_element(v.begin() , v.end()) -v.begin()



#define out_v(v) \
 for (auto &x : v) \
    cout << x << " "; \
 cout << '\n';

#define take_v(v) \
 for (auto &x : v) \
    cin>> x ; \

void solve() {
    int MOD =  1e9+7 ; 
    int n , k ; cin >> n >> k ;
    vector < ll > dp(n+1,1) ;
    
    for ( int i = k-2 ; i >= 0 ; i -- ){
        vector < ll > new_dp (n+1) ;
        for ( int j =  1 ; j <= n ; j++ ){
            for ( int r  = 1 ; r*r <= j ; r++ ){
                if (j % r == 0 ){
                    new_dp[j]=(new_dp[j] + (dp[j/r]))%MOD ;
                    if (j/r !=r ){
                        new_dp[j]= (new_dp[j] + (dp[r]))%MOD ;
                    }
                }
            }
        }
        dp = new_dp ;
    }
    ll ans = 0 ;
    for ( int i = 1 ; i <= n ; i++ ){
        ans = (ans + dp[i])%MOD ;
    }
    cout << ans << endl ;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}