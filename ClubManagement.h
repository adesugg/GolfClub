#ifndef CLUBMANAGEMENT_H
#define CLUBMANAGEMENT_H
#include "C:\Users\adepo\Downloads\Golf_project 4\Golf_project\include\GolfClubPlayer.h"

const int MAX_PLAYERS = 25;
class ClubManagement
{
    public:
        ClubManagement();
        virtual ~ClubManagement();
        ClubManagement(const ClubManagement& other);
        ClubManagement& operator=(const ClubManagement& other);
        bool add_player (string&, string&, string&, string&);
        void remove_player(string&);
        GolfClubPlayer* find_player(const string& playermemcode);
        void view_player(const string & playermemcode) const;
    protected:

    private:
        GolfClubPlayer** players;
        int player_cnt = 0;

};

#endif // CLUBMANAGEMENT_H
