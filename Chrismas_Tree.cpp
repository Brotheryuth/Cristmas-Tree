#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
} 
void hideCursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}
void MoveToTop(){
	cout << "\033[H";
}
void printPyramid(int n, int colors[], int numColors) {
    for (int i = 1; i <= n; i++) {
        // Print spaces for alignment
        for (int j = i; j <= n; j++) {
            cout << " ";
        }
        // Print colored stars
        for (int j = 1; j <= 2 * i - 1; j++) {
            int randomColor = colors[rand() % numColors];
            setColor(randomColor);
            cout << "*";
        }
        cout << endl;
    }
}

void printTrunk(int n) {
    setColor(6);
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= n - 2; j++) {
            cout << " ";
        }
        cout << "|_-_|" << endl;
    }
}

void printGreeting(int colors[], int numColors) {
    setColor(colors[rand() % numColors]);
    cout << "\tMERRY";
    setColor(colors[rand() % numColors]);
    cout << " CHRISTMAS" << endl;
    setColor(colors[rand() % numColors]);
    cout << "\t Ho Ho Ho!" << endl;
}

int main() {
    int n;
    srand(time(0));
    
    int colors[] = {1, 2, 3, 4, 5, 6, 9, 10, 11, 12, 13, 14, 15};
    int numColors = 13;
    
    cout << "Enter the size of pyramid: ";
    cin >> n;
    
    system("cls");
    
    printPyramid(n, colors, numColors);
    printTrunk(n);
    printGreeting(colors, numColors);
    setColor(15);
    cout << "\n(Press Ctrl+C to stop)" << endl;

    while (true) {
        Sleep(100); //collor speed 
        hideCursor();
        MoveToTop();
        printPyramid(n, colors, numColors);
        printTrunk(n);
        printGreeting(colors, numColors);
        setColor(15);
        cout << "\n(Press Ctrl+C to stop)" << endl;
    }
    
    return 0;
}