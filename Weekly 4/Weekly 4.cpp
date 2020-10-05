#include <iostream>
#include <vector>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <algorithm>

char capitalize(char letter);
int task1();
int task2();
int task3();
int task4();

int RNG(int min, int max);
int charConverter(char input);
int sixFinder(int roll1,int roll2, int roll3, int roll4, int roll5);
int pairFinder(int roll1, int roll2, int roll3, int roll4, int roll5);

int main()
{
    srand(time(nullptr));
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
        while (std::cin.fail()||choice>5||choice<1) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Invalid input, input a valid option: ";
            std::cin.clear(10000);
            std::cin >> choice;
        }
        switch (choice) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 4:
            task4();
            break;
        case 5:
            keepPlaying = false;
            break;
        }
    } while (keepPlaying == true);
}

int task1() {
    std::string input = "";
    char letter = 'x';
    bool keepPlaying = true;

    // I clear the screen and ask for input

     printf("\033c");
     std::cout << " Input something: ";
     std::cin.ignore(10000, '\n');
     std::getline(std::cin, input);

     // after getting input, I build the string back up, using my capitalize function in a for loop

     std::cout << " Capitalized, it is: " << std::endl;
        for (int i = 0; i < input.size(); i++) {
            input.at(i) = capitalize(input.at(i));
            std::cout << input.at(i);
        }
        std::cout << "\npress any key to return to the main menu.";
        std::cin.ignore(10000, '\n');
            _getch;
    
    return 0;
}

char capitalize(char letter) {
    //simply capitalizes letters it recieves.
    return toupper(letter);
}

int task2() {
    struct Target {
        int x;
        int y;
    }player, lvlUp, lvlDown, end;

    bool smileyTravel = true;
    char pressedKey = 'g';
    char playerChar = 'A';
    const int x = 10;
    const int y = 10;
    player.x = 0;
    player.y = 0;
    lvlUp.x = RNG(0, x-1);
    lvlUp.y = RNG(0, y-1);
    lvlDown.x = RNG(0, x-1);
    lvlDown.y = RNG(0, y-1);

    std::vector<std::vector<char>> board(x,std::vector<char>(y, ' '));
    
    do {
        
        //first part of this loop checks the position of each target on the board (player, level up, level down)
        //The reason for this is so that the next time the board is built, it knows if the player has leveled up or down, and if it needs to change the position of the levels.
        //if the player has touched either levelUp or levelDown, they generate a new position using my RNG function.
        printf("\033c");
        if (lvlUp.x == player.x && lvlUp.y==player.y) {
            lvlUp.x = RNG(0, x - 1);
            lvlUp.y = RNG(0, y - 1);
            if (playerChar == 'A') {
                playerChar = 'Z';
            }
            else {
                playerChar = playerChar - 1;
            }
        }
        if (lvlDown.x == player.x && lvlDown.y == player.y) {
            lvlDown.x = RNG(0, x - 1);
            lvlDown.y = RNG(0, y - 1);
            if (playerChar == 'Z') {
                playerChar = 'A';
            }
            else {
                playerChar = playerChar + 1;
            }
        }

        //now that I know what I need from the targets, I declare the values in my board vector
        board[lvlUp.x].at(lvlUp.y) = '\\';
        board[lvlDown.x].at(lvlDown.y) = '/';
        board[player.x].at(player.y) = playerChar;

        //then I build the board
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
               std::cout << board[i][j];
            }
            std::cout << std::endl;
        }
        std::cout << "Change into G!\nMove using WASD\n";
        //as the task specified, if the player reaches 'G', the game ends
        if (playerChar == 'G') {
            break;
        }

        //now, the player pushes the direction they want to move (using WASD)
        char pressedKey=_getch();

        if (pressedKey == 'w' && player.x != (x/x)-1) {
            board[player.x].at(player.y) = ' ';
            player.x = player.x - 1;
        }
        if (pressedKey == 'd' && player.y != y-1) {
            board[player.x].at(player.y) = ' ';
            player.y = player.y + 1;
        }
        if (pressedKey == 'a' && player.y != (y / y) - 1) {
            board[player.x].at(player.y) = ' ';
            player.y = player.y - 1;
        }
        if (pressedKey == 's' && player.x != x - 1) {
            board[player.x].at(player.y) = ' ';
            player.x = player.x + 1;
        }

    } while (smileyTravel == true);

    //I build the board again, as to not confuse the player when they reach G, then return them to the main menu.
    printf("\033c");
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
    
    std::cout << "You have reached G level of awesomeness, my G." << std::endl;
    std::cout << "Press any key to return to the main menu.";
    std::cin.ignore(10000, '\n');
    _getch;
    return 0;
}

int RNG(int min, int max) {
    //this function simply generates a random number based on the max value given.
    return rand() % max + 1;
}

int task3() {
    struct Contact {
        std::string name;
        long number;
        std::string fullContact(std::string name, long number) {
            std::string numberConvert = std::to_string(number);
            return name + " - " + numberConvert;
        }
    };
    int tracker = 0;
    bool keepPlaying = true;
    std::vector<Contact>contactList;
    int choice = 0;

    do {
        printf("\033c");               //I like clearing the console for menues, as it looks more clean.
        std::cout << "\t[Phonebook]" << std::endl;
        std::cout << "\n1. Contact list" << std::endl;
        std::cout << "2. Add new contact" << std::endl;
        std::cout << "3. Return to main menu" << std::endl;
        std::cout << "\n Make a selection: ";

        std::cin >> choice;
        while (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Invalid input, please enter a valid choice: ";
            std::cin >> choice;
        }
        switch (choice) {
        case 1:
            // Here, I check if the phonebook has any contacts saved, and print it if it does
            printf("\033c");
            if (contactList.size()<1) {
                std::cout << "No saved contacts"<<std::endl;
            }
            else {
                for (int i = 0; i < contactList.size(); i++) {
                    std::cout << i+1 <<". "<<contactList.at(i).name << " - " << contactList.at(i).number << std::endl;
                }
            }
            std::cout << "Do you want to return to the phonebook or the main menu? (1 for phonebook, 2 for main menu)" << std::endl;
            std::cin >> choice;
            
            switch (choice) {
            case 1:
                break;
            case 2:
                return 3;
            }
            
            
            break;
        case 2:
            //      First I check if the phonebook already has 10 contacts saved, which is the max.

            printf("\033c");
            if (contactList.size() == 10) {
                std::cout << "The phonebook is full." << std::endl;
            }
            else {
                //     User hasn't filled the phonebook up yet, so they may enter a new contact with name and number

                contactList.push_back(Contact());
                std::cout << "Please enter a phone number: ";
                std::cin >> contactList[tracker].number;
                while (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(32767, '\n');
                    std::cout << "Invalid input, please enter a number: ";
                    std::cin >> contactList[tracker].number;
                }
                std::cout << "Please enter the contact name: ";
                std::cin.ignore(10000, '\n');
                std::getline(std::cin, contactList[tracker].name);
                contactList[tracker].fullContact(contactList[tracker].name, contactList[tracker].number);
                std::cout << "Contact saved for " << contactList[tracker].name << std::endl;
            }
            std::cout << "Press any key to return to the phonebook. . .";
            tracker++;
            std::cin.ignore(10000, '\n');
            _getch;
            break;

        case 3:
            return 3;

        default:
                std::cout << "Fail";
            _getch;
        }
    } while (keepPlaying == true);
    return 3;
}

int task4() {
    //first off, I set up a struct for the dice
    struct Dice {
        int value;
        bool active;
        int roll() {
            int value = 0;
            do {
                value=rand() / 6 + 1;
            } while (value > 6 || value < 1);
            return value;
        }
    };
    char choice = 'x';
    int lockedDice = 0;
    int sixes = 0;
    int pairs = 0;
    //I also set up a vector for the dice, and fill it with 5 dice.
    std::vector<Dice> allDice;
    bool playing = true;
    for (int i = 0; i <= 5; i++) {
        allDice.push_back(Dice());
        allDice.at(i).active = true;
    }
    do {
        printf("\033c");
        //Now, the dice roll when the user presses a key, or it quits if the user presses Q.
        std::cout << "Press any key to roll dice. . .\nYou can press q to quit at any time."<<std::endl;
        choice=_getch();
        if (choice == 'q' || choice == 'Q') {
            break;
        }
        std::cout << "you rolled: " << std::endl;
        for (int i = 0; i < allDice.size(); i++) {
            if (allDice.at(i).active == true) {
                allDice.at(i).value = allDice.at(i).roll();
                std::cout << allDice.at(i).value << "  ";
            }
            if (allDice.at(i).active == false) {
                std::cout << "[" << allDice.at(i).value << "] ";
            }
        }
        //I send the values of the rolls to my sixFinder and pairFinder functions, which do as they're named and find any rolled 6's and pairs
        sixes = sixFinder(allDice.at(0).value, allDice.at(1).value, allDice.at(2).value, allDice.at(3).value, allDice.at(4).value);
        std::cout << "\n " << sixes << " sixes were rolled.";
        pairFinder(allDice.at(0).value, allDice.at(1).value, allDice.at(2).value, allDice.at(3).value, allDice.at(4).value);
        do {
            //  Now, the user has the option to 'hold' dice they've rolled. They may also select a previously locked die to unlock it.
            std::cout << "Please input which roll you want to keep, or unlock a previously locked roll (1-6), press H to halt this process." << std::endl;;
            choice = _getch();
            if (choice == 'q' || choice == 'Q') {
                playing = false;
                break;
            }
            lockedDice = charConverter(choice);
            while (lockedDice == -1) {
                std::cout << "Invalid input, select between 1-6, or input H to halt this process." << std::endl;
                choice = _getch();
                if (choice == 'q' || choice == 'Q') {
                    playing = false;
                    break;
                }
                lockedDice = charConverter(choice);
            }
            if (lockedDice > 0 && allDice.at(lockedDice - 1).active == true) {
                allDice.at(lockedDice - 1).active = false;
                std::cout << "Ok, roll number " << lockedDice << " has been locked. if you want to keep or reroll any more of your rolls, \n";
            }
            else if (lockedDice > 0 && allDice.at(lockedDice - 1).active == false) {
                allDice.at(lockedDice - 1).active = true;
                std::cout << "Ok, roll number " << lockedDice << " has been unlocked. If you want to keep or reroll any more of your rolls,\n";

            }
            
        } while (lockedDice != 0&&choice!='q'&&choice!='Q');
       
        // when the user ends the game, I print their rolls one final time so they can see what their final scores were.
    } while (playing == true);
    printf("\033c");
    std::cout << "Your final rolls were: \n";
    for (int i = 0; i < allDice.size(); i++) {
        std::cout << "[" << allDice.at(i).value << "] ";
    }
    std::cout << "\nPress any key to return to the main menu.";
    _getch();
    return 4;
}

int charConverter(char input) { //this function checks the input in the dice task. If the input is a number, it converts it to the int of the number.
    //                This function returns 0 if the input is H, as it ends the "holding phase" in the game. if anything else is input, it returns that the input is false
    if (input == 72 || input == 104) {
        return 0;
    }
    if(input==49||input==50||input==51||input==52||input==53||input==54) {
        return input - 48;
    }
    else {
        return -1;
    }
}

int sixFinder(int roll1, int roll2, int roll3, int roll4, int roll5) { //this function runs through all rolled values and checks if any are a 6, and returns how many there were.
    std::vector<int> values{ roll1,roll2,roll3,roll4,roll5 };
    int sixesFound = 0;
    for (int i = 0; i < values.size(); i++) {
        if (values.at(i) == 6) {
            sixesFound = sixesFound + 1;
        }
    }
    return sixesFound;
}
int pairFinder(int roll1, int roll2, int roll3, int roll4, int roll5) {//this function tracks how many of each value is rolled.
       //                                                                If there are more than one of a value, it is counted as a pair.
    int ones = 0;
    int twos = 0;
    int threes = 0;
    int fours = 0;
    int fives = 0;
    int sixes = 0;
    int pairs = 0;
    std::vector<int> values = { roll1,roll2,roll3,roll4,roll5 };
    for (int i = 0; i < values.size(); i++) {
        if (values.at(i) == 1) {
            ones++;
        }
        if (values.at(i) == 2) {
            twos++;
        }
        if (values.at(i) == 3) {
            threes++;
        }
        if (values.at(i) == 4) {
            fours++;
        }
        if (values.at(i) == 5) {
            fives++;
        }
        if (values.at(i) == 6) {
            sixes++;
        }
    }
    if (sixes >1) {
        std::cout << "\n You have a pair of 6";
    }
    if (fives >1) {
        std::cout << "\n You have a pair of 5";
    }
    if (fours >1) {
        std::cout << "\n You have a pair of 4";
    }
    if (threes >1) {
        std::cout << "\n You have a pair of 3";
    }
    if (twos >1) {
        std::cout << "\n You have a pair of 2";
    }
    if (ones >1) {
        std::cout << "\n You have a pair of 1";
    }
 
    std::cout << "\n\n";
    return 0;
}
