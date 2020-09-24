#include <bits/stdc++.h>

using namespace std;
int fen[5005];
int n;
int a[100005];
int d[100005];
void update(int p, int val){
    for(int i = p; i <= 5000; i += i & -i)
        fen[i] += val;
}
int sum(int p) {
    int ans = 0;
    for(int i = p; i; i -= i & -i)
        ans += fen[i];
    return ans;
}
int main() {

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = n; i >=1; i--) {
        d[i] = sum(a[i]);
        update(a[i], 1);
    }
    int ans = -1;
    for(int i = 1; i <= n; i++) {
        if(d[i] != 0) {
            ans = max(ans, d[i] + a[i]);
        }
    }
    if(ans != -1) cout << ans << endl;
    else {
        sort(a+1, a+n+1);
        a[0] = -1;
        int count = 0;
        for(int i = 1; i <= n; i++) if(a[i] != a[i-1]) count++;
        cout << count << endl;
    }
}
