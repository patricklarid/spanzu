#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <conio.h>

using namespace std;

int main()
{
    const int MAX_WRONG = 7; // maximum number of incorrect guesses allowed

    vector<string> words; // collection of possible words to guess
    words.push_back("ELEFANT");
    words.push_back("ARTROZA");
    words.push_back("CAMELEON"); //you can add as many words as you want 


    srand(static_cast<unsigned int>(time(0)));
    std::random_shuffle(words.begin(), words.end());
    const string THE_WORD = words[0]; // word to guess
    int wrong = 0; // number of incorrect guesses
    string soFar(THE_WORD.size(), '-'); // word guessed so far
    string used = ""; // letters already guessed

    cout << "Welcome to Hangman. Good luck!\n";

    // main loop
    while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
    {
        cout << "\n\nYou have " << MAX_WRONG - wrong;
        cout << " incorrect guesses left.\n";
        cout << "\nYou've used the following letters:\n" << used << endl;
        cout << "\nSo far, the word is:\n" << soFar << endl;

        char guess;
        cout << "\n\nEnter your guess: ";
        cin >> guess;
        guess = toupper(guess); // make it uppercase since the secret word is written in uppercase

        while (used.find(guess) != string::npos)
        {
            cout << "\nYou've already guessed " << guess << endl;
            cout << "Enter your guess: ";
            cin >> guess;
            guess = toupper(guess);
        }

        used += guess;

        if (THE_WORD.find(guess) != string::npos)
        {
            cout << "That's right! " << guess << " is in the word.\n";

            // update soFar to include newly guessed letter
            for (int i = 0; i < THE_WORD.length(); ++i)
            {
                if (THE_WORD[i] == guess)
                {
                    soFar[i] = guess;
                }
            }
        }
        else
        {
            cout << "Sorry, " << guess << " isn't in the word.\n";
            ++wrong;
             switch (wrong)
                {
                case 1:
                    cout << "     |        \n";
                    cout << "     O        \n";
                    cout << "              \n";
                    cout << "              \n";
                    cout << "              \n";
                    cout << "              \n";
                    cout << "              \n";
                    break;
                case 2:
                    cout << "     |        \n";
                    cout << "     O        \n";
                    cout << "     |        \n";
                    cout << "              \n";
                    cout << "              \n";
                    cout << "              \n";
                    cout << "              \n";
                    break;
                case 3:
                    cout << "     |        \n";
                    cout << "     O        \n";
                    cout << "    /|        \n";
                    cout << "              \n";
                    cout << "              \n";
                    cout << "              \n";
                    cout << "              \n";
                    break;
                case 4:
                    cout << "     |        \n";
                    cout << "     O        \n";
                    cout << "    /|\\      \n";
                    cout << "              \n";
                    cout << "              \n";
                    cout << "              \n";
                    cout << "              \n";
                    break;
                case 5:
                    cout << "     |        \n";
                    cout << "     O        \n";
                    cout << "    /|\\      \n";
                    cout << "     |        \n";
                    cout << "              \n";
                    cout << "              \n";
                    cout << "              \n";
                    break;
                case 6:
                    cout << "     |        \n";
                    cout << "     O        \n";
                    cout << "    /|\\      \n";
                    cout << "     |        \n";
                    cout << "    /         \n";
                    cout << "              \n";
                    cout << "              \n";
                    break;
                case 7:
                    cout << "     |        \n";
                    cout << "     O        \n";
                    cout << "    /|\\      \n";
                    cout << "     |        \n";
                    cout << "    / \\      \n";
                    cout << "              \n";
                    cout << "              \n";
                    break;
                }
        }
    }

    // game over
    if (wrong == MAX_WRONG)
    {
        cout << "\nYou've been hanged!";
    }
    else
    {
        cout << "\nYou guessed it!";
    }

    cout << "\nThe word was " << THE_WORD << endl;
    
    getch();
    return 0;
}
