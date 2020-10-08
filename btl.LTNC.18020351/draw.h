#ifndef __DRAW_H__
#define __DRAW_H__

#include <string>

std::string getHangPicture(int badGuessCount);
void TextColor(int color);
void clearScreen();
void renderGame(std::string guessedWord, int badGuessCount, std::string badGuess = "");
int printGameOverInfo(std::string guessedWord, std::string word, int badGuessCount);
void mayBay();

#endif // __DRAW_H__
