/*
 _   __                   ___                ___  _____  _____ 
| | / /                  / _ \              /   |/ __  \|  _  |
| |/ /  __ _ _ __   __ _/ /_\ \_   _ _ __  / /| |`' / /'| |/' |
|    \ / _` | '_ \ / _` |  _  | | | | '_ \/ /_| |  / /  |  /| |
| |\  \ (_| | | | | (_| | | | | |_| | | | \___  |./ /___\ |_/ /
\_| \_/\__,_|_| |_|\__, \_| |_/\__,_|_| |_|   |_/\_____/ \___/ 
                    __/ |                                      
                   |___/
*/
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()

int m, a[444];
pair<int, int> dp[444][444];

void solve(){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; ++i){
		scanf("%d", &a[i]);
		dp[i][i] = make_pair(1, 1);
	}
	for(int sz=2; sz<=n; ++sz){
		for(int l=1; l<=n-sz+1; ++l){
			int r = l + sz - 1;
			// Base Case -> Only `L` Out
			dp[l][r] = make_pair(1 + dp[l + 1][r].first, 1);
			for(int k=l + 1; k<=r; ++k){
				if(a[l] == a[k]){
					pair<int, int> tmp = make_pair(dp[l + 1][k - 1].first + dp[k][r].first, dp[k][r].second + 1);
					if(tmp.second > m){
						tmp.first += 1;
						tmp.second = 1;
					}
					dp[l][r] = min(dp[l][r], tmp);
				}
			}
		}
	}
	printf("%d\n", dp[1][n].first);
}

int main(){
	int q;
	scanf("%d %d", &q, &m);
	while(q--){
		solve();
	}
	return 0;
}
