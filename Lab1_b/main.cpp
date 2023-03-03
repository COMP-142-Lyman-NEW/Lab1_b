/** \file main.cpp
* \brief A small drawing program.
* \details  The program takes user inputs or generates random values to make a horizontal line, vertical line, rectangle, square, triangle,
* or assortment of shapes.
* \author Angela Lyman
* \version 0.1
* \date March 3, 2023
* \copyright N/A
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function prototypes
void horizontalLine(int, char);
void verticalLine(int, char);
void square(int, char);
void rectangle(int, int, char);
void triangle(int, char);
void drawShapes();

// Declaring constants
const int MAX_SHAPES = 10;
const int MIN_SHAPE_LENGTH = 2;
const int MIN_SHAPE_HEIGHT = 2;
const int MAX_SHAPE_LENGTH = 20;
const int MAX_SHAPE_HEIGHT = 20;

/**
* Function <code>main</code> presents the menu and calls the requested functionality.
*<BR>
* @return Function returns <code>0</code>.
*/
int main() {
    
    int choice;
    int length;
    int height;
    char symbol;
    
    do {
        // The Options Menu
        cout << "1) Draw a horizontal line" << endl;
        cout << "2) Draw a vertical line" << endl;
        cout << "3) Draw a square" << endl;
        cout << "4) Draw a rectangle" << endl;
        cout << "5) Draw a triangle" << endl;
        cout << "6) Draw 10 random shapes" << endl;
        cout << "7) Quit" << endl;
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
                    cout << "Enter the length of the square (must be greater than 1): ";
                    cin >> length;
                } while (length < 2);
                
                cout << "Enter the symbol you want: ";
                cin >> symbol;
                
                square(length, symbol);
                cout << endl;
                
                break;
                
            case 4:
                do {
                    cout << "Enter the length of the rectangle (must be greater than 1): ";
                    cin >> length;
                } while (length < 2);
                
                do {
                    cout << "Enter the height of the rectangle (must be greater than 1): ";
                    cin >> height;
                } while (height < 2);
                
                cout << "Enter the symbol you want: ";
                cin >> symbol;
                
                rectangle(length, height, symbol);
                cout << endl;
                
                break;
                
            case 5:
                do {
                    cout << "Enter the height of the triangle (must be greater than 1): ";
                    cin >> height;
                } while (height < 2);
                
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
                break; // no code needed here
                
            default:
                cout << "Invalid input." << endl;
                
                break;
        }
    } while (choice != 7);
    
    cout << "Goodbye!" << endl;
    
    return 0;
}

/**
* Function <code>horizontalLine</code> Creates a horizontal line with a length and symbol that the user gives
* <BR>
* @param length The length of the line (>= 1)
* @param symbol The symbols used to print the line, must be a printable ASCII character [33 - 126].
*/
void horizontalLine(int length, char symbol) {
    
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
void verticalLine(int height, char symbol) {
    
    for (int i = 0; i < height; i++) {
        cout << symbol << endl;
    }
}

/**
* Function <code>rectangle</code> Creates an unfilled rectangle with a length, height, and symbol that the user gives.
* <BR>
* @param length The length of the rectangle (>= 2)
* @param height The height of the rectangle (>= 2)
* @param symbol The symbols used to print the line, must be a printable ASCII character [33 - 126].
*/
void rectangle(int length, int height, char symbol) {
    
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
    
    // creates the last line of the rectangle, which is a solid line
    horizontalLine(length, symbol);
    
}

/**
* Function <code>square</code> Creates an unfilled square using the rectangle function, where both length and height are the same
* <BR>
* @param length The length of the square (>= 2)
* @param symbol The symbols used to print the line, must be a printable ASCII character [33 - 126].
*/
void square(int length, char symbol) {
    rectangle(length, length, symbol);
}

/**
* Function <code>square</code> Creates an unfilled triangle with a user-inputted height and symbol.
* @param height The number of rows of the triangle (>= 2)
* @param symbol The symbols used to print the line, must be a printable ASCII character [33 - 126].
*/
void triangle(int height, char symbol) {
    
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
    
    // seeds the random numbers to time, making them truly random
    srand(time(NULL));
    
    // creates the correct amount of shapes
    for (int i = 0; i < MAX_SHAPES; i++) {
        
        int shape = 1 + rand() % 5;
        int length, height;
        
        // if the shape is not a line, the length and height should be greater than the minimum (2)
        if (shape > 2) {
            length = MIN_SHAPE_LENGTH + rand() % MAX_SHAPE_LENGTH;
            height = MIN_SHAPE_HEIGHT + rand() % MAX_SHAPE_HEIGHT;
        }
        // if the shape is a line, length and height can be as low as 1
        else {
            length = 1 + rand() % MAX_SHAPE_LENGTH;
            height = 1 + rand() % MAX_SHAPE_HEIGHT;
        }
        
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
        
    }
}
