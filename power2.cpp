#include <bits/stdc++.h>

using namespace std;
int main () {
    int n;
    cin >> n;
    long long a[105];
    for(int i = 1; i<=n; i++) cin >> a[i];
    sort(a+1, a+n+1);
    long long p = 1;
    int pos = 1;
    bool ok = false;
    while(pos <= n) {
        while(p < a[pos]) p*= 2;
        if(p == a[pos]) cout << p << " ", ok = true;
        pos++;
    }
    if(!ok) cout << "No";
}
