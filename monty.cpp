#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

bool monty_hall();

void simulate(int num_iterations);

int main(){
  int trials;
  cout<<"How many trials do you want to run? ";
  cin>>trials;
  if(trials>0){
  simulate(trials);
  }
  return 0;
}

bool monty_hall(){
  int choice;
  char change;
  int car=rand()%3;
  
  cout<<"Which door do you want to choose: 1, 2, or 3 ";
  cin>>choice;
  choice--;
  
  int host=0;
  while(host==choice || host == car){
    host++;
  }
  
  cout<<"Host removed door number "<<host+1<<"."<<endl;
  cout<<"Do you want to swap doors? y or n ";
  cin>>change;
  if(change=='y'){
    int orig=choice;
    while(choice==orig || choice==host){
      choice=choice+2;
      if(choice<2){
	choice=choice%3;
      }
    }
  }
  if(choice==car){
    return true;
  }
  else{
    return false;
  }
}

void simulate(int num_iterations){
  int games=0;
  int Win=0;
  int lose=0;
  bool result;
  for(int i=0; i<num_iterations; i++){
    result=monty_hall();
    games++;
    if(result==true){
      Win++;
    }
    else{
      lose++;
    }
  }
  cout<<"You won "<<Win<<" games"<<endl;
  cout<<"You lost "<<lose<<" games"<<endl;
  double percentWon=Win*100.00/games;
  cout<<"Your percentage of winning is "<<percentWon<<"%"<<endl;
}
