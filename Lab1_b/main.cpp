/** \file main.cpp
* \brief A small drawing program.
* \details  The program takes user inputs or generates random values to make a horizontal line, vertical line, rectangle, square, triangle,
* or assortment of shapes.
* \author Angela Lyman
* \version 0.1
* \date 03/03/2023
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;

// Function prototypes
void horizontalLine(const int, const char);
void verticalLine(const int, const char);
void square(const int, const char);
void rectangle(const int, const int, const char);
void triangle(const int, const char);
void drawShapes();
void initializeArrays(int[], int[], char[], const int);
void drawShapesWithArrays(const int[], const int[], const char[], const int);

// Declaring constants
const int MAX_SHAPES = 10;
const int MIN_SHAPE_LENGTH = 1;
const int MIN_SHAPE_HEIGHT = 1;
const int MAX_SHAPE_LENGTH_RANGE = 20;
const int MAX_SHAPE_HEIGHT_RANGE = 20;

/**
* Function <code>main</code> presents the menu and calls the requested functionality.
*<BR>
* @return Returns <code>0</code>.
*/
int main() {
    
    const int MAX_ARRAY = 10;
    
    int choice, length, height;
    char symbol;
    
    int shapeType[MAX_ARRAY], shapeLength[MAX_ARRAY];
    char shapeChar[MAX_ARRAY];
    
    srand(static_cast<unsigned int>(time(NULL)));
    
    do {
        // The Options Menu
        cout << "1) Draw a horizontal line" << endl;
        cout << "2) Draw a vertical line" << endl;
        cout << "3) Draw a square" << endl;
        cout << "4) Draw a rectangle" << endl;
        cout << "5) Draw a triangle" << endl;
        cout << "6) Draw " << MAX_SHAPES << " random shapes" << endl;
        cout << "7) Draw random shapes using arrays" << endl;
        cout << "8) Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                do {
                    cout << "Enter the length of the line (must be greater than 0): ";
                    cin >> length;
                } while (length < 1);
                
                cout << "Enter the symbol you want: ";
                cin >> symbol;
                
                horizontalLine(length, symbol);
                cout << endl;
                
                break;
                
            case 2:
                do {
                    cout << "Enter the height of the line (must be greater than 0): ";
                    cin >> height;
                } while (height < 1);
                
                cout << "Enter the symbol you want: ";
                cin >> symbol;
                
                verticalLine(height, symbol);
                cout << endl;
                
                break;
                
            case 3:
                do {
                    cout << "Enter the length of the square (must be greater than 0): ";
                    cin >> length;
                } while (length < 1);
                
                cout << "Enter the symbol you want: ";
                cin >> symbol;
                
                square(length, symbol);
                cout << endl;
                
                break;
                
            case 4:
                do {
                    cout << "Enter the length of the rectangle (must be greater than 0): ";
                    cin >> length;
                } while (length < 1);
                
                do {
                    cout << "Enter the height of the rectangle (must be greater than 0): ";
                    cin >> height;
                } while (height < 1);
                
                cout << "Enter the symbol you want: ";
                cin >> symbol;
                
                rectangle(length, height, symbol);
                cout << endl;
                
                break;
                
            case 5:
                do {
                    cout << "Enter the height of the triangle (must be greater than 0): ";
                    cin >> height;
                } while (height < 1);
                
                cout << "Enter the symbol you want: ";
                cin >> symbol;
                
                triangle(height, symbol);
                cout << endl;
                
                break;
                
            case 6:
                drawShapes();
                cout << endl;
                
                break;
                
            case 7:
                initializeArrays(shapeType, shapeLength, shapeChar, MAX_ARRAY);
                drawShapesWithArrays(shapeType, shapeLength, shapeChar, MAX_ARRAY);
                cout << endl;
                
                break;
                
            case 8:
                break; // no code needed here
                
            default:
                cerr << "Invalid input." << endl << endl;
                
                break;
                
        }
    } while (choice != 8);
    
    cout << "Goodbye!" << endl;
    
    return 0;
}

/**
* Function <code>horizontalLine</code> Creates a horizontal line with a length and symbol that the user gives
* <BR>
* @param length The length of the line (>= 1)
* @param symbol The symbols used to print the line, must be a printable ASCII character [33 - 126].
*/
void horizontalLine(const int length, const char symbol) {
    assert(length > 0);
    assert(symbol > 32 && symbol < 127); // only printable characters
    
    for (int i = 0; i < length; i++) {
        cout << symbol;
    }
    cout << endl;
}

/**
* Function <code>verticalLine</code> Creates a vertical line with a height and symbol that the user gives
* <BR>
* @param height The height of the line (>= 1)
* @param symbol The symbols used to print the line, must be a printable ASCII character [33 - 126].
*/
void verticalLine(const int height, const char symbol) {
    assert(height > 0);
    assert(symbol > 32 && symbol < 127);
    
    for (int i = 0; i < height; i++) {
        cout << symbol << endl;
    }
}

/**
* Function <code>rectangle</code> Creates an unfilled rectangle with a length, height, and symbol that the user gives.
* <BR>
* @param length The length of the rectangle (>= 1)
* @param height The height of the rectangle (>= 1)
* @param symbol The symbols used to print the line, must be a printable ASCII character [33 - 126].
*/
void rectangle(const int length, const int height, const char symbol) {
    assert(length > 0);
    assert(height > 0);
    assert(symbol > 32 && symbol < 127);
    
    // creates the first line of the rectangle, which is a solid line
    horizontalLine(length, symbol);
    
    // if the user-inputted height is sufficient (>2), create the middle section
    for (int i = 0; i < height-2; i++) {
        cout << symbol;
        for (int j = 0; j < length-2; j++) {
            cout << " ";
        }
        cout << symbol << endl;
    }
    
    // if the height is sufficient (>1), creates the last line of the rectangle, which is a solid line
    if (height > 1) {
        horizontalLine(length, symbol);
    }
    
}

/**
* Function <code>square</code> Creates an unfilled square using the rectangle function, where both length and height are the same
* <BR>
* @param length The length of the square (>= 1)
* @param symbol The symbols used to print the line, must be a printable ASCII character [33 - 126].
*/
void square(const int length, const char symbol) {
    rectangle(length, length, symbol);
}

/**
* Function <code>square</code> Creates an unfilled triangle with a user-inputted height and symbol.
* <BR>
* @param height The number of rows of the triangle (>= 1)
* @param symbol The symbols used to print the line, must be a printable ASCII character [33 - 126].
*/
void triangle(const int height, const char symbol) {
    assert(height > 0);
    assert(symbol > 32 && symbol < 127);
    
    // creates each row of the triangle except the last one
    for (int i = 1; i <= height; i++) {
        // creates spaces to centre the triangle
        for (int j = i; j < height; j++) {
            cout << " ";
        }
        // for the 2 * height - 1 maximum characters in each row, the program outputs a symbol if it is a border character and spaces otherwise, except a row of symbols on the last line.
        for (int k = 1; k <= (2 * height - 1); k++) {
            if (k == 1 || k == (2 * i - 1) || i == height) {
                cout << symbol;
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

/**
* Function <code>drawShapes</code> draws a random assortment of shapes with random lengths, heights, and symbols.
*/
void drawShapes() {
    
    // creates the correct amount of shapes
    for (int i = 0; i < MAX_SHAPES; i++) {
        
        int shape = 1 + rand() % 5;
        int length, height;
        
        length = MIN_SHAPE_LENGTH + rand() % MAX_SHAPE_LENGTH_RANGE;
        height = MIN_SHAPE_HEIGHT + rand() % MAX_SHAPE_HEIGHT_RANGE;
        
        // creates a random printable character
        char symbol = 33 + rand() % (126-33+1);
        
        // creates a shape based on the random number from 1-5 assigned to int shape.
        if (shape == 1) {
            horizontalLine(length, symbol);
            cout << endl;
        }
        else if (shape == 2) {
            verticalLine(length, symbol);
        }
        else if (shape == 3) {
            square(length, symbol);
            cout << endl;
        }
        else if (shape == 4) {
            rectangle(length, height, symbol);
        }
        else if (shape == 5) {
            triangle(height, symbol);
        }
        else {
            assert(false); // should not be possible
        }
        
    }
}

/**
* Function <code>initializeArrays</code> randomly generates the characteristics of shapes and stores them in arrays which are passed in.
* <BR>
* @param shapeTy The type of shape, values in array range from 1 - 5
* @param shapeLen The length of the shape, values in array range from 1 - 20
* @param shapeCh The symbols used to print the line, values in array range from 33 - 126 (printable characters).
* @param size The size of the arrays [>= 1]
*/
void initializeArrays(int shapeTy[], int shapeLen[], char shapeCh[], const int size) {
    assert(size > 0);
    
    for (int i = 0; i < size; i++) {
        shapeTy[i] = 1 + rand() % 5;
        shapeLen[i] = MIN_SHAPE_LENGTH + rand() % MAX_SHAPE_LENGTH_RANGE;
        shapeCh[i] = 33 + rand() % 94;
    }
}

/**
* Function <code>drawShapes</code> prints an assortment of shapes with random lengths, heights, and symbols from the arrays initialized previously.
* <BR>
* @param shapeTy The type of shape, values in array range from 1 - 5
* @param shapeLen The length of the shape, values in array range from 1 - 20
* @param shapeCh The symbols used to print the line, values in array range from 33 - 126 (printable characters).
* @param size The size of the arrays [>= 1]
*/
void drawShapesWithArrays(const int shapeTy[], const int shapeLen[], const char shapeCh[], const int size) {
    
    for (int i = 0; i < size; i++) {
        if (shapeTy[i] == 1) {
            horizontalLine(shapeLen[i], shapeCh[i]);
            cout << endl;
        }
        else if (shapeTy[i] == 2) {
            verticalLine(shapeLen[i], shapeCh[i]);
        }
        else if (shapeTy[i] == 3) {
            square(shapeLen[i], shapeCh[i]);
            cout << endl;
        }
        else if (shapeTy[i] == 4) {
            rectangle(shapeLen[i], (MIN_SHAPE_LENGTH + rand() % MAX_SHAPE_LENGTH_RANGE), shapeCh[i]);
        }
        else if (shapeTy[i] == 5) {
            triangle(shapeLen[i], shapeCh[i]);
        }
        else {
            assert(false); // should not be possible
        }
            
    }
}
