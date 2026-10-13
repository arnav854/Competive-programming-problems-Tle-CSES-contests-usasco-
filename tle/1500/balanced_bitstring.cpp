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


string yes ="YES" ;
string no = "NO" ;
void solve() {
    int n , k ; cin >> n >> k ;
    string s ; cin >> s ; 
    for ( int i = 0 ; i < k ; i++ ){
        char p =s[i] ;
        for (int j = i+k ; j < n ;j+=k){
            if (s[j]!='?'&& p!='?' && (s[j]!=p)){
                cout <<no << endl ;
                return ;
            }else if (s[j]!='?'){
                p = s[j];
            }
        }
        s[i]=p;
    }
    int zero = 0 ; int one = 0 ;
    for (int i = 0 ; i < k ;i++ ){
        if (s[i]=='0') zero++ ;
        else if (s[i]=='1')one++ ;
    }
    if (zero>k/2 || one >k/2) {
        cout <<no << endl ;
        return ;
    }
    cout << yes << endl ;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t ; cin >> t ;  while(t--)
    solve();
    return 0;
}