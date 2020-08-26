
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <windows.h>
//#include <cassert>
using namespace std;
/*
    bool to_bool(const std::string& x) {
      assert(x == "False" || x == "True");
      return x == "True";
    }
*/
int main(){

    //define main vars
    string id;
    string pathbal;
    string ext = ".txt";
    //bool balexists;
    string pathbalstatus;
    bool exists;
    string sidpath;
    int optionmenu;
    const char *appdata = getenv ( "APPDATA" );
    sidpath = appdata;
    sidpath += "\\myprogram\\files\\sid" + ext;
    ifstream sessionID(sidpath);
    sessionID >> id;
    sessionID.close();
    pathbal = appdata;
    pathbal += "\\myprogram\\files\\users\\balance\\" + id + ext;
    pathbalstatus = appdata;
    pathbalstatus += "\\myprogram\\files\\status" + ext;
    //balfile check
    ifstream statfile(pathbalstatus);
    statfile >> exists;
    statfile.close();

    //balexists = to_bool(exists);
    //main menu
    mainmenu:
        system("cls");
  cout << "########################################    " << endl;
  cout << "BBBB  AAA  NN  N K K  H   H  OOOO  GGGGG  TM" << endl;
  cout << "B  B A   A N N N K K  H   H O    O G        " << endl;
  cout << "B B  AAAAA N  NN KK   HHHHH O    O G  GG    " << endl;
  cout << "B  B A   A N   N K K  H   H O    O G   G    " << endl;
  cout << "BBBB A   A N   N K  K H   H  OOOO  GGGGG    " << endl;
  cout << "########################################    " << endl;
  cout << "what would you like to do today?" << endl;
  cout << "01=transfer a sum of money  02=check my account's balance" << endl;
  cout << "03=delete my account        04=close the program" << endl;
  //cout << pathbal << endl;
  //cout << pathbalstatus << endl;
  //cout << exists << endl;
  //cout << id  << endl;
  //input processing
  cin >> optionmenu;
  switch(optionmenu){
    case 01: goto transfer;
    case 02: goto balance;
    case 03: goto accdelete;
    case 04: exit( 4 );
    default: cout << "invalid option";system("timeout /nobreak /t 3");goto mainmenu;
    }
return 0;
//transfer section
transfer:
    cout << "transfer works" << endl;
    system("pause");
//balance checking
balance:
int balvalue;

    if (exists = "1"){
        ifstream balfile(pathbal);
        balfile >> balvalue;
        balfile.close();
        cout << id << " your current balance is " << balvalue << endl;
        system("pause");
        system("cls");
        goto mainmenu;
    }else{
        ofstream balfile(pathbal);
        balfile << 0 ;
        balfile.close();
        cout << id << "'s balance file doesn't exist so we made one" << endl;
        system("pause");
        system("cls");
        goto mainmenu;
    }

//account deletion
accdelete:
    cout << "accdelete works" << endl;
    system("pause");
}
