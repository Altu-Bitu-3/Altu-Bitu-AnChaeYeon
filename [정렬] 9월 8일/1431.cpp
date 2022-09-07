#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {

	int sum1 = 0, sum2 = 0;

	if (a.size() != b.size()) { //두 시리얼 번호의 문자열 길이가 다르다면
		return a.size() < b.size(); //길이가 짧은 순서대로 정렬
	}

	//두 시리얼 번호의 길이가 같음
	for (int i = 0; i < a.size(); i++) {
		if (a[i] - '0' <= 9 && a[i] - '0' >= 0) { //시리얼 번호가 숫자
			sum1 += a[i] - '0';
		}
	}

	for (int i = 0; i < b.size(); i++) {
		if (b[i] - '0' <= 9 && b[i] - '0' >= 0) { //시리얼 번호가 숫자
			sum2 += b[i] - '0';
		}
	}

	//합이 작은순으로 정렬
	if (sum1 != sum2) {
		return sum1 < sum2;
	}

	//길이, 합 모두 같다면 알파벳 순으로
	return a < b;
}

int main() {

	//입력
	int n; 
	cin >> n; //시리얼 번호 개수

	vector<string> guitar(n);

	for (int i = 0; i < n; i++) {
		cin >> guitar[i];
	}

	sort(guitar.begin(), guitar.end(), cmp);

	//출력
	for (int i = 0; i < n; i++) {
		cout << guitar[i] << '\n';
	}

}