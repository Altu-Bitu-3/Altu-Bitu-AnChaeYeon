#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n; //출입 기록 수
    string name, check;
    map<string, int> member; //출입 기록한 전체 직원
    vector<string> enter_member; //회사에 남아있는 직원

    //입력
    cin >> n;
    while (n--) {
        cin >> name >> check;
        if (check == "enter") { //기록이 enter이면
            member[name] = 1; //key가 name, value는 1
        }
        else { //기록이 leave 이면
            member[name] = 0; //key가 name, value는 0
        }
    }

    for (auto i : member) {
        if (i.second == 1) { //기록이 enter이면
            enter_member.push_back(i.first); //enter_member에 추가
        }
    }

    sort(enter_member.rbegin(), enter_member.rend()); //역순으로 정렬

    for (auto i : enter_member) {
        cout << i << "\n";
    }

    return 0;
}