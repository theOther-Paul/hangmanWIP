#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <chrono>
#include <windows.h>
#include <string.h> //i don't think i need both string and string.h, but i'm keeping it anyway

//global variables
std::string TemporaryStrMemo;
std::string CorrectStrMemo;

void TitleDropBegin()
{
    std::cout << "    _                                                                                    " << std::endl;
    std::cout << "   ' )       )      )           /'                                                 /'    " << std::endl;
    std::cout << "    /      _/      /          /'                                               --/'--    " << std::endl;
    std::cout << "   /    _/~/    _/~____     /' ____     ____    ,__________     ____           /' ____   " << std::endl;
    std::cout << "  /  _/~  /  _/~ /'    )  /' /'    )--/'    )--/'    )     )  /'    )        /' /'    )--" << std::endl;
    std::cout << " /_/~    /_/~  /(___,/' /' /'       /'    /' /'    /'    /' /(___,/'       /' /'    /'   " << std::endl;
    std::cout << "/~      /~    (________(__(___,/   (___,/' /'    /'    /(__(________      (__(___,/'     " << std::endl;
    std::cout << "                                                                                         " << std::endl;
    Sleep(5000);
    std::cout << " ___                                                                                                            " << std::endl;
    std::cout << "(   )                                                                                                           " << std::endl;
    std::cout << " | | .-.     .---.   ___ .-.     .--.    ___ .-. .-.     .---.   ___ .-.       .--.      .-.      .-.      .-.  " << std::endl;
    std::cout << " | |/   |   / .-, | (   )   |   /    '  (   )   '   :   / .-, : (   )   '     /    |   /    '   /    '   /    '" << std::endl;
    std::cout << " |  .-. .  (__) ; |  |  .-. .  ;  ,-. '  |  .-.  .-. ; (__) ; |  |  .-. .    ;  ,-. ' |  .-. ; |  .-. ; |  .-. ;" << std::endl;
    std::cout << " | |  | |    .'`  |  | |  | |  | |  | |  | |  | |  | |   .'`  |  | |  | |    | |  | | | |  | | | |  | | | |  | |" << std::endl;
    std::cout << " | |  | |   / .'| |  | |  | |  | |  | |  | |  | |  | |  / .'| |  | |  | |    '  `-' | | |  | | | |  | | | |  | |" << std::endl;
    std::cout << " | |  | |  | /  | |  | |  | |  | |  | |  | |  | |  | | | /  | |  | |  | |     `.__. | | |  | | | |  | | | |  | |" << std::endl;
    std::cout << " | |  | |  ; |  ; |  | |  | |  | '  | |  | |  | |  | | ; |  ; |  | |  | |     ___ | | | '  | | | '  | | | '  | |" << std::endl;
    std::cout << " | |  | |  ' `-'  |  | |  | |  '  `-' |  | |  | |  | | ' `-'  |  | |  | |    (   )' / '  `-' / '  `-' / '  `-' /" << std::endl;
    std::cout << "(___)(___) `.__.'_. (___)(___)  `.__. | (___)(___)(___)`.__.'_. (___)(___)    `,__.'   `.__,'   `.__,'   `.__,' " << std::endl;
    std::cout << "                                ( `-' ;                                                                         " << std::endl;
    std::cout << "                                 `.__.                                                                          " << std::endl;
}

void TitleDropEnd() //need to improve this ascii screen to make it more readable
{
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "|#######                  ####### #     # ###### |" << std::endl;
    std::cout << "|   #    #    # ######    #       ##    # #     #|" << std::endl;
    std::cout << "|   #    #    # #         #       # #   # #     #|" << std::endl;
    std::cout << "|   #    ###### #####     #####   #  #  # #     #|" << std::endl;
    std::cout << "|   #    #    # #         #       #   # # #     #|" << std::endl;
    std::cout << "|   #    #    # #         #       #    ## #     #|" << std::endl;
    std::cout << "|   #    #    # ######    ####### #     # ###### |" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
}

int SmallTimer()
{
    int counter = 5; //amount of seconds
    Sleep(1000);
    while (counter >= 1)
    {
        std::cout << "\rThe game will begin in: " << counter << std::flush;
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
    Sleep(20000); //minor tweaks needed for accuracy and Qol; alsop sleep is in milliseconds
    std::cout << "# >Good!                                                                    #" << std::endl
              << "# >                   Now, Let the game begin!                              #" << std::endl
              << "#############################################################################" << std::endl;
}

void GetValidWord() //will get a random word from the word file
{
    std::ifstream WordsFile;     //declaration of the input file
    WordsFile.open("words.txt"); //opening procedure
    std::string WordsContent;
    //int WordsCounter = 0;
    std::vector<std::string> WordsFileData; //will store the contents of the words file
    if (WordsFile.is_open())
    {
        // while (!WordsFile.eof()) //will make sure that the file is read in it's entirety
        // {
        //     WordsFile >> WordsContent; //contains the file content
        //     a[WordsCounter] = WordsContent;
        //     WordsCounter++;
        // }
        while (WordsFile >> WordsContent)
        {
            WordsFileData.push_back(WordsContent); //optimisation purposes and overall a good practice
        }
    }

    else
        std::cout << "Error! File is inexistent or broken. Please make sure that you have the uncorrupted file to continue."; //will print out an error message if the file is missing or the file is broken in some way

    WordsFile.close();

    //picking a random word from the file
    srand(time(0));
    int ValidWordPosition = rand() % WordsFileData.size();
    std::string ValidWord;
    ValidWord = WordsFileData[ValidWordPosition];
    CorrectStrMemo = ValidWord; //memorizes the valid word to be used in the BeginPlay function and for testing purposes

    //mask operation
    for (int i = 1; i < ValidWord.length() - 1; i++) //will show only the first and the last letters of the word
    {
        ValidWord[i] = '-';
    }

    TemporaryStrMemo = ValidWord; //memorizes the masked word to be used in the BeginPlay() function
}

void BeginPlay() //main game loop
{
    std::string WordToGuess;
    GetValidWord();
    WordToGuess = TemporaryStrMemo;
    std::cout << WordToGuess << std::endl;
    int lives;
    if (WordToGuess.length() < 4)
        lives = 5;
    else
        lives = WordToGuess.length() / 2 + 3;
    std::cout << "\nYou have " << lives << " lives!";
    char UserGuess;
    std::cout << "(" << CorrectStrMemo << ")";

    while (lives > 0 && WordToGuess != CorrectStrMemo)
    {
        std::cout << "\nGuess the letter : ";
        std::cin >> UserGuess;
        for (size_t i = 1; i < WordToGuess.length() - 1; i++) //works fine for small words or 3 letter words, with 1 unknown one
        {
            for (size_t j = 1; j < CorrectStrMemo.length() - 1; j++)
            {
                if (lives > 0 && CorrectStrMemo[j] == UserGuess)
                {
                    std::cout << "\nCorrect guess! Keep going!";
                    WordToGuess[i] = UserGuess;
                    std::cout << "\nUpdated word is: " << WordToGuess;
                    std::cout << "\nLives remaining: " << lives;
                    break;
                }

                else
                {
                    std::cout << "\nIncorrect guess!" << std::endl;
                    lives--;
                    std::cout << lives << " lives remaining. Use them wisely!" << std::endl;
                    std::cout << " " << WordToGuess;
                    break;
                }
                break;
            }
        }

        //conditions to break the while and display the end screeens
        if (WordToGuess == CorrectStrMemo && lives > 0)
        {
            std::cout << std::endl
                      << "You won!";
            break;
        }
        else if (lives == 0)
        {
            std::cout << "You have no lives left to play!" << std::endl //need to connect it with the win/lose screeens
                      << "The game is over!";
            Sleep(1000);
            system("cls");
            TitleDropEnd();
        }
    }
}

int main()
{
    // ShowRules();
    // // Sleep(5000);
    // std::cin.get();
    // std::cout << std::endl;
    // SmallTimer();
    // system("cls");
    BeginPlay();
}