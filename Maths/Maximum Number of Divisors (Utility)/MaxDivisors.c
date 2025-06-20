//AUTHOR: hashlife
//REFERENCE: https://codeforces.com/blog/entry/14463?#comment-194530
//ONLINE CODE: https://ideone.com/JNRMsQ
//CODE DESCRIPTION: Calculates the exact maximum number of divisors over the range of numbers from 1 to N. (1 <= N <= 10^18)

#include <stdio.h>

unsigned long long n, res;
int p, primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 51, 53, 59, 61, 67, 71};

unsigned long long mul(unsigned long long a, unsigned long long b){
    unsigned long long res = 0;

    while (b){
        if (b & 1LL) res = (res + a);
        if (res >= n) return 0;
        a = (a << 1LL);
        b >>= 1LL;
    }

    return res;
}

void backtrack(int i, int lim, unsigned long long val, unsigned long long r){
    if (r > res) res = r;
    if (i == p) return;

    int d;
    unsigned long long x = val;

    for (d = 1; d <= lim; d++){
        x = mul(x, primes[i]);
        if (x == 0) return;
        backtrack(i + 1, d, x, r * (d + 1));
    }
}

int main(){
    /* Tested for n <= 10^18 */

    p = sizeof(primes) / sizeof(int);

    while (scanf("%llu", &n) != EOF){
        res = 0;
        backtrack(0, 100, 1, 1);
        printf("Maximum number of divisors of any number less than %llu = %llu\n", n, res);
    }
    return 0;
}
