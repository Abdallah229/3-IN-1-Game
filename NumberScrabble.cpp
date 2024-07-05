#include "NumberScrabble.h"


std :: string NumberScrabble () {
    std :: vector <int> numbers = {1,2,3,4,5,6,7,8,9} ;
    int inputP1 = 0 ;
    int inputP2 = 0 ;
    std :: cout << "                      ^_^ Welcome To Number Scrabble Game ^_^" <<std :: endl;
    std :: cout << "                      -------------------------------------" <<std :: endl;
    std :: cout << "\nGame Idea : Number scrabble is played with the list of numbers between 1 and 9. Each player takes\n"
                   "turns picking a number from the list. Once a number has been picked, it cannot be picked\n"
                   "again. If a player has picked three numbers that add up to 15, that player wins the game.\n"
                   "However, if all the numbers are used and no player gets exactly 15, the game is a draw.\n"<<std :: endl;
    std :: cout << "=======================================================================" << std :: endl;

    std :: cout << "The Initial List is : {  " ;
    Print_list(numbers);
    std :: cout << "  }" ;
    std :: cout << "\n=======================================================================" << std :: endl;
    std :: vector <int> P1nums ;
    std :: vector <int > P2nums ;
    int turn = 0 ;
    while (true){
        turn = 1  ;
        Is_Valid(turn,inputP1,numbers) ;
        P1nums.push_back(inputP1);
        auto P1it = std::find(numbers.begin(), numbers.end(), inputP1);
        if (P1nums.size() == 3 && std::accumulate(P1nums.begin(), P1nums.end(), 0) == 15)return "Player 1 Wins !!";
        numbers.erase(P1it);
        std::cout << "Player 1 Numbers is :  { ";
        Print_list(P1nums);
        std::cout << " }";
        std :: cout << "\n========================================================================" << std :: endl;
        if (hasWinningCombination(P1nums)) return "Player 1 Wins!!";

        // Check for draw
        if (numbers.empty()) return "Draw!";
        std::cout << "Remaining Numbers :  { ";
        Print_list(numbers);
        std::cout << " }";
        std :: cout << "\n========================================================================" << std :: endl;
        ///////////////////////////////////////////P2
        turn = 2  ;
        Is_Valid(turn,inputP2,numbers) ;
        P2nums.push_back(inputP2);
        auto P2it = std :: find(numbers.begin(),numbers.end(),inputP2) ;
        numbers.erase(P2it) ;
        std :: cout << "Player 2 Numbers is :  { ";
        Print_list(P2nums) ;
        std :: cout << "  }" ;
        std :: cout << "\n========================================================================" << std :: endl;
        if (hasWinningCombination(P1nums)) return "Player 2 Wins!!";
        // Check for draw
        if (numbers.empty()) return "Draw!";

        std :: cout << "Remaining Numbers :  {  " ;
        Print_list(numbers) ;
        std :: cout << "  }" ;
        std :: cout << "\n========================================================================" << std :: endl;



    }}





void Print_list(const std::vector<int>& numbers) {
    for(int val : numbers ){
        if(val != *(numbers.end()-1))  std :: cout << val << " , " ;
        else  std :: cout << val  ;
    }

}
void  Is_Valid (int turn ,int &num , std :: vector <int> & numbers ){
    while (true ){
        std::cout << "Player "<<turn<<",Enter Your Number  :  ";
        std::cin >> num;
        if (std::cin.fail()) {
            std::cin.clear(); // clear the error flag
            std::cin.ignore(1 , '\n'); // discard invalid input
            std::cout << "\nInvalid input. Please enter an integer." << std::endl;
            continue;
        }

        auto it = std ::find(numbers.begin(),numbers.end(),num) ;
        if(it == numbers.end()) {
            std :: cout << "\nInvalid Choice , Please Enter a Number from the list ! " ;

        }
        else return  ;// valid Choice
    }
}

bool hasWinningCombination( std::vector<int>& nums) {
    if (nums.size() < 3) return false;
    for (size_t i = 0; i < nums.size() - 2; ++i) {
        for (size_t j = i + 1; j < nums.size() - 1; ++j) {
            for (size_t k = j + 1; k < nums.size(); ++k) {
                if (nums[i] + nums[j] + nums[k] == 15) {
                    return true;
                }
            }
        }
    }
    return false;
}


