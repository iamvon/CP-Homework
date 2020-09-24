#include <iostream>
#include <random>
#define maxn 20

using namespace std;

int d;
int n;
int a[maxn];
int res = 0;
int x[maxn];
int arr[maxn];
void thu(int k, int sum) {
    if(k == n) {
        if(sum > res) {
            res = sum;
            for(int i = 0; i < n; i++) arr[i] = x[i];
        }
    } else {
        if(sum + a[k] <= d) {
            x[k] = 1;
            sum += a[k];
            thu(k + 1, sum);
            sum -= a[k];
        }
        x[k] = 0;
        thu(k + 1, sum);

    }
}
int main() {
    while(cin >> d) {
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        thu(0, 0);
        for(int i = 0; i < n; i++) if(arr[i] == 1) cout << a[i] << " ";
        cout << "sum:" << res << endl;
        res = 0;
    }
}
