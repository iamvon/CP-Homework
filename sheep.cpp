#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, nbL;
    cin >> n;
    cin >> nbL;
    bool a[10];
    for(int i = 0; i < 10; i++) a[i] = false;
    int val;
    bool ko = true;
    for(int i = 0; i < nbL; i++) {
        cin >> val;
        a[val] = true;
        if(val == 0) ko = false;
    }
    vector<char> c;
    for(int i = 0; i < 10; i++) if(!a[i]) c.push_back(i + 48);
    int base = 10 - nbL;
    string res;
    if(base == 1) {
        for(int i = 0; i < n; i++) cout << c[0];
        return 0;
    }
    if(ko) {
        while(n) {
            res += c[n%base];
            n /= base;

        }
        reverse(res.begin(), res.end());
        cout << res;
    } else {
        int sum = 0;
        int sl = 0;
        int del = 1;
        while(sum < n) {
            sl++;
            del *= base;
            sum += del;
        }
        int th = n - sum + del - 1;
        del = 1;
        for(int k = 1; k <= sl; k++) {
            int ind = th % (del * base) / del;
            del *= base;
            res += c[ind];
        }
        reverse(res.begin(), res.end());
        cout << res;
    }
}
