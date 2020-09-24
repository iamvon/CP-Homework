#include <iostream>
#include <random>
#include <cstdlib>

using namespace std;

const int n = 8;
int a[n*n];

int x[n];

int res = -1;
int arr[n];

void show(int sum) {
    static int count = 0;
    count++;
    cout << count << ": ";
    for(int i = 0; i < n; i++) cout << x[i] << " ";
    cout << sum << endl;

}
bool ok(int k, int i) {
    for(int j = 0; j < k; j++) {
        if(i == x[j] || abs(k -j) == abs(i - x[j])) return false;
    }
    return true;
}
void backtrack(int k) {
    if( k == n) {
       int sum = 0;
       for(int i = 0; i < n; i++) sum += a[i * n + x[i]];
       if(sum > res) {
            res = sum;
            for(int i = 0; i < n; i++) arr[i] = x[i];
       }
       //show(sum);
    } else {
        for(int i = 0; i < n; i++) {
            if(ok(k, i)) {
                x[k] = i;
                backtrack(k + 1);
            }
        }
    }
}
int main() {
    srand(123456789);
    for(int i = 0; i < n*n; i++) cin >> a[i]; //a[i] = rand() % 32000 + 1;
    /*for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cout << a[i * n +j] << " ";
        cout << endl;
    }*/
    backtrack(0);
    cout << res << endl;
    //for(int i = 0; i < n; i++) cout << arr[i] << " ";
}
