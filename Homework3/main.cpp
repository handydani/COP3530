
#include <iostream>
#include <string>
#include <list>
//code provided to me by Dr. Small
double evaluate (double num1, double num2, char operand);

template <typename ContainerT>
void tokenize(const std::string& str, ContainerT& tokens,
 const std::string& delimiters = " ", bool trimEmpty = false)
{
     std::string::size_type pos, lastPos = 0, length = str.length();
     using value_type = typename ContainerT::value_type;
     using size_type = typename ContainerT::size_type;
     while(lastPos < length + 1)
     {
         pos = str.find_first_of(delimiters, lastPos);

         if(pos == std::string::npos)
         {
             pos = length;
         }
         if(pos != lastPos || !trimEmpty)
            tokens.push_back(value_type(str.data()+lastPos, (size_type)pos-lastPos ));

        lastPos = pos + 1;
    }
}
int main() {
     std::list<std::string> tokens;
     char * pointer;
     pointer = tokens.begin();
     char value = NULL;
     std::list<int> operator_ctr;
     std::list<std::string> operand_ctr;
     double operator1 = 0;
     double operator2 = 0;
     char operand = '';
     double result = 0;
     bool open_parenthesis = false;

     while (pointer){

         value = * pointer;
         if (value == '('){
            open_parenthesis = true;
         }
         else if (value == ')'){
             open_parenthesis = false;
         }
         else if ((int)value = value){
             operator_ctr.push_back(value);
             if (operator_ctr.size() == 2){
                 operator1 = opertor_ctr.pop_back();
                 operator2 = opertor_ctr.pop_back();
                 operand = operand_ctr.pop_back();
                 result = evaluate(operator1, operator2, operand);
                 operator_ctr.push_back(result);
             }
         }
         else if (value == '+' || value == '-' || value == '*' || value == '/'){
             operand_ctr.push_back(value);
         }
         else{
             std::cout <<"error"<<std::endl;
         }
         ++pointer;
     }

    //  std::string test1_2 = "This is a test";
    //  std::string test3_4 = "This is\t\tanother \t test";
     //
    //  std::cout << "===== Test 1 =====" << std::endl;
    //  // defaults: space delimiters; null tokens
    //  tokenize( test1_2, tokens );
    //  int i = 0;
    //  for ( auto token : tokens )
    //     std::cout << i++ << ": = \"" << token << "\"" << std::endl;
    //  tokens.clear();
     //
    //  std::cout << "===== Test 2 =====" << std::endl;
    //  // space delimiters; no null tokens
    //  std::string delim2_3( " " );
    //  tokenize( test1_2, tokens, delim2_3, true );
    //  i = 0;
    //  for ( auto token : tokens )
    //     std::cout << i++ << ": = \"" << token << "\"" << std::endl;
    //  tokens.clear();
     //
    //  std::cout << "===== Test 3 =====" << std::endl;
    //  // space delimiters; no null tokens
    //  tokenize( test3_4, tokens, delim2_3, true );
    //  i = 0;
    //  for ( auto token : tokens )
    //     if ( token == "\t" )
    //     std::cout << i++ << ": = TAB" << std::endl;
    //     else
    //     std::cout << i++ << ": = \"" << token << "\"" << std::endl;
    //  tokens.clear();
     //
    //  std::cout << "===== Test 4 =====" << std::endl;
    //  // space and TAB delimiters; no null tokens
    //  std::string delim4( " \t" );
    //  tokenize( test3_4, tokens, delim4, true );
    //  i = 0;
    //  for ( auto token : tokens )
    //     if ( token == "\t" )
    //     std::cout << i++ << ": = TAB" << std::endl;
    //     else
    //     std::cout << i++ << ": = \"" << token << "\"" << std::endl;
    //  tokens.clear();
     return 0;
}
double evaluate (double num1, double num2, char operand){
    if (operand == '+'){
        return num1 + num2;
    }
    else if (operand == '-'){
        return num1 - num2;
    }
    else if (operand == '*'){
        return num1 * num2;
    }
    else if (operand == '/'){
        return num1 / num2;
    }
    else{
        return NULL;
    }

}
