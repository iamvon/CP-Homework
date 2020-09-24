#include <bits/stdc++.h>
using namespace std;
int n;
int a[300003][6];
int Q;
int main() {
    int w, h, c;
    cin >> n;
    for(int i = 1; i <= 5; i++) a[0][i] = 0;
    for(int i = 1; i<= n; i++) {
        cin >> w >> h >> c;
        for(int c_ = 1; c_ <= 5; c_++) {
            a[i][c_] = (c_ == c) ? a[i-1][c_] + w*h : a[i-1][c_];
        }
    }
    cin >> Q;
    for(int i = 1; i <= Q; i++) {
        cin >> w >> h >> c;
        cout << a[h][c] - a[w][c] << endl;
    }
}
