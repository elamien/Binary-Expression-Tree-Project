#pragma once
#ifndef BINARYEXPRESSIONTREE_H
#define BINARYEXPRESSIONTREE_H

#include "binaryTree.h"
#include <string>
#include <stack>

class binaryExpressionTree : public binaryTreeType<std::string>
{
public:
    bool buildExpressionTree(const std::string& postfixExpression);
    double evaluateExpressionTree();

private:
    // Implement the pure virtual functions from the base class
    bool search(const std::string& searchItem) const override {
        // Dummy implementation
        return false;
    }

    void insert(const std::string& insertItem) override {
        // Dummy implementation
    }

    void deleteNode(const std::string& deleteItem) override {
        // Dummy implementation
    }

    double evaluateExpressionTree(nodeType<std::string>* p);
};

#endif