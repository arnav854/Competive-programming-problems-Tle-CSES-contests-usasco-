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
    string ye ="YES" ;
    string no  ="NO" ; 
    int n ; cin >> n ;
    string  s ; cin >> s ; 
    int add = 0 ; int subs = 0 ; 
    for ( int i = 0 ; i < n ; i++ ){
        if (s[i] == '+') add++ ; 
        else subs ++ ;
    } 
    int q ; cin >> q ;
    // cout << add << " " << subs << endl ; 
    while ( q-- ){
        int a , b ; cin >> a >> b  ; 
        int maxi = max ( a, b ) ;
        int mini = min (a , b ) ;
        int diff = maxi - mini  ;
       ll val = 1LL * maxi * add - 1LL * maxi * subs;
        // cout << val << " " << diff << endl ; 
        if ( val == 0 ){
            cout << ye << endl ; 
            continue ; 
        }
        if ( diff == 0 ){
            cout << no <<endl ;
            continue ; 
        }
        if (val % diff !=0 ) {
            cout << no << endl ;
            continue;
        }
        ll div = (val/diff) ;
        div = abs(div) ;
        // cout << div << endl ; 
        if ( val >=0 ){
            if (div <= add ) cout << ye << endl ;
            else cout << no << endl; 
        }else {
            if (div<= subs) cout << ye << endl ;
            else cout << no << endl ;
        }

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}