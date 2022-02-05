#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <chrono>
#include <windows.h>
#include <string.h> //i don't think i need both string and string.h, but i'm keeping it anyway

// global variables
std::string TemporaryStrMemo;
std::string CorrectStrMemo;

void TitleDropBegin()
{
    std::cout << "    _                                                                                    " << std::endl
              << "   ' )       )      )           /'                                                 /'    " << std::endl
              << "    /      _/      /          /'                                               --/'--    " << std::endl
              << "   /    _/~/    _/~____     /' ____     ____    ,__________     ____           /' ____   " << std::endl
              << "  /  _/~  /  _/~ /'    )  /' /'    )--/'    )--/'    )     )  /'    )        /' /'    )--" << std::endl
              << " /_/~    /_/~  /(___,/' /' /'       /'    /' /'    /'    /' /(___,/'       /' /'    /'   " << std::endl
              << "/~      /~    (________(__(___,/   (___,/' /'    /'    /(__(________      (__(___,/'     " << std::endl
              << "                                                                                         " << std::endl;
    Sleep(3000);
    std::cout << " ___                                                                                                            " << std::endl
              << "(   )                                                                                                           " << std::endl
              << " | | .-.     .---.   ___ .-.     .--.    ___ .-. .-.     .---.   ___ .-.       .--.      .-.      .-.      .-.  " << std::endl
              << " | |/   |   / .-, | (   )   |   /    '  (   )   '   :   / .-, : (   )   '     /    |   /    '   /    '   /    '" << std::endl
              << " |  .-. .  (__) ; |  |  .-. .  ;  ,-. '  |  .-.  .-. ; (__) ; |  |  .-. .    ;  ,-. ' |  .-. ; |  .-. ; |  .-. ;" << std::endl
              << " | |  | |    .'`  |  | |  | |  | |  | |  | |  | |  | |   .'`  |  | |  | |    | |  | | | |  | | | |  | | | |  | |" << std::endl
              << " | |  | |   / .'| |  | |  | |  | |  | |  | |  | |  | |  / .'| |  | |  | |    '  `-' | | |  | | | |  | | | |  | |" << std::endl
              << " | |  | |  | /  | |  | |  | |  | |  | |  | |  | |  | | | /  | |  | |  | |     `.__. | | |  | | | |  | | | |  | |" << std::endl
              << " | |  | |  ; |  ; |  | |  | |  | '  | |  | |  | |  | | ; |  ; |  | |  | |     ___ | | | '  | | | '  | | | '  | |" << std::endl
              << " | |  | |  ' `-'  |  | |  | |  '  `-' |  | |  | |  | | ' `-'  |  | |  | |    (   )' / '  `-' / '  `-' / '  `-' /" << std::endl
              << "(___)(___) `.__.'_. (___)(___)  `.__. | (___)(___)(___)`.__.'_. (___)(___)    `,__.'   `.__,'   `.__,'   `.__,' " << std::endl
              << "                                ( `-' ;                                                                         " << std::endl
              << "                                 `.__.                                                                          " << std::endl;
}

void TitleDropEnd()
{
    std::cout << "--------------------------------------------------" << std::endl
              << "|#######                  ####### #     # ###### |" << std::endl
              << "|   #    #    # ######    #       ##    # #     #|" << std::endl
              << "|   #    #    # #         #       # #   # #     #|" << std::endl
              << "|   #    ###### #####     #####   #  #  # #     #|" << std::endl
              << "|   #    #    # #         #       #   # # #     #|" << std::endl
              << "|   #    #    # #         #       #    ## #     #|" << std::endl
              << "|   #    #    # ######    ####### #     # ###### |" << std::endl
              << "--------------------------------------------------" << std::endl;
}

void LoseScreen()
{
    std::cout << "----------------------------------------------------------" << std::endl
              << "|#     #                                              ###|" << std::endl
              << "| #   #   ####  #    #    #       ####   ####  ###### ###|" << std::endl
              << "|  # #   #    # #    #    #      #    # #      #      ###|" << std::endl
              << "|   #    #    # #    #    #      #    #  ####  #####   # |" << std::endl
              << "|   #    #    # #    #    #      #    #      # #         |" << std::endl
              << "|   #    #    # #    #    #      #    # #    # #      ###|" << std::endl
              << "|   #     ####   ####     ######  ####   ####  ###### ###|" << std::endl
              << "----------------------------------------------------------" << std::endl;
}

void WinScreen()
{
    std::cout << "------------------------------------------------" << std::endl
              << "|#     #                  #     #          ### |" << std::endl
              << "| #   #   ####  #    #    #  #  # # #    # ### |" << std::endl
              << "|  # #   #    # #    #    #  #  # # ##   # ### |" << std::endl
              << "|   #    #    # #    #    #  #  # # # #  #  #  |" << std::endl
              << "|   #    #    # #    #    #  #  # # #  # #     |" << std::endl
              << "|   #    #    # #    #    #  #  # # #   ## ### |" << std::endl
              << "|   #     ####   ####      ## ##  # #    # ### |" << std::endl
              << "------------------------------------------------" << std::endl;
}

int SmallTimer()
{
    int counter = 5; // amount of seconds
    Sleep(1000);
    while (counter >= 1)
    {
        std::cout << "\rLoading: " << counter << std::flush;
        Sleep(1000);
        counter--;
    }
    return 0;
}

void ShowRules()
{
    std::cout << "#############################################################################" << std::endl
              << "# >                       Read Carefully!                                   #" << std::endl
              << "# >You'll see a word, but the word is hidden, so you'll need to guess it!   #" << std::endl
              << "# >But there's the catch: You have a limited number of choices              #" << std::endl
              << "# > as your lives fade away with each wrong guess you make.                 #" << std::endl
              << "# >Your job is to input only one letter at a time and try to guess the word #" << std::endl
              << "# >    Do it right and you might survive                                    #" << std::endl
              << "# >Understood?                                                              #" << std::endl;
    system("pause");
    std::cout << "# >Good!                                                                    #" << std::endl
              << "# >                   Now, Let the game begin!                              #" << std::endl
              << "#############################################################################" << std::endl;
}

void GetValidWord() // will get a random word from the word file
{
    std::ifstream WordsFile;     // declaration of the input file
    WordsFile.open("words.txt"); // opening procedure
    std::string WordsContent;
    std::vector<std::string> WordsFileData; // will store the contents of the words file
    if (WordsFile.is_open())
    {
        while (WordsFile >> WordsContent)
        {
            WordsFileData.push_back(WordsContent); // optimisation purposes and overall a good practice
        }
    }

    else
        std::cout << "Error! File is inexistent or broken. Please make sure that you have the uncorrupted file to continue."; // will print out an error message if the file is missing or the file is broken in some way

    WordsFile.close();

    // picking a random word from the file
    srand(time(0));
    int ValidWordPosition = rand() % WordsFileData.size();
    std::string ValidWord;
    ValidWord = WordsFileData[ValidWordPosition];
    CorrectStrMemo = ValidWord; // memorizes the valid word to be used in the BeginPlay function and for testing purposes

    // mask operation
    for (int i = 1; i < ValidWord.length() - 1; i++) // will show only the first and the last letters of the word
    {
        ValidWord[i] = '-';
    }

    TemporaryStrMemo = ValidWord; // memorizes the masked word to be used in the BeginPlay() function
}

int GetLives(std::string str)
{
    int Lives = 0;
    if (str.length() < 4)
        return Lives = 5;
    else
        return Lives = str.length() / 2 + 3;
}

void BeginPlay() // main game loop
{
    std::string WordToGuess;
    GetValidWord();
    WordToGuess = TemporaryStrMemo;
    std::cout << WordToGuess << std::endl;

    int lives = GetLives(WordToGuess);
    std::cout << "\nYou have " << lives << " lives!";

    char UserGuess;

    while (lives > 0 && WordToGuess != CorrectStrMemo)
    {
        std::cout << "\nGuess the letter : ";
        std::cin >> UserGuess;
        bool correct = false; // the introduction of a bool variable helps in breaking the loops and assuring the correct behaviour of the program
        for (size_t i = 1; i < CorrectStrMemo.length() - 1; i++)
        {
            if (CorrectStrMemo[i] == UserGuess)
            {
                correct = true;
                WordToGuess[i] = UserGuess;
            }
        }
        if (correct)
        {
            std::cout << "\nCorrect guess! Keep going!";
            std::cout << "\nUpdated word is: " << WordToGuess;
            std::cout << "\nLives remaining: " << lives;
        }
        else
        {
            std::cout << "\nIncorrect guess!" << std::endl;
            lives--;
            std::cout << lives << " lives remaining. Use them wisely!" << std::endl;
            std::cout << " " << WordToGuess;
        }

        // conditions to break the while and display the end screeens
        if (WordToGuess == CorrectStrMemo && lives > 0)
        {
            std::cout << std::endl
                      << "\nYou won!";
            Sleep(5000);
            system("cls");
            WinScreen();
            break;
        }
        else if (lives == 0)
        {
            std::cout << "\nYou have no lives left to play!" << std::endl
                      << "\nThe game is over!";
            std::cout << "\nThe word was " << CorrectStrMemo;
            Sleep(5000);
            system("cls");
            LoseScreen();
            break;
        }
    }
}

// endless mode implementation function
void BeginEndlessPlay()
{

    int PlayedLoops = 1;
    std::cout << "\nRound " << PlayedLoops << std::endl;
    BeginPlay();
    PlayedLoops++;
    std::cout << "Do you wish to continue playing?(y/n)" << std::endl;
    char Choice;
    // checking choice validity
    do
    {
        std::cout << "\nInput your choice: ";
        std::cin >> Choice;
        tolower(Choice);
        if (Choice == 'y')
        {
            PlayedLoops++;
            system("cls");
            std::cout << "\nRound " << PlayedLoops << std::endl;
            BeginPlay();
        }

        else if (Choice == 'n')
        {
            system("cls");
            std::cout << "\nHope you had fun!" << std::endl;
            TitleDropEnd();
            break;
        }

        else
            break;
    } while (Choice != 'y' || Choice != 'n');
}

void DisplayMenu()
{
    std::cout << "#############################################################################" << std::endl
              << "#                             MENU                                          #" << std::endl
              << "# 1. Game mode                                                              #" << std::endl
              << "# 2. HighScore                                                              #" << std::endl
              << "# 3. Exit                                                                   #" << std::endl
              << "#############################################################################" << std::endl;
    unsigned int PlayerChoice;

    // will check if the choice is valid
    do
    {
        std::cout << "Chose an option: ";
        std::cin >> PlayerChoice;
        if (PlayerChoice > 3 || PlayerChoice < 0)
            std::cout << "Invalid choice! Please choose again!" << std::endl;
        else
        {
            switch (PlayerChoice)
            {
            case 1:
                system("cls");
                std::cout << "#############################################################################" << std::endl
                          << "#                           GAME MODES                                      #" << std::endl
                          << "# 1. Classic                                                                #" << std::endl
                          << "# 2. Endless                                                                #" << std::endl
                          << "# 3. Back to main                                                           #" << std::endl
                          << "#############################################################################" << std::endl;
                do
                {
                    std::cout << "Chose an option: ";
                    std::cin >> PlayerChoice;
                    if (PlayerChoice > 3 || PlayerChoice < 0)
                        std::cout << "Invalid choice! Please choose again!" << std::endl;
                    else
                    {
                        switch (PlayerChoice)
                        {
                        case 1:
                            std::cout << std::endl;
                            system("cls");
                            ShowRules();
                            system("pause");
                            std::cout << std::endl;
                            SmallTimer();
                            system("cls");
                            BeginPlay();
                            SmallTimer();
                            system("cls");
                            TitleDropEnd();
                            break;

                        // endless mode option
                        case 2:
                            std::cout << std::endl;
                            system("cls");
                            ShowRules();
                            system("pause");
                            std::cout << std::endl;
                            SmallTimer();
                            system("cls");
                            BeginEndlessPlay();
                            SmallTimer();
                            system("cls");
                            TitleDropEnd();
                            break;
                        case 3:
                            system("cls");
                            DisplayMenu();
                        }
                    }
                } while (PlayerChoice > 3 || PlayerChoice < 0);
                break;
            case 2:
                system("cls");
                std::cout << "#############################################################################" << std::endl
                          << "#                           HIGHSCORES                                      #" << std::endl
                          << "#                                                                           #" << std::endl
                          << "#                           COMING SOON                                     #" << std::endl
                          << "#                                                                           #" << std::endl
                          << "#############################################################################" << std::endl;
                break;
            case 3:
                system("cls");
                break;
            default:
                std::cout << "\nInvalid option!";
                break;
            }
        }
    } while (PlayerChoice > 3 || PlayerChoice < 0);
}

int main()
{
    system("cls");
    TitleDropBegin();
    Sleep(500);
    SmallTimer();
    system("cls");
    DisplayMenu();
}