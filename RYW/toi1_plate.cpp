/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi1_plate
 * ALGO		: Queue
 * DATE		: 17 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

int student[10100];

queue<int> q, room[11];

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i=1, x, y; i<=m; ++i){
		cin >> x >> y;
		student[y] = x;
	}
	while(1){
		char opr;
		cin >> opr;
		if(opr == 'X'){
			cout << 0;
			break;
		}
		if(opr == 'D'){
			if(q.empty()){
				cout << "empty\n";
				continue;
			}
			cout << room[q.front()].front() << "\n";
			room[q.front()].pop();
			if(room[q.front()].empty()){
				q.pop();
			}
		}
		else{
			int x;
			cin >> x;
			if(room[student[x]].empty()){
				q.push(student[x]);
			}
			room[student[x]].push(x);
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
	}
	return 0;
}
