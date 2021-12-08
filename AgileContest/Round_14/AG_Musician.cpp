/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

ll a[3030], ok[11];
bool choose[11];
int k, n;

int rec(int state){
	if(state == n + 1){
		int sum = 0;
		for(int i=1; i<=n; ++i){
			if(choose[i] == 0){
				sum += a[i];
				for(int j=i; j<=min(i+k-1, n); ++j){
					ok[j]++;
				}
			}
			if(i >= k && ok[i] < 2){
				sum = 1e9;
			}
			cout << choose[i] << "," << ok[i] << " ";
		}
		cout << sum ;
		cout << "\n";
		return sum;
	}
	choose[state + 1] = 1;
	int minn = min((int)1e9, rec(state + 1));
	choose[state + 1] = 0;
	return min(minn, rec(state + 1));
}

void solve(){
   	cin >> n >> k;
	assert(n <= 10);
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}	
	cout << rec(0);
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
