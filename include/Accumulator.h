#ifndef ACCUMULATOR_H_
#define ACCUMULATOR_H_

class Accumulator {

public:
    friend class AccumulatorTest;
    Accumulator();
    int add(int n1, int n2);
    int sub(int n1, int n2);

private:
    int accum(int n);
    int reset();

    int mVal;

};

#endif //ACCUMULATOR_H_
