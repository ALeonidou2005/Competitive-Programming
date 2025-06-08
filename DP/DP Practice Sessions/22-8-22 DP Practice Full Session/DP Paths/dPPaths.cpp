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
#define M 100

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	ll dp[N+1][M+1];

	ll n,m;
	cin>>n>>m;

	for (ll i = 0; i<n; i++)
		dp[i][0] = 1;
	for (ll i = 0; i<m; i++)
		dp[0][i] = 1;

	for (ll i = 1; i<n; i++)
		for (ll j = 1; j<m; j++)
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
	
	cout<<dp[n-1][m-1];
	
	return 0;
}


































