#include <conio.h>
#include <iostream>
#include <windows.h>
#include <ctime> 
#include <cstdlib>

class date_c {
    public:
        long int day{08};
        int month{08};
        int year{1998};
        long int pos{0};
       
        void set_mmddyyyy() {
            using namespace std;
            int wait(4000);

            short dd(0);
            system("CLS");
        
            while (dd < 01 || dd > 31) {
                
                cout << "Input day (dd): ";
                cin >> dd;
        
                if (dd < 1 || day > 31) {
                  cout << "\n incorrect number. try again.";
                  Sleep(wait);
                  system("CLS");
                }
            }
            day = dd;

            short mm(0);
            system("CLS");
        
            while (mm < 1 || mm > 12) {
                cout << "Input month's number (mm): ";
                cin >>mm;
        
                if (mm < 1 || mm > 12) {
                  cout << "\n incorrect number. try again.";
                  Sleep(wait);
                  system("CLS");
                }
            }
            month = mm;

            int yyyy(1970);
            system("CLS");
        
            cout << "Input year number: ";
            
            int p(2);
        
            while (p != 1) {
                cin >> yyyy;
                system("CLS");
                cout << "\t Year : "<< yyyy << endl;
                cout << "\t   Yes, "<< yyyy << " . . . . . . . press 1" << endl;
                cout << "\t   No, repeat . . . . . . . press 0 \n\n\t";
                cin >> p;
                if (p != 1) {
                    system("CLS");
                    cout << "Input year number: ";
                }
            }
            year = yyyy;
        }

        void write() {
            using namespace std;

            if (day < 10) cout << "0";
            cout << day << "/";
            
            if (month < 10) cout << "0";
            cout << month << "/";
            
            cout << year;
        }

        /*
        bool checkReal() {

            //в високостном 29, в отстальных - 28
            if ( !( (year % 400) == 0 || (year % 4) == 0) ) {
                if (month == 2 && day > 28) return false;
            } else if ( (year % 400) == 0 || (year % 4) == 0) {
                if (month == 2 && day > 29) return false;
            }
            //проверка количества дней в месяцах, кроме февраля
            if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
                if (day > 31) return false;
            } else if (month == 4 || month == 6 || month == 9 || month == 11) {
                if (day > 30) return false;
            }

         return true;
        }
        */

        int mmd(int mm, int yy) { //высчитывает счколько дней в месяце, необходим для date();
            const short mmd_array[13] {0,31,0,31,30,31,30,31,31,30,31,30,31};
            if (mm == 2) {
                if (!( (yy % 400) == 0 || (yy % 4) == 0) ) { 
                    return 28; 
                } else if (mm == 2 && ( (yy % 400) == 0 || (yy % 4) == 0)) {
                    return 29;
                }
            } else if (mm != 2) {
                return mmd_array[mm];
            }
        }

        void date(int pos) {  //высчитывает и выводит дату на экран
                                //для работы необходим mmd() и pos;
            
            day += pos;
            while (day > mmd(month,year) || month > 12) {
                if ( day > mmd(month,year) ) {
                    day -= mmd(month,year);
                    month++;
                }
                if (month > 12) {
                    year++;
                    month = 1;
                }
            }
        }

        void datePlusPos() {

            //set_mmddyyyy();
            day = 08;
            month = 08;
            year = 1998;

            std::cout << "Enter a day's Amount: ";
            std::cin >> pos;

            day += pos;
            while (day > mmd(month,year) || month > 12) {
                if ( day > mmd(month,year) ) {
                    day -= mmd(month,year);
                    month++;
                }
                if (month > 12) {
                    year++;
                    month = 1;
                }
            }

            write();
        }
};

int main() {
    date_c date_loo;
        while(1) {
    date_loo.datePlusPos();
    Sleep(5000);
        }
    _getwch();
    return 0;
}

