#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

#define ll long long
#define llu unsigned long long
#define F first
#define S second
#define endl "\n"

#define sortVct(a) sort (a.begin(), a.end())
#define reverseVct(a) reverse (a.begin(), a.end())
#define pb push_back

#define inf 1e6
#define INF 1e9
#define MOD 1000000007

typedef pair <ll, ll> ii;
typedef pair <ll,ii> iii;
typedef vector <ll> vi;
typedef vector <ii> vii;

ll mpow(ll a, ll b, ll modu){		//Time Complexity: O(log(p));
	ll res = 1;

	while (b > 0){
		if (b%2 == 1)
			res = (res * a) % modu;
		a = (a * a) % modu;
		b /= 2;
	}

	return res;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	ll a,b;
	cout<<"Enter base and exponent: ";
	cin>>a>>b;

	cout<<endl<<a<<" to the power of "<<b<<" = "<<mpow(a,b,MOD)<<endl;
	
	return 0;
}

/*

Binary / Efficient / Modular Exponention:
	=> Main Idea: Divide powers by two every time (a^b = (a*a)^(b/2))
	=> Used for quick exponentiation
	=> Used for taking mod of exponential results
	=> Time Complexity is O(log2(n)), where n is the exponent

*/


























