#include "binaryExpressionTree.h"
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream inputFile("Binary Expression Tree Data.txt");
    std::ofstream outputFile("results.txt");

    if (!inputFile)
    {
        std::cout << "Failed to open the input file." << std::endl;
        return 1;
    }

    if (!outputFile)
    {
        std::cout << "Failed to open the output file." << std::endl;
        return 1;
    }

    std::string postfixExpression;
    binaryExpressionTree expressionTree;

    while (std::getline(inputFile, postfixExpression))
    {
        expressionTree.destroyTree();

        if (expressionTree.buildExpressionTree(postfixExpression))
        {
            double result = expressionTree.evaluateExpressionTree();
            outputFile << postfixExpression << " = " << result << std::endl;
        }
        else
        {
            outputFile << "Invalid postfix expression: " << postfixExpression << std::endl;
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}