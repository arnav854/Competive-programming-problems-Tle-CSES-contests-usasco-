#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

void solve() {
    string x;
    vector<int> v(257, -1);

    while (cin >> x) {
        if (x == "()") {
            vector<int> store;
            int last_val = 1;

            if (v[1] == -1) {
                cout << "incomplete" << endl;
            } else {
                store.push_back(v[1]);
                bool flag = false ;
                for (int i =2;  i < 257 ; i++ ){
                    if (v[i]!=-1){
                        if (v[i/2]==-1){
                            cout <<"incomplete"<< endl; 
                            flag = true ;
                            break ; 
                        }else {
                            store.push_back(v[i]); 
                        }
                    }
                }
                if (!flag){
                    for (auto it : store)
                        cout << it << " ";

                    cout << endl;
                }
            }

            v = vector<int>(257, -1);
        } else {
            int n;
            string path;
            char ch;

            stringstream temp(x);
            temp >> ch >> n >> ch;
            getline(temp, path, ')');

            int st = int(pow(2, path.size()));

            for (int i = 0; i < path.size(); i++) {
                if (path[i] == 'R') {
                    st += int(pow(2, path.size() - (i + 1)));
                }
            }

            v[st] = n;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}