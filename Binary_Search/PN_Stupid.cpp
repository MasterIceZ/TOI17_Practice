/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PN_Stupid
 * ALGO		: Binary Search
 * DATE		: 29 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

void solve(){
	ll p, s;
	cin >> s >> p;
	ll l, r;
	l = 0, r = s / 2;
	while(l <= r){
		ll a = (l + r) / 2;
		ll b = s - a;
		if(a * b == p && a * b / b == a){
			cout << a << " " << b;
			return ;
		}
		if(a * b > p || a * b / b != a){
			r = a - 1;
		}
		else{
			l = a + 1;
		}
	}
	cout << "No answer";
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
