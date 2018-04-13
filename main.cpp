#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_PERIODS = 10;
const int MAX_TEAMS = 4;
const int MIN_PERIODS = 1;
const int MIN_TEAMS = 1;

void printScoreboard(vector < vector <int> >);
int randomBetween(int, int);

int main()
{
        srand((int) time(0));
        int periods;
        int teams;
        vector<vector<int> > board;

        cout<<"How many competitors? ";
        cin>>teams;
        cout<<"How many scoring periods? ";
        cin>>periods;

        if( teams < MIN_TEAMS || periods < MIN_PERIODS || 
                        teams > MAX_TEAMS || periods > MAX_PERIODS )
        {
                cout<<"Must have between "<<MIN_TEAMS<<" and "<<MAX_TEAMS<<" competitors.\n";
                cout<<"and between "<<MIN_PERIODS<<" and "<<MAX_PERIODS<<" periods.\n";
                return 0;
        }
        else
        {
                //make scoreboard and fill it with zeros
                for ( int i = 0; i < teams; i++ )
                {
                        vector<int> temp;
                        for ( int j = 0; j < periods; j++ )
                        {
                                temp.push_back(0);
                        }
                        board.push_back(temp);
                }
                //once created, display the scoreboard
                printScoreboard(board);

                for ( int i = 0; i < board.size(); i++ )
                {
                        for ( int j = 0; j < board[i].size(); j++ )
                        {
                                board[i][j] = randomBetween(5,5);
                        }
                }

                printScoreboard(board);
        }
        return 0;
}

void printScoreboard(vector< vector<int> > grid)
{
        cout<<"SCOREBOARD\n";

        for ( int i = 0; i < grid.size(); i++ )
        {
                cout<<"Player "<<i+1<<": ";
                for ( int j = 0; j < grid[i].size(); j++ )
                {
                        cout<<grid[i][j]<<"|";
                }
                cout<<endl;
        }
}

int randomBetween(int first, int second)
{
        if(first>second)
        {
                return second + rand()%(first-second+1);
        }

        else
        {
                return first + rand()%(second-first+1);
        }
}



