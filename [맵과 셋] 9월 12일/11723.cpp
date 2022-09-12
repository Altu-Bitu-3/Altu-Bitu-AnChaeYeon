#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); //�ð� ������

    int n, x; //n:�Է� ���� x:������ ��
    x >= 0 && x <= 20;
    string cmd; //���
    set<int> set, all;

    //�Է�
    cin >> n;
    while (n--) {
        cin >> cmd;
        if (cmd == "add") {
            cin >> x;
            set.insert(x);
        }
        if (cmd == "remove") {
            cin >> x;
            set.erase(x);
        }
        if (cmd == "check") {
            cin >> x;
            if (set.find(x) == set.end()) { //x�� ������
                cout << "0" << "\n"; //0�� ���
            }
            else { //x�� ������
                cout << "1" << "\n"; //1�� ���
            }
        }
        if (cmd == "toggle") {
            cin >> x;
            if (set.find(x) == set.end()) { //x�� ������
                set.insert(x); //x �߰�
            }
            else { //x ������
                set.erase(x); //����
            }
        }
        if (cmd == "all") {
            for (int i = 1; i <= 21; i++) { //1���� 20�� �ִ� set �����
                all.insert(i);
            }
            set = all; //set�� all�� ��ü
        }
        if (cmd == "empty") {
            set.clear();
        }
    }

    return 0;
}