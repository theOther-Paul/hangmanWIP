#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <chrono>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

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

void TitleDropEnd()
{
    std::cout << " 888888 88  88 888888     888888 88b 88 8888b.  d8b" << std::endl;
    std::cout << "  88   88  88 88__       88__   88Yb88  8I  Yb Y8P " << std::endl;
    std::cout << "  88   888888 88''       88''  88 Y88  8I  dY `''' " << std::endl;
    std::cout << "  88   88  88 888888     888888 88  Y8 8888Y'  (8) " << std::endl;
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
    int WordsCounter = 0;
    std::vector<std::string> a(2643); //to read content easier, using a vector with a counter is the best practice for now
    if (WordsFile.is_open())
    {
        while (!WordsFile.eof()) //will make sure that the file is read in it's entirety
        {
            WordsFile >> WordsContent; //contains the file content
            a[WordsCounter] = WordsContent;
            WordsCounter++;
        }
    }

    else
        std::cout << "Error! File is inexistent or broken. Please make sure that you have the uncorrupted file to continue."; //will print out an error message if the file is missing or the file is broken in some way

    WordsFile.close();
    srand(time(0));
    int ValidWordPosition = rand() % WordsCounter;
    std::string ValidWord;
    ValidWord = a[ValidWordPosition];
    for (int i = 1; i < ValidWord.length() - 1; i++) //will show only the first and the last letters of the word
    {
        ValidWord[i] = '-';
    }
    std::cout << ValidWord;
}

// {
//     int lives = GetValidWord().length() + 3;
//     if (true)
//         lives--;
//     if (lives == 0)
//     {
//         std::cout << "\n Game over!" << std::endl;
//         Sleep(5000);
//         system("cls");
//         TitleDropEnd();
//     }
// }

void BeginPlay() //main game loop
{
    GetValidWord(); //need to pass the random string to std::string WordToGuess
    std::string WordToGuess;
    std::string UserGuess;
    std::cout << "\nGuess the letter : ";
    getline(std::cin, UserGuess);
    for (int i = 0; i <= WordToGuess.length(); i++)
    {
        if (UserGuess = WordToGuess[i]) //i guess it doesn't work because WordToGuess is empty. Need to fix the variable problem first before completing the game loop. See line 124
            std::cout << UserGuess;
        else
        {
            if (UserGuess == WordToGuess)
            {
                std::cout << "You won!";
                Sleep(5000);
                system("cls");
                TitleDropEnd();
            }
            else
            {
                if (UserGuess != WordToGuess)
                {
                    std::cout << "You lose!";
                    Sleep(5000);
                    system("cls");
                    TitleDropEnd();
                }
            }
        }
    }
}

int main()
{
    ShowRules();
    Sleep(5000);
    std::cout << std::endl;
    SmallTimer();
    system("cls");
    BeginPlay();
}
