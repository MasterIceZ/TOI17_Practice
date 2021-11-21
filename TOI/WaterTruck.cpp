/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi16_watertruck
 * ALGO		: Dijkstra, Bitmasks, Topological Sort
 * DATE		: 21 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

void solve(){
	/*
	                                                                                                                                                                                                                          
                                                                                                                                                                                                                          
                                                                 tttt                                                           tttt                                                                   kkkkkkkk           
                                                              ttt:::t                                                        ttt:::t                                                                   k::::::k           
                                                              t:::::t                                                        t:::::t                                                                   k::::::k           
                                                              t:::::t                                                        t:::::t                                                                   k::::::k           
wwwwwww           wwwww           wwwwwwwaaaaaaaaaaaaa  ttttttt:::::ttttttt        eeeeeeeeeeee    rrrrr   rrrrrrrrr   ttttttt:::::ttttttt   rrrrr   rrrrrrrrr   uuuuuu    uuuuuu      cccccccccccccccc k:::::k    kkkkkkk
 w:::::w         w:::::w         w:::::w a::::::::::::a t:::::::::::::::::t      ee::::::::::::ee  r::::rrr:::::::::r  t:::::::::::::::::t   r::::rrr:::::::::r  u::::u    u::::u    cc:::::::::::::::c k:::::k   k:::::k 
  w:::::w       w:::::::w       w:::::w  aaaaaaaaa:::::at:::::::::::::::::t     e::::::eeeee:::::eer:::::::::::::::::r t:::::::::::::::::t   r:::::::::::::::::r u::::u    u::::u   c:::::::::::::::::c k:::::k  k:::::k  
   w:::::w     w:::::::::w     w:::::w            a::::atttttt:::::::tttttt    e::::::e     e:::::err::::::rrrrr::::::rtttttt:::::::tttttt   rr::::::rrrrr::::::ru::::u    u::::u  c:::::::cccccc:::::c k:::::k k:::::k   
    w:::::w   w:::::w:::::w   w:::::w      aaaaaaa:::::a      t:::::t          e:::::::eeeee::::::e r:::::r     r:::::r      t:::::t          r:::::r     r:::::ru::::u    u::::u  c::::::c     ccccccc k::::::k:::::k    
     w:::::w w:::::w w:::::w w:::::w     aa::::::::::::a      t:::::t          e:::::::::::::::::e  r:::::r     rrrrrrr      t:::::t          r:::::r     rrrrrrru::::u    u::::u  c:::::c              k:::::::::::k     
      w:::::w:::::w   w:::::w:::::w     a::::aaaa::::::a      t:::::t          e::::::eeeeeeeeeee   r:::::r                  t:::::t          r:::::r            u::::u    u::::u  c:::::c              k:::::::::::k     
       w:::::::::w     w:::::::::w     a::::a    a:::::a      t:::::t    tttttte:::::::e            r:::::r                  t:::::t    ttttttr:::::r            u:::::uuuu:::::u  c::::::c     ccccccc k::::::k:::::k    
        w:::::::w       w:::::::w      a::::a    a:::::a      t::::::tttt:::::te::::::::e           r:::::r                  t::::::tttt:::::tr:::::r            u:::::::::::::::uuc:::::::cccccc:::::ck::::::k k:::::k   
         w:::::w         w:::::w       a:::::aaaa::::::a      tt::::::::::::::t e::::::::eeeeeeee   r:::::r                  tt::::::::::::::tr:::::r             u:::::::::::::::u c:::::::::::::::::ck::::::k  k:::::k  
          w:::w           w:::w         a::::::::::aa:::a       tt:::::::::::tt  ee:::::::::::::e   r:::::r                    tt:::::::::::ttr:::::r              uu::::::::uu:::u  cc:::::::::::::::ck::::::k   k:::::k 
           www             www           aaaaaaaaaa  aaaa         ttttttttttt      eeeeeeeeeeeeee   rrrrrrr                      ttttttttttt  rrrrrrr                uuuuuuuu  uuuu    cccccccccccccccckkkkkkkk    kkkkkkk
	*/
//	https://media.discordapp.net/attachments/850747649405878275/911834468044644382/KangSoup.png?width=527&height=702
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
