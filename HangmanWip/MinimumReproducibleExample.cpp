#include <string>
#include <iostream>

int main()
{
    std::string CorrectStrMemo = "hello";
    std::string TemporaryStrMemo = "h---o";
    std::string WordToGuess;
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
            break;
        }
    }
}