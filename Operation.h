//
// Created by nightwind on 15-5-9.
//

#ifndef TASK2_1_OPERATION_H
#define TASK2_1_OPERATION_H


class Operation {
public:
    enum Type {
        operand,
        operators,
    };
    virtual Type getType() = 0;
};


#endif //TASK2_1_OPERATION_H
