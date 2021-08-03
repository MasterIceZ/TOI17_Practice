/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PT_Bracket
 * ALGO		: Heap
 * DATE		: 1 Aug 2021
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

void solve(){
	ll cnt=0, a, b, ans=0;
	bool ok = true;
	string s;
	cin >> s;
	priority_queue<int> pq;
	for(auto x: s){
		if(x == '('){
			cnt += 1;
		}
		else if(x == ')'){
			cnt -= 1;
		}
		else{
			cin >> a >> b;
			ans += b;
			pq.push(b - a);
			cnt -= 1;
		}
		if(cnt < 0){
			if(pq.empty()){
				ok = false;
			}
			else{
				ans -= pq.top();
				pq.pop();
				cnt += 2;
			}
		}
	}
	cout << ((!cnt && ok) ? ans : -1);
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
