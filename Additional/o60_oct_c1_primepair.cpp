#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

const int MxN = 1e6 + 10;

int ok[MxN], dp[MxN];

void solve(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	for(int i=2; i*i<=1000000; ++i){
		if(ok[i]){
			continue;
		}
		dp[i] = 1;
		for(int j=i*2; j<=1000000; j+=i){
			ok[j] = i;
		}
	}
	for(int i=2; i<=1000000; ++i){
		if(ok[i]){
			dp[i] = dp[i / ok[i]] + 1;
		}
	}
	int ans1, ans2, res;
	ans1 = ans2 = res = 0;
	for(int i=2; i<=1000000; ++i){
		int x = b - (b % i);
		int y = d - (d % i);
		if(x < a ||  y < c){
			continue;
		}
		if(dp[i] < res){
			continue;
		}
		if(dp[i] > res){
			res = dp[i];
			ans1 = x;
			ans2 = y;
		}
		else{
			if(ans1 + ans2 < x + y){
				ans1 = x;
				ans2 = y;
			}
			else if(ans1 + ans2 == x + y && x > ans1){
				ans1 = x;
				ans2 = y;
			}
		}
	}
	cout << ans1 << " " << ans2 ;
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
