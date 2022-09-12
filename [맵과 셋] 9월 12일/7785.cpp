#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n; //���� ��� ��
    string name, check;
    map<string, int> member; //���� ����� ��ü ����
    vector<string> enter_member; //ȸ�翡 �����ִ� ����

    //�Է�
    cin >> n;
    while (n--) {
        cin >> name >> check;
        if (check == "enter") { //����� enter�̸�
            member[name] = 1; //key�� name, value�� 1
        }
        else { //����� leave �̸�
            member[name] = 0; //key�� name, value�� 0
        }
    }

    for (auto i : member) {
        if (i.second == 1) { //����� enter�̸�
            enter_member.push_back(i.first); //enter_member�� �߰�
        }
    }

    sort(enter_member.rbegin(), enter_member.rend()); //�������� ����

    for (auto i : enter_member) {
        cout << i << "\n";
    }

    return 0;
}