#include <fstream>
#include <iomanip>
#include <iostream>
#include "hashTable.hpp"
#include "timer.h"

using namespace std;

string getDirection(int iDirection)
{
    string sDirection;
    switch (iDirection)
    {
        case 0:
            sDirection = "N";
            break;
        case 1:
            sDirection = "NE";
            break;
        case 2:
            sDirection = "E";
            break;
        case 3:
            sDirection = "SE";
            break;
        case 4:
            sDirection = "S";
            break;
        case 5:
            sDirection = "SW";
            break;
        case 6:
            sDirection = "W";
            break;
        case 7:
            sDirection = "NW";
            break;
        default:
            break;
    }
    return sDirection;
}

class Grid
{
    int numRows;
    int numColumns;
    char *grid;
public:
    explicit Grid(const char *fileName);

    int getNumRows() const;

    int getNumColumns() const;

    char &getChar(int rowIndex, int columnIndex);

    char &getChar(int rowIndex, int columnIndex) const;

    string getWord(int rowIndex, int columnIndex, int direction, int stringLength) const;
};

Grid::Grid(const char *fileName)
{
    ifstream inputFile(fileName);
    int row, column;
    inputFile >> row >> column;
    numRows = row, numColumns = column;
    grid = new char[numRows * numColumns + 1];
    for (int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j < numColumns; ++j)
        {
            char c;
            inputFile >> c;
            getChar(i, j) = c;
        }
    }
    grid[numRows * numColumns] = '\0';
}

string Grid::getWord(const int rowIndex, const int columnIndex, const int direction, const int stringLength) const
{
    char word[stringLength + 1];
    for (int i = 0; i < stringLength; ++i)
    {
        // start from North, go clockwise
        switch (direction)
        {
            case 0:
                word[i] = getChar(rowIndex - i, columnIndex);
                break;
            case 1:
                word[i] = getChar(rowIndex - i, columnIndex + i);
                break;
            case 2:
                word[i] = getChar(rowIndex, columnIndex + i);
                break;
            case 3:
                word[i] = getChar(rowIndex + i, columnIndex + i);
                break;
            case 4:
                word[i] = getChar(rowIndex + i, columnIndex);
                break;
            case 5:
                word[i] = getChar(rowIndex + i, columnIndex - i);
                break;
            case 6:
                word[i] = getChar(rowIndex, columnIndex - i);
                break;
            case 7:
                word[i] = getChar(rowIndex - i, columnIndex - i);
                break;
            default:
                break;
        }
    }
    word[stringLength] = '\0';
    return string(word);
}

int Grid::getNumRows() const
{
    return numRows;
}

int Grid::getNumColumns() const
{
    return numColumns;
}

char &Grid::getChar(int rowIndex, int columnIndex)
{
    return grid[rowIndex * numColumns + columnIndex];
}

char &Grid::getChar(int rowIndex, int columnIndex) const
{
    return grid[rowIndex * numColumns + columnIndex];
}

int main(int argc, char *argv[])
{
    HashTable ht(argv[1]);
    Grid grid(argv[2]);
    const int numRows = grid.getNumRows();
    const int numColumns = grid.getNumColumns();
    int numWordsFound = 0;
    timer t;
    t.start();
    for (int row = 0; row < numRows; ++row)
    {
        for (int col = 0; col < numColumns; ++col)
        {
            for (int dir = 0; dir < 8; ++dir)
            {
                for (int length = 3; length <= numRows && length <= numColumns; ++length)
                {
                    if ((dir == 7 || dir == 0 || dir == 1) && (row - length < -1))
                    {
                        continue;
                    }
                    if ((dir == 1 || dir == 2 || dir == 3) && (col + length > numColumns))
                    {
                        continue;
                    }
                    if ((dir == 3 || dir == 4 || dir == 5) && (row + length > numRows))
                    {
                        continue;
                    }
                    if ((dir == 5 || dir == 6 || dir == 7) && (col - length < -1))
                    {
                        continue;
                    }
                    string word = grid.getWord(row, col, dir, length);
                    if (ht.contains(word))
                    {
                        ++numWordsFound;
                        cout << left << setw(2) << getDirection(dir) << "(" << row << ", " << col << ")"
                             << ":\t" << word << endl;
                    }
                }
            }
        }
    }
    t.stop();
    cout << numWordsFound << " words found" << endl;
    cout << "Found all words in " << t << " seconds" << endl;
    return 0;
}
