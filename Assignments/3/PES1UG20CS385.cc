#include <complex>
#include <vector>
#include <iostream>
using namespace std;
using cd_t = complex<long double>;

cd_t e_pow_2pi_i_by_m(int m)
{
    return cd_t(cos(2.0 * M_PI / m), sin(2.0 * M_PI / m));
}

int bitReverse(int x, int log2n) 
{
    int n = 0;
    for (int i = 0; i < log2n; ++i)
    {
        n <<= 1;
        n |= (x & 1);
        x >>= 1;
    }
    return n;
}

vector<cd_t> fft(const vector<cd_t> &a)
{
    int p = a.size();

    if (p == 1)
        return vector<cd_t>(1, a[0]);

    vector<cd_t> w(p);
    for (int i = 0; i < p; i++) {
        if(i == 0){
            double alpha = 2 * M_PI * i / p;
            w[i] = cd_t(cos(alpha), sin(alpha));
        }
        else{
            int alpha = p / i;
        w[i] = e_pow_2pi_i_by_m(alpha);
        }
    }
 
    vector<cd_t> B0(p / 2), B1(p / 2);
    for (int i = 0; i < p / 2; i++) {
 
        B0[i] = a[i * 2];
 
        B1[i] = a[i * 2 + 1];
    }
 
    vector<cd_t> z0 = fft(B0);
 
    vector<cd_t> z1 = fft(B1);
 
    vector<cd_t> z(p);
 
    for (int k = 0; k < p / 2; k++) {
        z[k] = z0[k] + w[k] * z1[k];
        z[k + p / 2] = z0[k] - w[k] * z1[k];
    }
    return z;
}

int main()
{
    int N;
    cin >> N;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
    }

    vector<cd_t> complex_a;
    for (auto i : a)
    {
        complex_a.push_back(cd_t(i, 0));
    }

    vector<cd_t> ans = fft(complex_a);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
}
