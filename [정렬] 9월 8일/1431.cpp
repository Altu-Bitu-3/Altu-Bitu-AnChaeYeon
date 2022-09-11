#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {

	int sum1 = 0, sum2 = 0;

	if (a.size() != b.size()) { //�� �ø��� ��ȣ�� ���ڿ� ���̰� �ٸ��ٸ�
		return a.size() < b.size(); //���̰� ª�� ������� ����
	}

	//�� �ø��� ��ȣ�� ���̰� ����
	for (int i = 0; i < a.size(); i++) {
		if (a[i] - '0' <= 9 && a[i] - '0' >= 0) { //�ø��� ��ȣ�� ����
			sum1 += a[i] - '0';
		}
	}

	for (int i = 0; i < b.size(); i++) {
		if (b[i] - '0' <= 9 && b[i] - '0' >= 0) { //�ø��� ��ȣ�� ����
			sum2 += b[i] - '0';
		}
	}

	//���� ���������� ����
	if (sum1 != sum2) {
		return sum1 < sum2;
	}

	//����, �� ��� ���ٸ� ���ĺ� ������
	return a < b;
}

int main() {

	//�Է�
	int n; 
	cin >> n; //�ø��� ��ȣ ����

	vector<string> guitar(n);

	for (int i = 0; i < n; i++) {
		cin >> guitar[i];
	}

	sort(guitar.begin(), guitar.end(), cmp);

	//���
	for (int i = 0; i < n; i++) {
		cout << guitar[i] << '\n';
	}

}