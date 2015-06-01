//
// Created by nightwind on 15-5-8.
//

#include <iostream>
#include "Polynomial.h"
#include "Operators.h"

Polynomial Polynomial::calc(Operators::OperatorType ot, Polynomial p1, Polynomial p2)
{
    Polynomial p;
    while (!p1.nodes.empty() || !p2.nodes.empty())
    {
        if (p1.nodes.empty())
        {
            p.nodes.push(p2.nodes.front());
            p2.nodes.pop();
            continue;
        }
        else if (p2.nodes.empty())
        {
            p.nodes.push(p1.nodes.front());
            p1.nodes.pop();
            continue;
        }
        Node node;
        if (p1.nodes.front().exp > p2.nodes.front().exp)
        {
            node = p1.nodes.front();
            p1.nodes.pop();
        }
        else if (p1.nodes.front().exp == p2.nodes.front().exp)
        {
            node = p1.nodes.front();
            if (ot == Operators::add)
            {
                node.coef += p2.nodes.front().coef;
            }
            else
            {
                node.coef -= p2.nodes.front().coef;
            }
            p1.nodes.pop();
            p2.nodes.pop();
        }
        else
        {
            node = p2.nodes.front();
            p2.nodes.pop();
        }
        p.nodes.push(node);
    }
    cout << "size = " << p.nodes.size() << endl;
    return p;
}

Polynomial Polynomial::operator+(Polynomial& other)
{
    return calc(Operators::add, *this, other);
}

Polynomial Polynomial::operator-(Polynomial& other) {
    return calc(Operators::sub, *this, other);
}

void Polynomial::print() {
    bool first_term = true;
    //Polynomial print_polynomial(*this);
    queue<Node> print_nodes(this->nodes);

    while (!print_nodes.empty())
    {
        Node node = print_nodes.front();
        if (first_term)
        {
            first_term = false;
            if (node.coef < 0)
                cout << "-";
        }
        else if (node.coef < 0)
        {
            cout << "-";
        }
        else
        {
            cout << "+";
        }
        double r = node.coef >= 0 ? node.coef : -node.coef;
        if (r != -1) cout << r;

        if (node.exp > 1) cout << " X^" << node.exp;
        else if (node.exp == 1) cout << " X";
        else if (r == 1 && node.exp == 0) cout << " 1";
    }
    if (first_term)
        cout << "0";
    cout << endl;
}

Polynomial::Polynomial(Node nodes[], size_t length) {
    setNodes(nodes, length);
}

Polynomial::Polynomial(Polynomial const &polynomial) {
    nodes = queue<Node>(polynomial.nodes);
    name = polynomial.name;
}

void Polynomial::read() {
    clear();
    double coefficient;
    int last_exponent, exponent;
    bool first_term = true;
    cout << "enter the coefficients and exponents for the polynomiall" << endl;
    do {
        cout << "coefficient?" << flush;
        cin >> coefficient;
        if (coefficient != 0.0) {
            cout << "exponent? " << flush;
            cin >> exponent;
            if ((!first_term && exponent >= last_exponent) || exponent < 0)
            {
                exponent = 0;
                cout << "Bad exponent" << endl;
            } else {
                Node node(exponent, coefficient);
                nodes.push(node);
                first_term = false;
            }
        }
    } while (coefficient != 0.0 && exponent != 0);
}

void Polynomial::clear() {
    while (!this->nodes.empty())
    {
        this->nodes.pop();
    }
}

void Polynomial::equalsSum(Polynomial &p, Polynomial &q) {
    nodes = calc(Operators::add, p, q).nodes;
}

void Polynomial::setNodes(Node nodes[], size_t length) {
    for (int i = 0; i < length; i++)
    {
        this->nodes.push(nodes[i]);
    }
}

void Polynomial::equalsSub(Polynomial &p, Polynomial &q) {
    nodes = calc(Operators::sub, p, q).nodes;
}
