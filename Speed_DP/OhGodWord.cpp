/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Oh! god word
 * ALGO		: Binary Search
 * DATE		: 16 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

char a[1010];
int dp[1010][1010];

void solve(){
	cin >> a;
	int len = strlen(a);
	for(int i=0; i<len; ++i){
		dp[i][i] = 1;
	}
	int nax = 1, pt = 0;
	for(int i=len-2; i>=0; --i){
		if(a[i] == a[i + 1]){
			dp[i][i+1] = 1;
			nax = 2;
			pt = i;
		}
	}
	for(int k=3; k<=len; ++k){
		for(int i=0; i<=len; ++i){
			int j=i + k - 1;
			if(dp[i + 1][j - 1] == 1 && a[i] == a[j]){
				dp[i][j] = 1;
				if(k > nax){
					nax = k, pt = i;
				}
			}
		}
	}
	for(int i=pt; i<pt + nax; ++i){
		cout << a[i];
	}
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
