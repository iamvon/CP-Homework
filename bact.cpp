#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
long long k;

int main(){
    cin>>a>>b>>c>>d>>k;
    int cnt = a;
    int check = 0;
    while(k--){
        cnt = max(min(cnt*b-c,d),0);
        if(check == 0&& (cnt == d || cnt == a)){
            check = 1;
        }
        else if((cnt == d || cnt == a)&& check == 1) break;
        if (cnt == 0) break;
    }
    cout<<cnt;
}
