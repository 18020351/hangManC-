#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>
#include <Windows.h>
#include "draw.h"
#include "utility.h"

using namespace std;
bool stop = 1;
struct Hour
{
    int hour;
    int minute;
    int second;
};

char convert_int_to_Char(int k)
{
    switch (k)
    {
    case 0:
        return '0';
    case 1:
        return '1';
    case 2:
        return '2';
    case 3:
        return '3';
    case 4:
        return '4';
    case 5:
        return '5';
    case 6:
        return '6';
    case 7:
        return '7';
    case 8:
        return '8';
    case 9:
        return '9';
    default:
        break;
    }
}
// lấy giờ phút giây trong struct nạp vào chuỗi để in ra.
void insertarray(char *h, Hour *j)
{
    int temp = 0;
    temp = j->second;
    h[7] = convert_int_to_Char(temp % 10);
    h[6] = convert_int_to_Char(temp /= 10);

    temp = j->minute;
    h[4] = convert_int_to_Char(temp % 10);
    h[3] = convert_int_to_Char(temp /= 10);

    temp = j->hour;
    h[1] = convert_int_to_Char(temp % 10);
    h[0] = convert_int_to_Char(temp /= 10);

}
// hàm để đồng hồ dịch chuyển.
bool changetime(Hour *tiMe)
{
    if (tiMe->second > 0) -- tiMe->second;
    else if (tiMe->minute > 0)
    {
        tiMe->second = 59;
        -- tiMe->minute;
    }
    else if (tiMe->hour > 0)
    {
        -- tiMe->hour;
        tiMe->minute = 59;
        tiMe->second = 59;
    }
    else return 0;
    return 1;
}

//dung de in ra mot chuoi thay the ham cout
void WriteBlockChar(char * Arraych,int row, int col,int x, int y,int color)
{
    //x và y là tọa độ chuỗi cần in trên màn hình, có màu là color.
    CHAR_INFO *charater = new CHAR_INFO[row*col];
    for (int i = 0; i < row*col; i++)
    {
        charater[i].Attributes = color;
        charater[i].Char.AsciiChar = Arraych[i];
    }
    COORD sizebuff = { col,row };
    COORD pos = { 0,0 };
    SMALL_RECT earea = { x,y,x + col - 1,y + row - 1 };
    WriteConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), charater, sizebuff, pos, &earea);
    delete[] charater;
}

void printClock()
{
    Hour h = { 0,5,2 };
    char a[8] = { '0','0',':','0','0',':','0','0'};
    while (stop)
    {
        if (!changetime(&h))
        {
            stop = 0;
            clearScreen();
            cout<<"<<!!TIME UP!!>>"<<endl;
        }

        insertarray(a, &h);
        WriteBlockChar(a, 1, 8, 70, 3,0x004|0x060);
        Sleep(970);
    }
    return;
}
void gotoXY(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void close(DWORD evt)
{
    if (evt == CTRL_CLOSE_EVENT) stop = 0;
}
void introduce()
{
    int n = 0;
    int dem = 0;
    while(dem < 41)
    {
        clearScreen();
        TextColor(++n % 14 + 1);
        cout<<"  *           *  *****  *      *****  *****  *     *  *****     *****  ***** "<<endl;
        cout<<"   *         *   *      *      *      *   *  * * * *  *           *    *   * " <<endl;
        cout<<"    *   *   *    *****  *      *      *   *  *  *  *  *****       *    *   * "<<endl;
        cout<<"     * * * *     *      *      *      *   *  *     *  *           *    *   * "<<endl;
        cout<<"      *   *      *****  *****  *****  *****  *     *  *****       *    ***** "<<endl;
        cout<<"                                                                             "<<endl;
        cout<<"        *   *      *      *     *  *****  *     *      *      *     * "<<endl;
        cout<<"        *   *     * *     * *   *  *      * * * *     * *     * *   * "<<endl;
        cout<<"        *****    *****    *  *  *  *  **  *  *  *    *****    *  *  * "<<endl;
        cout<<"        *   *   *     *   *   * *  *   *  *     *   *     *   *   * * "<<endl;
        cout<<"        *   *  *       *  *     *  *****  *     *  *       *  *     * "<<endl;
        dem ++;
    }
}
const vector<string> HANGED2 = {
"    \\   \n"
"\\____\\__\n"
"/    /  \n"
"    /   \n",
"      \\   \n"
"  \\____\\__\n"
"  /    /  \n"
"      /   \n",
"        \\   \n"
"    \\____\\__\n"
"    /    /  \n"
"        /   \n",
"          \\   \n"
"      \\____\\__\n"
"      /    /  \n"
"          /   \n",
"            \\   \n"
"        \\____\\__\n"
"        /    /  \n"
"            /   \n",
"              \\   \n"
"          \\____\\__\n"
"          /    /  \n"
"              /   \n",
"                \\   \n"
"            \\____\\__\n"
"            /    /  \n"
"                /   \n",
"                  \\   \n"
"              \\____\\__\n"
"              /    /  \n"
"                  /   \n",
"                     \\   \n"
"                 \\____\\__\n"
"                 /    /  \n"
"                     /   \n",
"                        \\   \n"
"                    \\____\\__\n"
"                    /    /  \n"
"                        /   \n",
"                           \\   \n"
"                       \\____\\__\n"
"                       /    /  \n"
"                           /   \n",
"                               \\   \n"
"                           \\____\\__\n"
"                           /    /  \n"
"                               /   \n",
"                                  \\   \n"
"                              \\____\\__\n"
"                              /    /  \n"
"                                  /   \n",
};
int timSoKyTuDoanDung(char guess, string word)
{
    int dem = 0;
    for(int i = 0; i<word.size(); i++)
    {
        if(guess == word[i]) dem++;
    }
    return dem;
}
void mayBay(char guess, string word){
    int i = 0;
    int n = 0;
    int dem = 0;
    int dem1 = timSoKyTuDoanDung(guess, word);
    while(dem < 13){

        clearScreen();
        TextColor(++n % 14 + 1);
        cout<<HANGED2[i];
        i = (i+1) % HANGED2.size();
        if(dem1 > 0){
             cout<<"Congratulations, you have " << dem1 << " characters " <<guess<<endl;
        }
        else{
            cout<<"Sorry you guessed wrong!!!! :<<<<"<<endl;
        }
        std::this_thread::sleep_for (std::chrono::milliseconds(50));
        dem++;
    }
}
char readAGuess()
{
    char guess;
    cout << "Please enter your next guess: ";
    cin >> guess;
    return guess;
}

void update(string& guessedWord, const string& word, char guess)
{
    int n = guessedWord.length();
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (word[i] == guess)
            guessedWord[i] = guess;
        dem++;
    }
}
string rePlay()
{
    //cout<<"Correct word : "<< word <<endl ;
    cout<<"Do you want to replay( yes or no  ) : " ;
    string replay  ;
    cin >>  replay ;

    return replay;

}
//setup tỉ lệ màn hình console.
HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
void resizeConslole(int width, int height)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}
bool check_suggest(char s, string guessedWord)
{
    for(int i = 0; i<guessedWord.size(); i++)
    {
        if(s == guessedWord[i])
        {
            return false;
            break;
        }
    }
    return true;
}
void suggestion(string word, string guessedWord)
{
    for(int i = 0; i<word.size(); i++)
    {
        if(check_suggest(word[i], guessedWord))
        {
            cout<<"Suggested characters are : "<<word[i]<<endl;
            break;
        }
    }
}

int main(int argc, char* argv[])
{
    int option;
    resizeConslole(700, 350);
    introduce();
    cout<<endl;
    cout<<"Enter 1 : Start Game"<<endl;
    cout<<"Enter 2 : Quit Game"<<endl;
    cout<<"Enter your number : ";
    cin>>option;
    int win = 0;
    int lose = 0;
    switch(option)
    {
    case 1 :
    {
        system("color E");

        SetConsoleCtrlHandler((PHANDLER_ROUTINE)close, TRUE);
        thread clock;
        clock = thread(printClock);
        while(stop)
        {
            // gotoXY(0, 0);
rePlay:
            srand(time(0));
            cout<<"Topics include: " <<endl;
            cout<<"Choose 1 : Topic General"<<endl;
            cout<<"Choose 2 : Topic Fruit"<<endl;
            cout<<"Choose 3 : Topic Landscape"<<endl;
            cout<<"Choose 4 : Topic Animal"<<endl;
            cout<<"Choose 5 : Topic Plant"<<endl;
            cout<<"Choose 6 : Topic Vegetables"<<endl;
            cout<<"Choose 7 : Topic Weather"<<endl;
            cout<<"Choose 8 : Topic Color"<<endl;
            int topic;
chooseTopic:
            cout<<"Which topic do you choose? : ";
            cin>>topic;
            string fileName;
            if(topic == 1)
            {
                clearScreen();
                cout<<"You have chosen a General topic!!!"<<endl;
                fileName = argc > 1 ? argv[1] : "ogden_picturable_200.txt";
            }
            else if(topic == 2)
            {
                clearScreen();
                cout<<"You have chosen a Fruit topic!!!"<<endl;
                fileName = argc > 1 ? argv[1] : "Fruit.txt";
            }
            else if(topic == 3)
            {
                clearScreen();
                cout<<"You have chosen a Landscape topic!!!"<<endl;
                fileName = argc > 1 ? argv[1] : "Landscape.txt";
            }
            else if(topic == 4)
            {
                clearScreen();
                cout<<"You have chosen a Animal topic!!!"<<endl;
                fileName = argc > 1 ? argv[1] : "Animal.txt";
            }
            else if(topic == 5)
            {
                clearScreen();
                cout<<"You have chosen a Plant topic!!!"<<endl;
                fileName = argc > 1 ? argv[1] : "Plant.txt";
            }
            else if(topic == 6)
            {
                clearScreen();
                cout<<"You have chosen a Vegetables topic!!!"<<endl;
                fileName = argc > 1 ? argv[1] : "Vegetables.txt";
            }
            else if(topic == 7)
            {
                clearScreen();
                cout<<"You have chosen a Weather topic!!!"<<endl;
                fileName = argc > 1 ? argv[1] : "Weather.txt";
            }
            else if(topic == 8)
            {
                clearScreen();
                cout<<"You have chosen a Color topic!!!"<<endl;
                fileName = argc > 1 ? argv[1] : "Color.txt";
            }
            else
            {
                cout<<"You entered wrong, please select a topic again!!!"<<endl;
                goto chooseTopic;
            }
            while (true)
            {
                string word = chooseWord(fileName);
                int numSuggest = word.size() / 2;
                if (word.empty())
                {
                    cout << "No word available in " << fileName << endl;
                    return 0;
                }
                string guessedWord = string(word.length(), '-'); // xâu đựng những kí tự đoán đúng.
                int badGuessCount = 0; // số lần đoán sai.
                const int MAX_BAD_GUESS = 7; // số lần đoán sai tối đa.
                string badGuess; // xâu đựng các kí tự đoán sai.

                do
                {
                    renderGame(guessedWord, badGuessCount, badGuess);

                    if(numSuggest > 0)
                    {
chooseSug:
                        cout<<"You have " << numSuggest << " suggestion!!!!"<<endl;
                        cout<<"Do you want to suggest ? (y or n) : ";
                        char suggest;
                        cin>>suggest;
                        if(suggest == 'y')
                        {
                            suggestion(word, guessedWord);
                            numSuggest--;
                        }
                        else if(suggest == 'n')
                        {
                            goto startGame;
                        }
                        else
                        {
                            cout<<"You entered wrong, please select a topic again!!!" <<endl;
                            goto chooseSug;
                        }
                    }
                    else
                    {
                        cout<<"You have used up all the suggestions"<<endl;
                        goto startGame;
                    }

startGame:
                    char guess = readAGuess(); // nhập kí tự đoán.
                    if (contains(word, guess))
                    {
                        mayBay(guess, word);
                        update(guessedWord, word, guess); // nếu đúng thì thêm từ kí tự đoán đúng vào vị trí của nó trong từ.
                    }
                    else
                    {
                        // nếu sai thì tăng số lần đoán sai và thêm kí tự đoán sai vào xâu badGuess.
                        mayBay(guess, word);
                        badGuessCount++;
                        badGuess += string(1, guess) + ", " ;
                    }
                }
                while (badGuessCount < MAX_BAD_GUESS && guessedWord != word);
                int kt = printGameOverInfo(guessedWord, word, badGuessCount);
                if(kt == 1) win++;
                else lose++;
                cout<<endl;
                string replay = rePlay();
                if(replay == "yes")
                {
                    cout<<"WIN : " <<win <<" || "<<"LOSE : "<<lose<<endl;
                    goto rePlay;
                }
                else
                {
                    system("cls");
                    cout<<" Good bye ...! See you again" ;
                    break;
                }
            }


        }
        stop = 0;
        clock.join();
    }
    case 2:
    {
        clearScreen();
        cout<<endl<<"Good bye and see you again!!"<<endl;
        break;
    }
    }


    return 0;
}
