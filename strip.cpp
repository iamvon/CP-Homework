#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    int a[100005];
    int dem[10005];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i], dem[a[i]] = 0;
    int sl = 0;
    int u = -1, v = -1;
    int res = 0;
    int st = 0;
    int l = 0, r = -1;
    u = a[0];
    for(int i = 0; i < n; i++) {
        r = i;
        dem[a[i]]++;
        if(a[i] != u) {
            r = i;
            v = a[i];
            break;
        }
    }
    res = r + 1;
    sl = 2;
    while(r < n) {
        while(sl <= 2) {
            r++;
            if(r == n) {
                if(res < r - l) {
                    res = r - l;
                    st = l;
                }
                break;
            }
            if(a[r] != u && a[r] != v) sl++;
            if(sl > 2) {
                if(res < r - l) {
                    res = r - l;
                    st = l;
                }
            }
            dem[a[r]]++;
        }
        if(r==n) break;
        while(sl > 2 && l < n) {

            dem[a[l]]--;

            if(dem[a[l]] == 0) {
                sl--;
                if(a[l] == u) u = -1;
                else if(a[l] == v) v = -1;
            }
            l++;
        }

        if(u == -1) u = a[r];else if(v == -1) v = a[r];
    }
    cout << st + 1 << " " << res << endl;
}
