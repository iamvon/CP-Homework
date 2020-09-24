#include <bits/stdc++.h>

using namespace std;
string convert(int N) {
    string s = to_string(N);
    while(s.length() < 4) s = "0" + s;
    return s;
}
int cf[201][9000];
int ma[201];
int slma = 0;
bool ddid[9999];
int n;

struct stdt{
    int src, time, dur, tar;
};

stdt data[101];
int sldata = 0;
bool dd[101];
void call(int time, int id) {
    cout << "AT " << convert(time) << " CALL TO " << convert(id) << " RINGS ";
    int idx = upper_bound(ma, ma + slma, id) - ma - 1;
    if( idx >= slma  || ma[idx] != id){
        cout << convert(id) << "\n";
        return;
    }
    for(int i = 0; i < slma; i++) dd[i] = false;
    dd[idx] = true;
    while(cf[idx][time] != -1) {
        idx = cf[idx][time];
        if(dd[idx]) {
            cout << convert(9999) << "\n";
            return;
        }
    }
    cout << convert(ma[idx]) << "\n";
}
int main() {
    cin >> n;
    int count = 0;
    int val;
    while(cin >> val) {
        if(val != 0) {
            data[sldata].src = val;
            cin >> val, data[sldata].time = val;
            cin >> val, data[sldata].dur = val;
            cin >> val, data[sldata].tar = val;
            sldata++;
        } else {
            count++;
            cout << "CALL FORWARDING OUTPUT\n";
            cout << "SYSTEM " << count << "\n";
            break;
        }
    }
    for(int i = 0; i < 9999; i++) ddid[i] = false;
    for(int i = 0; i < sldata; i++) {
        if(ddid[data[i].src] == false) ma[slma++] = data[i].src, ddid[data[i].src] = true;
        if(ddid[data[i].tar] == false) ma[slma++] = data[i].tar, ddid[data[i].tar] = true;
    }
    sort(ma, ma + slma);
    for(int i = 0; i < slma; i++) {
        for(int t = 0; t <= 8784; t++) cf[i][t] = -1;
    }
    for(int i = 0; i < sldata; i++) {
        int src = data[i].src;
        int time = data[i].time;
        int dur = data[i].dur;
        int tar = data[i].tar;
        int idxS = upper_bound(ma, ma + slma, src) - ma - 1;
        int idxT = upper_bound(ma, ma + slma, tar) - ma - 1;
        for(int j = time; j <= time + dur; j++) cf[idxS][j] = idxT;
    }
    while(cin >> val) {
        if(val == 0) {
            count++;
            cout << "SYSTEM " << count << "\n";
        }
        if(val == 9000 && count == n) {
            cout << "END OD OUTPUT\n";
            break;
        }
        if(val != 9000 && val != 0) {
            int id, time;
            time = val;
            cin >> val;
            id = val;
            call(time, id);
        }
    }
}
