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
            �ܺο� �ִ� �Լ���� ������ ����Լ��� �ƴϱ� ������ this��� ������ ����
            ���� �Ķ���͵� �� ���� �䱸
            �ǿ������� ���� �ٲ�� ���� ������� �ʰڴ� ���� const ����
        */ 
                                        
};



