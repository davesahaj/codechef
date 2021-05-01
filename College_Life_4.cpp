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

ll minmax(ll a, ll b, bool f)
{
    if (f)
        return (a < b) ? a : b;

    return (a > b) ? a : b;
}

bool c(ll N, ll E, ll H)
{
    return ((N <= E) && N <= H);
}
bool s(ll N, ll E, ll H)
{
    return (3 * N <= H);
}
bool o(ll N, ll E, ll H)
{
    return (2 * N <= E);
}
bool sc(ll N, ll E, ll H)
{
    return ((H - N) / 2 >= 1) && ((H - N) / 2 >= N - E);
}
bool oc(ll N, ll E, ll H)
{
    return (((E - N) >= 1) && ((E - N) >= (N - H)));
}
bool os(ll N, ll E, ll H)
{
    return ((E / 2 >= 1) && (E / 2 >= (3 * N - H + 2) / 3));
}
bool osc(ll N, ll E, ll H)
{
    return ((E >= 3) && (H >= 4) && (N >= 3));
}

ll calc(ll N, ll E, ll H, ll A, ll B, ll C)
{
    bool f = N <= 0;
    if (f)
        return !f;

    ll x = 1e13;
    ll y{};

    ll NA = N * A;
    ll NB = N * B;
    ll NC = N * C;

    if (c(N, E, H))
        x = minmax(x, NC, true);

    if (s(N, E, H))
        x = minmax(x, NB, true);

    if (o(N, E, H))
        x = minmax(x, NA, true);

    if (sc(N, E, H))
    {
        if ((B - C) < 0)
            y = minmax(N - 1, (H - N) / 2, true);

        else
            y = minmax(1, (N - E), false);

        x = minmax(x, (B - C) * y + N * C, true);
    }

    if (oc(N, E, H))
    {
        if (A - C < 0)
            y = minmax(N - 1, E - N, true);

        else
            y = minmax(1, (N - H), false);

        x = minmax(x, (A - C) * y + N * C, true);
    }

    if (os(N, E, H))
    {
        if (A - B < 0)
            y = minmax(N - 1, E / 2, true);

        else
            y = minmax(1, (3 * N - H + 2) / 3, false);

        x = minmax(x, (A - B) * y + N * B, true);
    }

    if (osc(N, E, H))
    {
        x = minmax(x, A + B + C + calc(N - 3, E - 3, H - 4, A, B, C), true);
    }

    return x;
}

void solve()
{
    ll N, E, H, A, B, C;
    cin >> N >> E >> H >> A >> B >> C;

    ll x;
    x = calc(N, E, H, A, B, C);

    if (x == 1e13)
        cout << (-1) << ln;
    else
        cout << x << ln;
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