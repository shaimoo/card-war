#include "card.hpp"
using namespace std;
using namespace ariel;

    /// constructor
    Card::Card(int num,string sign_):number(num),sign(sign_)
        {}
    /// return the sign
    string Card::get_sign()
        {
            return sign;
        }
    /// return the number.
    int Card::get_number()
        {
        return number;
        }
    /// return the string of the card.
    string Card::to_String()
    {
        return "the card is :" +std::to_string(number) + " , " + sign;
    }
