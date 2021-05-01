#include <bits/stdc++.h>

typedef unsigned long long ull;
typedef long long ll;

#define vl vector<long long>
#define ln "\n"
#define pb emplace_back
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define loop(i, a, b) for (int i = (a); i <= (b); i++)
#define rloop(i, a, b) for (int i = (a); i >= (b); i--)
#define ploop(i, a, b, c)            \
    for (int i = (a); i <= (b); i++) \
        cout << c[i] << "";

using namespace std;

ll minValue(ll a, ll b)
{
    return (a < b) ? a : b;
}
ll maxValue(ll a, ll b)
{
    return (a > b) ? a : b;
}
ll cookingForN(ll n, ll e, ll h, ll a, ll b, ll c)
{
    if (n <= 0)
        return 0;

    ll answer = 1e15;

    if ((n <= e) && n <= h)
        answer = minValue(answer, n * c);

    if (3 * n <= h)
        answer = minValue(answer, n * b);

    if (2 * n <= e)
        answer = minValue(answer, n * a);

    if (((h - n) / 2 >= 1) && ((h - n) / 2 >= n - e))
    {
        if ((b - c) < 0)
        {
            ll tmp = minValue(n - 1, (h - n) / 2);
            answer = minValue(answer, (b - c) * tmp + n * c);
        }
        else
        {
            ll tmp = maxValue(1, (n - e));
            answer = minValue(answer, (b - c) * tmp + n * c);
        }
    }

    if (((e - n) >= 1) && ((e - n) >= (n - h)))
    {
        if (a - c < 0)
        {
            ll tmp = minValue(n - 1, e - n);
            answer = minValue(answer, (a - c) * tmp + n * c);
        }
        else
        {
            ll tmp = maxValue(1, (n - h));
            answer = minValue(answer, (a - c) * tmp + n * c);
        }
    }

    if ((e / 2 >= 1) && (e / 2 >= (3 * n - h + 2) / 3))
    {
        if (a - b < 0)
        {
            ll tmp = minValue(n - 1, e / 2);
            answer = minValue(answer, (a - b) * tmp + n * b);
        }
        else
        {
            ll tmp = maxValue(1, (3 * n - h + 2) / 3);
            answer = minValue(answer, (a - b) * tmp + n * b);
        }
    }

    if ((e >= 3) && (h >= 4) && (n >= 3))
    {
        answer = minValue(answer, a + b + c + cookingForN(n - 3, e - 3, h - 4, a, b, c));
    }

    return answer;
}
void solve()
{
    ll n, e, h, a, b, c;
    cin >> n >> e >> h >> a >> b >> c;
    ll answer;
    answer = cookingForN(n, e, h, a, b, c);
    if (answer == 1e15)
        cout << (-1) << ln;
    else
        cout << answer << ln;
}
int main()
{
    fast_cin();
    /* #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif */
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}