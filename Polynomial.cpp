//
// Created by nightwind on 15-5-8.
//

#include <iostream>
#include "Polynomial.h"
#include "Operators.h"

Polynomial Polynomial::calc(Operators::OperatorType ot, Polynomial p1, Polynomial p2)
{
    Polynomial p = Polynomial();
    while (!p1.empty() || !p2.empty())
    {
        if (p1.empty())
        {
            p.push(p2.front());
            p2.pop();
            continue;
        }
        else if (p2.empty())
        {
            p.push(p1.front());
            p1.pop();
            continue;
        }
        Node node;
        if (p1.front().exp > p2.front().exp)
        {
            node = p1.front();
            p1.pop();
        }
        else if (p1.front().exp == p2.front().exp)
        {
            node = p1.front();
            if (ot == Operators::add)
            {
                node.coef += p2.front().coef;
            }
            else
            {
                node.coef -= p2.front().coef;
            }
            p1.pop();
            p2.pop();
        }
        else
        {
            node = p2.front();
            p2.pop();
        }
        p.push(node);
    }
    cout << "size = " << p.size() << endl;
    return p;
}

Polynomial Polynomial::operator+(Polynomial& other)
{
    calc(Operators::add, *this, other);
}

Polynomial Polynomial::operator-(Polynomial& other) {
    calc(Operators::sub, *this, other);
}

void Polynomial::print() {
    while (!empty())
    {
        Node node = front();
        pop();
        cout << node.coef << "^" << node.exp << " ";
    }
    cout << endl;
}

Polynomial::Polynomial(Node nodes[], size_t length) {
    for (int i = 0; i < length; i++)
    {
        push(nodes[i]);
    }
}
