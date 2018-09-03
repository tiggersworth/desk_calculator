/***
 *  File: a5.hpp
 *  Author: tammy chang 
 */

#ifndef A5_HPP
#define A5_HPP
#include<stdexcept>
#include<stack>
#include "token.hpp"

template <typename Iter> double RPN(Iter first, Iter last) { //iter pointing at token


//valid RPN expression inside while
//always only two operands getting evaluated, 

std::stack<double> operands;
while(first!= last){
//read one token
  if(first->is_operand()){ // token is operand
    operands.push(first->as_operand());

  }
  else{
  //take the operator and use it on two elements
  //top then pop
    if(operands.size() < 2){
      throw std::runtime_error("error");
    }
    double x = operands.top();
    operands.pop();

    double y = operands.top();
    operands.pop();

    char c = first->as_operator();
    double answer;
    switch(c){

      case '+':
        answer = y + x;
       //evalute the x, y with the operators
        // push to stack
          break;
      case'-':
        answer = y - x;
          break;
      case'/':
        if ( x == 0 ){
          throw std::runtime_error("error");
        }
        answer = y / x;
          break;
      case'*':
        answer = y * x;
          break;
      default: throw std::runtime_error("should not reach here");
    }
    operands.push(answer);
  }
  first++;
  }

  if(operands.size() == 1){
    double z = operands.top();
    operands.pop();
    return z;
    }
  else{
    throw std::runtime_error("error");
  }




} // RPN

#endif // A5_HPP
