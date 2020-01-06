#include <string>
#include <iostream>
#include "..\ADTStack\stack.h"
using namespace std;

bool isIdentifier(char a);
bool isOperator(char b);
int solveSimpleArith(int operand1, char operat, int operand2);

// evaluateInfix(){

// }

// evaluatePostfix(){

// }

int evaluatePrefix_rec(string &exp){
	char firstChar;

	if (exp != ""){
		firstChar = exp.at(0);
		exp.erase(exp.begin());
	}


	// if it was identifier (a number ) just return it
	if(isIdentifier(firstChar)){
		// cout<<"reached identifier "<<firstChar<<endl;
		return (firstChar - 48);
	}
	
	else if(isOperator(firstChar)){

		// cout<<"reached exp "<<exp<<endl;
		int operand1 = evaluatePrefix_rec(exp);
		int operand2 = evaluatePrefix_rec(exp);
		return solveSimpleArith(operand1, firstChar, operand2);
	}
	return 0;
}

void infixToPostfix_stk(string &infix, string &postfix){
	Stack holdChars;

	while (infix != ""){
		// cout<<infix<<"\t"<<postfix<<endl;
		// if open paranthesis or operator, push to stack
		if(isOperator(infix.at(0)) | infix.at(0) == '('){
			holdChars.push(infix.at(0));
			infix.erase(infix.begin());
		} else if (isIdentifier(infix.at(0))){
			postfix.push_back(infix.at(0));
			infix.erase(infix.begin());
		}
		// if close paranthesis, pop from stack
		else if(infix.at(0) == ')'){
			infix.erase(infix.begin());
			int tmp = '\n';
			while(tmp != '('){
				holdChars.pop(tmp);
				if (tmp != '(')
					postfix.push_back((char)tmp);
			}
		}
	}

	while(!holdChars.isEmpty()){
		// cout<<infix<<"\t"<<postfix<<endl;
		int tmp = '\n';
		holdChars.pop(tmp);
		postfix.push_back((char)tmp);
	}
}

// infixToPrefix(){

// }

// postfixToinfix(){

// }

// postfixToPrefix(){

// }

// prefixToInfix(){

// }

void prefixToPostfix_rec(string &pre, string &post){
	char firstChar;
	if(pre != ""){
		firstChar = pre.at(0);
		pre.erase(pre.begin());
	}

	if(isIdentifier(firstChar))
		post = post + firstChar;
	else {
		prefixToPostfix_rec(pre, post);
		prefixToPostfix_rec(pre, post);
		post = post + firstChar;
	}
}

bool isIdentifier(char a){
	char identifiers[10] = {'0','1','2','3','4','5','6','7','8','9'};

	for(int i = 0; i < 10; i++){
		if(a == identifiers[i])
			return true;
	}

	return false;
}

bool isOperator(char b){
	char operators[4] = {'+','-','*','/'};

	for(int i = 0; i < 4; i++){
		if(b == operators[i])
			return true;
	}

	return false;
}

int solveSimpleArith(int operand1, char operat, int operand2){
	
	// cout<<"to solve : "<<operand1<<" "<< operat<< " "<< operand2<<endl;
	if (operat == '+')
		return operand1 + operand2;
	else if (operat == '-')
		return operand1 - operand2;
	else if (operat == '*')
		return operand1 * operand2;
	else if (operat == '/')
		return operand1 + operand2;

	return 0;
}

int main()
{
	string myPre = "++2*35*+*6426";
	string myInfix = "1-(2+3*4)/5";
	string myPost;
	cout<<evaluatePrefix_rec(myPre);
	// prefixToPostfix_rec(myPre, myPost);
	// infixToPostfix_stk(myInfix, myPost);
	cout<<"\n"<<myPost;
	return 0;
}