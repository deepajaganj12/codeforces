#include <bits/stdc++.h>
using namespace std;

char getChar(int idx) {
    return (idx % 2 == 0 ? 'a' : 'b');
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string x;
        cin >> x;

        int l = 0, r = n - 1;
        bool ok = true;

        for (int i = 0; i < n; i++) {
            char lc = getChar(l);
            char rc = getChar(r);

            bool canL = (x[i] == '?' || x[i] == lc);
            bool canR = (x[i] == '?' || x[i] == rc);

            if (!canL && !canR) {
                ok = false;
                break;
            }

            if (canL && canR) {
                if (l + 1 <= r) {
                    char nextL = getChar(l + 1);
                    if (x[i + 1] != '?' && x[i + 1] != nextL) {
                        r--;
                    } else {
                        l++;
                    }
                } else {
                    l++;
                }
            }
            else if (canL) {
                l++;
            }
            else {
                r--;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}
