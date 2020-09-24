#include <iostream>
#include <random>
#define maxn 20

using namespace std;

const int n = 12;
int s, d;
int res = -1;
int x[maxn];
int arr[maxn];
void thu(int k, int sum) {
    if(k == n) {
        int tong = 0;
        for(int i = 0; i < n; i++) tong += (x[i]) ? -d : s;
        if(tong > res) {
            res = tong;
            for(int i = 0; i < n; i++) arr[i] = x[i];
        }
    } else {
        if(k >= 5) sum -= (x[k-5]) ? -d : s;
        x[k] = 0;
        sum += s;
        if(k >= 4 && sum >= 0) sum -= s;
        else {
            thu(k + 1, sum);
            sum -= s;
        }
        x[k] = 1;
        sum -= d;
        if(k >= 4 && sum >= 0) sum += d;
        else {
            thu(k + 1, sum);
            sum += d;
        }
    }
}
int main() {
    while(cin >> s) {
        cin >> d;
        thu(0, 0);
        if(res >= 0) {
            cout << res << endl;
            for(int i = 0; i < n; i++) cout << arr[i] << " ";cout << endl;
        } else cout << "Deficit\n";
        res = -1;
    }
}
