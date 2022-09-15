#include <iostream>
#include <set>

using namespace std;

int main()
{

    //n:집합에 포함되어 있는 문자열, m:검사해야하는 문자열, ans:일치하는 문자열
    int n, m, ans = 0;
    //cmd1:집합에 추가, cmd2: 집합에 있는지 확인
    string cmd1, cmd2;
    set<string> s;

    //입력
    cin >> n >> m;
    while (n--) { //집합에 추가
        cin >> cmd1;
        s.insert(cmd1);
    }

    while (m--) { //집합에 포함되어 있는지 확인
        cin >> cmd2;
        if (s.find(cmd2) != s.end()) {
            ans++;
        }
    }

    cout << ans;

    return 0;
}