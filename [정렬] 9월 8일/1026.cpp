#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> line_a;
vector<int> line_b;

int main(void) {

	//���� ���� �Է�
	cin >> n;

	//����Ʈ a �Է�
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		line_a.push_back(k);
	}

	//����Ʈ b �Է�
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