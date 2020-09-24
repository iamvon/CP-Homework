#include <iostream>
using namespace std;
int main() {
    unsigned int m,n;
    cin >> m >> n;
        unsigned int sovong = (min(m,n) + 1) / 2;
        unsigned int val = (n>=m)? ((m%2)?0:2) : ((n%2)?1:3);
        cout << (sovong - 1) * 3 + sovong - 1 + val << endl;

}
