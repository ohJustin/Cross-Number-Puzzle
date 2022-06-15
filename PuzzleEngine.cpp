#pragma once

// PuzzleEngine.Cpp
// Justin Burns
// CS150
// 3/27/2022
// PuzzleBoard : While generating both a fully filled and partially revealed puzzle board, I must extract vertical and horizontal keyNumbers and display them.

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "PuzzleEngine.h"
using namespace std;

PuzzleEngine::PuzzleEngine() {
	this->file = "Template.txt";
}

bool PuzzleEngine::isFileOPenForWrite(ofstream& ofs, const string filename) { //Possibly going to be checking the BlankBoardtxt in order to fill the spaces before the "X's" ? (BrainStorming Function)
	ofs.open(filename);
	bool open = false;

	if (!ofs.is_open()) {
		open = false;
	}
	else {
		open = true;
	}
	return open;
}

void PuzzleEngine::setUpPuzzle() {

	string line;
	ifstream templateFile;
	int inc = 0;

	templateFile.open(this->file);
	if (!templateFile.is_open()) {
		cout << this->file << " Is not opening correctly! " << endl;
		return;
	}

	while (!templateFile.eof()) {
		getline(templateFile,line);
		//LOADS BOARD ONE ROW BY ONE
		loadBoard(inc, line);
		++inc;
	}
}

void PuzzleEngine::loadHint() {
//LOAD PEEKPUZZLE ( With Row Hint )... First puzzle displayed.
	for (int j = 0; j < 8; ++j) {
		this->templateBoard[0][j] = puzzleBoard[0][j];
	}
}

void PuzzleEngine::loadBoard(int row, string rowData) {
	//LOAD BOTH HINTPUZZLE AND ACTUAL PUZZLEBOARD TO EXTRACT KEYS FROM
	for (int i = 0; i < 15; ++i) {
		this->templateBoard[row][i] = rowData.at(i);
		this->puzzleBoard[row][i] = rowData.at(i);
	}
}



void PuzzleEngine::displayTemplateBoard() {
	this->displayBoard(this->templateBoard);
}

void PuzzleEngine::displayPuzzleBoard() {
	this->displayBoard(this->puzzleBoard);
}


void PuzzleEngine::displayBoard(string(&board)[15][15]) {
	//Display board given by parameter.
	for (int i = -1; i < 16; ++i) {
		cout << endl;
		for (int b = -1; b < 16; ++b) {
			if (i == -1 || i == 15 || b == -1 || b == 15) {
				cout << char(178);
				continue;
			}
			string keyWord = board[i][b];
			if (keyWord == "X") {
				cout << char(178);
				continue;
			}
			cout << board[i][b];
		}

	}
}

void PuzzleEngine::loadKeyWords() { 
	// FILLS ACTUAL PUZZLE WITH RANDOM STRING CHARACTERS(NUMBERS) DONE.
	for (int i = 0; i < 15; ++i) {
		for (int b = 0; b < 15; ++b) {
			if (puzzleBoard[i][b] != "X") {
				puzzleBoard[i][b] = (char(rand() % 10) + '0');
			}
		}
	}
	
} 

void PuzzleEngine::loadLists() { 
	//Extracts horizontal and vertical keyWords from puzzleBoard.
	//Horizontal List First.
	string currentAppend = "";
	int currentRow = 0;
	for (int row = 0; row < 15; ++row) {
			++currentRow;
		for (int column = 0; column < 15; ++column) {

			if (puzzleBoard[row][column] != "X") {
				currentAppend += puzzleBoard[row][column];
			}
			if(puzzleBoard[row][column] == "X" || column == 14)
			{
				if (currentAppend.length() > 1) {
					KeywordList.push_back(currentAppend);
				}
				currentAppend = "";
			}
		} 
	}
	//Vertical Extraction second.
	for (int column = 0; column < 15; ++column) {
		++currentRow;
		for (int row = 0; row < 15; ++row) {

			if (puzzleBoard[row][column] != "X") {
				currentAppend += puzzleBoard[row][column];
			}
			if (puzzleBoard[row][column] == "X" || row == 14)
			{
				if (currentAppend.length() > 1) {
					KeywordList.push_back(currentAppend);
				}
				currentAppend = "";
			}
		}
	}

}

bool isFirstLessThanSecond(const string& first, const string& second) { //Found @https://www.cplusplus.com/reference/list/list/sort/
	//List's Sorting Algorithm
	if (first.length() == second.length())
		return first < second;

	return(first.length() < second.length());
}

void PuzzleEngine::printKeys() {
	//Prints keyWords from engine's list.
	this->KeywordList.sort(isFirstLessThanSecond);
	int length = 4;
	for (string i : this->KeywordList) {
		if (i.length() > length) {
			cout << endl;
			length = i.length();
		}
		cout << i << endl;
	}

}


void PuzzleEngine::run() {
	cout << "======================CROSSNUMBER PUZZLE MADE BY JUSTIN BURNS 4/9/2022=============================";
	this->setUpPuzzle(); // Loads templateBoard with default given Template.
	this->loadKeyWords(); // Loads puzzleBoard with keyWords ( second board printed filled ).
	this->loadHint(); // Appends first keyWord onto templateBoard as a hint before displaying.
	this->displayTemplateBoard(); // Displays templateBoard
	this->loadLists(); // Fills list with vert and horiz keyWords. 
	cout << endl << endl; 
	this->printKeys(); // Prints keyWord list.
	this->displayPuzzleBoard(); // Displays puzzleBoard.
	cout << endl;
	cout << endl;
}
