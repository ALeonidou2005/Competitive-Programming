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

#define N 1000

ll dp[N+1];
ll arr[N+1];
ll pre[N+1];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	ll n;
	cin>>n;

	for (ll i = 0; i<n; i++)
		cin>>arr[i];
	
	ll ans = 1;
	dp[0] = 1;
	for (ll i = 1; i<n; i++){
		dp[i] = 1;
		for (ll j = i-1; j>=0; j--){
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(ans, dp[i]);
	}
	

	cout<<ans;
	
	
	return 0;
}


//Example: 8 -7 10 9 2 3 8 8 1   => 4





























