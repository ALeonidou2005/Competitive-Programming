#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

#define ll long long
#define llu unsigned long long
#define F first
#define S second
#define endl "\n"

#define sortVct(a) sort (a.begin(), a.end())
#define reverseVct(a) reverse (a.begin(), a.end())
#define pb push_back

#define debugPoint(a) cout<<"DEBUG: Reached "<<a<<endl

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

//Functions: 
int charToInt(char c) { return int(c)-48; };
char intToChar(int a) { return char(a+48); };

#define MAXN 101
#define MAXW 100001
	
ll item[MAXN][2];	//wheight, value
ll memo[MAXN][MAXW];

ll w, n;

ll solve(ll wheight, ll index){
	if (wheight > w)
		return inf * -1;
	if (index > n)
		return 0;

	if (memo[wheight][index] == -1)
		memo[wheight][index] = max(solve(wheight + item[index][0], index+1) + item[index][1], solve(wheight, index+1));

	return memo[wheight][index];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cout<<"Number of items: ";
	cin>>n;
	cout<<"Wheight Capacity: ";
	cin>>w;
	for (ll i = 0; i<n; i++){
		cout<<"\tItem "<<i+1<<endl;
		cout<<" Wheight: "<<": ";
		cin>>item[i][0];
		cout<<" Value: "<<": ";
		cin>>item[i][1];
	}

	for (ll i = 0; i<MAXN; i++)
		for (ll j = 0; j<MAXW; j++)
			memo[i][j] = -1;
	cout<<solve(0,0)<<endl;

	return 0;
}