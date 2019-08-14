/* O(Log(min(a, b))) - Returns a * b mod m without overflowing. 2 * (m - 1) must not overflow. */
long long mod_mul(long long a, long long b, long long m){
	long long ans = 0;

	// In case a >= m or b >= m.
	a %= m;
	b %= m;

	// Forcing b to be the smallest.
	if (a < b){
		swap(a, b);
	}

	// Decomposing b in binary. Adding to the answer a * 2^0, a * 2^1, a * 2^2, a * 2^4, a * 2^8, ...
	while (b > 0){
		// If current bit is set.
		if (b & 1ll){
			ans = (ans + a) % m;
		}

		b >>= 1ll; // Next bit.
		a = (2ll * a) % m; // Next power of two multiplied by a.
	}

	return ans;
}