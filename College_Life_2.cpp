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

void solve()
{
    ll s{};
    vi q{};
    ll mins{};

    cin >> s; //S

    REP(i, s) // duration of song
    {
        ll x;
        cin >> x;
        q.PB(x);
    }

    REP(i, s) //num of episodes
    {

        ll x, y;
        cin >> x;
        mins += q[i];

        REP(j, x)
        {
            cin >> y;
            mins += abs(y - q[i]);
        }
    }

    cout << mins << ln;
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