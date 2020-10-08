#include <iostream>
#include <cstdlib>
#include <vector>
#include <thread>
#include<Windows.h>
using namespace std;

void TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
string getHangPicture(int badGuessCount)
{
    string picture[] = {"",
"   ------------\n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        ",
"   ------------\n"
"   |          |\n"
"   |          O\n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        ",
"   ------------\n"
"   |          |\n"
"   |          O\n"
"   |          |\n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        ",
"   ------------\n"
"   |          |\n"
"   |          O\n"
"   |         /|\n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        ",
"   ------------\n"
"   |          |\n"
"   |          O\n"
"   |         /|\\\n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        ",
"   ------------\n"
"   |          |\n"
"   |          O\n"
"   |         /|\\\n"
"   |         / \n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        ",
"   ------------\n"
"   |          |\n"
"   |          O\n"
"   |         /|\\\n"
"   |         / \\\n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        ",

};
    return picture[badGuessCount];
}

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#elif __linux__
    system("clear");
#endif // _WIN32
}

void renderGame(string guessedWord, int badGuessCount, string badGuess = "")
{
    clearScreen();
    cout << "Current guess = " << guessedWord << endl;
    cout << "You have made bad " << badGuessCount << " guess(es)"
         << (badGuess.empty() ? "" : ": ") << badGuess << endl
         << getHangPicture(badGuessCount) << endl;
}

const vector<string> HANGED = {
"   ------------\n"
"   |         /\n"
"   |        O\n"
"   |       /|\\\n"
"   |       / \\\n"
"   |         \n"
"   |         \n"
"   |         \n"
"   |         \n"
"-------        ",
"   ------------\n"
"   |          |\n"
"   |          O\n"
"   |         /|\\\n"
"   |         / \\\n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        ",
"   ------------\n"
"   |           \\\n"
"   |            O\n"
"   |           /|\\\n"
"   |           / \\\n"
"   |             \n"
"   |             \n"
"   |             \n"
"   |             \n"
"-------        ",
"   ------------\n"
"   |          |\n"
"   |          O\n"
"   |         /|\\\n"
"   |         / \\\n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        "
};
 const vector<string> HANGED1 = {
"             \n"
"     *  *  *  * \n"
"    *     O    *\n"
"  *  *  \\//\\/  * *\n"
"    *     \\    * *\n"
"  *   *  / \\  * * * \n"
"  *   *         * * * \n"
"  *  * *   *  *  \n"
"    *    *    \n"
"   *   *   *   \n"
"              ",
"   *   *    *   \n"
"     *    *    * \n"
"  *   *   O  * * *\n"
" * * *  _/|\\_  * * **\n"
" *  *     |   *  * *\n"
"   *  *  / \\* ** * *\n"
" *   *     *   *\n"
" *  *   *   *   *\n"
"   *   *  *   * \n"
" *    *   *   * \n"
"              ",
" *  *   *   *  * \n"
"   * *   *    *  *\n"
" *  *  ** O  * *\n"
"  * *  * /\\\\  ***\n"
" * ***  / / \\  * *  *\n"
" * * *   / \\  **  *\n"
" * *  *  *  ** \n"
" *  *  *   **   * \n"
"  *  *   *   **  *\n"
"  *     *   ** \n"
"              ",
"   *   *    *   \n"
"     *    *    * \n"
"  *   *   O  * * *\n"
" * * *  _/|\\_  * * **\n"
" *  *     |   *  * *\n"
"   *  *  / \\* ** * *\n"
" *   *     *   *\n"
" *  *   *   *   *\n"
"   *   *  *   * \n"
" *    *   *   * \n"
"              "
};

int printGameOverInfo(string guessedWord, string word, int badGuessCount)
{
    renderGame(guessedWord, badGuessCount);
    if (guessedWord != word) {
        int n = 0;
        int i = 0;
        int dem = 0;
        while (dem < 10) {

            clearScreen();
            TextColor(++i % 14 + 1);
            cout << "Game Over!!! You are hanged" << endl
                 << "The correct word is : => => => " << word << endl;
            cout << HANGED[n];
            n = (n+1) % HANGED.size();
            std::this_thread::sleep_for (std::chrono::milliseconds(100));
            dem++;
        }
        return 0;
    }
    else {
       int i = 0;
       int n = 0;
       int dem = 0;
       while(dem < 10){
            clearScreen();
            TextColor(++i % 14 + 1);
            cout << "Congrats!!! You are free" << endl;
            cout << "The correct word is : => => => " << word << endl;
            cout << HANGED1[n];
            n = (n+1) % HANGED1.size();
            std::this_thread::sleep_for (std::chrono::milliseconds(100));
            dem++;
       }
        return 1;
    }
}
