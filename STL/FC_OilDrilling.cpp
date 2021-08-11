/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: FC_Oil Drilling
 * ALGO		: Data Structure
 * DATE		: 5 Aug 2021
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

set<int> s;
set<int>::iterator l, r;

int n;

void solve(){
	int x;
	cin >> x;
	if(s.empty()){
		cout << n;
		s.insert(x);
		return ;
	}
	l = r = s.lower_bound(x);
	l--;
	if(r == s.begin()){
		cout << (*r) - x;
	}
	else if(r == s.end()){
		cout << x - (*l);
	}
	else{
		cout << min((*r) - x, x - (*l));
	}
	s.insert(x);
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> n >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
