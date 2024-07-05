#include "Subtract a square.h"
bool isPerfectSquare(int n) {
    int root = (int)(std::sqrt(n));
    return n == root * root;

}
void Number_Is_Valid(int turn, int &num) {
    while (true) {
        if (Get_Input(turn, num)) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "\nInvalid input. Please enter a positive integer.\n";
            continue;
        }
        else if (turn > 0) {
            if (!isPerfectSquare(num)) {
                std::cout << "Invalid, Please Enter a Perfect Square Number below The Initial Number!" << std::endl;
                continue;
            } else {return;}
        } else {return;}
    }
}

bool Get_Input (int turn , int & num) {
    if(turn > 0 ) {
        std::cout << "\n[ Player " << turn << " ] Enter Your Number (Positive Integer): ";
        std :: cin >> num ;
        std :: cout << std  :: endl ;
        std :: cout << "===========================================================================================" << std :: endl;
        return std :: cin.fail() || num <= 0  ;
    }
    else {
        std::cout << "\nPlease Enter the Initial Number (Positive Integer ): ";
        std :: cin >> num ;
        std :: cout << std  :: endl ;
        std :: cout << "===========================================================================================" << std :: endl;

        return std :: cin.fail() || num <=0  ;
    }

}


void Print_Details () {
    std :: cout << "                      ^_^ Welcome To Subtract a square Game ^_^" <<std :: endl;
    std :: cout << "                      -----------------------------------------" <<std :: endl;
    std :: cout << "\nGame Idea : This is a two-player mathematical game of strategy. It is played by two\n"
                   "people with a pile of coins (or other tokens) between them. The players take turns\n "
                   "removing coins from the pile, always removing a non-zero square number of coins\n"
                   "(1, 4, 9, 16,...). The player who removes the last coin wins"<<std :: endl;
    std :: cout << "===========================================================================================" << std :: endl;
}


std::string Subtract_A_Square() {
    Print_Details();
    int total = 0 ,turn = 0 , Input = 0  ;
    Number_Is_Valid(turn , total ) ;
    std::cout << "The Initial Value is ---- > " << total << std::endl;

    turn = 1; // Start with Player 1
    while (true) {
        Number_Is_Valid(turn, Input);
        if(Input > total )
        {
            std :: cout << "Invalid Move! Entered number is greater than current total." << std :: endl;
            Number_Is_Valid(turn, Input);
        }
        total -= Input;

        if (total == 0) {
            return "*************************************************************\n"
                   "Congratulations! Player " + std::to_string(turn) + " Wins\n"
                                                                       "*************************************************************\n\n";
        }
        std::cout << "[ Player " << turn << " ] subtracted " << Input << " from the total.\n";

        std::cout << "The Remaining Value is ----> " << total << std :: endl ;
        std :: cout << "===========================================================================================" << std :: endl;
        
        // Switch turn
        turn = (turn == 1) ? 2 : 1;
    }
}

