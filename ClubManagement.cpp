#include "../include/ClubManagement.h"

ClubManagement::ClubManagement()
{
players = new GolfClubPlayer*[MAX_PLAYERS];
}

ClubManagement::~ClubManagement()
{
    //dtor
    delete[] players;
}
bool ClubManagement::add_player(string &name, string &surname, string &member_code, string& password  ){

 if (player_cnt < MAX_PLAYERS){
    players[player_cnt] = new GolfClubPlayer(name, surname, member_code, password);
    cout << "Player " << players[player_cnt]->Getname() << " " << players[player_cnt]->Getsurname() << " " << players[player_cnt]->Getmember_code() << " created" << endl;
    player_cnt++;
    return true;

 }
  else {

    cout << "Error. Maximum amount of players reached. " << endl;
    return false;
}
}
void ClubManagement::remove_player(string &memcode){
 for (int i=0; i < player_cnt; i++){
    if ((players[i]->Getmember_code()) == memcode){
        for (int a = i; a < player_cnt-1; a++){
            *(players[a]) = *(players[a+1]);
        }
        player_cnt --;
        cout << "Player has been removed" << endl;

    }
else {
cout << "No player found." << endl;
}
}

}
GolfClubPlayer* ClubManagement::find_player(const string& memcode) {
    for (int i = 0; i < player_cnt; i++) {
        if (players[i]->Getmember_code() == memcode) {
            return players[i];
        }
    }
    return nullptr; // Player not found
}
 void ClubManagement::view_player(const string & playermemcode) const {
     bool exist = false;
  for (int i = 0; i < player_cnt; i++){
    if (players[i]->Getmember_code() == playermemcode){
        exist = false;
        players[i]->view_account_info();
        cout << endl;
        players[i]->calculate_results();
        cout << endl;
        players[i]->view_scorecard();
        cout << endl;

    }
 }
 if (!exist){
    cout << "No player found" << endl;
 }


 }

ClubManagement::ClubManagement(const ClubManagement& other)
{
    //copy ctor
}

ClubManagement& ClubManagement::operator=(const ClubManagement& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

