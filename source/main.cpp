#include "Accumulator.h"
#include "Multiplier.h"
#include <iostream>


int main(int argc, char** argv)
{
    Accumulator ac;
    int n1 = 8;
    int n2 = 5;
    std::cout << n1 << " + " << n2 << " = " << ac.add(n1, n2) << std::endl;
    std::cout << n1 << " - " << n2 << " = " << ac.sub(n1, n2) << std::endl;

    Multiplier ml;
    std::cout << n1 << " x " << n2 << " = " << ml.mul(n1, n2) << std::endl;
    std::cout << n1 << " / " << n2 << " = " << ml.div(n1, n2) << std::endl;

    return 0;
}
