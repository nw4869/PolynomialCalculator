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
    Node(int exp, double coef): exp(exp), coef(coef){}
    Node(){}
    int exp;
    double coef;
};

class Polynomial: public Operation {
public:
    Polynomial() { }
    Polynomial(Node nodes[], size_t length);

    Polynomial(Polynomial const & polynomial);

    Polynomial operator+(Polynomial& other);
    Polynomial operator-(Polynomial& other);
    void clear();
    void read();
    void print();
    //enum OperatorType {
    //    add,
    //    sub,
    //};
    Polynomial calc(Operators::OperatorType ot,Polynomial p1, Polynomial p2);

    void equalsSum(Polynomial &p, Polynomial &q);

    virtual Type getType() const
    {
        return operand;
    }

    void setNodes(Node nodes[], size_t length);

    void equalsSub(Polynomial &p, Polynomial &q);

public:
    char getName() const {
        return name;
    }

    void setName(char name) {
        Polynomial::name = name;
    }

private:
    char name;

    queue<Node> nodes;

};


#endif //TASK2_1_POLYNOMIAL_H
