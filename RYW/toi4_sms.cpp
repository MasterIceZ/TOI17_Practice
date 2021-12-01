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

string st;

string k[] = {"", "", "CAB", "FDE", "IGH", "LJK", "OMN", "SPQR", "VTU", "ZWXY"};

void click(int pos, int time){
	if(pos == 1){
		for(int i=1; i<=time && st.size(); ++i){
			st.pop_back();
		}
	}
	else if(pos <= 6 || pos == 8){
		time %= 3;
		st += k[pos][time];
	}
	else{
		time %= 4;
		st += k[pos][time];
	}
}

void solve(){
	int n, s, t, x, y;
	cin >> n >> s >> t;
	click(s, t);
	for(int i=2; i<=n; ++i){
		cin >> x >> y >> t;
		s = s + x + (y * 3);
		click(s, t); 
	}
	cout << (st.empty() ? "null": st);
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
