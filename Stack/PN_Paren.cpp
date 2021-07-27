/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PN_Parenthesis
 * ALGO		: Stack
 * DATE		: 22 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int cnt[50050];

void solve(){
	int n, mxs, mx;
	mxs = mx = 0;
	cin >> n;
	stack<pair<char, int>> st;
	for(int i=1; i<=n; ++i){
		char x;
		cin >> x;
		if(x == '('){
			st.emplace(x, 0);
		}
		else{
			int nx = 0;
			while(!st.empty()){
				pair<char, int> now = st.top();
				st.pop();
				if(now.first != '('){
					nx = max(nx, now.second);
				}
				else{
					break;
				}
			}
			cnt[nx + 1] += 1;
			mx += 1;
			mxs = max(mxs, nx + 1);
			st.emplace('T', nx + 1);
		}
	}
	cout << mx << "\n" << mxs << "\n";
	for(int i=1; i<=mxs; ++i){
		cout << cnt[i] << " ";
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
