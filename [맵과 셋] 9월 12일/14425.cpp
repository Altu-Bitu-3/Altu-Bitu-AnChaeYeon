#include <iostream>
#include <set>

using namespace std;

int main()
{

    //n:���տ� ���ԵǾ� �ִ� ���ڿ�, m:�˻��ؾ��ϴ� ���ڿ�, ans:��ġ�ϴ� ���ڿ�
    int n, m, ans = 0;
    //cmd1:���տ� �߰�, cmd2: ���տ� �ִ��� Ȯ��
    string cmd1, cmd2;
    set<string> s;

    //�Է�
    cin >> n >> m;
    while (n--) { //���տ� �߰�
        cin >> cmd1;
        s.insert(cmd1);
    }

    while (m--) { //���տ� ���ԵǾ� �ִ��� Ȯ��
        cin >> cmd2;
        if (s.find(cmd2) != s.end()) {
            ans++;
        }
    }

    cout << ans;

    return 0;
}