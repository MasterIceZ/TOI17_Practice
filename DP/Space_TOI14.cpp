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

char a[2][10010];
int h[2][10010], w[2][10010];
int c[2][10010], maxx[2][10010];

void solve(){
	int n, m, cnt = 0, sum = 0, mid;
	cin >> m >> n;
	int square = 0, diamond = 0, triangle = 0;
	for(int i=1; i<=n+1; ++i){
		if(i <= n){
			cin >> (a[i % 2] + 1);
		}
		else{
			memset(a[i % 2], '0', sizeof a[i % 2]);
		}
		memset(h[i % 2], 0, sizeof h[i % 2]);
		memset(w[i % 2], 0, sizeof w[i % 2]);
		memset(c[i % 2], 0, sizeof c[i % 2]);
		memset(maxx[i % 2], 0, sizeof maxx[i % 2]);
		cnt = 0;
		for(int j=1; j<=m; ++j){
			if(a[i % 2][j] == '1'){
				cnt++;
				if(a[i % 2][j + 1] != '1'){
					sum = cnt;
					cnt = 0;
					mid = (j + j - sum + 1) >> 1;
					for(int k=j-sum+1; k<=j; ++k){
						h[i % 2][k] = h[(i + 1) % 2][mid] + 1;
						w[i % 2][k] = sum;
						c[i % 2][k] = c[(i + 1) % 2][mid] + sum;
						maxx[i % 2][k] = max(w[i % 2][k], maxx[(1 + i) % 2][k]);
					}
				}
			}
			else{
				if(a[(i + 1) % 2][j] == '1' && a[i % 2][j - 1] == '0' && a[i % 2][j + 1] == '0'){
					cnt++;
				}
				if(a[(i + 1) % 2][j] == '1' && a[(i + 1) % 2][j + 1] != '1' && a[i % 2][j - 1] != '1' && a[i % 2][j + 1] != '1'){
					sum = cnt;
					cnt = 0;
					mid = (j + j - sum + 1) >> 1;
					if(h[(i + 1) % 2][mid] * h[(i + 1) % 2][mid] == c[(i + 1) % 2][mid] && h[(i + 1) % 2][mid] == w[(i + 1) % 2][mid]){
//						dbg(i, j);
						square++;
					}
					else if(2 * (h[(i + 1) % 2][j] / 2) * (h[(i + 1) % 2][j] / 2) + h[(i + 1) % 2][j] == c[(i + 1) % 2][j] && h[(i + 1) % 2][j] % 2 == 1){
						diamond++;
					}
					else{
						triangle++;
					}
				}
				cnt = 0;
			}
		}
	}
	cout << square << " " << diamond << " " << triangle;
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
