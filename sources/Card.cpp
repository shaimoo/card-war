#include "card.hpp"
#include <stdexcept>
using namespace std;
using namespace ariel;
Card::Card(int num,string sign_){
	number = num;
	sign = sign_;
    }
    
string Card::get_sign(){
    return sign;
}

int Card::get_number(){
return number;
}
