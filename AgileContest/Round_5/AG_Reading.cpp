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

ll qsP[100100], qsQ[100100];

void solve(){
	ll stp, stq, edp, edq, k;
	cin >> stp >> stq >> edp >> edq >> k;
	ll ptq = stq - 1, ptp = stp - 1;
	ll sumQ = 0, sumP = 0;
	for(int i=1; i<=k; ++i){
		if(ptq >= edq){
			sumP += qsP[ptp++];
		}
		else if(sumP + qsP[ptp] <= sumQ + qsQ[ptq] && ptp < edp){
			sumP += qsP[ptp++];
		}
		else{
			sumQ += qsQ[ptq++];
		}
		dbg(sumQ, sumP);
	}
	cout << max(sumP, sumQ);
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	ll n, m, q = 1;
	cin >> n >> m >> q;
	for(int i=0; i<n; ++i){
		cin >> qsP[i];
	}
	for(int i=0; i<m; ++i){
		cin >> qsQ[i];
	}
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
