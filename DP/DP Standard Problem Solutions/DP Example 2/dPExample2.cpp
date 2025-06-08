#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

#define N 100
ll dp[N+1];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	ll n;
	cin>>n;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (ll i = 4; i<=n; i++)
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
	
	cout<<dp[n];
	
	return 0;
}


/*
	N > 3
	1, 2, 3

	EG: N = 4
	1+1+1+1
	
	s(4) = (s(3) + 1) + (s(2) + 2) + (s(1) + 3)
*/






























