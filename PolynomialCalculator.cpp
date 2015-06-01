//
// Created by Night Wind on 15/5/11.
//

#include "PolynomialCalculator.h"
#include "Operators.h"
#include "Polynomial.h"

ReversePolishCalculator<Operation>::ErrorCode PolynomialCalculator::pushOperation(const Polynomial operation) {
    operations.push(operation);
    return success;
}

ReversePolishCalculator<Operation>::ErrorCode PolynomialCalculator::pushAdd() {
    const Operators add = Operators(Operators::add);
    operations.push(add);
    return success;
}

ReversePolishCalculator<Operation>::ErrorCode PolynomialCalculator::pushSub() {
    const Operators sub = Operators(Operators::sub);
    operations.push(sub);
    return success;
}

ReversePolishCalculator<Operation>::ErrorCode PolynomialCalculator::calc(Polynomial& result) {
    while (!operations.empty()) {
        const Operation& operation = operations.top();
        if (operation.getType() == Operation::operators)  {
            Operators* op = (Operators *) &operation;
            if (op->getOperatorType() == Operators::add || op->getOperatorType() == Operators::sub) {
                if (operations.empty()) {
                    return underflow;
                }
                Polynomial &p = (Polynomial &) operations.top();
                operations.pop();

                if (operations.empty()) {
                    return underflow;
                }
                Polynomial &q = (Polynomial &) operations.top();
                operations.pop();

                Polynomial r;
                if (op->getOperatorType() == Operators::add) {
                    r.equalsSum(p, q);
                } else if (op->getOperatorType() == Operators::sub) {
                    r.equalsSub(p, q);
                }
                operations.push(r);

            } else if (op->getOperatorType() == Operators::equal) {
                // print top
                if (operations.empty()) {
                    return underflow;
                }
                result = (Polynomial&) operations.top();
            }
        }
    }
}
