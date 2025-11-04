V=\frac{\pi h^{2}}{3}(3R-h) // Объем сегмента шара
V=\frac{2}{3}\pi R^{2}h // Объем сектора шара
V_x = \pi \int _{a}^{b} [f(x)]^{2} dx // Объем тела вращения вокруг OX
V_y = 2 \pi \int _{a}^{b} x f(x) dx // Объем тела вращения вокруг OY


// Инверсия по модулю
int MOD = 998244353;

int power(int a, int b) {
    int res = 1;
    while(b > 0) {
        if(b % 2 == 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

int inv(int a) {
    return power(a, MOD - 2);
}

// Расширенный алгоритм Евклида
int gcd (int a, int b, int & x, int & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

// Решето 
int n;
vector<char> prime (n+1, true); // phi[i] = i;
prime[0] = prime[1] = false;
for (int i=2; i<=n; ++i)
	if (prime[i]) // phi[i] == i;
		if (i * 1ll * i <= n)
			for (int j=i*i; j<=n; j+=i)
				prime[j] = false; //  phi[j] = phi[j] * (i - 1) / i
				
// FFT
const int mod = 7340033;
const int root = 5;
const int root_1 = 4404020;
const int root_pw = 1<<20;
 
void fft (vector<int> & a, bool invert) {
	int n = (int) a.size();
 
	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}
 
	for (int len=2; len<=n; len<<=1) {
		int wlen = invert ? root_1 : root;
		for (int i=len; i<root_pw; i<<=1)
			wlen = int (wlen * 1ll * wlen % mod);
		for (int i=0; i<n; i+=len) {
			int w = 1;
			for (int j=0; j<len/2; ++j) {
				int u = a[i+j],  v = int (a[i+j+len/2] * 1ll * w % mod);
				a[i+j] = u+v < mod ? u+v : u+v-mod;
				a[i+j+len/2] = u-v >= 0 ? u-v : u-v+mod;
				w = int (w * 1ll * wlen % mod);
			}
		}
	}
	if (invert) {
		int nrev = reverse (n, mod);
		for (int i=0; i<n; ++i)
			a[i] = int (a[i] * 1ll * nrev % mod);
	}
}

void multiply (const vector<int> & a, const vector<int> & b, vector<int> & res) {
	vector<int> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	size_t n = 1;
	while (n < max (a.size(), b.size()))  n <<= 1;
	n <<= 1;
	fa.resize (n),  fb.resize (n);
 
	fft (fa, false),  fft (fb, false);
	for (size_t i=0; i<n; ++i)
		fa[i] *= fb[i];
	fft (fa, true);
 
	res.resize (n);
	for (size_t i=0; i<n; ++i)
		res[i] = int (fa[i].real() + 0.5);
}
