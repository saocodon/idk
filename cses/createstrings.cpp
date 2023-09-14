#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int cnt = 0;
string s;
char x[8];
bool a[8];

void Try(int i) {
    for (int j = 0; j < s.length(); j++) {
        if (!a[j]) {
            // unmark previous result
            a[x[i]] = false;
            // mark current result
            a[j] = true;
            x[i] = j;
            if (i == s.length() - 1) {
                // print result
                for (int k = 0; k <= i; k++)
                    cout << s[x[k]];
                cout << "\n";
                cnt++;
            } else {
                Try(i + 1);
                a[j] = false;
            }
        }
    }
}

int main() {
    cin >> s;
    sort(s.begin(), s.end());
    Try(0);
    cout << cnt;
}
