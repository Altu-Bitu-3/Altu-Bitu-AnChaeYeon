#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> line_a;
vector<int> line_b;

int main(void) {

	//원소 개수 입력
	cin >> n;

	//리스트 a 입력
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		line_a.push_back(k);
	}

	//리스트 b 입력
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		line_b.push_back(k);
	}

	sort(line_a.begin(), line_a.end());
	sort(line_b.begin(), line_b.end());

	int answer = 0;
	for (int i = 0; i < n; i++) {
		answer += line_a[i] * line_b[n - 1 - i];
	}

	//output
	cout << answer;

}