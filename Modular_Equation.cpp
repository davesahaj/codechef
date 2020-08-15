#pragma region Template

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
typedef vector<pll> vpll;
typedef vector<pii> vpii;

#define FOR(i, j, k, in) for (ll i = j; i < k; i += in)
#define RFOR(i, j, k, in) for (ll i = j; i >= k; i -= in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

#define MOD 1000000007
#define F first
#define S second
#define PB push_back
#define EB emplace_back
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

const string YESNO[2] = {"NO", "YES"};
const string YesNo[2] = {"No", "Yes"};
const string yesno[2] = {"no", "yes"};
void YES(bool t = 1) { cout << YESNO[t] << ln; }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { cout << YesNo[t] << ln; }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { cout << yesno[t] << ln; }
void no(bool t = 1) { yes(!t); }

void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(string &a) { cin >> a; }

ll IN()
{
    ll x;
    cin >> x;
    return x;
}

template <class T>
void scan(vector<T> &a)
{
    for (auto &i : a)
        scan(i);
}
template <class T>
void scan(T &a) { cin >> a; }

#pragma endregion

ll solve()
{
    ll n, m, c{}, i{2};
    scan(n);
    scan(m);

    vl p(1 + n, 1);
    while (i <= n)
    {
        c += p[m % i];
        ll j = m % i;
        while (j <= n)
        {
            ++p[j];
            j = j + i;
        }
        ++i;
    }

    return c;
}

int main()
{

    fast_cin();

    /* #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif*/

    ll t;
    cin >> t;
    while (t--)
    {
        cout << solve() << ln;
    }
    return 0;
}