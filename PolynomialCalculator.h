//
// Created by Night Wind on 15/5/11.
//

#ifndef TASK2_1_POLYNOMIALCALCULATOR_H
#define TASK2_1_POLYNOMIALCALCULATOR_H

#include "ReversePolishCalculator.h"
#include "Operation.h"
#include "Polynomial.h"
#include <stack>
using namespace std;

class PolynomialCalculator: public ReversePolishCalculator<Polynomial> {

public:
    virtual ErrorCode pushOperation(const Polynomial operation);

    virtual ErrorCode pushAdd();

    virtual ErrorCode pushSub();

    virtual ErrorCode calc(Polynomial& result);

private:
    stack<Operation> operations;
};


#endif //TASK2_1_POLYNOMIALCALCULATOR_H
