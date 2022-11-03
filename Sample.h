#pragma once

class Negative {};

class Sample {
    private:
        int m;
        int n;
        void setM(int x, int y);

    public:
        Sample();
        Sample(int i);
        Sample(const Sample& a);
        ~Sample();
        void setM(int x);
        int getM() const;
        Sample operator+(const Sample& a);
        friend Sample operator-(const Sample& a, const Sample& b);            
        /*
            외부에 있는 함수라는 뜻으로 멤버함수가 아니기 때문에 this라는 개념이 없음
            따라서 파라미터도 두 개를 요구
            피연산자의 값이 바뀌는 것을 허용하지 않겠다 따라서 const 선언
        */ 
                                        
};



