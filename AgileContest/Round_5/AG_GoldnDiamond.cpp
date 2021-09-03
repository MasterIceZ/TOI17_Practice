#include<bits/stdc++.h>
using namespace std;

int v[777][777], qsr[777][777], qsc[777][777];
int dr[777][777], ur[777][777], dl[777][777], ul[777][777];
int r, c;

void dbg(int a[777][777]){
	printf("+++\n");
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return ;
}

void solve(){
	memset(dl, 0x3f, sizeof dl);
	memset(dr, 0x3f, sizeof dr);
	memset(ul, 0x3f, sizeof ul);
	memset(ur, 0x3f, sizeof ur);
	scanf("%d %d", &r, &c);
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			scanf("%d", &v[i][j]);
		}
	}
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			qsc[i][j] = v[i][j] + qsc[i - 1][j];
			qsr[i][j] = v[i][j] + qsr[i][j - 1];
		}
	}
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			if(i == 1 && j == 1){
				dr[i][j] = v[i][j];
			}
			else{
				dr[i][j] = v[i][j] + min(dr[i - 1][j], dr[i][j-1]);
			}
		}
	}
	for(int i=1; i<=r; ++i){
		for(int j=c; j>=1; --j){
			if(i == 1 && j == c){
				dl[i][j] = v[i][j];
			}
			else{
				dl[i][j] = v[i][j] + min(dl[i - 1][j], dl[i][j + 1]);
			}
		}
	}
	for(int i=r; i>=1; --i){
		for(int j=1; j<=c; ++j){
			if(i == r && j == 1){
				ur[i][j] = v[i][j];
			}
			else{
				ur[i][j] = v[i][j] + min(ur[i + 1][j], ur[i][j - 1]);
			}
		}
	}
	for(int i=r; i>=1; --i){
		for(int j=c; j>=1; --j){
			if(i == r && j == c){
				ul[i][j] = v[i][j];
			}
			else{
				ul[i][j] = v[i][j] + min(ul[i + 1][j], ul[i][j + 1]);
			}
		}
	}
	int ansr, ansc, bestr, bestc;
	ansr = ansc = bestr = bestc = 1e9;
	for(int i=1; i<=r; ++i){
		bestr = 1e9 + 10;
		for(int j=1; j<=c; ++j){
			bestr = min(bestr, dr[i][j] + ur[i][j] - 2 * v[i][j] - qsr[i][j-1]);
			ansr = min(ansr, ul[i][j] + dl[i][j] - 2 * v[i][j] + qsr[i][j] + bestr);
		}
	}
	for(int j=1; j<=c; ++j){
		bestc = 1e9 + 10;
		for(int i=1; i<=r; ++i){
			bestc = min(bestc, dr[i][j] + dl[i][j] - 2 * v[i][j] - qsc[i - 1][j]);
			ansc = min(ansc, ur[i][j] + ul[i][j] - 2 * v[i][j] + qsc[i][j] + bestc);
		}
	}
	printf("%d", min(ansr, ansc));
	return ;
}

int main(){
	int q;
	scanf("%d", &q);
	while(q--){
		solve();
		printf("\n");
	}
	return 0;
}
