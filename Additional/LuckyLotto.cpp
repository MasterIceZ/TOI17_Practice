/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Lucky Lotto
 * ALGO		: Math
 * DATE		: 21 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

const int MxN = 1e3 + 10;
int pre[MxN];

int sq(int n){
	int l, r;
	l = 1, r = n;
	while(l < r){
		int mid = (l + r) / 2;
		if(mid * mid == n){
			return mid;
		}
		if(mid <= n / mid){
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	if((l - 1) * (l - 1) == n){
		return l - 1;
	}
	else{
		return l;
	}
}

void solve(){
	int n;
	cin >> n;
	int s = sq(n);
	cout << pre[s];
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);

	pre[1] = 1;
	pre[2] = 2;
	for(int i=3; i<=1000; ++i){
		pre[i] = pre[i - 1] + pre[i - 2];
	}

	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
