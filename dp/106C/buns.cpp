#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <cstring>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>

using namespace std;

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define SORT(__a) sort(__a.begin(), __a.end())
#define RSORT(__a) sort(__a.rbegin(), __a.rend())
#define INF INT_MAX
#define VS vector<string>
#define VI vector<int>
#define PB push_back
#define clr(__v,__x) memset(__v, __x, sizeof __v);
#define rep(i, n) FOR(i,0,n)
#define all(a) a.begin(), a.end()
bool isprime(int n){ if(n<2)return false;  for(int i=2;i*i<=n;i++)if(n%i==0)return false;  return true;} 
string itos(int n){stringstream ss;ss << n;return ss.str();}

const double PI  = acos(-1.0);
static const double EPS = 1e-5;
typedef long long ll;
typedef pair<int, int> P;

int main(){
	int n, m, c0, d0;
	int dp[20][1010];
	int kosu[1010];
	int bun[1010];
	int nedan[1010];
	while(cin >> n >> m >> c0 >> d0){
		int a, b;
		rep(i, m){
			cin >> a >> b >> bun[i] >> nedan[i];
			kosu[i] = a / b;
		}
		kosu[m] = n / c0;
		bun[m] = c0;
		nedan[m] = d0;
		rep(i, 20) rep(j, 1010) dp[i][j] = -INF;
		int res = 0;
		dp[0][n] = 0;
		rep(i, m+1){
			for(int j = n; j >= 0; j--){
				//cout << i << "," << j << ":" << dp[i][j] << " kosu=" << kosu[i] << endl;
				rep(k, kosu[i]+1){
					if(j - k*bun[i] >= 0){
						dp[i+1][j-k*bun[i]] = max(dp[i+1][j-k*bun[i]], dp[i][j] + nedan[i]*k);
					}else{
						break;
					}
				}
			}
		}
		rep(i, n+1) res = max(res, dp[m+1][i]);
		cout << res << endl;
	}
	return 0;
}