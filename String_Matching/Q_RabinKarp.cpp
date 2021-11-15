/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Q_Rabin Karp
 * ALGO		: Rabin Karp
 * DATE		: 14 Nov 2021
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

const ll MOD = 12582917;
const ll HSH = 37;

ll create(char s){
	if(isalpha(s)){
		return s - 'a' + 10;
	}
	return s - '0';
}

void solve(){
	string text, pattern;
	cin >> text >> pattern;
	ll ht, hp;
	ht = hp = 0;
	for(int i=0; i<pattern.size(); ++i){
		ht = ((ht * HSH) + create(text[i])) % MOD;
		hp = ((hp * HSH) + create(pattern[i])) % MOD;
	}
	ll cut = 1;
	for(int i=1; i<pattern.size(); ++i){
		cut = (cut * HSH) % MOD;
	}
	for(int i=0; i<=text.size() - pattern.size(); ++i){
		if(ht == hp){
			int x;
			for(x = 0; x<pattern.size(); ++x){
				if(pattern[x] != text[i + x]){
					break;
				}
			}
			if(x == pattern.size()){
				cout << "Lucky";
				return ;
			}
		}
		ht -= (create(text[i]) * cut) % MOD;
		ht += MOD;
		ht %= MOD;
		ht = ((ht * HSH) + create(text[i + pattern.size()])) % MOD;
	}
	cout << "Unlucky";
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
