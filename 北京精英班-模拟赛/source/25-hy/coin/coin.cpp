#include<iostream>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<iomanip>
#include<cstdio>
#include<cmath>
using namespace std;

double a[100010], b[100010];
double mx; int n;
int ch[100010];
double tur = 232.6, alp = 0.8;

long double total() {
	long double wa = 0, wb = 0;
	for (int i = 0; i < n; ++i)
		switch (ch[i]) {
		case 1: --wa; wb += b[i] - 1; break;
		case 2: wa += a[i] - 1; --wb; break;
		case 3: wa += a[i] - 2; wb += b[i] - 2; break;
		}
	return min(wa, wb);
}

void randflip() {
	for (int i = 0; i < n; ++i)
		ch[i + 0] = (ch[i + 0] + (int)(rand() / 32767.0 * 4 * tur) % 4) % 4;
}

void upd_randflip() {
	for (int i = 0; i < n; ++i)
		if ((ch[i] = (ch[i] + (int)(rand() / 32767.0 * 5 * tur) % 5) % 5) == 4)
			ch[i] = 3;
}

void s(int i, double wa, double wb) {
	if (i == n) {
		mx = max(mx, min(wa, wb));
		return;
	}
	s(i + 1, wa, wb);
	s(i + 1, wa + a[i] - 1, wb - 1);
	s(i + 1, wa - 1, wb + a[i] - 1);
	s(i + 1, wa + a[i] - 2, wb + b[i] - 2);
}

int main() {
	freopen("coin.in", "r", stdin);
	freopen("coin.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i] >> b[i];
	if (n <= 12) {
		s(0, 0, 0);
		cout << fixed << setprecision(4) << mx << endl;
	} else { //random hhh
		//of course not simulated annealing #(funny)
		long double g = 0;
		srand(time(0) + n * n + 19260817);
		srand(time(0) + clock() + rand());
		for (int i = 0; i < 1000; ++i) srand(((rand() + 3) << 1) - 5);
		for (int i = 0; i < n; ++i) ch[i] = rand() / 32767.0 * 4;
		g = max(total(), g);
		while (clock() <= 900) {
			while (abs(tur *= alp) >= 1e-5) {
				randflip();
				long double w = total();
				if (g - total() > n / 3.0) {
					upd_randflip();
				}
				g = max(w, g);
			}
			tur = rand() / 32767.0 * rand() * 1.3;
		}
		cout << fixed << setprecision(4) << g << endl;
	}
	return 0;
}
