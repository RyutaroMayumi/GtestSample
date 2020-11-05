#include "Accumulator.h"


Accumulator::Accumulator()
: mVal(0)
{}

int Accumulator::add(int n1, int n2)
{
    reset();
    accum(n1);
    accum(n2);
    return mVal;
}

int Accumulator::sub(int n1, int n2)
{
    reset();
    accum(n1);
    accum(-n2);
    return mVal;
}

int Accumulator::accum(int n)
{
    mVal += n;
    return mVal;
}

int Accumulator::reset()
{
    mVal = 0;
    return mVal;
}
