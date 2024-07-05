#include "NumberScrabble.h"
#include "The 100 Game.h"
#include "Subtract a square.h"
void menu() ;
int getValidInput(const std::string& prompt, int min, int max) ;
void Games(int & choice) ;
/////////////////////////////////////////////////////////////////////
int main (){
    std :: cout << "                              ^_^ Welcome To My Program ^_^" <<std :: endl;
    std :: cout << "                              -----------------------------" <<std :: endl;
    std :: cout << "The Program has 3 games in it : \n" ;
    menu() ;

    return 0;
}
//////////////////////////////////////////////////////////////////
int getValidInput(const std::string& prompt, int min, int max) {
    int input;
    while (true) {

        std::cout << prompt;
        std::cin >> input;

        // Check if the input failed or is out of the specified range
        if (std::cin.fail() || input < min || input > max) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "\nInvalid input. Please enter an integer between " << min << " and " << max << ".\n";
            continue;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard any extra input
            return input; // Return the valid input
        }
    }
}
void menu() {
    while (true) {
        std :: cout <<"1) Number Scrabble\n"
                      "2) The 100 Game\n"
                      "3) Subtract a Square\n" << std ::endl ;
        int choice = getValidInput("Choose What Game You Want To Play (1-3): ", 1, 3);
        std :: cout <<std ::endl   ;
        Games(choice);
        std :: string Exit_Prompt  = "Do You Want To Play another Game?\n"
         "1) Continue\n"
         "2) Exit\n"
         "Please Enter Your Choice: ";
        int Exit = getValidInput(Exit_Prompt, 1, 2);

        if (Exit == 2) {
            break;
        }
    }
}
void Games(int & choice) {
    switch (choice) {
        case 1 :
            std :: cout <<  NumberScrabble();
            break;
        case 2 :
            std :: cout << The_100_Game();
            break;
        case 3 :
            std :: cout <<  Subtract_A_Square();
            break;
    }
}