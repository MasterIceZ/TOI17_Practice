/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PN_Find Root
 * ALGO		: Divide and Conquer
 * DATE		: 19 Aug 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

ll mod;

struct Poly{
	ll one, two, three, six;
};
Poly mul(Poly lhs, Poly rhs){
	Poly ret;
	ret.one = ((lhs.one * rhs.one) % mod + (lhs.two * rhs.two * 2) % mod + (lhs.three * rhs.three * 3) % mod + (lhs.six * rhs.six * 6) % mod) % mod;
	ret.two = ((lhs.one * rhs.two) % mod + (lhs.two * rhs.one) % mod + (3 * lhs.six * rhs.three) % mod + (3 * lhs.three * rhs.six) % mod) % mod;
	ret.three = ((lhs.one * rhs.three) % mod + (lhs.three * rhs.one) % mod + (lhs.two * rhs.six * 2) % mod + (lhs.six * rhs.two * 2) % mod) % mod;
	ret.six = ((lhs.one * rhs.six) % mod + (lhs.six * rhs.one) % mod + (lhs.two * rhs.three) % mod + (lhs.three * rhs.two) % mod) % mod;
	return ret;
}

Poly divide(Poly now, ll n){
	if(n == 0){
		return Poly{1, 0, 0, 0};
	}
	Poly tmp = divide(now, n/2);
	Poly m = mul(tmp, tmp);
	if(n % 2){
		m = mul(m, now);
	}
	return m;
}
void solve(){
	Poly start;
	ll n;
	cin >> start.one >> start.two >> start.three >> n >> mod;
	start.one %= mod;
	start.two %= mod;
	start.three %= mod;
	start.six = 0;
	Poly ans = divide(start, n);
	cout << ans.one << " " << ans.two << " " << ans.three << " " << ans.six;
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
