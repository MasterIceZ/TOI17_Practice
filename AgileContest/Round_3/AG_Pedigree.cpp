/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Pedigree
 * ALGO		: Divide and Conquer
 * DATE		: 24 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

#define int long long

const int MxN = 22;

int a[MxN];
bool notOK;

int divide(int level, int value){
	int nowV = (2 * value) + 1 - a[level];
	if(nowV <= 1){
		notOK = true;
		return -1;
	}
	if(level == 1){
		return nowV;
	}
	return divide(level - 1, nowV/2) + divide(level - 1, nowV - (nowV / 2));
}

void solve(){
	notOK = false;
	int k, w;
	cin >> k >> w;
	for(int i=1; i<k; ++i){
		cin >> a[i];
	}
	int val = divide(k - 1, w);
	if(notOK || val <= 1){
		cout << -1;
	}
	else{
		cout << val;
	}
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
