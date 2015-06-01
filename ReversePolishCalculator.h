//
// Created by Night Wind on 15/5/11.
//

#ifndef TASK2_1_REVERSEPOLISHCALCULATOR_H
#define TASK2_1_REVERSEPOLISHCALCULATOR_H

template <class T>
class ReversePolishCalculator {

public:
    enum ErrorCode {
        success,
        underflow,
        overflow,
        error,
    };

    virtual ErrorCode pushOperation(const T operation) = 0;
    virtual ErrorCode pushAdd() = 0;
    virtual ErrorCode pushSub() = 0;
    virtual ErrorCode calc(T& result) = 0;
};


#endif //TASK2_1_REVERSEPOLISHCALCULATOR_H
