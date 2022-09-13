//벡터 사용
#include <iostream> // 입출력 라이브러리
#include <vector> // 벡터 라이브러리
using namespace std;  // namespace 사용

/*
    매개변수에 &를 붙이면 원본을 참조하게 됩니다.
    **이 문제에서는 굳이 참조자를 사용할 필요는 없지만, C++에서는 주로 &를 붙입니다**
*/

vector<int> calcPlus(string &a, string &b) { // 두 숫자를 계산하는 함수
    int idx_a = a.size() - 1; // 일의 자리 인덱스
    int idx_b = b.size() - 1; // 일의 자리 인덱스
    bool carry = false;  // 올림 true, false 
    vector<int> ans; // 정수형 벡터 ans 선언

    while (idx_a >= 0 && idx_b >= 0) { // idx_a, idx_b 가 0 이상일 때
        int num = (a[idx_a--] - '0') + (b[idx_b--] - '0'); // 문자를 숫자로 바꾸어 더하기, 그리고 인덱스 변경

        num += carry;            // num에 carry 더해주기. (carry는 어차피 1 아니면 0)
        carry = num / 10;        // num의 값이 10이상이면 carry가 1, 아니면 0
        ans.push_back(num % 10); // 올림을 제외한 값만 스택에 push
    }

    // a에서 남은 숫자 반영
    while (idx_a >= 0) { // idx_a 가 0 이상일 때
        int num = a[idx_a--] - '0'; // a[idx_a]를 숫자로 변환하여 num에 저장

        num += carry; // num+carry=num
        carry = num / 10; // num 을 10으로 나눈 몫을 carry 에 저장
        ans.push_back(num % 10); // num을 10으로 나눈 나머지를 ans 에 삽입
    }

    // 남은 올림 확인
    if (carry) // 올림이 true 라면
        ans.push_back(1); // ans에 1 삽입

    return ans; // ans 값을 리턴
}

int main() {
    ios::sync_with_stdio(0); // c와 c++의 동기화를 끊어 속도를 올림
    cin.tie(0); // cin과 cout의 묶음을 풀어줌

    string a, b; // 문자 a,b 선언 (사실 숫자지만 문자로 선언해줌)
    vector<int> ans; // 정수형 벡터 ans 선언

    cin >> a >> b;     // a,b 입력

    //연산
    if (a.length() < b.length()) // b의 길이가 더 길다면
        swap(a, b); // a 와 b의 자리를 바꿈

    ans = calcPlus(a, b); // calcPlus 함수에 a,b를 전달하고 결과값을 ans에 저장 

    //출력
    while (!ans.empty()) { // ans가 빌때까지
        cout << ans.back(); // 출력
        ans.pop_back(); // 출력한 값은 ans 에서 삭제
    }
}