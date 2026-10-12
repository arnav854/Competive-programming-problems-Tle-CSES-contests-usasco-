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
# define end '\n'


#define out_v(v) \
 for (auto &x : v) \
    cout << x << " "; \
 cout << '\n';

#define take_v(v) \
 for (auto &x : v) \
    cin>> x ; \

void solve() {
    int n ; cin >> n ; 
    vi v (n) ;
    take_v(v) ;
    string s ; cin >> s ; 
    vi pre(n+1) ;
    int xor_0 (0) ,xor_1 (0) ; 
    for (int i = 0 ; i < n ; i++ ){
        pre[i+1] = pre[i]^ v[i] ;
        if (s[i]=='0') xor_0 ^= v[i] ;
        if (s[i]=='1') xor_1 ^= v[i] ;
    }

    int q ; cin >> q ;
    while ( q-- ){
        int p ;  cin >> p ;
        if (p == 1){
            int a , b ; cin >> a >> b  ;
            xor_0 =  xor_0 ^ (pre[b]^(pre[a-1])) ;
            xor_1 =  xor_1 ^ (pre[b]^(pre[a-1]));
        }else {
            int a ; cin >> a ;
            if ( a == 1 ){
                cout << xor_1 << " " ;
            }else {
                cout << xor_0 << " " ;
            }
        }
    }
    cout << end ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t ; cin >> t ;  while(t--)
    solve();
    return 0;
}