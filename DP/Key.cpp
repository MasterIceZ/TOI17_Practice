/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Key TOI12
 * ALGO		: Dynamic Programming
 * DATE		: 13 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int lena, lenb, dp[1010][1010];
string a, b, name;

bool solve(){
	memset(dp, 0, sizeof dp);
	cin >> name;
	dp[0][0] = 1;
	for(int i=0; i<=lena; ++i){
		for(int j=0; j<=lenb; ++j){
			if(!dp[i][j]){
				continue;
			}
			if(i < lena && a[i] == name[i+j]){
				dp[1 + i][j] = 1;
			}
			if(j < lenb && b[j] == name[i+j]){
				dp[i][1 + j] = 1;
			}
		}
	}
	return dp[lena][lenb];
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);

	cin >> a >> b;
	lena = a.size(), lenb = b.size();
	int q = 1;
	cin >> q;
	while(q--){
		cout <<	(solve()?"Yes":"No");
		cout << endl;
	}
	return 0;
}
