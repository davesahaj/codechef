#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

#define FOR(i, j, k, in) for (ll i = j; i < k; i += in)
#define RFOR(i, j, k, in) for (ll i = j; i >= k; i -= in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

#define MOD 1000000007
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define PI 3.1415926535897932384626433832795
#define INF (int)1e9

#define ln "\n"
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

/**
* Limits in C++ for reference
* _____________________________________________________________________________________
* |Sr| Macro Name | Description                     | Value
* |No|____________|_________________________________|__________________________________
* |1.| ULLONG_MAX | Maximum value unsigned long long| 18,446,744,073,709,551,615 (10^20)
* |2.| LLONG_MAX  | Maximum value long long         | 9,223,372,036,854,775,807 (10^19)
* |3.| LLONG_MIN  | Minimum value long long         |-9,223,372,036,854,775,808 -1*(10^19)
* |4.| INT_MAX    | Maximum value int               | 2,147,483,647 (10^10)
* |5.| INT_MIN    | Minimum value int               |-2,147,483,648 (10^10)
*/

void array_rotation(char arr[], ll n)
{
    int k = 1;

    k %= n;

    int slice = gcd(n, k);

    for (int i{}; i < slice; i++)
    {
        int tmp = arr[i];
        int j = i;

        while (1)
        {
            int x = j + k;

            if (x >= n)
                x -= n;

            if (x == i)
                break;

            arr[j] = arr[x];
            j = x;
        }

        arr[j] = tmp;
    }
}

bool array_check(char s[], ll n, ll c)
{
    REP(i, n)
    {
    }
}

void solve()
{
    ll n, c;
    bool flag = false;
    cin >> n >> c;

    char s[n];
    cin >> s;

    REP(i, n)
    {
        if (flag)
            break;

        array_rotation(s, n);
        array_check(s, n, c);
    }
}

int main()
{

    fast_cin();

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}