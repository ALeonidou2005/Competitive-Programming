#include <iostream>

#define ll long long

using namespace std;

ll gcd(ll u, ll v) {
  ll shift;
  if (u == 0)
    return v;
  if (v == 0)
    return u;
  shift = __builtin_ctz(u | v);
  u >>= __builtin_ctz(u);
  do {
    ll m;
    v >>= __builtin_ctz(v);
    v -= u;
    m = (ll)v >> 31;
    u += v & m;
    v = (v + m) ^ m;
  } while (v != 0);
  return u << shift;
}

ll gcd2(ll a, ll b){
	if (b==0)
		return a;
	return gcd(b, a%b);
}


#define N 10000000

int main(){

    auto start = std::chrono::high_resolution_clock::now();
    auto stop = std::chrono::high_resolution_clock::now();
	auto duration = duration_cast<std::chrono::microseconds>(stop - start);

	const ll a = 75000, b = 15000;

  ll t = 5, d1,d2, m;
  for (ll k = 1; k<=t; k++){
    cout<<"\t\tTEST "<<k<<endl;
    start = std::chrono::high_resolution_clock::now();
    for (ll i = 0; i<N; i++)
      m = gcd(a+i,b);
    stop = std::chrono::high_resolution_clock::now();
    duration = duration_cast<std::chrono::microseconds>(stop - start);
    d1 = duration.count();


    start = std::chrono::high_resolution_clock::now();
    for (ll i = 0; i<N; i++)
      m = gcd2(a+i,b);
    stop = std::chrono::high_resolution_clock::now();
    duration = duration_cast<std::chrono::microseconds>(stop - start);
    d2 = duration.count();

    cout<<"Time taken by test 1: "<<d1<<" microseconds"<<endl;
    cout<<"Time taken by test 2: "<<d2<<" microseconds"<<endl;
    if (d1 < d2)
      cout<<"  => GCD 1"<<endl;
    else
      cout<<"  => GCD 2"<<endl;
  }

	
	return 0;
}

/*
SPEED TEST RESULTS:
Binary GCD is slightly faster for very large numbers.
Normal GCD is slightly faster for smaller numbers.
The difference in effeciency between binary and normal gcd with large numbers is less significant than the difference in effeciency between binary and normal gcd with small numbers.

SPEED TEST CONSLUSION:
Use normal GCD by default.
In case of a time limit in a program which depends largely in gcd of large numbers trye using binary gcd to avoid TLE. However, the difference is so small that it is very rare that binary gcd will be enough to optimize the program.

*/