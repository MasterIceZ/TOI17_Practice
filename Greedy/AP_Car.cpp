/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AP_Car
 * ALGO		: Greedy
 * DATE		: 1 Aug 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

struct Car{
	int stp, edp;
	bool operator < (const Car& o) const{
		if(stp != o.stp){
			return stp < o.stp;
		}
		return edp > o.edp;
	}
};

void solve(){
	int n, t, v, st, ed, cnt;
	cin >> n >> t;
	vector<Car> car(n + 1);
	for(int i=1; i<=n; ++i){
		cin >> car[i].stp >> v;
		car[i].edp = car[i].stp + t * v;
	}
	sort(car.begin() + 1, car.begin() + 1 + n);
	st = ed = -1;
	cnt = 0;
	for(int i=1; i<=n; ++i){
		if(car[i].edp < ed){
			continue;
		}
		if(car[i].edp == ed && car[i].stp > st){
			continue;
		}
		cnt += 1;
		st = car[i].stp;
		ed = car[i].edp;
	}
	cout << cnt;
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
