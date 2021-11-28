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

const int MxN = 3333;
int a[MxN];

void solve(){
	int n;
	cin >> n;
	bool can = false;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		if(a[i] > 0){
			can = true;
		}
	}
	if(!can){
		cout << "Empty sequence";
		return ;
	}
	int maxx = -1e9;
	int st = 1, ed = 0, sum = 0, last = 1;
	for(int i=1; i<=n; ++i){
		sum += a[i];
		if(sum > maxx){
			maxx = sum;
			st = last;
			ed = i;
		}
		if(sum < 0){
			sum = 0;
			last = i + 1;
		}
	}
	for(int i=st; i<=ed; ++i){
		cout << a[i] << " ";
	}
	cout << "\n" << maxx ;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
