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

using ll = long long;

int a[1010][1010], b[1010][1010];
ll dp0[1010][1010], dp1[1010][1010];

void solve(){
	int r, c, k;
	cin >> r >> c >> k;
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			cin >> a[i][j];
			b[i][j] = a[i][j];
		}
	}
	if(k == 2){
		for(int i=1; i<=r; ++i){
			for(int j=1; j<=c; ++j){
				cin >> b[i][j];
			}
		}
	}
	for(int i=r; i>=1; --i){
		for(int j=c; j>=1; --j){
			dp1[i][j] = 1e18;
			if(i == r && j == c){
				dp1[i][j] = b[i][j];
			}
			if(i + 1 <= r){
				dp1[i][j] = min(dp1[i][j], dp1[i+1][j] + b[i][j]);
//				cout << dp0[i][j] << " ";
//				cout << "DONE 1" << endl;
			}
			if(j + 1 <= c){
				dp1[i][j] = min(dp1[i][j], dp1[i][j+1] + b[i][j]);
//				cout << dp0[i][j] << " ";
//				cout << "DONE 2" << endl;
			}
		}
	}
	ll ans = 1e18;
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			dp0[i][j] = 1e18;
			if(i == 1 && j == 1){
				dp0[i][j] = a[i][j];
			}
			if(i - 1 > 0){
				dp0[i][j] = min(dp0[i][j], dp0[i-1][j] + a[i][j]);
//				cout << "DONE 3\n";
			}
			if(j - 1 > 0){
				dp0[i][j] = min(dp0[i][j], dp0[i][j-1] + a[i][j]);
//				cout << "DONE 4\n";
			}
			ans = min(ans, dp0[i][j] + dp1[i][j] - max(a[i][j], b[i][j]));
		}
	}
	cout << ans ;
//	for(int i=1; i<=r; ++i){
//		for(int j=1; j<=c; ++j){
//			cout << dp0[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;	
//	for(int i=1; i<=r; ++i){
//		for(int j=1; j<=c; ++j){
//			cout << dp1[i][j] << " ";
//		}
//		cout << endl;
//	}	
	memset(dp0, 0, sizeof dp0);
	memset(dp1, 0, sizeof dp1);
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
