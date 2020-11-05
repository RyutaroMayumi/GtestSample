#ifndef MULTIPLIER_H_
#define MULTIPLIER_H_


#include "Accumulator.h"


class Multiplier {

public:
    friend class MultiplierTest;
    Multiplier();
    int mul(int n1, int n2);
    int div(int n1, int n2);

private:
    bool sign(int n);
    unsigned short abs(int n);
    Accumulator mAc;

};

#endif //MULTIPLIER_H_
