#include <bits/stdc++.h>

using namespace std;

int minDel (const string &s) {
    stack<char> temp;
    int count = 0;
    for (const auto x: s) {
        if(x == 'b') temp.push('b');
        else if(!temp.empty()) {
            temp.pop();
            count++;
        }
    }
    return count;
}

int main() {
    string s;
    cin >> s;
    cout << minDel(s);
    return 0;
}