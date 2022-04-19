#include <iostream>
#include <ctime>

void printIntroduction(int Difficulty)
{
    std::cout << "\nYou are at Geek Squad, doing level " << Difficulty;
    std::cout << " data backups for clients.\nYou'll have to verify all of the client's data was transferred to ensure they are happy.\nYou'll need to enter the correct code to close the tag.\n";
}

bool PlayGame(int Difficulty) 
{
    printIntroduction(Difficulty);
    //these are the variables that add up to what the user is trying to guess
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    //result variables
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //more stupid intro text lmao
    std::cout << std::endl;
    std::cout << "* Theres 3 sources of the data.\n";
    std::cout << "* The amount of data adds up to: " << CodeSum << std::endl;
    std::cout << "* Additionally, the amount of data also multiplies to be " << CodeProduct << std::endl;
    
    //store the player's guess in the variables
    int guessA, guessB, guessC;
    std::cin >> guessA >> guessB >> guessC;

    // make the player's guess for sums be vars
    int GuessSum = guessA + guessB + guessC;
    int GuessProd = guessA * guessB * guessC;

    //did the player get it right
    if (GuessSum == CodeSum && GuessProd == CodeProduct) 
    {
        if (Difficulty < 4){
            std::cout << "\n***Well done agent! You've successfully verified all of the client's data. Keep going!***\n";
        }
        return true;
    } else {
        std::cout << "\n !!! Careful, agent. You entered the wrong amount of data. Try again. !!!\n";
        return false;
    }

}


int main() 
{
    srand(time(NULL));
    int levelDifficulty = 1;
    int const MaxLevel = 4;

    while (levelDifficulty <= MaxLevel) // loop game until all levels are completed
    {
        bool bLevelComplete = PlayGame(levelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if(bLevelComplete) 
        {
            ++levelDifficulty;
        }
    }
    std::cout << "\n ******************************** Great work.********************************\nYour shift has ended, and you will be paid approximately 2 dollars for your work\n";
    std::cout << "\nowned lmao";
    return 0;
}