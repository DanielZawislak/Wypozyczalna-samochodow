#include <iostream>
#include<windows.h>
#include<mysql.h>
#include <sstream>
#include<stdio.h>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include<conio.h>
#include <math.h>
#include<iomanip>

using namespace std;

MYSQL* connect(){

    MYSQL* conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "", "samochody", 0, NULL, 0);

    if(!conn){

        cout<<"Nieprawidlowe polaczenie z baza";
        exit(0);
        return 0;

    }
    else
        return conn;

}



