//
// Created by nightwind on 15-5-8.
//

#ifndef TASK2_1_POLYNOMIAL_H
#define TASK2_1_POLYNOMIAL_H

#include <queue>
#include "Operation.h"
#include "Operators.h"

using namespace std;

struct Node {
    int exp;
    float coef;
};

class Polynomial: private queue<Node>, public Operation {
public:
    Polynomial(Node nodes[], size_t length);

    Polynomial operator+(Polynomial& other);
    Polynomial operator-(Polynomial& other);
    void print();
    //enum OperatorType {
    //    add,
    //    sub,
    //};
    Polynomial calc(Operators::OperatorType ot,Polynomial p1, Polynomial p2);

    virtual Type getType()
    {
        return operand;
    }
private:
    Polynomial() { }

public:
    char getName() const {
        return name;
    }

    void setName(char name) {
        Polynomial::name = name;
    }

private:
    char name;
};


#endif //TASK2_1_POLYNOMIAL_H
