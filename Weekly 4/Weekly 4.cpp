#include <iostream>
#include <vector>
#include <conio.h>

char capitalize(char letter);
int task1();
int task2();

int main()
{
    bool keepPlaying = true;
    int choice = 0;
    do {
        printf("\033c");
        std::cout << "Which task would you like to check?" << std::endl;
        std::cout << " 1. Capitalize letters." << std::endl;
        std::cout << " 2. Movement on a board." << std::endl;
        std::cout << " 3. Phonebook." << std::endl;
        std::cout << " 4. Dice task" << std::endl;
        std::cout << "\n 5. Exit program.";
        std::cin >> choice;
        while (std::cin.fail()||choice>4||choice<1) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Invalid input, input a valid option: ";
            std::cin >> choice;
        }
        switch (choice) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 5:
            keepPlaying = false;
            break;
        }
    } while (keepPlaying == true);
}

int task1() {
    char letter = 'x';
    bool keepPlaying = true;
    do {
        printf("\033c");
        std::cout << " Input a lower case letter: ";
        std::cin >> letter;        
        std::cout << " Capitalized, it is " << capitalize(letter)<<std::endl;
        std::cout << "Do you want to return to the main menu? (y for yes, n for no)" << std::endl;
        std::cin >> letter;
        switch (letter) {
        case'y':case'Y':
            keepPlaying = false;
            break;
        case'n':case'N':
            keepPlaying = true;
            break;
        default:
            std::cout << "Invalid input . . . Returning to main menu . . .";
        }
    } while (keepPlaying == true);
    return 0;
}

int task2() {
    bool smileyTravel = true;
    char pressedKey = 'g';
    std::vector<std::vector<char>> board{
    {'|','-','-','-','-','-','-','-','-','|',},
    {'|',' ',' ',' ',' ',' ',' ',' ',' ','|',} ,
    {'|',' ',' ',' ',' ',' ',' ',' ',' ','|',} ,
    {'|',' ',' ',' ',' ',' ',' ',' ',' ','|',} ,
    {'|',' ',' ',' ',2,' ',' ',' ',' ','|',} ,
    {'|',' ',' ',' ',' ',' ',' ',' ',' ','|',} ,
    {'|',' ',' ',' ',' ',' ',' ',' ',' ','|',} ,
    {'|',' ',' ',' ',' ',' ',' ',' ',' ','|',} ,
    {'|',' ',' ',' ',' ',' ',' ',' ',' ','|',} ,
    {'|','-','-','-','-','-','-','-','-','|',} ,
    };
    
    do {
        printf("\033c");
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
        char pressedKey=_getch();
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i].at(j) == 2) {
                    if (pressedKey == 'd'&&board[i].at(j+1)==' ') {
                        board[i].at(j)=' ';
                        board[i].at(j + 1) = 2;
                        break;
                    }
                    if (pressedKey == 'a' && board[i].at(j - 1) == ' ') {
                        board[i].at(j) = ' ';
                        board[i].at(j - 1) = 2;
                        break;
                    }                             
                    if (pressedKey == 'w' && board[i].at(i-1) == ' ') {
                        board[i].at(j) = ' ';
                        
                    }
                }
            }
        }

    } while (smileyTravel == true);
    return 0;
}
char capitalize(char letter) {
    return toupper(letter);
}