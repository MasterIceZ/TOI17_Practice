/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Road Cut
 * ALGO		: Dynamic Programming
 * DATE		: 21 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;
int a[111][111], qsd[111], qsr[111];
int nd[111], nr[111];

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m, sum = 0;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
			qsd[i] += a[i][j];
			qsr[j] += a[i][j];
			sum += a[i][j];
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=1, x; j<=m; ++j){
			cin >> x;
			nd[i] += x;
			nr[j] += x;
		}
	}
	int nax = 0;
	for(int i=1; i<=n; ++i){
		nax = max(nax, sum - qsd[i] + nd[i-1] + nd[i+1]);
	}
	for(int j=1; j<=m; ++j){
		nax = max(nax, sum - qsr[j] + nr[j-1] + nr[j+1]);
	}
	cout << nax << endl; 
	return 0;
}
