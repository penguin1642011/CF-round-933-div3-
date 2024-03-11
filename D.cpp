#include<bits/stdc++.h>
/*
        penguin yes cop code
        https://codeforces.com/profile/Tuanhaiphong2
*/
using namespace std;
#define ll long long
#define fi first
#define se second
#define MOD 1000000007
const int MAXN = 4e5+7;
vector<ll> topo;
static ll in[1000];
ll dx[8] = {-1,0,0,1,-1,-1,1,1};
ll dy[8] = {0,-1,1,0,-1,1,-1,1};
static ll Hash,base = 131,k,n,a[MAXN],b[MAXN],dp[MAXN],ans,f[1007];
vector<pair<ll,char>> vi;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("ROBOT.INP","r",stdin);
    //freopen("ROBOT.OUT","w",stdout);
    static ll tt,xx,y,x,z,yy,d,j,l,r,lo,rr,i,res,m,index,note,cnt;
    string ss,stt,sss,str,st,s;
    cin >> tt;
    while(tt--){
        cin >> n >> m >> k;
        char kt;
        for (i = 1;i <= m;i++){
            cin >> x >> kt;
            vi.push_back({x,kt});
        }
        for (i = 1;i <= n;i++)
        dp[i] = -1,f[i] = -1;
        dp[k] = 0,f[k] = 0;
        for (i = 0;i < vi.size();i++){
            for (j = 1;j <= n;j++){
            note = j;
            x = (j+vi[i].fi)%n;
            if (x==0)x = n;
            y = note;
            note = 1;
            if (y-vi[i].fi<0)note = -1;
            y = (n+(abs(y-vi[i].fi)%n*note))%n;
            if (y==0) y = n;
                if (vi[i].se=='0'){
                    if (f[j]>=i)dp[x] = i+1;
                }
                if (vi[i].se=='1'){
                    if (f[j]>=i)dp[y] = i+1;
                }
                if (vi[i].se=='?'){
                    if (f[j]>=i)dp[x] = dp[y] = i+1;
                }
            }
                for (l = 1;l <= n;l++)
                f[l] = dp[l];
        }
        vector<ll> v;
        for (i = 1;i <= n;i++)
        if (dp[i]==m)v.push_back(i);
        cout << v.size() << '\n';
        for (auto it : v)
        cout << it << ' ';
        cout << '\n';
        vi.clear();
    }
    return (0^0)&(200+10);
}
/*
  4 9 2 4
1 0 0 0 0
9 0 1 1 1
7 0 1 1 1
3 0 1 1 1
4 0 1 1 2

5
0 1 3 3 1
0 0 1 2 1

theo chieu kim dong ho (x+y)%n
nguoc chieu kim dong ho (n+(x-y))%n
*/
