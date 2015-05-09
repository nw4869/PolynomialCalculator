//
// Created by nightwind on 15-5-9.
//

#ifndef TASK2_1_OPERATORS_H
#define TASK2_1_OPERATORS_H


#include "Operation.h"

class Operators: public Operation {
public:
    enum OperatorType {
        add,
        sub,
    };
    Operators(OperatorType operatorType) { this->operatorType = operatorType; }

    OperatorType getOperatorType() { return operatorType; }

private:
    virtual Type getType() { return operators; }
    OperatorType operatorType;
};


#endif //TASK2_1_OPERATORS_H
