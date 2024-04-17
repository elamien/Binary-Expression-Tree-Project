#define _CRT_SECURE_NO_WARNINGS

#include "binaryExpressionTree.h"
#include <cstring>
#include <iostream>
#include <sstream>
#include <stack>

bool binaryExpressionTree::buildExpressionTree(const std::string& postfixExpression)
{
    // Create a stack to hold the nodes
    std::stack<nodeType<std::string>*> nodeStack;

    // Convert the postfix expression to a char array
    char* expression = new char[postfixExpression.length() + 1];
    strcpy(expression, postfixExpression.c_str());

    // Tokenize the expression
    char* token = strtok(expression, " ");
    while (token != nullptr)
    {
        if (std::isdigit(token[0]))
        {
            // If the token is a number, create a new node and push it onto the stack
            nodeType<std::string>* newNode = new nodeType<std::string>;
            newNode->info = token;
            newNode->lLink = nullptr;
            newNode->rLink = nullptr;
            nodeStack.push(newNode);
        }
        else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')
        {
            // If the token is an operator, create a new node and pop two nodes from the stack
            nodeType<std::string>* newNode = new nodeType<std::string>;
            newNode->info = token;
            newNode->rLink = nodeStack.top();
            nodeStack.pop();
            newNode->lLink = nodeStack.top();
            nodeStack.pop();
            nodeStack.push(newNode);
        }
        else
        {
            std::cout << "Invalid token: " << token << std::endl;
            return false;
        }

        token = strtok(nullptr, " ");
    }

    // The last node on the stack is the root of the expression tree
    root = nodeStack.top();
    nodeStack.pop();

    delete[] expression;

    return true;
}

double binaryExpressionTree::evaluateExpressionTree()
{
    return evaluateExpressionTree(root);
}

double binaryExpressionTree::evaluateExpressionTree(nodeType<std::string>* p)
{
    if (p->lLink == nullptr && p->rLink == nullptr)
    {
        // If p is a leaf node, return the value stored at p
        return std::stod(p->info);
    }
    else
    {
        // If p is an operator node, recursively evaluate the left and right subtrees
        double leftValue = evaluateExpressionTree(p->lLink);
        double rightValue = evaluateExpressionTree(p->rLink);

        // Apply the operator to the results and return the value
        char op = p->info[0];
        switch (op)
        {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            return leftValue / rightValue;
        default:
            // Handle invalid operator
            std::cout << "Invalid operator: " << op << std::endl;
            return 0.0;
        }
    }
}