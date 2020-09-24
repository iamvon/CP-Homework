#include <bits/stdc++.h>

using namespace std;
void cal(int sum, int n, long long &u, long long &v, long long &res) {
    int tmp = sum;
    long long big = 0;
    for(int i = 0; i < n; i++) {
        int choo = min(sum, 9);
        big = big *10 + choo;
        sum -= choo;
    }
    //cout << big << " ";
    sum = tmp;
    long long small = 0;
    for(int i = 0; i < n; i++) {
        int choo = (i == 0) ? max(1, sum - (n - i - 1) * 9) : max(0, sum - (n - i - 1) * 9);
        choo = min(choo, 9);
        small = small *10 + choo;
        sum -= choo;
    }
    //cout << small << endl;
    if(sum == 0) {
        if(res < big - small) {
            res = big - small;
            u = big, v = small;
        }
    }
}
int main() {
    int n;
    long long u, v;

    cin >> n;
    long long res = -1;
    for(int sum = 1; sum <= 9*n; sum++) cal(sum, n, u, v, res);
    //cout << u << " - " << v << " = ";
    cout << res << endl;

}
