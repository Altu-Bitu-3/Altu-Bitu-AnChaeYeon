//���� ���
#include <iostream> // ����� ���̺귯��
#include <vector> // ���� ���̺귯��
using namespace std;  // namespace ���

/*
    �Ű������� &�� ���̸� ������ �����ϰ� �˴ϴ�.
    **�� ���������� ���� �����ڸ� ����� �ʿ�� ������, C++������ �ַ� &�� ���Դϴ�**
*/

vector<int> calcPlus(string &a, string &b) { // �� ���ڸ� ����ϴ� �Լ�
    int idx_a = a.size() - 1; // ���� �ڸ� �ε���
    int idx_b = b.size() - 1; // ���� �ڸ� �ε���
    bool carry = false;  // �ø� true, false 
    vector<int> ans; // ������ ���� ans ����

    while (idx_a >= 0 && idx_b >= 0) { // idx_a, idx_b �� 0 �̻��� ��
        int num = (a[idx_a--] - '0') + (b[idx_b--] - '0'); // ���ڸ� ���ڷ� �ٲپ� ���ϱ�, �׸��� �ε��� ����

        num += carry;            // num�� carry �����ֱ�. (carry�� ������ 1 �ƴϸ� 0)
        carry = num / 10;        // num�� ���� 10�̻��̸� carry�� 1, �ƴϸ� 0
        ans.push_back(num % 10); // �ø��� ������ ���� ���ÿ� push
    }

    // a���� ���� ���� �ݿ�
    while (idx_a >= 0) { // idx_a �� 0 �̻��� ��
        int num = a[idx_a--] - '0'; // a[idx_a]�� ���ڷ� ��ȯ�Ͽ� num�� ����

        num += carry; // num+carry=num
        carry = num / 10; // num �� 10���� ���� ���� carry �� ����
        ans.push_back(num % 10); // num�� 10���� ���� �������� ans �� ����
    }

    // ���� �ø� Ȯ��
    if (carry) // �ø��� true ���
        ans.push_back(1); // ans�� 1 ����

    return ans; // ans ���� ����
}

int main() {
    ios::sync_with_stdio(0); // c�� c++�� ����ȭ�� ���� �ӵ��� �ø�
    cin.tie(0); // cin�� cout�� ������ Ǯ����

    string a, b; // ���� a,b ���� (��� �������� ���ڷ� ��������)
    vector<int> ans; // ������ ���� ans ����

    cin >> a >> b;     // a,b �Է�

    //����
    if (a.length() < b.length()) // b�� ���̰� �� ��ٸ�
        swap(a, b); // a �� b�� �ڸ��� �ٲ�

    ans = calcPlus(a, b); // calcPlus �Լ��� a,b�� �����ϰ� ������� ans�� ���� 

    //���
    while (!ans.empty()) { // ans�� ��������
        cout << ans.back(); // ���
        ans.pop_back(); // ����� ���� ans ���� ����
    }
}