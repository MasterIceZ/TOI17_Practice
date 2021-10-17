#include <bits/stdc++.h>
using namespace std;

int num[11];
int arr[55][55];

void renum(){
    for(int i = 0 ; i < 10 ; i++) num[i] = 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int W, L, cnt = 0;
    cin >> W >> L;
    for(int i = 0 ; i < W ; i++){
        for(int j = 0 ; j < L ; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0 ; i <= W-5 ; i++){
        for(int j = 0 ; j <= L-5 ; j++){
//			renum();
			int p = 0;
			memset(num, 0, sizeof num);
            for(int k = 0 ; k < 5 ; k++){
                for(int l = 0 ; l < 5 ; l++){
                    if(num[arr[i+k][j+l]] == 0 ){
                        p++;
                        num[arr[i+k][j+l]] = 1;
                    }
                }
            }
			if(p >= 5) cnt++;
        }
    }
    cout << cnt;
    return 0;
}
