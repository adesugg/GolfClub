#include "../include/Scorecard.h"
#include "../include/GolfClubPlayer.h"
GolfClubPlayer::GolfClubPlayer() // must create an account to do anything
{


}
GolfClubPlayer::GolfClubPlayer(string name, string surname, string member_code, string password) // must create an account to do anything
{
this-> name = name;
this->surname = surname;
this->member_code= member_code;
this-> password = password;
DOB = "Unknown";

scorecard = new Scorecard*[MAX_SCORECARDS];
}
 // choose what you want to do


void GolfClubPlayer::add_Scorecard(){
    if (count_sc < MAX_SCORECARDS) {
        // creates new dcorecard and adds it to the dynamic array
        handicap--;
        scorecard[count_sc] = new Scorecard(handicap);
        cout << "New scorecard created. " << endl;

        count_sc++;

    }
    else {
        std::cout << "Maximum number of scorecards reached. Cannot add another one.\n";
    }
}

void GolfClubPlayer::enter_strokes(){
last_index = count_sc - 1;
if (last_index >= 0){

    scorecard[last_index]->AddStroke();
}
else {
    cout << "No scorecard available. Please add a scorecard." << endl;
}

}
void GolfClubPlayer::calculate_results(){
last_index = count_sc - 1;
if (last_index >= 0){
    cout << "Results calculated for last scorecard:\n";
    scorecard[last_index]->Calculate();
}

else {
    cout << "No scorecard available. Please add a scorecard." << endl;
}
}
void GolfClubPlayer::view_account_info(){
cout << "Account Info: " <<endl;
cout << "****************"<< endl;
cout << "Name: " << name << " " << surname << endl;
cout << "Member ID: " << member_code << endl;
cout << "Date of Birth (DD/MM/YY): " << DOB << endl;


}
void GolfClubPlayer::manage_account(){
cout << "Manage Account: " << endl;
cout << "****************"<< endl;
cout << "1)Change name\n2)Change surname\n3)Change Date of Birth\n4)Change password" << endl;
int choose;
cin >> choose;
switch(choose){

case 1: {

cout << "Enter new name" << endl;
cin >> name;
cout << "Name updated" << endl;
break;
}

case 2:{

cout << "Enter new surname" << endl;
cin >> surname;
cout << "Surname updated"<<endl;
break;
}
case 3:{

cout << "Enter new Date of Birth (DD/MM/YY)" << endl;
cin >> DOB;
cout << "Date of Birth updated"<<endl;
break;
}

case 4:{
string newpassword,confirmpassword;
cout << "Enter new password" << endl;
cin >> newpassword;
cout << "Confirm password" <<endl;
cin >> confirmpassword;
if (newpassword==confirmpassword){
    password = confirmpassword;
    cout << "Password has been updated" << endl;
    break;
}
else {
    cout << "Password does not match" << endl;
    break;
}
}

}

}
void GolfClubPlayer::view_scorecard(){
cout << "Viewing all scorecards for player \n";

for (int i = 0; i < count_sc; i++){
    cout << "Scorecard " << i + 1 << " \n";
    scorecard[i]->ShowCard();
    cout << endl;
}
cout << "End of scorecards" << endl;

}

GolfClubPlayer::~GolfClubPlayer() //destructor
{


    for (int i = 0; i < count_sc; ++i) {
        delete scorecard[i];
    }

    delete[] scorecard;
    //dtor
}
