#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <string>
#include <map>

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


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	map <char, int> mp;	// declare map
	string s;
	cin>>s;
	
	//example to show all functions...
	mp['F'] = 3;
	if (mp.find('F') !=  mp.end())		//check if a map key exists
		mp.erase('F');		//erase from map

	//Insert in map
	mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    
    int len = s.size()-1;
    int ans = mp[s[len]];
    for (int i = len-1; i>=0; i--){
        if (mp[s[i]] < mp[s[i+1]])
            ans -= mp[s[i]];
        else
            ans += mp[s[i]];
    }

    //Looping through map:
    cout<<endl<<"Printing Map: "<<endl;
    map <char, int> :: iterator it;		//map iterator
    for ( it = mp.begin(); it!=mp.end(); it++)
    	cout<<"KEY:"<<it->F<<"  VALUE:"<<it->S<<endl;
    cout<<endl;
	
	cout<<ans;

	return 0;
}

/*
Sample Input:
IVXXMMDLCICVVI
*/

/*

Maps Vs Unordered Maps:
=> (ordered) Maps: Uses Binary Segment Trees and have time complexity of O(NlogN)
=> Unordered Maps: Uses hashing table. Thus, data collisions are possible, thus has time complexity of O(1) to O(N)
=> Strategy: Use ordered maps by default, and if too slow, try switching to unordered map

* Note Declaration and use are the same => only difference: use "unordered_map" instead of "map" keyword

*/
































