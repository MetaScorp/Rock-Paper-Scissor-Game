#include<iostream>
using namespace std;
enum objtype{ROCK, PAPER, SCISSOR};
void displayrules()
{ cout<<"\n===========================================================================================";
  cout<<"\n >> Game Rules:";
  cout<<"\n";
  cout<<"\n 1. If both the players choose the same object, the play is tie.";
  cout<<"\n 2. If one player chooses rock and the other chooses scissor,";
  cout<<"\n    then player choosing the rock will win as the rock breaks the scissor.";
  cout<<"\n 3. If one player chooses rock and the other chooses paper,";
  cout<<"\n    then player choosing paper will win as paper covers the rock.";
  cout<<"\n 4. If one player chooses paper and the other chooses scissor,";
  cout<<"\n    then player choosing the scissors wil win as scissor cut the paper.";
  cout<<"\n";
  cout<<"\n >> How to play?:";
  cout<<"\n";
  cout<<"\n To select rock press 'R'";
  cout<<"\n To select paper press 'P'";
  cout<<"\n To select scissor press 'S'";
  cout<<"\n To exit and see the final results press 'X'";
  cout<<"\n===========================================================================================";
}
bool validselection(char ch)
{ switch (ch)
  { case 'R':
      case 'r':
      case 'S':
      case 's':
      case 'P':
      case 'p':
       return true;
      default:
          return false;
  }
}
objtype retrieveply(char ch)
{ objtype object;
   switch (ch)
  { case 'R':
      case 'r':
          object=ROCK;
          break;
      case 'S':
      case 's':
          object=SCISSOR;
          break;
      case 'P':
      case 'p':
          object=PAPER;
  }
   return object;
}
void convertenum(objtype object)
{ switch(object)
  { case ROCK:
        cout<<"Rock";
        break;
      case PAPER:
          cout<<"Paper";
          break;
      case SCISSOR:
          cout<<"Scissor";
  }
}
objtype winningobject(objtype play1, objtype play2)
{ if((play1== ROCK && play2== SCISSOR)||(play2==ROCK && play1== SCISSOR))
   return ROCK;
  else
  if((play1== ROCK && play2== PAPER)||(play2==ROCK && play1== PAPER))
   return PAPER;
  else
  return SCISSOR;  
}
void gameresult(objtype play1, objtype play2, int &winner)
{ objtype winnerobject;
  if(play1==play2)
  { winner=0;
    cout<<"\n -> This game is a tie";
    cout<<"\n";
  }
  else
  {
    if(play1==winnerobject)
    winner=1;
    else
    if(play2==winnerobject)
    winner=2;
    cout<<" -> Hurray! player "<<winner<<" wins this game"<<endl;
  }
}
void displayresult(int gcount,int wcount1, int wcount2)
{ cout<<"Total number of plays:"<<gcount<<endl;
   cout<<"Total number of plays won by player 1:"<<wcount1<<endl;
    cout<<"Total number of plays won by player 2:"<<wcount2<<endl;
 
}
int main()
{ int gamecount=0,wincount=0,wincount1=0;
  int gamewinner;
  char response;
  char selection1;
  char selection2;
  char name;
  objtype play1;
  objtype play2;
displayrules();
 cout<<"\n";
 cout<<"\n Press 'Y' to play the game:";
cin>>response;
cout<<endl;
while(response=='Y'||response=='y')
{ cout<<"PLayer 1 enter your selection:";
  cin>>selection1;
  cout<<endl;
 
  cout<<"PLayer 2 enter your selection:";
  cin>>selection2;
  cout<<endl;
 
if(validselection(selection1)&&validselection(selection2))
{ play1= retrieveply(selection1);
  play2= retrieveply(selection2);
  gamecount++;
  gameresult(play1,play2, gamewinner);
  if(gamewinner==1)
   wincount++;
  else
   if(gamewinner==2)
   wincount++;
 }
 cout<<"\n--------------------------------";
 cout<<"\n";
 cout<<" Press 'Y' to play more and 'X' to exit:";
cin>>response;
cout<<endl;
}
displayresult(gamecount, wincount, wincount1);
return 0;
}


