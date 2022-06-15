// PuzzleEngine.Cpp
// Justin Burns
// CS150
// 3/27/2022
// PuzzleBoard : While generating both a fully filled and partially revealed puzzle board, I must extract vertical and horizontal keyNumbers and display them.
#include "PuzzleEngine.h"
#include <iostream>
#include <string>
#include <fstream>

int main()
{
	srand((unsigned int)time(NULL));
	PuzzleEngine engine;
	engine.run();
}

