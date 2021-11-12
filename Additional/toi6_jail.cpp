#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

void solve(){
	int n, m;
	cin >> n >> m;
	deque<int> dq;
	for(int i=1; i<=n; ++i){
		dq.push_back(i);
	}
	int cnt = 0;
	while(!dq.empty()){
		cnt++;
		if(cnt == m){
			cout << dq.front() << " " ;
			dq.pop_front();
			cnt = 0;
		}
		else{
			dq.push_back(dq.front());
			dq.pop_front();
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
