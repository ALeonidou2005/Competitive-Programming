#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define llu unsigned long long
#define endl "\n"


int main(){
	
	/* 
	declaration
	*/
	vector <ll> v;
	//vector <ll> vect(10, 0);		//init & assign
	//vector <ll> vect(10);		//init & resize
	
	/* 
	assignment - initialisation
	*/
	v.assign(2, 0);	//assign
	//v.resize(10);

	/* 
	add element
	*/
	for (ll i= 0; i<7; i++)
		v.push_back(i*2);
	v.push_back(0);
	v.__emplace_back(2);	//emplace back is the same as push_back but using a different (sometimes faster method depending on the use)

	/* 
	remove element
	*/
	//v.clear();
	v.pop_back();	//remove last
	v.erase(v.begin());		//remove first element
	v.erase(v.begin() + 2);  //remove third element
	v.erase(v.end() - 2, v.end()); 	// remove last two elements



	//access - use
    for (ll i = 0; i<v.size(); i++)
        cout<<v[i]<<" ";

	return 0;
}


































