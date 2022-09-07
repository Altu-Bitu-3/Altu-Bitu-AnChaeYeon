#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
	int x, y;
};

bool cmp(const point& a, const point& b) {

	if (a.y != b.y) {
		return a.y < b.y;
	}

	return a.x < b.x;
}

int main() {

	int n;
	cin >> n;

	vector<point> array(n);

	for (int i = 0; i < n; i++) {
		cin >> array[i].x >> array[i].y;
	}

	sort(array.begin(), array.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << array[i].x << ' ' << array[i].y << '\n';
	}

}