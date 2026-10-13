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
    int n ; cin >> n ; 
    vector < int > visit(n,-1) ;
    vector < vector < int >> part (n) ; 
    stack < int >st  ; 

    for ( int i = 0 ; i < n-1 ; i++ ){
        int a , b  ; cin >> a >> b ; 
        a-- ; b-- ;
        part[a].push_back(b) ;
        part[b].push_back(a) ;
    }
    st.push(0); visit[0]=0;
    while (!st.empty()){
        int val = st.top() ;
        st.pop();
        for (auto it : part[val]){
            if (visit[it]==-1){
                st.push(it) ;
                visit[it]=1-visit[val];
            }
        }
        
    }
    int v = 0 ;
    vector < int > u_vec ; 
    for ( int  i = 0 ; i < n ;i++ ){
        if (visit[i]==1){
            v++ ;
           
        }else {
            u_vec.push_back(i) ;
        }
    }
    ll ans = 0 ;
    for (int i  = 0 ; i <u_vec.size() ;i++ ){
        ans += (v-part[u_vec[i]].size()) ; 
    }
    cout << ans << endl ;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    solve();
    return 0;
}