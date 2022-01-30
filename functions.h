
bool regist(MYSQL* conn){

    MYSQL_ROW row;
    MYSQL_RES* res;
    system( "cls" );
    string login;
    string password,password1;
    string idkonta,idkonta1;

    int unique_code;

    exist_login:
    cout<<"Rozpoczynam proces rejestracji.."<<endl;
    Sleep(2000);
    cout<<"Prosze wpisac swoj login"<<endl;
    cin>>login;

    if(check_if_exist(conn, "users", "login", login )){

        cout<<"Ten login jest zajety. Prosze wpisac inny login"<<endl;
        getch();
        system("cls");
        goto exist_login;

    }

    password:

    cout<<"Podaj haslo"<<endl;
    cin>>password;
    cout<<"Powtorz haslo"<<endl;
    cin>>password1;

    if(password!=password1){

        cout<<"Hasla sie nie zgadzaja"<<endl;
        cout<<"Podaj ponownie haslo"<<endl;
        goto password;

    }



    cout<<"Twoje  dane to:"<<endl;
    cout<<"Login: "<<login<<endl;
    string confirm;
    cout<<"Potwierdzasz zalozenie konta? T/N"<<endl;
    cin>>confirm;
    if(confirm=="T" || confirm=="t" ){

        int qstate = 0, quantity;

        stringstream ss;
        ss << "INSERT INTO `users`(`idkonta`, `login`, `password`,`last_login`) VALUES ('""','" <<login<< "','" <<password<< "','""')";

        string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);

        stringstream ss1;
        ss1 << "SELECT max(id) FROM users";


        if(qstate == 0){

            cout<<"Prawidlowo zarejestrowano konto"<<endl<<"Za chwile zostaniesz przekierowany do menu wyboru"<<endl;
            Sleep(4000);
            system("cls");

            return true;
        }


    }
    else{

        return false;
        system("PAUSE");

    }


}

bool change_password(MYSQL* conn, string login){

    system("cls");
    cout<<"Zmiana hasla"<<endl;

    MYSQL_ROW row;
    MYSQL_RES* res;

    int qstate = 0;
    string bad_password,bad_password1,new_password,new_password1,password;

    cout<<"W celu weryfikacji musisz podac swoje aktualne haslo "<<endl;
    bad_password:
    cout<<"Podaj haslo"<<endl;
    cin>>password;

    stringstream ss;
    ss << "SELECT * FROM users where login= '" << login << "' AND password='" << password << "'  ";

    string query = ss.str();

    const char* q = query.c_str();
    qstate = mysql_query(conn, q);

    res = mysql_store_result(conn);
    row= mysql_fetch_row(res);

    if(row==0){

        cout<<"Nieprawidlowe haslo"<<endl;
        goto bad_password;

    }


    system("cls");
    cout<<"Dane ktore zostaly wprowadzone sa prawidlowe"<<endl;

    cout<<"Podaj nowe haslo"<<endl;
    bad_password1:
    cin>>new_password;
    cout<<"Powtorz nowe haslo"<<endl;
    cin>>new_password1;

    if(new_password1!=new_password){

        cout<<"Hasla sie nie zgadza"<<endl;
        goto bad_password1;
    }else{

        stringstream ss2;
        ss2 << "UPDATE users SET password =  '" << new_password << "' WHERE login = '" << login << "'";
        string query2 = ss2.str();
        const char* q2 = query2.c_str();
        qstate = mysql_query(conn, q2);

        cout<<"Haslo zostalo zmienione, prosze czekac"<<endl;
        Sleep(3000);
        return true;   //Pozwala wrocic do glownego menu

    }

    return false;
}



bool wprowadzenieauta(MYSQL* conn, string idkonta, string login,string marka,string model,string rocznik,string przebieg,string kolor){
    wprowadzenieauta:
    int wybor,n,p;
    string markaa,modell,rocznikk,przebiegg,kolorr,numerkonta,numerodbiorcy,markasprzedaz,modelsprzedaz,roczniksprzedaz,przebiegsprzedaz,kolorsprzedaz;
    cout<<"Wybierz operacje"<<endl;
    cout<<"1. Wprowadzenie samochodu"<<endl;
    cout<<"2. Szybka Sprzedaz samochodu"<<endl;
    cout<<"3. Wyjscie"<<endl;
    cin>>wybor;
    if(wybor==1 || wybor==2)
    {
        MYSQL_ROW row,row1;
        MYSQL_RES* res;
        int qstate = 0;
        stringstream ss1,ss2,ss3,ss4,ss5,ss6;
        ss1 << "SELECT * FROM users where idkonta= '" << idkonta << "'";
        ss2 << "SELECT * FROM users where marka= '" << marka << "'";
        ss3 << "SELECT * FROM users where model= '" << model << "'";
        ss4 << "SELECT * FROM users where rocznik= '" << rocznik << "'";
        ss5 << "SELECT * FROM users where przebieg= '" << przebieg << "'";
        ss6 << "SELECT * FROM users where kolor= '" << kolor << "'";
        string query = ss1.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);

        res = mysql_store_result(conn);
        row= mysql_fetch_row(res);

        char* owner_id=row[0];

            if(wybor==1){

                cout<<"Podaj dane auta: "<<endl;
                cout<<"Podaj marke"<<endl;
                cin>>markaa;


                stringstream ss2;

                 ss2 << "UPDATE users SET marka =  '" << markaa << "' WHERE idkonta = '" << idkonta << "'";


                string query2 = ss2.str();
                const char* q2 = query2.c_str();
                qstate = mysql_query(conn, q2);
                cout<<"Podaj model"<<endl;
                cin>>modell;


                stringstream ss3;

                 ss3 << "UPDATE users SET model =  '" << modell << "' WHERE idkonta = '" << idkonta << "'";


                string query3 = ss3.str();
                const char* q3 = query3.c_str();
                qstate = mysql_query(conn, q3);
                cout<<"Podaj rocznik"<<endl;
                 cin>>rocznikk;

                stringstream ss4;

                 ss4 << "UPDATE users SET rocznik =  '" << rocznikk << "' WHERE idkonta = '" << idkonta << "'";


                string query4 = ss4.str();
                const char* q4 = query4.c_str();
                qstate = mysql_query(conn, q4);
                cout<<"Podaj przebieg"<<endl;
                cin>>przebiegg;

                stringstream ss5;

                 ss5 << "UPDATE users SET przebieg =  '" << przebiegg << "' WHERE idkonta = '" << idkonta << "'";


                string query5 = ss5.str();
                const char* q5 = query5.c_str();
                qstate = mysql_query(conn, q5);
                cout<<"Podaj kolor"<<endl;
                 cin>>kolorr;

                stringstream ss6;

                 ss6 << "UPDATE users SET kolor =  '" << kolorr << "' WHERE idkonta = '" << idkonta << "'";


                string query6 = ss6.str();
                const char* q6 = query6.c_str();
                qstate = mysql_query(conn, q6);


                cout<<"Auto zostalo wprowadzone"<<endl;

                qstate = mysql_query(conn, q);

                res = mysql_store_result(conn);
                row= mysql_fetch_row(res);

                cout<<"Stan pojazdu: "<<row[4]<<" "<<row[5]<<" "<<row[6]<<" "<<row[7]<<" "<<row[8]<<""<<endl;
                getch();

            }



              if(wybor==2)
                {
                stringstream ss0;
                ss0 << "SELECT * FROM users where marka= '" << marka << "'";
                if(marka == ""){                                                      //Sprawdza czy uzytkownik moze sprzedac auto, jesli go nie ma to wraca do menu
                    cout<<"Brak aut";
                    Sleep(3000);
                    return true;
                }

                    cout<<"Podaj id konta osoby ktorej chcesz sprzedac samochod: ";
                    cin>>numerodbiorcy;




                    stringstream ss1,ss2,ss3,ss4,ss5,ss6,ss7,ss8,ss9,ss10;

                 ss1 << "UPDATE users SET marka =  '" << "" << "' WHERE idkonta = '" << idkonta << "'";
                 ss2 << "UPDATE users SET marka =  '" << marka << "' WHERE idkonta = '" << numerodbiorcy << "'";
                 ss3 << "UPDATE users SET model =  '" << "" << "' WHERE idkonta = '" << idkonta << "'";
                 ss4 << "UPDATE users SET model =  '" << model << "' WHERE idkonta = '" << numerodbiorcy << "'";
                 ss5 << "UPDATE users SET rocznik =  '" << "" << "' WHERE idkonta = '" << idkonta << "'";
                 ss6 << "UPDATE users SET rocznik =  '" << rocznik << "' WHERE idkonta = '" << numerodbiorcy << "'";
                 ss7 << "UPDATE users SET przebieg =  '" << "" << "' WHERE idkonta = '" << idkonta << "'";
                 ss8 << "UPDATE users SET przebieg =  '" << przebieg << "' WHERE idkonta = '" << numerodbiorcy << "'";
                 ss9 << "UPDATE users SET kolor =  '" << "" << "' WHERE idkonta = '" << idkonta << "'";
                 ss10 << "UPDATE users SET kolor =  '" << kolor << "' WHERE idkonta = '" << numerodbiorcy << "'";

                string query1 = ss1.str();
                const char* q1 = query1.c_str();
                qstate = mysql_query(conn, q1);
                string query2 = ss2.str();
                const char* q2 = query2.c_str();
                qstate = mysql_query(conn, q2);
                string query3 = ss3.str();
                const char* q3 = query3.c_str();
                qstate = mysql_query(conn, q3);
                string query4 = ss4.str();
                const char* q4 = query4.c_str();
                qstate = mysql_query(conn, q4);
                string query5 = ss5.str();
                const char* q5 = query5.c_str();
                qstate = mysql_query(conn, q5);
                string query6 = ss6.str();
                const char* q6 = query6.c_str();
                qstate = mysql_query(conn, q6);
                string query7 = ss7.str();
                const char* q7 = query7.c_str();
                qstate = mysql_query(conn, q7);
                string query8 = ss8.str();
                const char* q8 = query8.c_str();
                qstate = mysql_query(conn, q8);
                string query9 = ss9.str();
                const char* q9 = query9.c_str();
                qstate = mysql_query(conn, q9);
                string query10 = ss10.str();
                const char* q10 = query10.c_str();
                qstate = mysql_query(conn, q10);

		 cout<<"Trwa sprzedaz auta, prosze czekac.."<<endl;
                Sleep(2000);
                cout<<"Auto zostalo sprzedane";
                Sleep(3000);

                    }



        else{
        cout<<"Dane nieprawidlowe"<<endl;
        getch();
        }


    if(wybor==3)
            {
        return(0);
            }

}

}

bool edycjaauta(MYSQL* conn, string idkonta, string login){
    edycjaauta:
    int wybor,n,p;
    string przebieg,kolor,numerkonta;

    cout<<"Wybierz operacje"<<endl;
    cout<<"1. Edycja samochodu"<<endl;
    cout<<"2. Wyjscie"<<endl;
    cout<<"Twoj wybor"<<endl;
    cin>>wybor;
    if(wybor==1)
    {



        MYSQL_ROW row,row1;
        MYSQL_RES* res;

        int qstate = 0;
        stringstream ss1;
        ss1 << "SELECT * FROM users where idkonta= '" << idkonta << "'";

        string query = ss1.str();

        const char* q = query.c_str();
        qstate = mysql_query(conn, q);

        res = mysql_store_result(conn);
        row= mysql_fetch_row(res);

        char* owner_id=row[0];

            if(wybor==1){

                cout<<"W celu edycji  auta mozesz zmienic przebieg lub kolor "<<endl;
                cout<<"Podaj przebieg"<<endl;
                cin>>przebieg;


                stringstream ss2;

                 ss2 << "UPDATE users SET przebieg =  '" << przebieg << "' WHERE idkonta = '" << idkonta << "'";


                string query2 = ss2.str();
                const char* q2 = query2.c_str();
                qstate = mysql_query(conn, q2);
                 cout<<"Podaj kolor"<<endl;
                cin>>kolor;


                stringstream ss3;

                 ss3 << "UPDATE users SET kolor =  '" << kolor << "' WHERE idkonta = '" << idkonta << "'";


                string query3 = ss3.str();
                const char* q3 = query3.c_str();
                qstate = mysql_query(conn, q3);



                cout<<"Dane zostaly wprowadzone"<<endl;

                qstate = mysql_query(conn, q);

                res = mysql_store_result(conn);
                row= mysql_fetch_row(res);


                getch();

            }





    if(wybor==2)
            {
        return(0);
            }

}

}
bool wyswietlauta(MYSQL* conn, string idkonta, string marka){
    wyswietlauta:
    int wybor;


    stringstream ss0;
                ss0 << "SELECT * FROM users where marka= '" << marka << "'";
                if(marka == ""){                                                              //Sprawdza czy uzytkownik posiada
                    cout<<"Brak aut";
                    Sleep(3000);
                    return true;
                }

    MYSQL_ROW row,row1;
        MYSQL_RES* res;

        int qstate = 0;
        stringstream ss1;
       ss1 << "SELECT * FROM users where idkonta= '" << idkonta << "'";


        string query = ss1.str();

        const char* q = query.c_str();
        qstate = mysql_query(conn, q);


        res = mysql_store_result(conn);
        row= mysql_fetch_row(res);
        cout<<"Posiadany pojazd: "<<endl;
        cout<<"Marka    -> "<<row[4]<<""<<endl;
        cout<<"Model    -> "<<row[5]<<""<<endl;
        cout<<"Rocznik  -> "<<row[6]<<""<<endl;
        cout<<"Przebieg -> "<<row[7]<<""<<endl;
        cout<<"Kolor    -> "<<row[8]<<""<<endl;


    cout<<"1. Wyjscie"<<endl;
    cin>>wybor;


    if(wybor==1)
            {
        return true;
            }

}


bool sprzedaz(MYSQL* conn, string idkonta, string login, string marka){
    sprzedaz:
    int wybor,n,p;
    string model,marka,numerkonta,numerodbiorcy;


    cout<<"Wybierz operacje"<<endl;
    cout<<"1. Sprzedaz samochodu"<<endl;
    cout<<"2. Wyjscie"<<endl;
    cout<<"Twoj wybor"<<endl;
    cin>>wybor;
    if(wybor==1)
    {



        MYSQL_ROW row,row1;
        MYSQL_RES* res;

        int qstate = 0;
        stringstream ss1;
        ss1 << "SELECT * FROM users where idkonta= '" << idkonta << "'";


        string query = ss1.str();

        const char* q = query.c_str();
        qstate = mysql_query(conn, q);

        res = mysql_store_result(conn);
        row= mysql_fetch_row(res);

        char* owner_id=row[0];

            if(wybor==1){




            stringstream ss1,ss2,ss3,ss4,ss5,ss6;

                ss1 << "UPDATE users SET marka =  '" << "" << "' WHERE idkonta = '" << idkonta << "'";
                ss2 << "UPDATE users SET model =  '" << "" << "' WHERE idkonta = '" << idkonta << "'";
                ss3 << "UPDATE users SET rocznik =  '" << "" << "' WHERE idkonta = '" << idkonta << "'";
                ss4 << "UPDATE users SET przebieg =  '" << "" << "' WHERE idkonta = '" << idkonta << "'";
                ss5 << "UPDATE users SET kolor =  '" << "" << "' WHERE idkonta = '" << idkonta << "'";
                ss6 << "INSERT INTO `auta`(`idauta`, `marka`, `model`,`rocznik`,`przebieg`,`kolor`) VALUES ('""','" << row[4]<< "','"<< row[5]<<"','"<< row[6]<<"','"<< row[7]<<"','"<< row[8]<<"')";



                string query1 = ss1.str();
                const char* q1 = query1.c_str();
                qstate = mysql_query(conn, q1);
                string query2 = ss2.str();
                const char* q2 = query2.c_str();
                qstate = mysql_query(conn, q2);
                string query3 = ss3.str();
                const char* q3 = query3.c_str();
                qstate = mysql_query(conn, q3);
                string query4 = ss4.str();
                const char* q4 = query4.c_str();
                qstate = mysql_query(conn, q4);
                string query5 = ss5.str();
                const char* q5 = query5.c_str();
                qstate = mysql_query(conn, q5);
                string query6 = ss6.str();
                const char* q6 = query6.c_str();
                qstate = mysql_query(conn, q6);


                cout<<"Dane zostaly wprowadzone"<<endl;

                qstate = mysql_query(conn, q);

                res = mysql_store_result(conn);
                row= mysql_fetch_row(res);


                getch();

            }


        else{
        cout<<"Dane nieprawidlowe"<<endl;
        getch();
        }


    if(wybor==2)
            {
        return(0);
            }

}

}

bool wynajem(MYSQL* conn, string idauta, string login, string marka, string idkonta){
    sprzedaz:
    int wybor,n,p;
    string model,marka,numerkonta,numerodbiorcy,wprmarka,wprmodel,wprrocznik,wprprzebieg,wprkolor,wpridauta;
        MYSQL_ROW row,row1;
        MYSQL_RES* res;

    for(int cos=24;cos<26;cos++){
        int qstate = 0;
        stringstream ss1;

       ss1 << "SELECT * FROM auta where idauta= '" << cos << "'";


        string query = ss1.str();

        const char* q = query.c_str();
        qstate = mysql_query(conn, q);



        res = mysql_store_result(conn);
        row= mysql_fetch_row(res);


        cout<<"Dostepne auta: "<<endl;
        cout<<"IdAuta -> "<<row[0]<<"";
        cout<<"  Marka -> "<<row[1]<<"";
        cout<<"  Model -> "<<row[2]<<"";
        cout<<"  Rocznik -> "<<row[3]<<"";
        cout<<"  Przebieg -> "<<row[4]<<"";
        cout<<"  Kolor -> "<<row[5]<<""<<endl;


        }


    cout<<"Wybierz operacje"<<endl;
    cout<<"1. Wynajmij samochod"<<endl;
    cout<<"2. Wyjscie"<<endl;
    cout<<"Twoj wybor: ";
    cin>>wybor;
    if(wybor==1)
    {







        int qstate = 0;
        stringstream ss1;
        ss1 << "SELECT * FROM users where idkonta= '" << idkonta << "'";


        string query = ss1.str();

        const char* q = query.c_str();
        qstate = mysql_query(conn, q);

        res = mysql_store_result(conn);
        row= mysql_fetch_row(res);

        char* owner_id=row[0];

            if(wybor==1){

            cout<<"Podaj id auta do wynajecia: "<<endl;
            cin>>wpridauta;

            cout<<"Podaj marke"<<endl;
            cin>>wprmarka;
            cout<<"Podaj model"<<endl;
            cin>>wprmodel;
            cout<<"Podaj rocznik"<<endl;
            cin>>wprrocznik;
            cout<<"Podaj przebieg"<<endl;
            cin>>wprprzebieg;
            cout<<"Podaj kolor"<<endl;
            cin>>wprkolor;


            stringstream ss1,ss2,ss3,ss4,ss5,ss6,ss7,ss8,ss9,ss10,ss11;
                ss11 << "UPDATE auta SET idauta =  '" << "" << "' WHERE idauta = '" << wpridauta << "'";
                ss1 << "UPDATE users SET marka =  '" << wprmarka<< "' WHERE idkonta = '" << idkonta << "'";
                ss6 << "UPDATE auta SET marka =  '" << "" << "' WHERE idauta = '" << wpridauta << "'";
                ss2 << "UPDATE users SET model =  '" << wprmodel<< "' WHERE idkonta = '" << idkonta << "'";
                ss7 << "UPDATE auta SET model =  '" << "" << "' WHERE idauta = '" << wpridauta << "'";
                ss3 << "UPDATE users SET rocznik =  '" << wprrocznik<< "' WHERE idkonta = '" << idkonta << "'";
                ss8 << "UPDATE auta SET rocznik =  '" << "" << "' WHERE idauta = '" << wpridauta << "'";
                ss4 << "UPDATE users SET przebieg =  '" << wprprzebieg<< "' WHERE idkonta = '" << idkonta << "'";
                ss9 << "UPDATE auta SET przebieg =  '" << "" << "' WHERE idauta = '" << wpridauta << "'";
                ss5 << "UPDATE users SET kolor =  '" << wprkolor<< "' WHERE idkonta = '" << idkonta << "'";
                ss10 << "UPDATE auta SET kolor =  '" << "" << "' WHERE idauta = '" << wpridauta << "'";






                string query1 = ss1.str();
                const char* q1 = query1.c_str();
                qstate = mysql_query(conn, q1);
                string query2 = ss2.str();
                const char* q2 = query2.c_str();
                qstate = mysql_query(conn, q2);
                string query3 = ss3.str();
                const char* q3 = query3.c_str();
                qstate = mysql_query(conn, q3);
                string query4 = ss4.str();
                const char* q4 = query4.c_str();
                qstate = mysql_query(conn, q4);
                string query5 = ss5.str();
                const char* q5 = query5.c_str();
                qstate = mysql_query(conn, q5);
                string query6 = ss6.str();
                const char* q6 = query6.c_str();
                qstate = mysql_query(conn, q6);
                string query7 = ss7.str();
                const char* q7 = query7.c_str();
                qstate = mysql_query(conn, q7);
                string query8 = ss8.str();
                const char* q8 = query8.c_str();
                qstate = mysql_query(conn, q8);
                string query9 = ss9.str();
                const char* q9 = query9.c_str();
                qstate = mysql_query(conn, q9);
                string query10 = ss10.str();
                const char* q10 = query10.c_str();
                qstate = mysql_query(conn, q10);
                string query11 = ss11.str();
                const char* q11 = query11.c_str();
                qstate = mysql_query(conn, q11);


                cout<<"Dane zostaly wprowadzone"<<endl;

                qstate = mysql_query(conn, q);

                res = mysql_store_result(conn);
                row= mysql_fetch_row(res);


                getch();

            }


        else{
        cout<<"Dane nieprawidlowe"<<endl;
        getch();
        }


    if(wybor==2)
            {
        return(0);
            }

}

}





bool user_panel(MYSQL* conn, string login ){

    MYSQL_ROW row,row1;
    MYSQL_RES* res;

    start:

    system("cls");

    stringstream ss;

    ss << "SELECT * FROM users where login= '" << login << "' ";

    string query = ss.str();
    const char* q = query.c_str();
    int qstate = mysql_query(conn, q);

    res = mysql_store_result(conn);
    row = mysql_fetch_row(res);

    stringstream ss2;

    ss2 << "SELECT * FROM account where id_owner= '" << row[0] << "' ";

    string query2 = ss2.str();
    const char* q2 = query2.c_str();
    int qstate1 = mysql_query(conn, q2);


    cout<<"Witaj, "<<endl;
    cout<<"Nazwa Uzytkownika -> "<<row[1]<<endl;
    cout<<"IdKlienta - > "<<row[0]<<""<<endl;
    cout<<"Ostatnio zalogowales sie "<<row[3]<<endl;



    time_t czas;
    time( & czas );


    stringstream ss1;
    ss1 << "UPDATE users SET last_login =  '" << ctime( & czas ) << "' WHERE login = '" << login << "'";
    string query1 = ss1.str();
    const char* q1 = query1.c_str();
    qstate = mysql_query(conn, q1);

    int action;
    cout<<endl;
    cout<<"Co chcesz zrobic?"<<endl;
    cout<<"1. Zmien haslo"<<endl;
    cout<<"2. Wprowadzenie auta/Szybka Sprzedaz"<<endl;
    cout<<"3. Edycja auta"<<endl;
    cout<<"4. Wyswietl moje auta"<<endl;
    cout<<"5. Sprzedaj auto"<<endl;
    cout<<"6. Wynajmij auto"<<endl;
    cout<<"7. Wyloguj sie"<<endl;

    cout<<endl;
    cout<<"Twoj wybor: ";
    cin>>action;

    switch(action){

    case 1:
        if(change_password(conn,login))
            goto start;
        break;
    case 2:
        if(wprowadzenieauta(conn,row[0],login,row[4],row[5],row[6],row[7],row[8]))
            goto start;
        break;
    case 3:
        if(edycjaauta(conn,row[0],login))
            goto start;
        break;
    case 4:
        if(wyswietlauta(conn,row[0],row[4]))
            goto start;
        break;
    case 5:
        if(sprzedaz(conn,row[0],login,row[4]))
            goto start;
        break;
    case 6:
        if(wynajem(conn,row[0],login,row[1],row[0]))
            goto start;
        break;
    case 7:
        return false;
        break;

     default:
        cout<<"Nieprawidlowy wybor"<<endl;
        goto start;

    }

}

bool login(MYSQL* conn){

    string login,password,dalej;

    login:
    system("cls");

    cout<<"Podaj login"<<endl;
    cin>>login;
    cout<<"Podaj haslo"<<endl;
    cin>>password;

    MYSQL_ROW row;
    MYSQL_RES* res;

    int qstate = 0;
    stringstream ss1;
    ss1 << "SELECT * FROM users where login= '" << login << "'  AND password= '" << password << "'";

    string query = ss1.str();


    const char* q = query.c_str();
    qstate = mysql_query(conn, q);

    res = mysql_store_result(conn);
    row= mysql_fetch_row(res);

    if(row!=0){

         cout<<"Zalogowano, prosze czekac.. "<<endl;
        Sleep(1500);
        if(!user_panel(conn,login))

            return false;


    }
    else{

        cout<<"Dane nieprawidlowe.."<<endl;
        Sleep(1500);
        goto login;

    }

}




