#include<iostream>

using namespace std;

class overflowError{};
class incorrectInputError{};;

long long int product(int num, int count) {
    long long int answer = 1;
    int temp;

    for (int i = 0; i < count; i++) {
        temp = answer * (num - i);

        if (temp < answer) {
            throw overflowError();
        }
        
        answer = temp;
    }
    return answer;
}

long long int solution(int balls, int share) {
    long long int answer;
    
    if (balls < share) {
        throw incorrectInputError();        // ������ �߻��Ͽ����Ƿ� ���� ����. �� �Լ��� ȣ���� �Լ��� exit��
    }

    try {
        long long int a = product(balls, share);
        long long int b = product(share, share);
        answer = a / b;
    }catch (overflowError e) {
        cout << "OverFlowError occurred" << endl;
        answer = -1;
    }
    
    return answer;
}

int main(void) {
    while (true) {
        int ball, shar;
        cin >> ball >> shar;
        if (ball == -1) {
            break;
        }

        try {                               // ������ �ǽɵǴ� �κ�
            cout << solution(ball, shar) << endl;
        }
        catch(incorrectInputError e) {      // ���� ��Ҵ� ���
            cout << "IncorrectInputError occurred: " << ball << " " << shar << endl;        // ������ ���� ó��
        }

    }

    // ������ ���� ó���� �ϰ� �ٽ� ���� ����
    return 0;
}


/*
// ������ �߻��ص� �׿� ���� ��ó�ൿ�� ���� �� �ٽ� ���� �����ϵ��� �ϴ� ���� Error Handling�� ��ǥ
// ���� �߻� ��, �׿� ���� catch�� �� �� �̻��� �� �� �� ������ �� ���� catch���� �� ������ ���� ����
// catch(...) �� ��� ������ �� ����. ������ �𸣱� ������ �� ��Ȳ�� �´� ������ ��ġ �Ұ���. �ּ��� ���α׷��� �״� ���� ���� ����. ������� ����
// �������� �ڵ忡�� �ſ� �߿��ϱ� ������, �������� ���̱� ���ؼ��� �����Ȳ/�������Ȳ�� ���� ������ �ѷ��ϰ�, �̿� ���� ��õ� ��Ȯ�� ���� ����.
*/
