#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

void printgame(string str) {
    for (int i = 0; i < str.size(); i++) {
        cout << str[i];
    }
    cout << endl;
    return;
}

struct DifficultyLevel {
    string name;
    int maxTries;
};

const vector<DifficultyLevel> difficultyLevels = {
    {"Easy", 10},
    {"Medium", 6},
    {"Hard", 3}
};

int main() {
    vector<string> dictionary = {"time", "year", "people", "way", "day", "man", "thing", "woman", "life", "child",
                                 "world", "school", "state", "family", "student", "group", "country", "problem", "hand", "part", 
                                 "place", "case", "week", "company", "system", "program", "question", "work", "government", "number", 
                                 "night", "point", "home", "water", "room", "mother", "area", "money", "story", "fact", 
                                 "month", "lot", "right", "study", "book", "eye", "job", "word", "business", "issue", 
                                 "side", "kind", "head", "house", "service", "friend", "father", "power", "hour", "game", 
                                 "line", "end", "member", "law", "car", "city", "community", "name", "president", "team", 
                                 "minute", "idea", "kid", "body", "information", "back", "parent", "face", "others", "level", 
                                 "office", "door", "health", "person", "art", "war", "history", "party", "result", "change", 
                                 "morning", "reason", "research", "girl", "guy", "moment", "air", "teacher", "force", "education"};
    bool playAgain = true;

    while (playAgain) {
        srand(time(0));
        int x = abs(rand()) % dictionary.size();
        string picked = dictionary[x];
        
        
        string guess = "";

        for(int i = 0; i < picked.size(); i++) {
            guess = guess + "_";
        }


        int wrongs = 0;
        vector<char> guessedLetters; // Track the guessed letters

        // Select difficulty level
        int levelChoice;
        cout << "Select the difficulty level:" << endl;
        for (int i = 0; i < difficultyLevels.size(); i++) {
            cout << i + 1 << ". " << difficultyLevels[i].name << endl;
        }
        cin >> levelChoice;
        while (levelChoice < 1 || levelChoice > difficultyLevels.size()) {
            cout << "Invalid choice. Choose again." << endl;
            cin >> levelChoice;
        }
        cout << "This is a " << picked.size() << " letter word."<< endl;
        printgame(guess);


        const DifficultyLevel& chosenLevel = difficultyLevels[levelChoice - 1];
        cout << "You have maximum " << chosenLevel.maxTries << " guesses" << endl;

        while (wrongs < chosenLevel.maxTries && guess != picked) {
            char ltr;
            cout << "Enter a letter: ";
            cin >> ltr;
            bool alreadyGuessed = false;

            // Check if the letter has already been guessed using a traditional for loop
            for (int i = 0; i < guessedLetters.size(); i++) {
                if (guessedLetters[i] == ltr) {
                    alreadyGuessed = true;
                    break;
                }
            }

            if (alreadyGuessed) {
                cout << "You have already guessed the letter '" << ltr << "'. Try again." << endl;
                continue;
            }

            guessedLetters.push_back(ltr);

            int used = 0;
            for(int j = 0; j < picked.size(); j++) {
                if (ltr == picked[j]) {
                    guess[j] = ltr;
                    used++;
                }
            }

            if (used == 0) {
                cout << "Wrong guess" << endl;
                wrongs++;
            }

            cout << guess << endl;
        }

        if (wrongs == chosenLevel.maxTries) {
            cout << guess << endl;
        }
        if (wrongs < chosenLevel.maxTries) {
            cout << "You won" << endl;
            cout << "The word is " << guess << endl;
        }
        else {
            cout << "You lose" << endl;
            cout << "The word was "<< picked << endl;
        }

        char playAgainChoice;
        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgainChoice;

        if (playAgainChoice != 'Y' && playAgainChoice != 'y') {
            playAgain = false;
        }
    }

    return 0;
}