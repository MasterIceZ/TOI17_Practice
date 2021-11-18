/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi3_treasure
 * ALGO		: Math
 * DATE		: 17 Nov 2021
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
	double ii = 0, jj = 0;
	while(1){
		string s;
		cin >> s;
		if(s == "*"){
			break;
		}
		int opr = 0;
		double cur = 0, di = 0, dj = 0;
		for(int i=0; i<s.size(); ++i){
			if(isdigit(s[i])){
				cur *= 10;
				cur += s[i] - '0';
			}
			else{
				if(s[i] == 'N'){
					opr++;
					di++;
				}
				else if(s[i] == 'S'){
					opr++;
					di--;
				}
				else if(s[i] == 'E'){
					opr++;
					dj++;
				}
				else{
					opr++;
					dj--;
				}
			}
		}
		if(opr > 1){
			cur /= sqrt(2);
		}
		ii += di * cur;
		jj += dj * cur;
	}
	cout << fixed << setprecision(3) << jj << " " << ii << "\n";
	cout << sqrt(ii * ii + jj * jj);
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
