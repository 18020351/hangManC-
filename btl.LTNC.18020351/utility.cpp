#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

string normalize(const string& s)
{
    string news = s;
    transform(s.begin(), s.end(), news.begin(), ::tolower);
    return news;
}

string chooseWord(const string& fileName)
{
    vector<string> vocabulary;
    vector<string> vocabulary1;
    vector<string> vocabulary2;
    ifstream file(fileName);
    if (!file.is_open())
        return "";

    while (!file.eof())
    {
        string line;
        getline(file, line);
        if (file && !line.empty())
            vocabulary.push_back(normalize(line));
    }
    int n = vocabulary.size();
    for(int i = 0; i<n; i++)
    {
        if(vocabulary[i].size() <= 5)
        {
            vocabulary1.push_back(vocabulary[i]);
        }
        else
        {
            vocabulary2.push_back(vocabulary[i]);
        }
    }
    int n1 = vocabulary1.size();
    int n2 = vocabulary2.size();
chooseOption:
    cout<<"You want to choose easy or hard (e or h) : ";
    char choose;

    cin>>choose;
    if(choose == 'e')
    {
        return n1 > 0 ? vocabulary1[rand() % n1] : "";
    }
    else if(choose == 'h')
    {
        return n2 > 0 ? vocabulary2[rand() % n2] : "";
    }
    else
    {
        cout<<"You entered wrong, please select again!!!"<<endl;
        goto chooseOption;
    }
    //cout << "vocabulary size = " << n << endl;
}



bool contains(string word, char guess)
{
    return (word.find(guess) != string::npos);
}
