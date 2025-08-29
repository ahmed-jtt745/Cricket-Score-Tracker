#include<iostream>
#include<string.h>
#include<conio.h>
#include "Player.h"
using namespace std;
int z=0, a=1, b=2, buff;
char X[11][20];
char Y[11][20];
int scoreTochase, name, bowler_count=0, win_check = 0;
int bat1 = 2, bat2 = 2, bowl1, bowl2;
char T_name[2][15];
Batter Bat[2][11];
Bowler Bowl[2][11];
bool check;
class Rules{
	private:
		int over;
		int players;
	public:
		Rules(int, int);
		void setOver(int);
		int getOver();
		void setPlayer(int);
		int getPlayer()	const;
};
Rules::Rules(int x, int y)
{
	setOver(x);
	setPlayer(y);	
}
void Rules::setOver(int x)
{
	over = x;
}
int Rules::getOver()
{
	return over;
}
void Rules::setPlayer(int x)
{
	players = x;	
}
int Rules::getPlayer()	const
{
	return players;
}

class Inning{
	private:
		int over;
		int players;
		int score;
	public:
		Inning(int, int);
		int getScore();
		void incrementOver();
		int getOver();
		void scoreUpdate(int);
		virtual void inning() = 0;
		virtual ~Inning();
		Rules R;
};
Inning::Inning(int x, int y):R(x, y)
{
	over = 1;
	score = 0;
}
int Inning::getScore()
{
	return score;
}
void Inning::scoreUpdate(int x)
{
	score+=x;
}
void Inning::incrementOver()
{
	++over;
}
int Inning::getOver()
{
	return over;
}
Inning::~Inning()
{
	
}
class First_ING:public Inning{
	private:
		double RunRate;
		double ProjectedScore;
	public:
		First_ING(int, int);
		double RunrateCal();
		double ProjectedCal();
		int getWicket();
		void inning();
};
First_ING::First_ING(int x, int y):Inning(x, y)
{
	RunRate = 0.0;
	ProjectedScore = 0.0;
}
double First_ING::RunrateCal()	
{
	RunRate = (getScore()*1.0)/(getOver()*1.0);
	return RunRate;
}
double First_ING::ProjectedCal()
{
	static int t = R.getOver();
	ProjectedScore = RunrateCal()*t;
	t--;
	return ProjectedScore;
}
void First_ING::inning()
{
	int scr1=0, scr2=0, score, ballsFaced1=0, ballsFaced2=0, ball_wickets, wicket = R.getPlayer()-1, Wicket = 0, ball_score, Over = 0,over_length, i;
	int strike_rotation=1, buffer, in_check=0, buff_check=0;
	char Over_stat[12], pl[2][20],bal[20]="", temp[20];
	do{
		check = true;
		cout<<endl<<"Enter the name of Opener...";
		cin.get(pl[0], 20);	
		if(cin.fail())
		{
			check = false;
			cin.clear();
			cin.ignore(100,'\n');
			cout<<"Wrong input."<<endl;
		}
	}while(check == false);
	Bat[0][a-1].setName(pl[0]);
	cin.ignore();
	do{
		check = true;
		cout<<"Enter the name of other batsman...";
		cin.get(pl[1], 20);	
		if(cin.fail())
		{
			check = false;
			cin.clear();
			cin.ignore(100,'\n');
			cout<<"Wrong input."<<endl;
		}
	}while(check == false);
	Bat[0][b-1].setName(pl[1]);
	for(i=1;i<=R.getOver();i++)
	{
		cin.ignore();
		strcpy(temp, bal);
		do{
			buffer = 0;
			do{
				check = true;
				cout<<"Enter the name of the bowler...";
				cin.get(bal, 20);
				if(cin.fail())
				{
					check = false;
					cin.clear();
					cin.ignore(100,'\n');
					cout<<"Wrong input."<<endl;
				}
			}while(check == false);
			cin.ignore();
			if(strcmp(temp, bal)==0)
			{
				cout<<"A bowler cannot bowl two overs continously"<<endl;
				buffer++;
			}			
		}while(buffer==1);
		for(int j=0;j<=z;j++)
		{
			char* s = Bowl[0][j].getName();
			if(strcmp(s,bal)==0)
			{
				buff = z;
				z = j;
				buff_check++;
			}
		}
		if(i==1)
			cout<<"";
		else if(buff_check==0)
			z++;
		cout<<endl<<"For wicket press \"W\", for wide press \"w";
		cout<<endl<<"Press Enter to continue";
		getch();
		Bowl[0][z].setName(bal);
		Bowl[0][z].incrementOvers();
		score = 0, ball_wickets = 0, ball_score = 0, Over++, over_length = 6;
		cout<<endl<<"Over = "<<Over;
		cout<<endl<<"Enter the score..."<<endl;
		for(int j=0;j<over_length;j++)
		{
			cin>>Over_stat[j];
			if(Over_stat[j]=='w')
			{
				over_length++, score++;
			}
			else if(Over_stat[j]=='0')
			{
				if(strike_rotation%2!=0)
					ballsFaced1++;	
				else
					ballsFaced2++;	
			}
			else if(Over_stat[j]=='1')
			{
				score++;
				if(strike_rotation%2!=0)
				{
					scr1++,	ballsFaced1++;	
				}
				else
				{
					scr2++,	ballsFaced2++;	
				}
				strike_rotation++;
			}
			else if(Over_stat[j]=='3')
			{
				score+=3;
				if(strike_rotation%2!=0)
				{
					scr1+=3,	ballsFaced1++;
				}
				else
				{
					scr2+=3,	ballsFaced2++;
				}
				strike_rotation++;
			}
			else if(Over_stat[j]=='2')
			{
				score+=2;
				if(strike_rotation%2!=0)
				{
					scr1+=2,	ballsFaced1++;
				}
				else
				{
					scr2+=2,	ballsFaced2++;	
				}	
			}
			else if(Over_stat[j]=='4')
			{
				score+=4;
				if(strike_rotation%2!=0)
				{
					scr1+=4,	ballsFaced1++;	
				}
				else
				{
					scr2+=4,	ballsFaced2++;
				}
			}
			else if(Over_stat[j]=='6')
			{
				score+=6;
				if(strike_rotation%2!=0)
				{
					scr1+=6,	ballsFaced1++;	
				}
				else
				{
					scr2+=6,	ballsFaced2++;	
				}	
			}
			else if(Over_stat[j]=='W')
			{
				Wicket++;
				Bowl[0][z].incrementWickets();
				if(strike_rotation%2!=0)
					ballsFaced1++;
				else
					ballsFaced2++;
				wicket--,	ball_wickets++;
				if(strike_rotation%2!=0)	
				{
					cin.ignore();
					Bat[0][a-1].addRuns(scr1);
					Bat[0][a-1].addBalls(ballsFaced1);
					cout<<endl<<Bat[0][a-1]<<" is out at "<<Bat[0][a-1].getScore()<<"("<<Bat[0][a-1].getBallsFaced()<<")";
//					Bat[0][player_count].updateStats(pl[0], scr1, 0.0, ballsFaced1);
					if(wicket!=0)
					{
						if(a<b)
						{
							while(a!=(b+1))
							{
								a++;	
							}	
						}	
						else
							a++;
					}
					else if(wicket==0)
					{
						Bat[0][b-1].addRuns(scr2);
						Bat[0][b-1].addBalls(ballsFaced2);
					}
					scr1=0,	ballsFaced1=0;	
				}
				else
				{
					cin.ignore();
					Bat[0][b-1].addRuns(scr2);
					Bat[0][b-1].addBalls(ballsFaced2);
					cout<<endl<<Bat[0][b-1]<<" is out at "<<Bat[0][b-1].getScore()<<"("<<Bat[0][b-1].getBallsFaced()<<")";
//					Bat[0][player_count].updateStats(pl[1], scr2, 0.0, ballsFaced2);
					if(wicket!=0)
					{
						if(b<a)
						{
							while(b!=(a+1))
							{
								b++;	
							}	
						}	
						else
							b++;
					}
					else if(wicket==0)
					{
						Bat[0][a-1].addRuns(scr1);
						Bat[0][a-1].addBalls(ballsFaced1);	
					}
					scr2=0;
					ballsFaced2=0;	
				}	
				if(wicket==0)
				{
					over_length = j+1, in_check++;
					cout<<endl<<"Team is all out:(";
					Bowl[0][z].updateRuns(score);
					scoreTochase = getScore();
					break;
				}
				else if(strike_rotation%2!=0)
				{
					do{
						check = true;
						cout<<endl<<"Enter the name of new Batsman...";
						cin.get(pl[0], 20);
						if(cin.fail())
						{
							check = false;
							cin.clear();
							cin.ignore(100,'\n');
							cout<<"Wrong input."<<endl;
						}
					}while(check == false);
					Bat[0][a-1].setName(pl[0]);
					bat1++;
				}
				else if(strike_rotation%2==0)
				{
					do{
						check = true;
						cout<<endl<<"Enter the name of new Batsman...";
						cin.get(pl[1], 20);
						if(cin.fail())
						{
							check = false;
							cin.clear();
							cin.ignore(100,'\n');
							cout<<"Wrong input."<<endl;
						}
					}while(check == false);
					Bat[0][b-1].setName(pl[1]);
					bat1++;
				}
			}
			if(j==(over_length-1))
			{
				Bowl[0][z].updateRuns(score);
				Bat[0][a-1].addRuns(scr1);
				Bat[0][a-1].addBalls(ballsFaced1);
				Bat[0][b-1].addRuns(scr2);
				Bat[0][b-1].addBalls(ballsFaced2);
				scr1 = 0;
				scr2 = 0;
				ballsFaced1 = 0;
				ballsFaced2 = 0;
				strike_rotation++;
			}
		}
		if(i==R.getOver())
			in_check++;
		scoreUpdate(score);

		cout<<endl<<T_name[name]<<":-";
		cout<<endl<<"Score in the over => "<<score;
		cout<<endl<<"Over stats => ";
		for(int j=0; j<over_length; j++)
			cout<<Over_stat[j]<<" ";
		cout<<endl<<"Score => "<<getScore()<<"-"<<Wicket<<"\tRunrate => "<<RunrateCal();
		cout<<endl<<setw(20)<<Bat[0][a-1]<<"   "<<setw(5)<<Bat[0][a-1].getScore()<<"("<<setw(2)<<Bat[0][a-1].getBallsFaced()<<")";
		if(strike_rotation%2!=0 &&(wicket!=0 || R.getOver()!=i))
			cout<<"*";
		cout<<endl<<setw(20)<<Bat[0][b-1]<<"   "<<setw(5)<<Bat[0][b-1].getScore()<<"("<<setw(2)<<Bat[0][b-1].getBallsFaced()<<")";
		if(strike_rotation%2==0 &&(wicket!=0 || R.getOver()!=i))
			cout<<"*";
		cout<<endl;
		if(name==0)
			cout<<endl<<T_name[name+1]<<":-";
		else
			cout<<endl<<T_name[name-1]<<":-";
		cout<<endl<<setw(20)<<Bowl[0][z]<<"   "<<setw(2)<<Bowl[0][z].getRuns()<<"-"<<Bowl[0][z].returnWickets()<<"("<<setw(2)<<Bowl[0][z].returnOvers()<<")"<<endl;
		incrementOver();
		if(buff_check!=0)
			z = buff;
		buff_check=0;	  
		if(wicket==0)
			break;
	}
	scoreTochase=getScore();
}
class Second_ING:public Inning{
	private:
		double ReqRR;
	public:
		Second_ING(int, int);
		void inning();
		double getReqRR();
};
Second_ING::Second_ING(int x, int y):Inning(x, y)
{
	ReqRR=0.0;
}
double Second_ING::getReqRR()
{
	static int t = R.getOver()-1;
	ReqRR = ((scoreTochase+1)-getScore())/t;
	t--;
	return ReqRR;
}
void Second_ING::inning()
{
	int scr1=0, scr2=0, score,tem=0, ballsFaced1=0, ballsFaced2=0, ball_wickets, ball_score, buff_check=0;
	int Over = 0, over_length, trike_rotation=1, buffer, wicket = R.getPlayer()-1, Wicket = 0, strike_rotation = 1, a = 1, b = 2;
	char pl[2][20],bal[20]="", temp[20], Over_stat[12];
	do{
		check = true;
		cout<<endl<<"Enter the name of Opener...";
		cin.get(pl[0], 20);	
		if(cin.fail())
		{
			check = false;
			cin.clear();
			cin.ignore(100,'\n');
			cout<<"Wrong input."<<endl;
		}
	}while(check == false);
	Bat[1][a-1].setName(pl[0]);
	cin.ignore();
	do{
		check = true;
		cout<<"Enter the name of other batsman...";
		cin.get(pl[1], 20);	
		if(cin.fail())
		{
			check = false;
			cin.clear();
			cin.ignore(100,'\n');
			cout<<"Wrong input."<<endl;
		}
	}while(check == false);
	Bat[1][b-1].setName(pl[1]);
	for(int i=1;i<=R.getOver();i++)
	{
		cin.ignore();
		strcpy(temp, bal);
		do{
			buffer = 0;
			do{
				check = true;
				cout<<"Enter the name of the bowler...";
				cin.get(bal, 20);
				if(cin.fail())
				{
					check = false;
					cin.clear();
					cin.ignore(100,'\n');
					cout<<"Wrong input."<<endl;
				}
			}while(check == false);
			cin.ignore();
			if(strcmp(temp, bal)==0)
			{
				cout<<"A bowler cannot bowl two overs continously"<<endl;
				buffer++;
			}				
		}while(buffer==1);
		for(int j=0;j<=z;j++)
		{
			char* s = Bowl[1][j].getName();
			if(strcmp(s,bal)==0)
			{
				buff = z;
				z = j;
				buff_check++;
			}
		}
		if(i==1)
			cout<<"";
		else if(buff_check==0)
			z++;
		cout<<endl<<"For wicket press \"W\", for wide press \"w";
		cout<<endl<<"Press Enter to continue";
		getch();
		Bowl[1][z].setName(bal);
		Bowl[1][z].incrementOvers();
		score = 0, ball_wickets = 0, ball_score = 0, Over++, over_length = 6;
		for(int j=0;j<12;j++)
			Over_stat[j] = '\0';
		cout<<endl<<"Over = "<<Over;
		cout<<endl<<"Enter the score..."<<endl;
		for(int j=0;j<over_length;j++)
		{
			cin>>Over_stat[j];
			if(Over_stat[j]=='w')
			{
				over_length++, scoreUpdate(1), score++;
			}
			else if(Over_stat[j]=='0')
			{
				if(strike_rotation%2!=0)
					ballsFaced1++;	
				else
					ballsFaced2++;		
			}
			else if(Over_stat[j]=='1')
			{
				score++;
				if(strike_rotation%2!=0)
				{
					scr1++, scoreUpdate(1), ballsFaced1++;	
				}
				else
				{
					scr2++, ballsFaced2++;	
				}
				strike_rotation++;
			}
			else if(Over_stat[j]=='3')
			{
				score+=3, scoreUpdate(3);
				if(strike_rotation%2!=0)
				{
					scr1+=3, ballsFaced1++;
				}
				else
				{
					scr2+=3, ballsFaced2++;
				}
				strike_rotation++;
			}
			else if(Over_stat[j]=='2')
			{
				score+=2, scoreUpdate(2);
				if(strike_rotation%2!=0)
				{
					scr1+=2, ballsFaced1++;
				}
				else
				{
					scr2+=2, ballsFaced2++;	
				}	
			}
			else if(Over_stat[j]=='4')
			{
				score+=4, scoreUpdate(4);
				if(strike_rotation%2!=0)
				{
					scr1+=4, ballsFaced1++;	
				}
				else
				{
					scr2+=4, ballsFaced2++;
				}
			}
			else if(Over_stat[j]=='6')
			{
				score+=6, scoreUpdate(6);
				if(strike_rotation%2!=0)
				{
					scr1+=6, ballsFaced1++;	
				}
				else
				{
					scr2+=6, ballsFaced2++;	
				}	
			}
			else if(Over_stat[j]=='W')
			{
				Wicket++;
				Bowl[1][z].incrementWickets();
				if(strike_rotation%2!=0)
					ballsFaced1++;
				else
					ballsFaced2++;
				wicket--, ball_wickets++;
				if(strike_rotation%2!=0)	
				{
					cin.ignore();
					Bat[1][a-1].addRuns(scr1);
					Bat[1][a-1].addBalls(ballsFaced1);
					cout<<endl<<Bat[1][a-1]<<" is out at "<<Bat[1][a-1].getScore()<<"("<<Bat[1][a-1].getBallsFaced()<<")";
//					Bat[1][player_count].updateStats(pl[0], scr1, 0.0, ballsFaced1);
					if(wicket!=0)
					{
						if(a<b)
						{
							while(a!=(b+1))
							{
								a++;	
							}	
						}	
						else
							a++;
					}
					else if(wicket==0)
					{
						Bat[1][b-1].addRuns(scr2);
						Bat[1][b-1].addBalls(ballsFaced2);
					}
					scr1=0,	ballsFaced1=0;	
				}
				else
				{
					cin.ignore();
					Bat[1][b-1].addRuns(scr2);
					Bat[1][b-1].addBalls(ballsFaced2);
					cout<<endl<<Bat[1][b-1]<<" is out at "<<Bat[1][b-1].getScore()<<"("<<Bat[1][b-1].getBallsFaced()<<")";
//					Bat[1][player_count].updateStats(pl[1], scr2, 0.0, ballsFaced2);
					if(wicket!=0)
					{
						if(b<a)
						{
							while(b!=(a+1))
							{
								b++;
							}	
						}	
						else
							b++;
					}					
					else if(wicket==0)
					{
						Bat[1][a-1].addRuns(scr1);
						Bat[1][a-1].addBalls(ballsFaced1);	
					}
					scr2=0,	ballsFaced2=0;	
				}	
				if(wicket==0)
				{
					over_length = j+1;
					if(scoreTochase>getScore())
					{
						Bowl[1][z].updateRuns(score);
						win_check++;
						cout<<endl<<T_name[name]<<" is all out and lost the match with "<<scoreTochase-getScore()<<" runs";
					}	
					else if(scoreTochase==getScore())
					{
						Bowl[1][z].updateRuns(score);
						win_check++;
						cout<<endl<<T_name[name]<<" is all out and the match has tied.";
					}
					scoreTochase = getScore();
					break;
				}
				else if(strike_rotation%2!=0)
				{
					do{
						check = true;
						cout<<endl<<"Enter the name of new Batsman...";
						cin.get(pl[0], 20);
						if(cin.fail())
						{
							check = false;
							cin.clear();
							cin.ignore(100,'\n');
							cout<<"Wrong input."<<endl;
						}
					}while(check == false);
					Bat[1][a-1].setName(pl[0]);
					bat2++;
				}
				else if(strike_rotation%2==0)
				{
					do{
						check = true;
						cout<<endl<<"Enter the name of new Batsman...";
						cin.get(pl[1], 20);
						if(cin.fail())
						{
							check = false;
							cin.clear();
							cin.ignore(100,'\n');
							cout<<"Wrong input."<<endl;
						}
					}while(check == false);
					Bat[1][b-1].setName(pl[1]);
					bat2++;
				}
			}
			if(j==(over_length-1))
			{
				Bowl[1][z].updateRuns(score);
				Bat[1][a-1].addRuns(scr1);
				Bat[1][a-1].addBalls(ballsFaced1);
				Bat[1][b-1].addRuns(scr2);
				Bat[1][b-1].addBalls(ballsFaced2);
				scr1 = 0;
				scr2 = 0;
				ballsFaced1 = 0;
				ballsFaced2 = 0;
				strike_rotation++;
			}
			if(scoreTochase<getScore())
			{
				cout<<T_name[name]<<" has won the match with "<<wicket<<" wickets";
				Bowl[1][z].updateRuns(score);
				Bat[1][a-1].addRuns(scr1);
				Bat[1][a-1].addBalls(ballsFaced1);
				Bat[1][b-1].addRuns(scr2);
				Bat[1][b-1].addBalls(ballsFaced2);
				win_check++;
				break;
			}
			else if(scoreTochase==getScore())
				cout<<"Scores are level."<<endl;
		}
		if(i==R.getOver() && scoreTochase>getScore())
		{
			cout<<T_name[name]<<" has lost the match with "<<scoreTochase-getScore()<<" runs";
			win_check++;
		}
		else if(i==R.getOver() && scoreTochase==getScore())
		{
			cout<<"Match has tied";
			win_check++;
		}
		cout<<endl<<T_name[name]<<":-";
		cout<<endl<<"Score in the over => "<<score;
		cout<<endl<<"Over stats = ";
		for(int j=0; j<over_length; j++)
			cout<<Over_stat[j]<<" ";
		cout<<endl<<"Score => "<<getScore()<<"-"<<Wicket;
		cout<<endl<<setw(20)<<Bat[1][a-1]<<"   "<<setw(5)<<Bat[1][a-1].getScore()<<"("<<setw(2)<<Bat[1][a-1].getBallsFaced()<<")";
		if(strike_rotation%2!=0)
			cout<<"*";
		cout<<endl<<setw(20)<<Bat[1][b-1]<<"   "<<setw(5)<<Bat[1][b-1].getScore()<<"("<<setw(2)<<Bat[1][b-1].getBallsFaced()<<")";
		if(strike_rotation%2==0)
			cout<<"*";
		cout<<endl;
		if(name==0)
			cout<<endl<<T_name[name+1]<<":-";
		else
			cout<<endl<<T_name[name-1]<<":-";
		cout<<endl<<setw(20)<<Bowl[1][z]<<"   "<<setw(2)<<Bowl[1][z].getRuns()<<"-"<<Bowl[1][z].returnWickets()<<"("<<setw(2)<<Bowl[1][z].returnOvers()<<")";
		if(win_check==0)
		{
			cout<<endl<<"Required Runrate => "<<getReqRR();
			cout<<endl<<T_name[name]<<" needs "<<(scoreTochase+1)-getScore()<<" in "<<(R.getOver()-i)*6<<" balls";
		}
		cout<<endl;
		incrementOver();
		if(buff_check!=0)
			z = buff;
		buff_check=0;
		if(wicket==0 || scoreTochase<getScore())
			break;
	}	
}
