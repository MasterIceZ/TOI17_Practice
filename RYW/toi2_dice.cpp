/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi2_dice
 * ALGO		: Implementation
 * DATE		: 14 Dec 2021
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
	int n;
	cin >> n;
	while(n--){
		vector<int> v = {0, 1, 2, 3, 4, 5, 6};
		string s;
		cin >> s;
		for(auto x: s){
			if(x == 'F'){
				v[0] = v[2];
				v[2] = v[1];
				v[1] = v[5];
				v[5] = v[6];
				v[6] = v[0];
			}
			else if(x == 'B'){
				v[0] = v[1];
				v[1] = v[2];
				v[2] = v[6];
				v[6] = v[5];
				v[5] = v[0];
			}
			else if(x == 'L'){
				v[0] = v[1];
				v[1] = v[4];
				v[4] = v[6];
				v[6] = v[3];
				v[3] = v[0];
			}
			else if(x == 'R'){
				v[0] = v[1];
				v[1] = v[3];
				v[3] = v[6];
				v[6] = v[4];
				v[4] = v[0];
			}
			else if(x == 'C'){
				v[0] = v[2];
				v[2] = v[4];
				v[4] = v[5];
				v[5] = v[3];
				v[3] = v[0];
			}
			else{
				v[0] = v[2];
				v[2] = v[3];
				v[3] = v[5];
				v[5] = v[4];
				v[4] = v[0];
			}
		}
		cout << v[2] << " ";
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
