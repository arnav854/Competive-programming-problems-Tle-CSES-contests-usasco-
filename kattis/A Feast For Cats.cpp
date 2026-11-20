#include <iostream>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

int parent (int a , vector < int > &p){
    int x = a ; 
    while (p[a]!=a){
        a = p[a] ;
    }
    p[x] = a ;
    return a ; 
}
void solve() {
    int l , c ; cin >> l >> c  ;
    int size = ((c)*(c-1))/2 ; 
    l-= c ; 
    vector < vector < int >> v (size , vector <int>(3)) ;
    for ( int i =0  ; i < size  ; i++ ){
        int a , b , c ;  cin >>a  >> b >> c ; 
        v[i][0] =  c ;
        v[i][1] =  a ;
        v[i][2] =  b ;
    }
    vector < int > parent_c (c) ;
    vector < int > cnt (c,1) ;
    for (int i= 0 ; i < c ; i++ ){
        parent_c[i] = i ;
    }
    sort(v.begin() , v.end()) ;
    int ans = 0 ;
    for (int i =0  ; i < size ; i++ ){
        int a = parent(parent_c[v[i][1]] , parent_c) ;
        int b = parent(parent_c[v[i][2]] , parent_c) ;
        if (a != b){
            ans += (v[i][0]) ; 
            if (cnt[a]>=cnt[b]){
                parent_c[b] = a ;
                cnt[a]+=(cnt[b]) ;
            }else {
                parent_c[a] = b ;
                cnt[b]+=(cnt[a]) ;

            }
        }
    }
    if (ans <= l ){
        cout << "yes" << endl ;

    }else cout << "no" << endl ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t ; cin >> t ;  while(t--)
    solve();
    return 0;
}