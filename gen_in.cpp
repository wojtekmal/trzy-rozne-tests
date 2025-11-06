#include <bits/stdc++.h>
using namespace std;
#define ll long long

mt19937 rng{};

struct Test
{
    ll n;
    vector<ll> types;
    vector<ll> positions;
};

Test get_random_test(ll max_n, ll type_count, ll max_pos)
{
    Test result;
    result.n = rng() % max_n + 1;
    result.types = vector<ll>(result.n);
    result.positions = vector<ll>(result.n);

    for (ll i = 0; i < result.n; i++)
    {
        result.types[i] = rng() % type_count + 1;
        result.positions[i] = rng() % (max_pos + 1);
    }

    sort(result.positions.begin(), result.positions.end());
    return result;
}

void check_test(const Test& test)
{
    assert(1 <= test.n && test.n <= 1000'000);
    assert(test.types.size() == test.n);
    assert(test.positions.size() == test.n);

    for (int i = 0; i < test.n - 1; i++)
    {
        assert(test.positions[i] <= test.positions[i + 1]);
    }

    for (int i = 0; i < test.n; i++)
    {
        assert(0 <= test.positions[i] && test.positions[i] <= INT_MAX);
        assert(1 <= test.types[i] && test.types[i] <= INT_MAX);
    }
}

void write_test(const Test& test, const string& group, int index)
{
    auto file = ofstream(group + "/" + to_string(index) + ".in");
    file << test.n << "\n";

    for (int i = 0; i < test.n; i++)
    {
        file << test.types[i] << " " << test.positions[i] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    for (int i = 1; i < 10000;)
    {
        write_test(get_random_test(5, 5, 5), "tiny", i++);
    }

    for (int i = 1; i < 1000;)
    {
        write_test(get_random_test(100, 100, 100), "small", i++);
    }

    for (int i = 1; i < 1000;)
    {
        write_test(get_random_test(1000, 1000, 1000), "medium", i++);
    }

    for (int i = 1; i < 100;)
    {
        write_test(get_random_test(1000000, INT_MAX, INT_MAX), "big", i++);
    }
}