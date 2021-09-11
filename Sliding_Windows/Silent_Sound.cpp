/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Silent Sound
 * ALGO		: Sliding Windows
 * DATE		: 9 Sep 2021
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

int a[1000100];

void solve(){
	int n, m, c;
	cin >> n >> m >> c;
	deque<int> nin, nax;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	bool printed = false;
	for(int i=1; i<=n; ++i){
		while(!nax.empty() && a[i] >= a[nax.back()]){
			nax.pop_back();
		}
		while(!nin.empty() && a[i] <= a[nin.back()]){
			nin.pop_back();
		}
		nax.push_back(i);
		nin.push_back(i);
		if(i < m){
			continue;
		}
		while(!nax.empty() && nax.front() <= i - m){
			nax.pop_front();
		}
		while(!nin.empty() && nin.front() <= i - m){
			nin.pop_front();
		}
		if(a[nax.front()] - a[nin.front()] <= c){
			cout << i - m + 1 << "\n";
			printed = true;
		}
	}
	if(!printed){
		cout << "NONE\n";
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
	}
	return 0;
}
