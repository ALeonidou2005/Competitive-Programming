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
#define V 100

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll coins[N+1];
	ll dp[V+1];

	ll v, n;
	cin>>v>>n;
	for (ll i = 0; i<n; i++)
		cin>>coins[i];

	dp[0] = 0;
	for (ll i = 1; i<=v; i++){
		dp[i] = INF;
		for (ll j = 0; j<n; j++){
			ll dif = i - coins[j];
			if (dif >= 0)
				dp[i] = min(dp[i], dp[dif]+1);
		}
	}
	
	cout<<dp[v];

	return 0;
}


/*Test Cases
	7 4 1 3 4 5	=> 2
	10 2 1 5	=> 2
	11 3 1 2 3   => 4
*/



























