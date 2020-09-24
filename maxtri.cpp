#include <iostream>
using namespace std;
int main() {
    int a,b,c;
    cin >> a >> b >> c;
    if(a < b) swap(a,b);
    if(a < c) swap(a,c);
    if(b < c) swap(b,c);
    if(a==0&&b==0&&c==0) cout << 0;else cout << a << b << c;
}
