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

#define W 1000
#define N 1000

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	ii items[N+1];
	ll dp[N+1][W+1];

	ll w,n;
	cin>>w>>n;

	ll a,b;
	for (ll i = 1; i<=n; i++){
		cin>>a>>b;
		items[i] = ii(b,a);
	}

	for (ll i = 0; i<w; i++)
		dp[0][i] = 0;

	ll dif;
	for (ll i = 1; i<=n; i++){
		for (ll j = 0; j<=w; j++){
			dif = j - items[i].F;
			if (dif>=0)
				dp[i][j] = max(dp[i-1][dif] + items[i].S, dp[i-1][j]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	
	/*
	cout<<endl<<"DEBUG DP:"<<endl;
	for (ll i = 1; i<=n; i++){
		cout<<i<<": ";
		for (ll j = 0; j<w; j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	*/

	vi selected;
	ll jPos = w;
	for (ll i = n; i>=0; i--){
		if (dp[i][jPos] > dp[i-1][jPos]){
			selected.pb(i);
			jPos -= items[i].F;
		}
	}
	sortVct(selected);

	cout<<"MAX VAL: "<<dp[n][w]<<endl;

	cout<<"SELECTED ITEM INDEXES: ";
	for (llu i = 0; i<selected.size(); i++)
		cout<<selected[i]<<" ";
	
	return 0;
}



//10 4 10 5 40 4 30 6 50 3































