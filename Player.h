#include<iostream>
#include<string.h>
#include<iomanip>
char x[20]="";	//For temporary initialization of member = name
using namespace std;
class Player{	
	public:
		char name[20];
		Player(char []);
		void setName(char []);
		char* getName();
};
Player::Player(char n[])
{
	setName(n);
}
void Player::setName(char x[])
{
	strcpy(name, x);
}
char* Player::getName()
{
	return name;
}
class Batter:public Player{
	friend ostream& operator<<(ostream&, Batter&);
	private:
		int score;
		double SR;
		int balls_faced;
	public:
		Batter();
		void setScore(int);
		int getScore()	const;
		void setBallsFaced(int);
		int getBallsFaced()	const;
		void addRuns(int);
		void addBalls(int);
		void updateStats(char[], int, double, int);
};
ostream& operator<<(ostream& os, Batter& B)
{
	os<<B.name;
	return os;
}
Batter::Batter():Player(x)
{
	score = 0;
	SR = 0.0;
	balls_faced = 0;
}
void Batter::setScore(int x)
{
	score = x;
}
int Batter::getScore()	const
{
	return score;
}
void Batter::setBallsFaced(int x)
{
	balls_faced = x;
}
int Batter::getBallsFaced()	const
{
	return balls_faced;
}
void Batter::addRuns(int x)
{
	score+=x;
}
void Batter::addBalls(int x)
{
	balls_faced+=x;
}
void Batter::updateStats(char n[], int r, double sr, int b)
{
	setName(n);
	setScore(r);
	setBallsFaced(b);
}

class Bowler : public Player {
    friend ostream& operator<<(ostream&, Bowler&);
private:
    int overs;
    int runs;
    int wickets;
public:
    Bowler();
    void incrementOvers();
    int returnOvers() const;
    void updateRuns(int);
    int getRuns() const;
    void incrementWickets();
    int returnWickets() const;
};
ostream& operator<<(ostream& os, Bowler& x)
{
    os<< x.name;
    return os;
}
Bowler::Bowler() : Player(x)
{
    overs = 0;
    runs = 0;
    wickets = 0;
}
void Bowler::incrementOvers()
{
    ++overs;
}
void Bowler::incrementWickets()
{
    ++wickets;
}
void Bowler::updateRuns(int x)
{
    runs += x;
}
int Bowler::returnOvers() const
{
    return overs;
}
int Bowler::getRuns() const
{
    return runs;
}
int Bowler::returnWickets() const
{
    return wickets;
}
