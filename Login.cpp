// gotta love the homies at cplusplus.com for the sourcecode : http://www.cplusplus.com/forum/general/74374/
#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>


using namespace std;

int main(){

    Login:
    string usrname;
    string psword;
    string rpsword;
    string sidpath;
    string path;
    string ext = ".txt";

    printf("Username: ");
    cin >> usrname;
    printf("Password: ");
    cin >> psword;

    const char *appdata = getenv ( "APPDATA" );
    path = appdata;
    path += "\\myprogram\\files\\users\\" + usrname + ext;

    ifstream readUser(path.c_str());
    readUser >> rpsword;

    if(!readUser){

        printf("Incorrect Username or Password.  \n");
        system("PAUSE");
        printf("\n");
        goto Login;

    }

    if(psword != rpsword){

        printf("Incorrect Username or Password.  \n");
        printf("Please press any key, and then retry the login.\n");
        cin.get();
        goto Login;

    }
sidpath = appdata;
sidpath += "\\myprogram\\files\\sid" + ext;
ofstream sidfile(sidpath);
sidfile << usrname ;
sidfile.close();
system("main.exe");
return 0;
}
