#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

string getDirection(int iDirection)
{
    string sDirection;
    switch (iDirection)
    {
        case 1:
            sDirection = "N";
            break;
        case 2:
            sDirection = "NE";
            break;
        case 3:
            sDirection = "E";
            break;
        case 4:
            sDirection = "SE";
            break;
        case 5:
            sDirection = "S";
            break;
        case 6:
            sDirection = "SW";
            break;
        case 7:
            sDirection = "W";
            break;
        case 8:
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

    char getChar(int rowIndex, int columnIndex);

    char getChar(int rowIndex, int columnIndex) const;

    string getWord(int rowIndex, int columnIndex, int direction, int stringLength) const;
};

Grid::Grid(const char *fileName)
{
    ifstream inputFile(fileName);
    int r, c;
    inputFile >> r >> c;
    numRows = r, numColumns = c;
    grid = new char[numRows * numColumns + 1];
    for (int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j < numColumns; ++j)
        {
            inputFile >> grid[i * numRows + j];
        }
    }
    grid[numRows * numColumns] = '\0';
}

string Grid::getWord(int rowIndex, int columnIndex, int direction, int stringLength) const
{
    char word[stringLength + 1];
    for (int i = 0; i < stringLength; ++i)
    {
        // start from North, go clockwise
        switch (direction)
        {
            case 1:
                word[i] = getChar(rowIndex - i, columnIndex);
                break;
            case 2:
                word[i] = getChar(rowIndex - i, columnIndex + i);
                break;
            case 3:
                word[i] = getChar(rowIndex, columnIndex + i);
                break;
            case 4:
                word[i] = getChar(rowIndex + i, columnIndex + i);
                break;
            case 5:
                word[i] = getChar(rowIndex + i, columnIndex);
                break;
            case 6:
                word[i] = getChar(rowIndex + i, columnIndex - i);
                break;
            case 7:
                word[i] = getChar(rowIndex, columnIndex - i);
                break;
            case 8:
                word[i] = getChar(rowIndex - i, columnIndex - i);
                break;
            default:
                break;
        }
    }
    word[stringLength] = '\0';
    return string(word);
}

char Grid::getChar(int rowIndex, int columnIndex)
{
    return grid[rowIndex * numColumns + columnIndex];
}

char Grid::getChar(int rowIndex, int columnIndex) const
{
    return grid[rowIndex * numColumns + columnIndex];
}

class HashTable
{
public:
    HashTable();

    void insert(string &data);
};

HashTable::HashTable()
{
    // TODO
}

void HashTable::insert(string &data)
{
    // TODO
}

int main(int argc, char *argv[])
{
    string dictionaryFileName = argv[1];
    ifstream dictionary(dictionaryFileName);
    HashTable ht;
    string line;
    while (dictionary >> line)
    {
        ht.insert(line);
    }

    Grid grid(argv[2]);
    // S (0, 1):	ban
    cout << left << setw(2) << getDirection(5) << "(" << 0 << ", " << 1 << ")"
         << ":\t" << grid.getWord(0, 1, 5, 3) << endl;
    return 0;
}
