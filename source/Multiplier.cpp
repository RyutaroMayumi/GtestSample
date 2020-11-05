#include "Multiplier.h"
#include <cmath>


Multiplier::Multiplier()
: mAc(Accumulator())
{}

int Multiplier::mul(int n1, int n2)
{
    bool s = sign(n1) ^ sign(n2);
    unsigned short multiplicant = abs(n1);
    unsigned short multiplier = abs(n2);

    int sum = 0;
    for (int i = multiplier; i > 0; i--) {
        sum = mAc.add(sum, multiplicant);
    }

    return sum * pow(-1,s);
}

int Multiplier::div(int n1, int n2)
{
    bool s = sign(n1) ^ sign(n2);
    unsigned short divident = abs(n1);
    unsigned short divisor = abs(n2);

    int sum = divident;
    int i = 0;
    while (sum >= divisor) {
        i++;
        sum = mAc.sub(sum, divisor);
    }

    return i * pow(-1,s);
}

bool Multiplier::sign(int n)
{
    return (bool)(n >> 31);
}

unsigned short Multiplier::abs(int n)
{
    return (n ^ (n >> 31)) - (n >> 31);
}
