/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Jelly
 * ALGO		: Implement
 * DATE		: 24 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int divide(int a){
	int cnt = 0;
	while(a != 1){
		++cnt;
		a /= 2;
	}
	return cnt;
}

void solve(){
	int a, b, c, cnt = 0;
	cin >> a >> b >> c;
	cnt += divide(a) + divide(b) + divide(c);
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
