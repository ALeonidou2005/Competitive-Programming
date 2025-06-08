#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define llu unsigned long long
#define F first
#define S second
#define endl "\n"

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
	ll n, w;
	cout<<"Number of items: ";
	cin>>n;
	cout<<"Maximum wheight: ";
	cin>>w;

	cout<<"Wheight and Value of all items: ";
	ll win,vin;
	for (ll i = 1; i<=n; i++){
		cin>>win>>vin;
		items[i] = ii(win,vin);
	}

	//process
	for (ll i = 1; i<=n; i++){
		for (ll j = 0; j<=w; j++){
			if (items[i].F > j){
				dp[i][j] = dp[i-1][j];
			}
			else{
				dp[i][j] = max(items[i].S + dp[i-1][j-items[i].F], dp[i-1][j]);
			}
		}
	}

	printTable(n,w);

	//output
	cout<<endl;
	cout<<"Maximum Value: "<<dp[n][w]<<endl;
	cout<<"Items Selected: ";
	ll i = n, j = w;
	while(dp[i][j] != 0){
		if (dp[i-1][j] != dp[i][j]){
			cout<<items[i].F<<"|"<<items[i].S<<" ";
			j -= items[i].F;
		}
		i--;
	}

	cout<<endl;
	return 0;
}

/*
Test Case:
	n = 4, w = 7, items = 1 1 3 4 4 5 5 7
	MAX ANS = 9
	ITEMS = 4|5, 3|4


	n = 3, w = 7, items = 1 2 3 6 5 5
	MAX ANS = 8
	ITEMS = 1|2, 3|6
*/

































