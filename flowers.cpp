#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int q;
    int a[10005];
    int val = 0;
    int sum = 0;
    int tmp;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        val = max(val, tmp);
        sum += tmp;
    }
    cin >> q;
    cout << (long long)q * (val * n - sum);
}
