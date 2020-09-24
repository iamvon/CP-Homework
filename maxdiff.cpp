#include <iostream>
using namespace std;
int main() {
    int n;
    char a[100005];
    cin >> n;
    char u, val;
    int mi = 100005, ma = -100005;
    cin >> u;
    mi = 0;
    ma = 1;
    int dem = 1;
    for(int i = 1; i < n; i++) {
        cin >> val;
        if(val != u) dem--;
        else dem++;
        mi = min(mi, dem);
        ma = max(ma, dem);
    }
    cout << ma - mi;

}
