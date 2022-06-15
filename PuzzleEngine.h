#pragma once

// PuzzleEngine.Cpp
// Justin Burns
// CS150
// 3/27/2022
// PuzzleBoard : While generating both a fully filled and partially revealed puzzle board, I must extract vertical and horizontal keyNumbers and display them.

#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
using namespace std;
class PuzzleEngine
{
public:
	PuzzleEngine();
	bool isFileOPenForWrite(ofstream& ofs, const string filename);
	void setUpPuzzle();
	void run();
	void loadBoard(int row, string rowData);
	void loadHint();
	void displayTemplateBoard();
	void displayPuzzleBoard();
	void displayBoard(string (&board)[15][15]);
	void loadKeyWords();
	void loadLists();
	void printKeys();
private:
	string file = "?";
	string puzzleBoard[15][15];
	string templateBoard[15][15];
	string hintNum = "";
	list<string>KeywordList;


};

