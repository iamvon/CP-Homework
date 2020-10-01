#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
	// your code goes here
	string a,b;
	int n,m;
	int da[10], db[10];
	cin >> a >> b;
	n = a.length();
	m = b.length();
	for (int i =0; i<=9; i++){
		da[i] = 0;
		db[i] =0;
	}
	for (int i = 0; i < n; i++){
		int k = a[i] -48;
		da[k]++;
	}
	for (int i = 0; i < m; i++){
		int k = b[i] -48;
		db[k]++;
	}
	string s = "";
	// cout << a << b<< endl;
	for (int i =9; i>=0; i--){
		// cout << i << ' ' << da[i] << ' ' << db[i]<< endl;
		if (da[i] == db[i]){
			for (int j =1; j<=da[i]; j++){
				s += char(i+48);
			}
		}
		else {
			for (int j = 1; j <= min(da[i], db[i]); j++){
				s += char(i+48);
			}
		}
	}
	if (s != ""){
		cout << s;
	}
	else {
		cout << "No solution";
	}
	return 0;
}
