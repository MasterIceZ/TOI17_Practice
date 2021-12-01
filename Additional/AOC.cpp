/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int a[2222];

void solve(){
	int n, cnt = 0;
	n = 2000;
//	n = 10;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	int last = 1e9 + 10;
	for(int i=1; i<=n; i += 4){
		for(int j=0; j<=3 && i + j + 3 <= 1 + n; ++j){
//			cerr << "i + j : " << i + j << "\n";
			int stp = i + j, sum = 0;
			for(int k=0; k<3; ++k){
				sum += a[k + stp];
			}
//			cerr << sum << "\n";
			cnt += (sum > last);
			last = sum;
		}
	}
	cout << cnt;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
