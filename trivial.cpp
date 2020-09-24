#include <bits/stdc++.h>
using namespace std;
double cal(int x) {
    int sum = -x;
    for(int i = 1; i <= (int)sqrt(x); i++) {
        if(x%i==0) {
            sum += i;
            if(i < x/i) sum += x/i;
        }
    }
    return (double)sum * 1.0 / x;
}
double cal2(int x) {
    int sum = -x;
    for(int i = 1; i <= x; i++) if(x%i==0) sum += i;
    return (double)sum * 1.0 / x;
}
int main() {
    int a, b;


    while(cin >> a >> b) {
        double mi = 100007, ma = 0;
        int miv, mav;

        double mi2 = 100007, ma2 = 0;
        int miv2, mav2;
        for(int i = a; i <= b; i++) {
            double val = cal2(i);
            if(val < mi) {
                mi = val;
                miv = i;
            }
            if(val > ma) {
                ma = val;
                mav = i;
            }
        }
        cout << miv << " " << mav << endl;

        for(int i = a; i <= b; i++) {
            double val2 = cal(i);
            if(val2 < mi2) {
                mi2 = val2;
                miv2 = i;
            }
            if(val2 > ma2) {
                ma2 = val2;
                mav2 = i;
            }
        }
        cout << miv2 << " " << mav2 << endl;
    }
}
