#include <iostream>
#include <stack>
#include "Polynomial.h"

void readPolynomial(Polynomial *pPolynomial);

using namespace std;


void introduction()
/*
PRE: None.
POST: An introduction to the program Polynomial Calculator is printed.
*/
{
    cout << "Polynomial Calculator Program." << endl
    << "This program simulates a polynomial calculator that works on a\n"
    << "stack and a list of operations. It models a reverse Polish\n"
    << "calculator where operands are entered before the operators. An\n"
    << "example to add two polynomials and print the answer is ?P?Q+= .\n"
    << "P and Q are the operands to be entered, + is add, and = is\n"
    << "print result. The result is put onto the calculator's stack.\n\n";
}

void instructions()
/*
PRE: None.
POST: Prints out the instructions and the operations allowed on the
calculator.
*/
{
    cout << "\nEnter a string of instructions in reverse Polish form.\n"
    << "The allowable instructions are:\n\n"
    << "?:Read 	+:Add 	=:Print 	-:Subtract\n"
    << "*:Multiply 	q:Quit 	/:Divide 	h:Help\n\n";
}

char get_command()
/*
PRE: None.
POST: A legal command is read from the user and returned.
*/
{
    char command, d;
    cout << "Select command and press <Enter>:";
    while (1) {
        do {
            cin.get(command);
        } while (command == '\n');
        do {
            cin.get(d);
        } while (d != '\n');
        command = tolower(command);
        if  (command == '?' || command == '=' || command == '+' ||
             command == '-' || command == 'h' || command == '*' ||
             command == '/' || command == 'q' || command == 'p' ||
             command == 'h') {
            return (command);
        }
        cout << "Please enter a valid command:" << endl;
        instructions();
    }
}

void readInput(stack<Operation*>& operations) {
    Polynomial* p;
    char c;
    while ((c = get_command()) != 'q')
    {
        if (c == '?')
        {
            readPolynomial(p);
        }
        else if (c == '+' || c == '-')
        {
            Operators::OperatorType type;
            switch (c)
            {
                case '+':
                    type = Operators::add;
                    break;
                case '-':
                    type = Operators::sub;
                    break;
                default:break;
            }
            Operators* op = new Operators(type);
            operations.push(op);
        }
        else
        {
            p->setName(c);
            operations.push(p);
        }
    }
}

void readPolynomial(Polynomial *pPolynomial) {

}

int main() {
    Node nodes[] = {{1,1}, {2,2}, {3,3}};
    Polynomial polynomial = Polynomial(nodes, 3);
//    polynomial = polynomial + polynomial;
    polynomial = polynomial.calc(Operators::add, polynomial, polynomial);
    polynomial.print();
    return 0;
}