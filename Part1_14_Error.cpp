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
        throw incorrectInputError();        // 에러가 발생하였으므로 에러 던짐. 이 함수를 호출한 함수로 exit함
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

        try {                               // 에러가 의심되는 부분
            cout << solution(ball, shar) << endl;
        }
        catch(incorrectInputError e) {      // 에러 잡았다 요놈
            cout << "IncorrectInputError occurred: " << ball << " " << shar << endl;        // 에러에 대한 처리
        }

    }

    // 에러에 대한 처리를 하고 다시 정상 실행
    return 0;
}


/*
// 에러가 발생해도 그에 대한 대처행동을 취한 뒤 다시 정상 실행하도록 하는 것이 Error Handling의 목표
// 에러 발생 시, 그에 대한 catch가 두 개 이상일 때 한 번 잡히면 그 다음 catch들은 그 에러를 잡지 않음
// catch(...) 은 모든 에러를 다 잡음. 원인을 모르기 때문에 그 상황에 맞는 적절한 조치 불가능. 최소한 프로그램이 죽는 것을 막기 위함. 권장되지 않음
// 가독성은 코드에서 매우 중요하기 때문에, 가독성을 높이기 위해서는 정상상황/비정상상황에 대한 구분이 뚜렷하고, 이에 대한 명시도 명확한 것이 좋다.
*/
