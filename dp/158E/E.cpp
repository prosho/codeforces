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

const double PI  = acos(-1.0);
static const double EPS = 1e-5;
typedef long long ll;
typedef pair<int, int> P;

int N, K;
const int MAX_N = 4010;
int dp[MAX_N][MAX_N];
int t[MAX_N], d[MAX_N];

int main(){
	while(cin >> N >> K){
		rep(i, N){cin >> t[i]; cin >> d[i]; t[i]--;}
		rep(i, MAX_N) rep(j, MAX_N) dp[i][j] = 9999999;
		dp[0][0] = 0;
		int res = 0;
		rep(i, N){
			rep(j, K + 1){
				// tuuwa
				if(dp[i][j] <= t[i]){
					res = max(res, t[i] - dp[i][j]);
					dp[i+1][j] = min(dp[i+1][j], t[i] + d[i]);
				}else{
					dp[i+1][j] = min(dp[i+1][j], dp[i][j] + d[i]);
				}
				// shikato
				dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
			}
		}
		rep(i, K + 1) res = max(res, 86400 - dp[N][i]);
		cout << res << endl;
	}
	return 0;
}