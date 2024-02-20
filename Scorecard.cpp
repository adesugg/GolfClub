
#include "../include/GolfClubPlayer.h"
#include <iomanip>
Scorecard::Scorecard(int h)
{
    handicap = h;

    //for(int i = 0; i < NUM_OF_HOLES; i++)
    //    free[i] = 0;

    for(int i = 0; i < NUM_OF_HOLES; i++)
            free[i] = h/NUM_OF_HOLES;

    for(int i = 0; i < h%NUM_OF_HOLES; i++)
    {
        for(int j = 0; j < NUM_OF_HOLES; j++)
            if(i+1 == index[j])
                free[j] += 1;
    }

    for(int i = 0; i < NUM_OF_HOLES; i++)
        strokes[i] = 0;

    for(int i = 0; i < NUM_OF_HOLES; i++)
        net[i] = 0;

    for(int i = 0; i < NUM_OF_HOLES; i++)
        score[i] = 0;
}

void Scorecard::AddStroke()
{
    while(hole_count < 18)
    {
        int stroke;
        cout << "\nEnter the number of strokes for hole no." << hole_count+1 << ": " ;
        cin >> stroke;
        strokes[hole_count] = stroke;
        hole_count++;
    }
}

void Scorecard::Calculate()
{
    for(int i = 0; i < NUM_OF_HOLES; i++)
        net[i] = strokes[i] - free[i];

    for(int i = 0; i < NUM_OF_HOLES; i++)
    {
        int par_diff = net[i] - par[i];
        if(par_diff > 2)
            score[i] = 0;
        else
        {
            score[i] = (par_diff*(-1))+2;
        }
    }
}

void Scorecard::ShowCard()
{
    cout << "\n\nHandicap: " << handicap << endl;
    cout << setw(118) << setfill('_') << "" << endl;
    cout << "|Holes   ";
    for(int i = 0; i < NUM_OF_HOLES; i++)
    {
        if(holes[i] < 10)
            cout << setw(2) << "|  " << holes[i] << "  ";
        else
            cout << setw(1) << "| " << holes[i] << "  ";

    }
    cout << "|\n|________|";
    for(int i = 0; i < NUM_OF_HOLES; i++){cout << "_____|";}

    cout << "\n|Par     ";
    for(int i = 0; i < NUM_OF_HOLES; i++)
    {
        if(par[i] < 10)
            cout << setw(2) << "|  " << par[i] << "  ";
        else
            cout << setw(1) << "| " << par[i] << "  ";
    }
    cout << "|\n|________|";
    for(int i = 0; i < NUM_OF_HOLES; i++){cout << "_____|";}
    cout << "\n|Index   ";
    for(int i = 0; i < NUM_OF_HOLES; i++)
    {
        if(index[i] < 10)
            cout << setw(2) << "|  " << index[i] << "  ";
        else
            cout << setw(1) << "| " << index[i] << "  ";
    }
    cout << "|\n|________|";
    for(int i = 0; i < NUM_OF_HOLES; i++){cout << "_____|";}
    cout << "\n|Free    ";
    for(int i = 0; i < NUM_OF_HOLES; i++)
    {
        if(free[i] < 10)
            cout << setw(2) << "|  " << free[i] << "  ";
        else
            cout << setw(1) << "| " << free[i] << "  ";

    }
    cout << "|\n|________|";
    for(int i = 0; i < NUM_OF_HOLES; i++){cout << "_____|";}
    cout << "\n|Strokes ";
    for(int i = 0; i < NUM_OF_HOLES; i++)
    {
        if(strokes[i] < 10)
            cout << setw(2) << "|  " << strokes[i] << "  ";
        else
            cout << setw(1) << "| " << strokes[i] << "  ";
    }
    cout << "|\n|________|";
    for(int i = 0; i < NUM_OF_HOLES; i++){cout << "_____|";}
    cout << "\n|Net     ";
    for(int i = 0; i < NUM_OF_HOLES; i++)
    {
        if(net[i] >= 0 && net[i] < 10)
            cout << setw(2) << "|  " << net[i] << "  ";
        else if(net[i] < 0 || net[i] >= 10)
            cout << setw(1) << "| " << net[i] << "  ";
    }
    cout << "|\n|________|";
    for(int i = 0; i < NUM_OF_HOLES; i++){cout << "_____|";}
    cout << "\n|Score   ";
    for(int i = 0; i < NUM_OF_HOLES; i++)
    {
        if(score[i] < 10 || score[i] >= 0)
            cout << setw(2) << "|  " << score[i] << "  ";
        else
            cout << setw(1) << "|  " << score[i] << " ";
    }
    cout << "|\n|________|";
    for(int i = 0; i < NUM_OF_HOLES; i++){cout << "_____|";}
    for(int i = 0; i < NUM_OF_HOLES; i++)
        total = total + score[i];
    cout << "\nTotal: " << total << endl;
}

Scorecard::~Scorecard()
{
    cout << "Scorecard destroyed" << endl;
}
