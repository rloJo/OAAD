#include <iostream>
#include <cmath>

using namespace std;

int tc;
int m;

void solution() {
	cin >> tc;
	while (tc--) {
		cin >> m; m++;
		double s = 0;
		while(--m) s += log10(m);
		cout << (int)s + 1 << '\n';
	}
}

int main()
{
	solution();
	return 0;
}
