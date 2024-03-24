#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>
using namespace std;

int main() {
    
    int secret_number, score, choice, id, password, password_check, user_id, user_password;
    string name;

    while (true) {
        system("clear");
        cout << "Welcome to Number Guessing Game" << endl;
        cout << "--------------------------------" << endl;
        cout << "Choose an option:" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                system("clear");
                cout << "Enter Your SAP ID: ";
                cin >> id;
                cout << "Enter Your Password: ";
                cin >> password;
                
                if (id == user_id && password == user_password) {
                    system("clear");


                    srand(time(NULL));
                    secret_number = rand() % 100 + 1;
                    
                    
                    for (score = 100; score > 0; score -= 10) {
                        int user_guess;
                        cout << endl << "Please choose any number between 1 to 100: ";
                        cin >> user_guess;
                        
                        if (user_guess == secret_number) {
                            cout << endl << "Congratulations! " << name << " Your guess " << user_guess << " is correct! Your score is " << score << " out of 100." << endl;
                            break;
                        } else if (user_guess > secret_number) {
                            if (user_guess > secret_number + 10) {
                                cout << endl << "Your guess is too far from the correct number." << endl;
                            } else {
                                cout << endl << "Your guess is greater than the correct number within the range of 10 numbers" << endl;
                            }
                        } else {
                            if (user_guess > secret_number - 10) {
                                cout << endl << "Your guess is lesser than the correct number within the range of 10 numbers" << endl;
                            } else {
                                cout << endl << "Your guess is too far from the correct number" << endl;
                            }
                        }
                    }
                    
                    if (score == 0) {
                        cout << endl << "Sorry! " << name << " You have used all of your attempts. Your score is 0 out 100." << endl;   
                    }
                    cout << endl << "Press <Enter> to continue...";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get();
                    break;
                } else {
                    cout << "Wrong ID or Password! Please try again." << endl;
                }
                break;
                
            case 2:
                system("clear");
                cout << endl << "Enter Your Name: ";
                cin >> name;
                cout << endl << "Enter Your ID: ";
                cin >> id;
                cout << endl << "Enter Your Password: ";
                cin >> password;
                cout << endl << "Confirm Your Password: ";
                cin >> password_check;
                
                if (password_check == password) {
                    user_id = id;
                    user_password = password;
                } else {
                    cout << "Passwords do not match! Please try again." << endl;
                    cin.get();
                }
                
                break;
                
            case 3:
                exit(1);
                break;
                
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    }
    return 0;
}
