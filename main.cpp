#include <iostream>
#include "C:\Users\adepo\Downloads\Golf_project 4\Golf_project\include\Scorecard.h"
#include "C:\Users\adepo\Downloads\Golf_project 4\Golf_project\include\ClubManagement.h"
using namespace std;
ClubManagement manager1;
string management_passcode = "A098rrt";
void Man_Menu ();
void Main_menu();
void Play_Menu(ClubManagement &manager);
int main()
{
Main_menu();



   return 0;
}

void Main_menu(){
int menu_option = 0;
do {
cout << "\n Grange Golf Club \n \n" << endl;
cout << "-----------------------------\n";
cout << "1) Manager Login \n" << endl;
cout << "2) Player Login \n" << endl;
cout << "3) Exit \n" << endl;
cin >> menu_option;

if (menu_option == 1){
string enter_management_passcode;
cout << "Please enter management passcode: \n";
cin >> enter_management_passcode;

if (enter_management_passcode == management_passcode){

    Man_Menu();
}
else {
    cout << "Access to Management denied" << endl;
    Main_menu();
}
}
else if (menu_option == 2){

    Play_Menu(manager1);
}
else if (menu_option ==3){
    cout << "Exiting Program" << endl;

}
else {

    cout << "Please select a valid option" << endl;
}


}while (menu_option > 4 && menu_option < 0);
}

//Management Menu

void Man_Menu () {
    int choice;
    do{
    cout << "Management Menu" <<endl;
    cout << "-----------------------------\n";
    cout << " 1)Add Player \n 2)Remove Player \n 3)Display Player \n 4)Log out \n" << endl;
    cin >> choice;
    switch(choice){

case 1: {

        string Pname;
        string Pwordd;
        string Pmemcode;
        string Psurname;
        cout << "Add Player \n \n";
        cout << "Enter Player's name:" << endl;
        cin >> Pname;
        cout << "Enter Surname" << endl;
        cin >> Psurname;
        cout << "Enter Player's member ID:" << endl;
        cin >> Pmemcode;
        cout << "Enter Player's password" << endl;
        cin >> Pwordd;
        manager1.add_player(Pname, Psurname, Pmemcode, Pwordd);
        break;



}
case 2: {

        string Pmemcode;
        cout << "Remove Player \n \n";
        cout << "Enter Player's Member ID: " << endl;
        cin >> Pmemcode;
        manager1.remove_player(Pmemcode);
        break;




}
case 3: {
        string Pmemcode;
        cout << "Display Player \n \n" ;
        cout << "Enter Member ID" << endl;
        cin >> Pmemcode;
        manager1.view_player(Pmemcode);
        break;


}

case 4: {

       cout << "Logging out" << endl;
       break;

}


    }






    }while (choice != 4);
    Main_menu();

}
//Player Menu
void Play_Menu(ClubManagement &manager){

int playmenuchoice = 0;
cout << "Player Login \n\n";
string playerID, playerPassword;

    // Get player name and password
    cout << "Enter your member ID: \n";
    cin >> playerID;
    cout << "Enter your password: \n";
    cin >> playerPassword;

    // Check if the player is registered
    GolfClubPlayer* currentPlayer = manager.find_player(playerID);

    if (currentPlayer == nullptr || (currentPlayer->Getpassword() != playerPassword)) {
        cout << "Login invalid. Please try again\n";
        Play_Menu(manager1);
    }



do {

cout << "\n1)Add Scorecard \n2)Enter Strokes \n3)Calculate Results \n4)Display Scorecard \n5)Manage Account\n6)Log out\n" << endl;
cin >> playmenuchoice;

switch(playmenuchoice){


case 1: {


        currentPlayer->add_Scorecard();
        cout << endl;
        break;

}
case 2: {
    currentPlayer->enter_strokes();
    break;

}

case 3: {


       currentPlayer->calculate_results();
       break;


}

case 4:
    {

        currentPlayer->view_scorecard();

        break;



    }
case 5:
    {
       currentPlayer->manage_account();
       break;
    }



case 6:
    {
        break;
    }





}

}while (playmenuchoice !=6);
Main_menu();
}
