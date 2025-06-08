#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

#define ll long long
#define llu unsigned long long
#define F first
#define S second
#define endl "\n"

#define sortVct(a) sort (a.begin(), a.end())
#define reverseVct(a) reverse (a.begin(), a.end())
#define pb push_back

#define printVct(v) for(llu i = 0; i<v.size(); i++) cout<<v[i]<<" "; cout<<endl
#define printPair(x) cout<<x.first<<" "<<x.second<<endl
#define printArr(arr,s,e) for(int J=s; J<=e; J++) cout<<arr[J]<<" "; cout<<endl

#define inf 1e6
#define INF 1e9
#define MOD 1000000007

//Types: 
typedef pair <ll, ll> ii;
typedef pair <ll,ii> iii;
typedef vector <ll> vi;
typedef vector <ii> vii;

#define N 100
#define W 100

ll dp[N+1][W+1];
ii items[N+1];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	ll n, w;
	cin>>w>>n; 

	ll tw,tv;
	for (ll i = 1; i<=n; i++){
		cin>>tv>>tw;
		items[i] = ii(tv,tw);
	}
	
	for (ll i = 0; i<=w; i++)
		dp[0][i] = 0;

	for (ll i = 1; i<=n; i++){\
		for (ll j = 0; j<=w; j++){
			if (items[i].S > j)
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = max(dp[i-1][j], items[i].F + dp[i-1][j - items[i].S]);
		}
	}

	
	cout<<dp[n][w];	
	
	return 0;
}


//10 4 10 5 40 4 30 6 50 3































