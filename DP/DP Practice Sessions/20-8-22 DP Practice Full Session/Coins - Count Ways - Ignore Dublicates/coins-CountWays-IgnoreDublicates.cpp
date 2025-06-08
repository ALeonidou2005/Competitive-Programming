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

ll items[N+1];
ll dp[N+1][V+1];

ll v, n;

void debugDP(){
	cout<<endl;
	for (ll i = 0; i<=n; i++){
		cout<<i<<": ";
		for (ll j = 0; j<=v; j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	


	cin>>v>>n;
	for (ll i = 0; i<n; i++)
		cin>>items[i];
	
	for (ll i = 0; i<=v; i++)
		dp[0][i] = 0;
	for (ll i = 1; i<=n; i++)
		dp[i][0] = 1;

	debugDP();

	for (ll i = 1; i<=n; i++){

		for (ll j = 1; j<=v; j++){
			if (items[i] > j){
				dp[i][j] = dp[i-1][j];
			}
			else{
				dp[i][j] = max(dp[i-1][j], 1 + dp[i-1][j - items[i]]);
			}
		}
	}
	
	debugDP();

	cout<<dp[n][v];
	
	return 0;
}


//5 3 1 3 4































