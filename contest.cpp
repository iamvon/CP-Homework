#include <iostream>
using namespace std;
int main() {
    int n,t,f,x;
    cin >> n >> t >> f >> x;
        if((t-1)*60 - (n-f)*x == 0) {
            cout << "EXACT!\n";
        } else if((t-1)*60 - (n-f)*x > 0) {
            cout << "YES\n";
            cout << (t-1)*60 - (n-f)*x<<"\n";
        } else {
            cout << "NO\n";
            cout << -(t-1)*60 + (n-f)*x<<"\n";
            cout << n - f - (t-1)*60/x<<"\n";
        }

}
