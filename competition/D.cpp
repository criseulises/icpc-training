#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MOD = 998244353;
const int MAXN = 1000000 + 5;
const int ALPHABET_SIZE = 26;

long long fact[MAXN];
long long invFact[MAXN];

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

void precalculate_factorials() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAXN - 1] = modInverse(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precalculate_factorials();

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        int q;
        cin >> q;

        vector<vector<int>> prefix_counts(n + 1, vector<int>(ALPHABET_SIZE, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < ALPHABET_SIZE; ++j) {
                prefix_counts[i + 1][j] = prefix_counts[i][j];
            }
            prefix_counts[i + 1][s[i] - 'a']++;
        }

        for (int k = 0; k < q; ++k) {
            string query_type;
            cin >> query_type;

            if (query_type == "INSIDE") {
                int l, r;
                string w;
                cin >> l >> r >> w;

                int len_s = r - l + 1;
                if (len_s != (int)w.length()) {
                    cout << "NO" << "\n";
                    continue;
                }
                
                vector<int> s_counts(ALPHABET_SIZE, 0);
                for (int i = 0; i < ALPHABET_SIZE; ++i) {
                    s_counts[i] = prefix_counts[r][i] - prefix_counts[l - 1][i];
                }

                vector<int> w_counts(ALPHABET_SIZE, 0);
                for (char ch : w) {
                    w_counts[ch - 'a']++;
                }

                bool is_anagram = true;
                for (int i = 0; i < ALPHABET_SIZE; ++i) {
                    if (s_counts[i] != w_counts[i]) {
                        is_anagram = false;
                        break;
                    }
                }

                if (is_anagram) {
                    cout << "YES" << "\n";
                } else {
                    cout << "NO" << "\n";
                }

            } else if (query_type == "COUNT") {
                int l, r;
                cin >> l >> r;

                long long len = r - l + 1;

                vector<int> s_counts(ALPHABET_SIZE, 0);
                for (int i = 0; i < ALPHABET_SIZE; ++i) {
                    s_counts[i] = prefix_counts[r][i] - prefix_counts[l - 1][i];
                }

                long long result = fact[len];

                for (int count : s_counts) {
                    if (count > 0) {
                        result = (result * invFact[count]) % MOD;
                    }
                }
                
                cout << result << "\n";
            }
        }
    }

    return 0;
}