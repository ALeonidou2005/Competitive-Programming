#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define llu unsigned long long
#define F first
#define S second
#define endl "\n"
#define pb push_back

#define N 100
#define W 1000

//Types: 
typedef pair <ll, ll> ii;
typedef pair <ll,ii> iii;
typedef vector <ll> vi;
typedef vector <ii> vii;

ii items[N+1];
ll dp[N+1][W+1];

void printTable(ll n, ll w){
	cout<<"\n\n     DEBUGGING TABLE VALUES"<<endl;
	for (ll i = 0; i<=n; i++){
		cout<<i<<": ";
		for (ll j = 0; j<=w; j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	//initialise
	for (ll i = 0; i<=W; i++)
		dp[0][i] = 0;

	//input
	cout<<"KNAPSACK SOLUTION - (max N: "<<N<<", max W: "<<W<<")"<<endl;
	ll n;
	cout<<"Number of items: ";
	cin>>n;

	cout<<"Wheight and Value of all items: ";
	ll win,vin;
	for (ll i = 1; i<=n; i++){
		cin>>win;
		items[i] = ii(win,win);
	}

	//process
	for (ll i = 1; i<=n; i++){
		for (ll j = 0; j<=W; j++){
			if (items[i].F > j){
				dp[i][j] = dp[i-1][j];
			}
			else{
				dp[i][j] = max(items[i].S + dp[i-1][j-items[i].F], dp[i-1][j]);
			}
		}
	}

	ll a = n, b = W;
	vii selectedItems;
	while(dp[a][b] != 0){
		if (dp[a-1][b] != dp[a][b]){
			selectedItems.pb(items[a]);
			b -= items[a].F;
		}
		a--;
	}
	sort(selectedItems.begin(), selectedItems.end());

	//printTable(n,W);

	//output
	cout<<endl;
	cout<<"Maximum Value: "<<dp[n][W]<<endl;
	cout<<"Items Selected: ";
	for (llu i = 0; i<selectedItems.size(); i++)
		cout<<selectedItems[i].F<<" ";

	cout<<endl;
	return 0;
}

/*
Test Cases:
	//n = 5, 3 4 5 1 2
	//n = 15, 19 429 859 948 210 7 27 679 749 73 222 437 857 779 879
	//n = 6, 32 53 89 12 11 99
*/




































