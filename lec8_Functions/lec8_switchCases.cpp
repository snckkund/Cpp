// Switch cases
#include <iostream>
using namespace std;

int main() {
    // // - 1
    // int n = 2;
    // switch (n) {
    //     case 1:
    //         cout << "1st case" << endl;
    //         break;
    //     case 2:
    //         cout << "2nd case" << endl;
    //         break;
    //     default :
    //         cout << "default case";
    // }

    // // - 2
    // int n = '1';
    // switch (n) {
    //     case 1:
    //         cout << "1st case" << endl;
    //         break;
    //     case '1':
    //         cout << "2nd case '1'" << endl;
    //         break;
    //     default :
    //         cout << "default case";
    // }

    // // exit from infinite loop without break statement
    // int choice;
    // while (true) { // Infinite loop
    //     std::cout << "Enter a number (1 to 3), or 0 to exit: ";
    //     std::cin >> choice;

    //     switch (choice) {
    //         case 1:
    //             std::cout << "You chose 1\n";
    //             break;
    //         case 2:
    //             std::cout << "You chose 2\n";
    //             break;
    //         case 3:
    //             std::cout << "You chose 3\n";
    //             break;
    //         case 0:
    //             std::cout << "Exiting...\n";
    //             goto end_loop; // Use a goto statement to exit the loop
    //         default:
    //             std::cout << "Invalid choice\n";
    //             break;
    //         }
    //     }
    // end_loop: // Label to jump to for breaking out of the loop
    //     return 0;

    // int choice;
    // while (true) { // Infinite loop
    //     std::cout << "Enter a number (1 to 3), or 0 to exit: ";
    //     std::cin >> choice;

    //     switch (choice) {
    //         case 1:
    //             std::cout << "You chose 1\n";
    //             break;
    //         case 2:
    //             std::cout << "You chose 2\n";
    //             break;
    //         case 3:
    //             std::cout << "You chose 3\n";
    //             break;
    //         case 0:
    //             std::cout << "Exiting...\n";
    //             return 0; // Exit the program
    //         default:
    //             std::cout << "Invalid choice\n";
    //             break;
    //     }
    // }

    // // calculator
    // int a,b,op;
    // cout << "enter 'a': ";
    // cin >> a;
    // cout << "enter 'b': ";
    // cin >> b;
    // cout << "=======choose=======" << endl;
    // cout << " '+' --> 1 \n '-' --> 2 \n '*' --> 3 \n '/' --> 4" << endl;
    // cout << "====================" << endl;
    // cout << "your choice: ";
    // cin >> op;
    // switch (op) {
    //     case 1:
    //         cout << a << "+" << b << "=" << a+b;
    //         break;
    //     case 2:
    //         cout << a << "-" << b << "=" << a-b;
    //         break;
    //     case 3:
    //         cout << a << "*" << b << "=" << a*b;
    //         break;
    //     case 4:
    //         cout << a << "/" << b << "=" << a/b;
    //         break;
    //     default:
    //         cout << "invalid input";
    // }

    /*  how many change of notes it will take to get me a particular value of money
        with options (₹ 500, 100, 50, 20, 10, 5, 2, 1) notes/coins
        for ex: ₹ 1331 requires: 2x 500, 3x 100, 1x 20, 1x 10, 1x 1 {h/w} 
        @Homework    
    */
    cout << "Enter a value: ";
    int rup;
    int c_500=0, c_200=0, c_100=0, c_50=0, c_20=0, c_10=0, c_5=0, c_2=0, c_1=0;
    cin >> rup;
    
    int temp = rup;

    switch (500) {
        case 500:
            if (temp >= 500) {
                c_500 = temp / 500;
                temp %= 500;
                if (c_500 !=0) {
                    cout << " - " << c_500 << "x Rs500 = " << c_500 * 500 << endl;
                }
            }
        case 200:
            if (temp >= 200) {
                c_200 = temp / 200;
                temp %= 200;
                if (c_200 !=0) {
                    cout << " - " << c_200 << "x Rs200 = " << c_200 * 200 << endl;
                }
            }
        case 100:
            if (temp >= 100) {
                c_100 = temp / 100;
                temp %= 100;
                if (c_100 !=0) {
                    cout << " - " << c_100 << "x Rs100 = " << c_100 * 100 << endl;
                }
            }
        case 50:
            if (temp >= 50) {
                c_50 = temp / 50;
                temp %= 50;
                if (c_50 !=0) {
                    cout << " - " << c_50 << "x Rs50 = " << c_50 * 50 << endl;
                }
            }
        case 20:
            if (temp >= 20) {
                c_20 = temp / 20;
                temp %= 20;
                if (c_20 !=0) {
                    cout << " - " << c_20 << "x Rs20 = " << c_20 * 20 << endl;
                }
            }
        case 10:
            if (temp >= 10) {
                c_10 = temp / 10;
                temp %= 10;
                if (c_10 !=0) {
                    cout << " - " << c_10 << "x Rs10 = " << c_10 * 10 << endl;
                }
            }
        case 5:
            if (temp >= 5) {
                c_5 = temp / 5;
                temp %= 5;
                if (c_5 !=0) {
                    cout << " - " << c_5 << "x Rs5 = " << c_5 * 5 << endl;
                }
            }
        case 2:
            if (temp >= 2) {
                c_2 = temp / 2;
                temp %= 2;
                if (c_2 !=0) {
                    cout << " - " << c_2 << "x Rs2 = " << c_2 * 2 << endl;
                }
            }
        case 1:
            if (temp >= 1) {
                c_1 = temp / 1;
                temp %= 1;
                if (c_1 !=0) {
                    cout << " - " << c_1 << "x Rs1 = " << c_1 * 1 << endl;
                }
            }
        default:
            break;
    }

    return 0;
}