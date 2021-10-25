#include<bits/stdc++.h>
using namespace std;
int hi[2010];
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int q;
    cin >> q;
    while(q--){
        memset(hi, 0, sizeof hi);
        int n, m, s;
        cin >> n >> m >> s;
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= m; j++){
                int now;
                cin >> now;
                now += s * i;
                if(now > hi[j]){
                    ans++;
                    hi[j] = now;
                }
            }
        }
        cout << ans << "\n";
    }

}
