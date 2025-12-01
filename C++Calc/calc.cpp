#include <iostream>

int main() {
    float num1;
    float num2;
    float proccess;
    char op;

    std::cout << "Please input the first number: ";
    std::cin >> num1;
    
    std::cout << std::endl << "Please input the second number: ";
    std::cin >> num2;
    
    std::cout << std::endl << "Please input the operator you will use: ";
    std::cin >> op;
    std::cout << std::endl;


    switch (op){
        case '+':
            proccess = num1 + num2;
            std::cout << proccess << std::endl;
            break;
        case '-':
            proccess = num1 - num2;
            std::cout << proccess << std::endl;
            break;
        case '*':
            proccess = num1 * num2;
            std::cout << proccess << std::endl;
            break;
        case '/':
            proccess = num1 / num2;
            std::cout << proccess << std::endl;
            break;
        case '%':
            proccess = num1 % num2;
            std::cout << proccess << std::endl;
            break;
        default:
            std::cout << "invalid operator" << std::endl;
            break;
       







    }

}
