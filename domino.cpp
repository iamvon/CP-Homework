#include <iostream>
#include <random>
#define maxn 25

using namespace std;

int n;
int a[maxn];
int res;
int hieu;
int x[maxn];
int arr[maxn];
int sum() {
    int val = 0;
    for(int i = 0; i < n; i++) {
        val += (x[i]) ? a[i] : -a[i];
    }
    return abs(val);
}
void tryy(int k) {
    if(k == n) {
        int val = sum();
        if(val < res) {
            res = val;
            for(int i = 0; i < n; i++) arr[i] = x[i];
        }
    } else {
        x[k] = 0;
        tryy(k + 1);
        x[k] = 1;
        tryy(k + 1);
    }
}
int main() {
    hieu = 0;
    cin >> n;
    int tren, duoi;
    for(int i = 0; i < n; i++) {
        //tren = rand() % 7;
        //duoi = rand() % 7;
        cin >> tren >> duoi;
        a[i] = tren - duoi;
        hieu += a[i];
    }
    res = abs(hieu);
    tryy(0);

    cout << res << endl;
    //for(int i = 0; i < n; i++) if(arr[i] == 1) cout << i << " ";
}
