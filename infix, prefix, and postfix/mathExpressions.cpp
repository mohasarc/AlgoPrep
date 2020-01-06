#include <string>
#include <iostream>
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
		cout<<"reached identifier "<<firstChar<<endl;
		return (firstChar - 48);
	}
	
	else if(isOperator(firstChar)){

		cout<<"reached exp "<<exp<<endl;
		int operand1 = evaluatePrefix_rec(exp);
		int operand2 = evaluatePrefix_rec(exp);
		return solveSimpleArith(operand1, firstChar, operand2);
	}
	return 0;
}

// infixToPostfix(){

// }

// infixToPrefix(){

// }

// postfixToinfix(){

// }

// postfixToPrefix(){

// }

// prefixToInfix(){

// }

// prefixToPostfix(){

// }

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
	
	cout<<"to solve : "<<operand1<<" "<< operat<< " "<< operand2<<endl;

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
	string myExp = "++2*35*+*6426";
	cout<<evaluatePrefix_rec(myExp);
	return 0;
}