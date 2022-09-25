#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){

	ios_base::sync_with_stdio(0);

	cin.tie(0);

	int N, K;
	cin >> N >> K;

	vector<char> v(N);

	fill(v.begin(),	v.end(), '?'); 

	int idx = 0;

	for (int i = 0; i < K;i++){

		int temp;
		char c;
		cin >> temp >> c;

		temp%= N;

		if (idx - temp < 0)
			idx= (idx - temp) + N;

		else
			idx-= temp;


		if (v[idx] != '?' && v[idx] != c)
		{
			cout<< "!\n";
			return 0;
		}
		else
			v[idx] = c;
	}


	for (int i = 0; i < N;i++)
		for (int j = i + 1; j < N; j++)
			if (v[i] != '?' && v[i] == v[j])
			{
				cout<< "!\n";
				return 0;
			}

	for (int i = 0; i < N;i++)
		cout << v[(i + idx) % N];

	cout << "\n";

	return 0;

}