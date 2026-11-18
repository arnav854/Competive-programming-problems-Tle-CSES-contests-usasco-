#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <vector>
using namespace std;
using namespace __gnu_pbds;
void calc_parent (vector < vector < pair < int , int > >> &parent , vector <vector < char>>&v , int i , int j , int r , int c , vector < vector< int >> &visited){
    if (i >= r || i < 0 || j >= c || j < 0 ) return ;
    if (visited[i][j] == 1) return  ; 
    visited[i][j] = 1 ;
    if (i-1>=0 && v[i][j]==v[i-1][j]) {
        parent[i-1][j].first = parent[i][j].first ;
        parent[i-1][j].second = parent[i][j].second ;
        calc_parent(parent , v , i-1 , j , r ,c , visited ) ;
    } 
    if (i+1 < r  && v[i][j]==v[i+1][j]) {
        parent[i+1][j].first = parent[i][j].first ; 
        parent[i+1][j].second = parent[i][j].second ; 
        calc_parent(parent , v , i+1 , j , r ,c , visited ) ;
    }
    
    if (j-1>=0 && v[i][j-1]==v[i][j]) {
        
        parent[i][j-1].first = parent[i][j].first ; 
        parent[i][j-1].second = parent[i][j].second ; 
        calc_parent(parent , v , i , j-1 , r ,c , visited ) ;
    }
    if (j+1 < c && v[i][j+1]==v[i][j]) {
        parent[i][j+1].first = parent[i][j].first ; 
        parent[i][j+1].second = parent[i][j].second ; 
        calc_parent(parent , v , i , j+1 , r ,c , visited ) ;
    
    }

}
string ne ="neither" ;
string de ="decimal" ;
string bi ="binary" ;

void solve() {
    int r ,c ; cin >> r >> c ; 
    vector < vector < char >> v ( r, vector < char > (c) ) ;
    vector < vector < pair < int , int > >> parent( r , vector < pair < int , int >>(c)) ;
    vector < vector < int >> visited(r , vector < int > (c)) ;

    for ( int i = 0 ; i < r ; i++ ){
        for ( int j =0 ;  j < c ; j++ ) {
            cin >> v[i][j] ;
            parent[i][j] = {i,j} ;
            visited[i][j] = -1 ; 
        }
    }
    for (int i = 0 ;  i < r ; i++ ){
        for ( int j = 0 ; j < c ; j++ ){
            if (visited[i][j]==-1){
                calc_parent(parent , v , i , j , r , c , visited) ;
            }
        }
    }
    int q ; cin >> q ;
    while(q--){
        int r1 , c1 , r2 , c2 ; cin >> r1 >> c1 >> r2 >> c2  ;
        r1-- ; r2-- ; c1-- ; c2-- ; 
        if (parent[r1][c1]==parent[r2][c2] && v[r1][c1]=='1'){
            cout << de << endl ;
        }else if( parent[r1][c1]==parent[r2][c2] && v[r1][c1]=='0'){
            cout << bi << endl ; 
        }else { 
            cout << ne << endl; 
        }


    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}