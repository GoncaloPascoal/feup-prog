/*
	DISCLAIMER: This is a solution to an exam exercise and is not meant to be run as source code.
	I considered that line and column numbers start at 1 and because of that subtracted 1 from the line and
	column values to get the correct indexes for the two-dimensional vector.
*/

/* 2A
The board constructor has default values for its parameters (numLines and numColumns). That means we can
declare Board b without giving any arguments to the constructor (the default values will be used).
On the other hand, the Ship class has only one constructor with five parameters, meaning we must pass 
those values when we create a Ship object (we can't simply do Ship s).
*/

Board(size_t numLines = 10, size_t numColumns = 10) {
	vector<int> tempCol(numColumns, -1);
	vector<vector<int>> tempBoard(numLines, tempCol);
	board = tempBoard;
}

bool Board::canPutShip(Position pos, char dir, size_t size) {
	switch(dir){
	case 'H':
		if (pos.col - 1 + size > board[0].size()) {		// Ship extends beyond the board
			return false;
		}
		int lineIndex = pos.lin - 1;
		int colIndex = pos.col - 1;
		for (int i = colIndex; i < colIndex + size; i++) {
			if (board[lineIndex][i] != -1) {
				return false;
			}
		}
		break;
	case 'V':
		// DONE
		break;
	}
	return true;
}

bool Board::putShip(const Ship &s) {
	Position shipPos = s.pos();
	char shipDir = s.dir();
	size_t shipSize = s.size();
	
	if (!canPutShip(shipPos, shipDir, shipSize)) {
		return false;
	}
	
	unsigned int shipId = s.id();
	int lineIndex = shipPos.lin - 1;
	int colIndex = shipPos.col - 1;
	
	switch(shipDir) {
	case 'H':
		for (int i = colIndex; i < colIndex + shipSize; i++) {
			board[lineIndex][i] = shipId;
		}
		break;
	case 'V':
		for (int i = lineIndex; i < lineIndex + shipSize; i++) {
			board[i][colIndex] = shipId;
		}
		break;
	}
	
	ships.push_back(s);
	
	return true;
}

int main() {
	Board b(10, 20);
	
	unsigned int id;
	Position pos;
	char symbol, dir;
	size_t size;
	
	cout << "Enter ship info\n";
	cout << "ID: "; cin >> id;
	cout << "Symbol: "; cin >> symbol;
	cout << "Line: "; cin >> pos.lin;
	cout << "Column: "; cin >> pos.col;
	cout << "Direction (H or V): "; cin >> dir;
	cout << "Size: "; cin >> size;
	
	Ship s(id, symbol, pos, dir, size);
	
	try {
		if (!b.putShip(s)) {
			throw runtime_error("Can't put ship!");
		}
	} catch (runtime_error error) {
		cerr << error.what();
	}
	
	
	return 0;
}