#include "connect.h"
#include "query.h"
#include "functions.h"

MYSQL* conn=connect();

int main()
{
    menu:

    system("cls"); //czyszczenie ekranu



    string choose;

    start:
    cout<<"Witam serdecznie, wybierz operacje"<<endl<<endl;
    cout<<"1. Zaloguj sie"<<endl;
    cout<<"2. Zarejestruj sie"<<endl<<endl;
    cout<<"Twoj wybor: ";
    cin>>choose;


    if(choose=="1"){
        if(!login(conn))
            goto menu;
    }

    if(choose=="2"){
                if(regist(conn))

            goto menu;
        }
    else{
        cout<<"Nieprawidlowy wybor, sprobuj jeszcze raz"<<endl;
        Sleep(2000);
        system("cls"); //czyszczenie ekranu
        goto start;
    }

    }


