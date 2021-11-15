/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi5_lkd
 * ALGO		: Implementation
 * DATE		: 15 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

void solve(){
	int q;
	cin >> q;
	int state = 1;
	while(q--){
		string s;
		cin >> s;
		int ans = 0;
		if(s.size() != 16){
			continue;
		}
		for(int i=0; i<8; ++i){
			string now = s.substr(i * 2, 2);
			ans *= 2;
			if(state == 1){
				if(now == "11"){
					state = 2;
					ans += 1;
				}
			}
			else if(state == 2){
				if(now == "10"){
					state = 3;
				}
				else{
					state = 4;
					ans += 1;
				}
			}
			else if(state == 3){
				if(now == "11"){
					state = 1;
				}
				else{
					state = 2;
					ans += 1;
				}
			}
			else{
				if(now == "01"){
					state = 3;
				}
				else{
					state = 4;
					ans += 1;
				}
			}
		}
		cout << (char)ans;
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
