
/*

This program demonstrates my skills in working 
with the standard template library (stl) and algorithms.

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

int main()
{
    const int MAX_WRONG = 8; // Maximum allowable number of errors
    vector<string> words;    // A selection of words for guessing
    words.push_back("GUESS");
    words.push_back("HANGMAN");
    words.push_back("DIFFICULT");
    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end());
    const string THE_WORD = words[0]; // The word to guess
    int wrong = 0;  // Number of erroneous options
    string soFar(THE_WORD.size(), '-'); // Part of the word currently open
    string used = ""; // Already guessed letters
    cout << "Welcome to Hangman. Good luck!\n";
    
    // main loop
    while((wrong < MAX_WRONG) && (soFar != THE_WORD))
    {
        system("clear"); // I use Linux 

        cout << "\n\nYou have " << (MAX_WRONG - wrong);
        cout << " incorrect guesses left.\n";
        cout << "\nYou've used the following letters:\n" << used << endl;
        cout << "\nSo far, the word is:\n" << soFar << endl;
        char guess;
        cout << "\n\nEnter your guess: ";
        cin >> guess;
        guess = toupper(guess); // Translating the character to uppercase, 
        //since the hidden word is written in uppercase.
        while(used.find(guess) != string::npos)
        {
            cout << "\nYou've already guessed " << guess << endl;
            cout << "Enter your gues: ";
            cin >> guess;
            guess = toupper(guess);
        }
        used += guess;
        if(THE_WORD.find(guess) != string::npos)
        {
            cout << "That's right! " << guess << " is in the word.\n";
            // update the soFar variable to include the newly guessed letter.
            for(int i = 0; i < THE_WORD.length(); ++i)
            {
                if(THE_WORD[i] == guess)
                {
                    soFar[i] = guess;
                }
            }
        }
        else
        {
            cout << "Sorry, " << guess << " isn't in the word.\n";
            ++wrong;
        }
        // Game over
        if(wrong == MAX_WRONG)
        {
            cout << "\nYou've been hanged!";
        }
        else
        {
            cout << "\nYou guessed it!";
        }
        cout << "\nThe word was " << THE_WORD << endl;
    }


    return 0;
}