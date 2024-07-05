#include "The 100 Game.h"

void  The_100_valid (int turn ,int &num ){
    while (true ){
        std :: vector <int> numbers = {1,2,3,4,5,6,7,8,9,10} ;
        std::cout << "Player "<<turn<<", Enter Your Number From ( 1 --> 10 )  :  ";
        std::cin >> num;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.fail()) {
            std::cin.clear(); // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std :: cout << std :: endl;
            std::cout << "Invalid input. Please enter an integer." << std::endl;
            continue;
        }
        auto it = std ::find(numbers.begin(),numbers.end(),num) ;
        if(it == numbers.end()) {
            std :: cout << std :: endl;
            std :: cout << "Invalid Choice , Please Enter a Number from 1 --> 10 ! "<<std::endl ;

        }

        else
        {   std :: cout << std :: endl;
            std :: cout << "=======================================================================" << std :: endl;

            return ;}  ;// valid Choice
    }
}

std :: string The_100_Game ()
{
    int sum = 0 , turn ,P1_Input, P2_Input ;
    std :: cout << "                      ^_^ Welcome To The 100 Game ^_^" <<std :: endl;
    std :: cout << "                      -------------------------------" <<std :: endl;
    std :: cout << "\nGame Idea : Two players start from 0 and alternatively add a number from 1 to 10 to the sum.\n"
                   "The player who reaches 100 wins." <<std :: endl;
    std :: cout << "=======================================================================" << std :: endl;

    while (true) {
        turn= 1 ;
        The_100_valid(turn,P1_Input) ;
        sum += P1_Input ;
        if(sum>=100) return "Player 1 Wins !!" ;
        std :: cout << "The sum Now is  : " << sum << std :: endl ;
        turn = 2 ;
        The_100_valid(turn,P2_Input) ;
        sum+=P2_Input ;
        if(sum>=100) return "Player 2 Wins !! " ;
        std :: cout << "The sum Now is  : " << sum << std :: endl ;

    }
}
