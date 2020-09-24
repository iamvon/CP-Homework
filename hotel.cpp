#include <iostream>
using namespace std;
int main() {
    int n;

    cin>>n;
        int f[101];
        int pre[101];
        f[0] = 0;
        f[2] = 1;pre[2] = 2;
        f[3] = 1;pre[3] = 3;
        for(int i = 4; i <= n; i++) {
            f[i] = n+1;
            if(i-2 >= 2) {
                if(f[i] > f[i-2] + 1) {
                    f[i] = f[i-2] + 1;
                    pre[i] = 2;
                }
            }
            if(i-2 >= 2) {
                if(f[i] > f[i-3] + 1) {
                    f[i] = f[i-3] + 1;
                    pre[i] = 3;
                }
            }
        }
        int u=0,v=0;
        while(n) {
            if(pre[n] == 2) u++;
            else v++;
            n = n - pre[n];
        }
        cout << u << " " << v << endl;

}
