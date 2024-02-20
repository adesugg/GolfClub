#ifndef SCORECARD_H
#define SCORECARD_H
#include <iostream>
using namespace std;

const int NUM_OF_HOLES = 18;
class Scorecard
{
    public:
        Scorecard(int h);
        virtual ~Scorecard();
        void AddStroke();
        void Calculate();
        void ShowCard();

    protected:

    private:
        const int holes[NUM_OF_HOLES] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
        const int par[NUM_OF_HOLES] = {4,5,3,4,4,5,3,5,3,5,3,4,4,4,4,5,4,3};
        const int index[NUM_OF_HOLES] = {16,4,8,2,18,14,10,6,12,11,15,5,13,1,17,7,3,9};
        int free[NUM_OF_HOLES];
        int strokes[NUM_OF_HOLES];
        int net[NUM_OF_HOLES];
        int score[NUM_OF_HOLES];
        int handicap;
        int hole_count = 0;
        int total = 0;

};

#endif // SCORECARD_H
