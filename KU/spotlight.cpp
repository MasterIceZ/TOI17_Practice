/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: spotlight
 * ALGO		: Dynamic Programming
 * DATE		: 26 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 444;
int a[MxN];

void solve(){
	int n, l, r;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> l >> r;
		a[l]++;
		if(r < l){
			a[0]++;
		}
		a[r]--;
	}
	for(int i=1; i<360; ++i){
		a[i] += a[i - 1];
	}
	int curr = 0, ans = 0;
	for(int i=0; i<360; ++i){
		if(!a[i]){
			ans = max(ans, curr);
			curr = 0;
		}
		else{
			curr++;
		}
	}
	ans = max(ans, curr);
	int back = 0, front = 0;
	for(int i=359; i>=0; --i){
		if(!a[i]){
			break;
		}
		back++;
	}
	for(int i=0; i<=359; ++i){
		if(!a[i]){
			break;
		}
		front++;
	}
	
	if(front != 0 && back != 0){
		ans = max(ans, front + back);	
	}
	ans = min(ans, 360);
	cout << (ans >= 360 ? 360: ans);
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
