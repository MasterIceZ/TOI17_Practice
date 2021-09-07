/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Pillar TCP
 * ALGO		: Dynamic Programming
 * DATE		: 7 Sep 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int a[100100], dp[100100];

void solve(){
	int n;
	cin >> n;
	for(int i=0; i<n; ++i){
		cin >> a[i];
	}
	dp[n - 1] = 1;
	for(int i=n-2; i>=0; --i){
		if(a[i + 1] - a[i] >= 1 && a[i + 1] - a[i] <= 2){
			dp[i] = dp[i + 1] + 1;
		}
		else{
			dp[i] = 1;
		}
	}
	int nax = 0, id = 0, sum = 0;
	for(int i=0; i<n; ++i){
		if(i < n - 1 && dp[i + 1] + 1 >= nax){
			if(dp[i + 1] + 1 == nax){
				id = min(i, id);
			}
			else{
				nax = dp[i + 1] + 1;
				id = i;
			}
		}
		if(i != 0 && sum + 1 >= nax){
			if(sum + 1 == nax){
				id = min(id, i);
			}
			else{
				nax = sum + 1;
				id = i;
			}
		}
		if(i > 0 && i < n - 1 && a[i + 1] - a[i - 1] >= 2 && a[i + 1] - a[i - 1] <= 4 && sum + dp[i + 1] + 1 >= nax){
			if(nax == sum + dp[i + 1] + 1){
				id = min(i, id);
			}
			else{
				nax = sum + dp[i + 1] + 1;
				id = i;
			}
		}
		if(i > 0 && a[i] - a[i - 1] >= 1 && a[i] - a[i - 1] <= 2){
			sum += 1;
		}
		else{
			sum = 1;
		}
	}
	dp[n - 1] = 1, sum = 0;
	for(int i=n-2; i>=0; --i){
		if(a[i] - a[i + 1] >= 1 && a[i] - a[i + 1] <= 2){
			dp[i] = dp[i + 1] + 1;
		}
		else{
			dp[i] = 1;
		}
	}
	for(int i=0; i<n; ++i){
		if(i < n - 1 && dp[i + 1] + 1 >= nax){
			if(dp[i + 1] + 1 == nax){
				id = min(id, i);
			}
			else{
				nax = dp[i + 1] + 1;
				id = i;
			}
		}
		if(i != 0 && sum + 1 > nax){
			if(sum + 1 == nax){
				id = min(i, id);
			}
			else{
				nax = sum + 1;
				id = i;
			}
		}
		if(i > 0 && i < n - 1 && a[i - 1] - a[i + 1] >= 2 && a[i - 1] - a[i + 1] <= 4 && sum + dp[i + 1] + 1 >= nax){
			if(nax == sum + dp[i + 1] + 1){
				id = min(i, id);
			}
			else{
				nax = sum + dp[i + 1] + 1;
				id = i;
			}
		}
		if(i > 0 && a[i - 1] - a[i] >= 1 && a[i - 1] - a[i] <= 2){
			sum += 1;
		}
		else{
			sum = 1;
		}
	}
	if(n == 1){
		cout << 1 << " " << 0 ;
	}
	else{
		cout << nax << " " << id;
	}
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
