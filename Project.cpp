#include<iostream>
#include<string.h>
#include<iomanip>
#include<conio.h>
#include "Inning.h"
using namespace std;
void match();
int main()
{
	match();
}
void match()
{
	Inning *I;
	int Toss[2], overs, players;
	cout<<endl<<"Enter the number of overs...";
	cin>>overs;
	do{
		cout<<"Enter the number of players...";
		cin>>players;	
		if(players%2==0 || players==1)
			cout<<"Kindly enter an odd number(greater than 1)."<<endl;
	}while(players%2==0 || players==1);
	cin.ignore();
	cout<<endl<<"Press Enter to continue...";
	getch();
	do{
		check = true;
		cout<<endl<<"Enter the name of Team 1...";
		cin.get(T_name[0],15);
		cin.ignore();
		if(cin.fail())
		{
			check = false;
			cin.clear();
			cin.ignore(100,'\n');
			cout<<"Wrong input.";
		}
	}while(check == false);
	do{
		check = true;
		cout<<endl<<"Enter the name of Team 2...";
		cin.get(T_name[1],15);
		cin.ignore();
		if(cin.fail())
		{
			check = false;
			cin.clear();
			cin.ignore(100,'\n');
			cout<<"Wrong input.";
		}
	}while(check == false);
	cout<<endl<<"Press Enter to continue";
	getch();
	I = new First_ING(overs,players);
	do{
		cout<<endl<<"Who has won the toss?"<<endl<<"1. "<<T_name[0]<<endl<<"2. "<<T_name[1]<<endl<<"...";
		cin>>Toss[0];
		if(Toss[0]!=1 && Toss[0]!=2)
			cout<<"Wrong input input again"<<endl;
	
	}while(Toss[0]!=1 && Toss[0]!=2);
	do{
		cout<<"What they have decided?"<<endl<<"1. Bat"<<endl<<"2. Bowl"<<endl<<"...";
		cin>>Toss[1];
		if(Toss[1]!=1 && Toss[1]!=2)
			cout<<"Wrong input input again"<<endl;
	}while(Toss[1]!=1 && Toss[1]!=2);
	if(Toss[0]==1)
	{
		cout<<T_name[0]<<" has won the toss ";
		if(Toss[1]==1)
		{
			cout<<"and decided to bat first";
			name=0;	
		}
		else 
		{
			cout<<"and decided to bowl first";
			name=1;	
		}
	}
	else if(Toss[0]==2)
	{
		cout<<T_name[1]<<" has won the toss ";
		if(Toss[1]==1)
		{
			cout<<"and decided to bat first";
			name=1;	
		}
		else 
		{
			cout<<"and decided to bowl first";
			name=0;	
		}	
	}
	cout<<endl<<"Press Enter to continue";
	getch();
	cout<<endl;
	cin.ignore();
	I->inning();
	if(name==0)
		name++;
	else
		name--;
	bowl1 = z;
	z=0;
	cout<<endl<<T_name[name]<<" needs "<<scoreTochase+1<<" in "<<I->R.getOver()*6<<" balls";
	cout<<endl<<"Press Enter to continue";
	getch();
	delete I;
	I = 0;
	I = new Second_ING(overs, players);
	cin.ignore();
	I->inning();
	bowl2 = z;
	int alignment_of_name1 = strlen(T_name[0]), alignment_of_name2 = strlen(T_name[1]);
	if(alignment_of_name1%2==1)
		alignment_of_name1++;
	if(alignment_of_name2%2==1)
		alignment_of_name2++;
	cout<<endl<<endl<<"Press Enter for the Stats";
	getch();
	cout<<endl;
	for(int i=0;i<=76;i++)
		cout<<"-";
	if(name==0)
		cout<<endl<<"|"<<setw(19-(alignment_of_name2/2))<<" "<<setw(alignment_of_name2)<<T_name[name+1]<<setw((19-(alignment_of_name2/2)))<<"|"<<setw(19-(alignment_of_name1/2))<<" "<<setw(alignment_of_name1)<<T_name[name]<<setw(19-(alignment_of_name1/2))<<"|"<<endl;
	else
		cout<<endl<<"|"<<setw(19-(alignment_of_name1/2))<<" "<<setw(alignment_of_name1)<<T_name[name-1]<<setw(19-(alignment_of_name1/2))<<"|"<<setw(19-(alignment_of_name2/2))<<" "<<setw(alignment_of_name2)<<T_name[name]<<setw(19-(alignment_of_name2/2))<<"|"<<endl;
	for(int i=0;i<=76;i++)
		cout<<"-";
	for(int i=0; i<players; i++)
	{
		if(i<bat1)
			cout<<endl<<"| "<<setw(20)<<Bat[0][i]<<"   "<<setw(5)<<Bat[0][i].getScore()<<"("<<setw(2)<<Bat[0][i].getBallsFaced()<<")";
		else
			cout<<endl<<"|"<<setw(33)<<" ";
		cout<<setw(5)<<"|";
		if(i<bat2)
			cout<<setw(20)<<Bat[1][i]<<"   "<<setw(5)<<Bat[1][i].getScore()<<"("<<setw(2)<<Bat[1][i].getBallsFaced()<<")     |";
		else
			cout<<setw(38)<<"|";
	}
	cout<<endl;
	for(int i=0;i<=76;i++)
		cout<<"-";
	if(name==0)
		cout<<endl<<"|"<<setw(19-(alignment_of_name1/2))<<" "<<setw(alignment_of_name1)<<T_name[name]<<setw(19-(alignment_of_name1/2))<<"|"<<setw(19-(alignment_of_name2/2))<<" "<<setw(alignment_of_name2)<<T_name[name+1]<<setw(19-(alignment_of_name2/2))<<"|"<<endl;
	else
		cout<<endl<<"|"<<setw(19-(alignment_of_name2/2))<<" "<<setw(alignment_of_name2)<<T_name[name]<<setw(19-(alignment_of_name2/2))<<"|"<<setw(19-(alignment_of_name1/2))<<" "<<setw(alignment_of_name1)<<T_name[name-1]<<setw(19-(alignment_of_name1/2))<<"|"<<endl;
	for(int i=0;i<=76;i++)
		cout<<"-";
	for(int i=0; i<players; i++)
	{
		if(i<=bowl1)
			cout<<endl<<"| "<<setw(20)<<Bowl[0][i]<<"   "<<setw(2)<<Bowl[0][i].getRuns()<<"-"<<Bowl[0][i].returnWickets()<<"("<<setw(2)<<Bowl[0][i].returnOvers()<<")";
		else
			cout<<endl<<"|"<<setw(32)<<" ";
		cout<<setw(6)<<"|";
		if(i<=bowl2)
			cout<<setw(20)<<Bowl[1][i]<<"   "<<setw(2)<<Bowl[1][i].getRuns()<<"-"<<Bowl[1][i].returnWickets()<<"("<<setw(2)<<Bowl[1][i].returnOvers()<<")      |";
		else
			cout<<setw(38)<<"|";
	}
	cout<<endl;
	for(int i=0;i<=76;i++)
		cout<<"-";
	getch();
	delete I;
}

