#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

void solve() {
    string s;
    getline(cin >> ws, s);

    stack<string> st;

    string l = "LOAD ";
    string m = "MIX";
    string sto = "STORE bowl_";
    string a = "ADD";
    string b = "BAKE ";
    string spr = "SPRINKL";
    string gr = "GRATE";

    int n = 1;

    stringstream ss(s);
    string x;

    while (ss >> x) {

        if (x == ")") {

            string temp1 = st.top(); st.pop();
            string op = st.top(); st.pop();
            string temp3 = st.top(); st.pop();

            cout << l << temp3 << '\n';

            if (op == m)
                cout << m << " ";
            else if (op == a)
                cout << a << " ";
            else if (op == spr)
                cout << spr << " ";
            else if (op == gr)
                cout << gr << " ";

            cout << temp1 << '\n';
            cout << sto << n << '\n';

            st.push("bowl_" + to_string(n));
            n++;
        }
        else if (x != "(") {
            st.push(x);
        }
    }

    cout << b << st.top() << '\n';
}
int main (){
    solve();
}