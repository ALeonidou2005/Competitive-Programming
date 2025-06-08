#include <iostream>

using namespace std;

#define ll long long
#define N 50
#define V 250

ll dp[N+1][V+1];
ll items[N+1];
ll v, n;

void debugDP(){
	 cout<<endl<<"DEBUG:"<<endl;
  	for (ll i = 0; i<=n+1; i++){
  		cout<<i<<": ";
  		for (ll j = 0; j<=v+1; j++)
  			cout<<dp[i][j]<<" ";
  		cout<<endl;
  	}
  	cout<<endl;
}

int main(){

	cin>>v>>n;
	for (ll i = 0; i<n; i++)
		cin>>items[i];

    for (ll i = 1; i <= v+1; i++)
     	dp[0][i] = 0;
    for (ll i = 1; i <= n; i++)
      	dp[i][0] = 1;

	debugDP();

  	for (ll i = 1; i <= n; i++){
      	for (ll j = 1; j <= v; j++){
        	if(items[i-1] > j)
        	   	dp[i][j] = dp[i-1][j];
        	else
            	dp[i][j] = dp[i-1][j] + dp[i][j-items[i-1]];       
      	}
  	}

  	debugDP();

    cout<<"Total Solutions: "<<dp[n][v];

    return 0;
}



//Sample: 4 3 1 2 3		=> 4






























