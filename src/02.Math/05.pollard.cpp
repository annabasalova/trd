typedef long long ll;

inline ll f(ll x, ll n) { return (__int128_t) (x + 1) * (x + 1) % n; }

ll find_divisor(ll n, ll seed = 1) {
    ll x = seed, y = seed;
    ll d = 1;
    while (d == 1 || d == n) {
        // двигаем первый указатель на шаг
        y = f(y);
        // а второй -- на два
        x = f(f(x));
        // пытаемся найти общий делитель
        d = gcd(abs(x - y), n);
    }
    return d;
}
