/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_No Discord
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

void solve(){
	int a, b;
	cin >> a >> b;
	if(a > 7 || b > 7){
		exit(0);
	}
	if(a == 1){
		cout << b-1;
	}
	else if(a == 2){
		set<tuple<int, int>> s;
		for(int i=2; i<=b; ++i){
			for(int j=2; j<=b; ++j){
				if(__gcd(i, j) != 1 && i + j <= b){
					s.emplace(i, j);
					dbg(i, j);
				}
			}
		}
		cout << s.size();
	}
	else if(a == 3){
		set<tuple<int, int, int>> s;
		for(int i=2; i<=b; ++i){
			for(int j=2; j<=b; ++j){
				for(int k=2; k<=b; ++k){
					if(i + j + k <= b && __gcd(__gcd(i, j), k) != 1){
						s.emplace(i, j, k);
						dbg(i, j, k);
					}
				}
			}
		}
		cout << s.size();
	}
	else{
		cout << 0;
	}
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
