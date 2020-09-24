#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int k = sqrt(n);
    int ans = k * 2 - 1;
    int remain = n - k*k;
    while(remain) {
        ans += remain / k;
        remain = remain - (remain /k) * k;
        k--;
    }
    cout << ans;
}
