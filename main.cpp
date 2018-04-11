#include <iostream>
#include <vector>

using namespace std;

const int MAX_PERIODS = 10;
const int MAX_TEAMS = 4;
const int MIN_PERIODS = 1;
const int MIN_TEAMS = 1;

int main()
{
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
        cout<<"SCOREBOARD"<<endl;
       
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
        for ( int i = 0; i < teams; i++ )
        {
              cout<<"Player "<<i+1<<": ";
              for ( int j = 0; j < periods; j++ )
              {
                    cout<<board[i][j]<<"|";
              }
              cout<<endl;
        }
  }
  return 0;
}
