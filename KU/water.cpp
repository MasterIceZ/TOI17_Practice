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

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

struct Node{
	int i, j, val;
};

int a[20][1 << 11];

void solve(){
	int n, l, x;
	cin >> n >> l >> x;
	queue<Node> q;
	q.push({1, x, 1});
	while(!q.empty()){
		Node now = q.front();
		q.pop();
		dbg(now.i, now.j, now.val);
		a[now.i][now.j] += now.val;
		if(now.i == n + 1){
			continue;
		}
		if(now.j + 1 < 2 * l && now.j - 1 > 0){
			q.push({now.i + 1, now.j - 1, now.val});
			q.push({now.i + 1, now.j + 1, now.val});
		}
		else if(now.j + 1 == 2 * l){
			q.push({now.i + 1, now.j - 1, now.val * 2});
		}
		else{
			q.push({now.i + 1, now.j + 1, now.val * 2});
		}
	}
	// print a[n + 1][i]
	if(n % 2){
		for(int i=2, cnt = 0; cnt < l - 1; cnt++, i+=2){
			cout << a[n + 1][i] << " ";
		}
	}
	else{
		for(int i=1, cnt = 0; cnt < l; cnt++, i+=2){
			cout << a[n + 1][i] << " ";
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
		cout << endl;
	}
	return 0;
}
