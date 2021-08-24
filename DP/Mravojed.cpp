/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Mravojed
 * ALGO		: Dynamic Programming
 * DATE		: 24 Aug 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

char a[111][111];

void solve(){
	int r, c;
	cin >> r >> c;
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			cin >> a[i][j];
		}
	}
	pair<int, int> one, two;
	int cou1 = 0;
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			if(a[i][j] == 'x'){
				while(i + cou1 <= r && j + cou1 <= c && a[i + cou1][j] == 'x' && a[i][j + cou1] == 'x'){
					cou1++;
				}
				one = make_pair(i, j);
				break;
			}
		}
		if(cou1 != 0){
			break;
		}
	}
	
	for(int i=one.first; i<=one.first + cou1 - 1; ++i){
		for(int j=one.second; j<=one.second + cou1 - 1; ++j){
			a[i][j] = '.';
		}
	}
	
	int cou2 = 0;
	for(int i=r; i>=1; --i){
		for(int j=c; j>=1; --j){
			if(a[i][j] == 'x'){
				//cout << i << " " << j << "\n";
				while(a[i - cou2][j] == 'x' || a[i][j - cou2] == 'x'){
					cou2++;
				}
				two = make_pair(i - cou2 + 1, j - cou2 + 1);
				break;
			}
		}
		if(cou2 != 0){
			break;
		}
	}
	if(one == two || two == make_pair(0, 0)){
		cout << one.first << " " << one.second << " " << 1 << "\n";
		cout << one.first << " " << one.second << " " << cou1 ;
		return ;
	}
	cout << one.first << " " << one.second << " " << cou1 << "\n";
	cout << max(1, two.first) << " " << max(1, two.second) << " " << cou2;
	
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
