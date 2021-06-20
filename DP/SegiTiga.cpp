/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: SegiTiga
 * ALGO		: Dynamic Programming
 * DATE		: 14 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int n, dp[333][333][5];
string s;

int opr(int x, int y){
	if(x == 0 && y == 2){
		return 0;
	}
	if((x == 0 && y == 0) || (x == 1 && y == 0) || (x == 2 && y == 1)){
		return 2;
	}
	return 1;
}

void solve(){
	memset(dp, 0, sizeof dp);
	cin >> n;
	cin >> s;
	if(s[0] != '0'){
		cout << "no";
		return ;
	}
	for(int sz=0; sz<n; ++sz){
		for(int i=0; i+sz<n; ++i){
			int j = i + sz;
			if(i == j){
				dp[i][j][s[i] - '0'] = 1;
			}
			else{
				for(int k=i; k<j; ++k){
					for(int a=0; a<3; ++a){
						for(int  b=0; b<3; ++b){
							if(dp[i][k][a] && dp[k+1][j][b]){
								dp[i][j][opr(a, b)] = 1;
							}
						}
					}
				}
			}
		}
	}
	cout << (dp[0][n-1][0]?"yes":"no");
//	cout << endl;
//	for(int i=0; i<n; ++i){
//		for(int j=0; j<n; ++j){
//			cout << "(" << dp[i][j][0] << ", " << dp[i][j][1] << ", " << dp[i][j][2] << ") ";
//		}
//		cout << endl;
//	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 20;
//	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
