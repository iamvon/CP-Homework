#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int vang = 0, bac = 0;
    int val;
    for(int i = 0; i < n; i++) {
        cin >> val;
        if(val > vang) {
            bac = vang;
            vang = val;
        } else if(val == vang) {}
        else if(val > bac) {
            bac = val;
        }
    }
    cout << bac << endl;
}
