#include <iostream>
using namespace std;
int len(long long x) {
    int ans = 0;
    while(x) {
        x/=10;
        ans++;
    }
    return ans;
}
int main() {
    int n, k;
    cin >> n >> k;
    long long val = 1;
    for(int i = 1; i < n; i++) val *= 10;
    long long lua = (long long)((val - 1) / k + 1) * k;
    int leng = len(lua);
    if(leng != n) cout << "NO\n";else
        cout << lua << endl;

}
