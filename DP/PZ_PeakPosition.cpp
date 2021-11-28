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

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const ll MOD = 1e9 + 9;
const ll MxN = 1e6;
ll mem[MxN + 10], fac[MxN + 10];

void solve(){
	int i;
	cin >> i;
	cout << mem[i];
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	fac[0] = fac[1] = 1;
	for(ll i=2; i<=MxN; ++i){
		fac[i] = fac[i - 1] * i;
		fac[i] %= MOD;
	}
	mem[0] = 0, mem[1] = 0, mem[2] = 0;
	for(int i=3; i<=MxN; ++i){
		mem[i] = (i - 2) * (mem[i - 1] + fac[i - 1]);
		mem[i] %= MOD;
	}
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
