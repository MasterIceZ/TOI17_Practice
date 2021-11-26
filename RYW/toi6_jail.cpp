/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi6_jail
 * ALGO		: Brute Force
 * DATE		: 25 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

void solve(){
	int n, m;
	cin >> n >> m;
	queue<int> q;
	for(int i=1; i<=n; ++i){
		q.push(i);
	}
	int it = 0;
	while(!q.empty()){
		it++;
		if(it % m == 0){
			cout << q.front() << " ";
			q.pop();
		}
		else{
			q.push(q.front());
			q.pop();
		}
	}
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
