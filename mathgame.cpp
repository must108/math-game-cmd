#include <iostream>
#include <windows.h>
#include <unistd.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#define MAX 12;
using namespace std;

int MathGame(char beginning){
    int actual, user = 0, x, y, counter = 0, score = 0, diff;
    char c;

    while (counter == 0 || counter == -1){
        srand(time(NULL));

        if(beginning == '+'){
            x = 1 + rand() % 100;
            y = 1 + rand() % 100;

            cout << x << " plus " << y << "?" << endl;
            cin >> user;
            actual = x+y;
            diff = abs(user-(x+y));
        } else if(beginning == '-'){
            x = 1 + rand() % 100;
            y = 1 + rand() % 100;

            cout << x << " minus " << y << "?" << endl;
            cin >> user;
            actual = x-y;
            diff = abs(user-(x-y));
        } else if(beginning == '*'){
            x = 1 + rand() % MAX;
            y = 1 + rand() % MAX;

            cout << x << " times " << y << "?" << endl;
            cin >> user;
            actual = x*y;
            diff = abs(user-(x*y));
        } else if(beginning == '/'){
            x = 1 + rand() % MAX;
            y = 1 + rand() % MAX;

            cout << x << " divided by " << y << "?" << endl;
            cin >> user;
            actual = x/y;
            diff = abs(user-(x/y));
        } else {
            cout << "Invalid input." << endl;
        }

        if(user < actual){
            cout << "Your answer is " << diff << " less than the correct answer." << endl;
            cout << "Your final score is " << score << "." << endl;
            sleep(4);
            system("cls");
            cout << "Would you like to play again? (Y/N)" << endl;
            cin >> c;
            if (c == 'Y'){
                system("cls");
                counter = 0;
                score = 0;
                c == ' ';
            } else {
                system("cls");
                counter += 1;
                cout << "Goodbye!";
                break;
            }
        } else if(user > actual){
            cout << "Your answer is " << diff << " more than the correct answer." << endl;
            cout << "Your final score is " << score << "." << endl;
            sleep(2);
            system("cls");
            cout << "Would you like to play again? (Y/N)" << endl;
            cin >> c;
            if (c == 'Y'){
                system("cls");
                counter = 0;
                score = 0;
                c == ' ';
            } else {
                system("cls");
                counter += 1;
                cout << "Goodbye!";
                break;
            }
        } else {
            cout << "Correct!" << endl;
            usleep(300000);
            system("cls");
            score += 1;
        }
    }
}

int main(){

    char beginning;

    cout << "Welcome to the Math Game!" << endl;
    sleep(1);
    cout << "You can use this game to practice basic math problems." << endl;
    sleep(1);
    cout << "+ : Addition, - : Subtraction, * : Multiplication, / : Division" << endl;
    cin >> beginning;
    MathGame(beginning);

    return 0;
}

