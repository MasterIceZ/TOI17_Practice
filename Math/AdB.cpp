/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: A divide B mod C
 * ALGO		: Fermat's Little Thoery
 * DATE		: 8 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

ll c;

ll mod_of_power(ll a, ll b){
	if(b == 1){
		return a % c;
	}
	ll now = mod_of_power(a, b/2);
	if(b % 2){
		return (((now * now) % c) * a) % c;
	}
	return (now * now) % c;
}

void solve(){
	ll a, b;
	cin >> a >> b >> c;
	ll ans = a % c;
	ans *= mod_of_power(b, c-2);
	cout << ans;
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
