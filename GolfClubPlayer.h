#ifndef GOLFCLUBPLAYER_H
#define GOLFCLUBPLAYER_H
#include <string>
#include <iostream>
#include "C:\Users\adepo\Downloads\Golf_project 4\Golf_project\include\Scorecard.h"
using namespace std;
const int MAX_NO_OF_STROKES = 18;
const int MAX_SCORECARDS = 54;
class GolfClubPlayer
{
    public:

        GolfClubPlayer();
        GolfClubPlayer(string, string, string, string);
         virtual ~GolfClubPlayer();

        string Getname() { return name; }
        string Getsurname() { return surname; }
        void Setname(string val) { name = val; }
        string Getmember_code() { return member_code; }
        void Setmember_code(string val) { member_code = val; }
        void add_Scorecard();
        void view_scorecard();
        void enter_strokes();
        void calculate_results();
        void view_account_info();
        void manage_account();
        void Setpassword(string val) { password = val;}
        string Getpassword() {return password;}

    protected:

    private:
        string name;
        string password;
        string member_code;
        int strokes[MAX_NO_OF_STROKES]; // dynamic array of strokes that can't be more than 18
        int counter = 0;
        int handicap = 55;
        Scorecard ** scorecard;
        int count_sc = 0;
        int last_index = 0;
        string surname;
        string DOB;
};



#endif // GOLFCLUBPLAYER_H
