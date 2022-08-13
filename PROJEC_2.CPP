#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
#include<process.h>
#include<math.h>
#include<fstream.h>
#include<graphics.h>
#include<ctype.h>
#include<time.h>

char grid[3][3], temp[9], x='X', o='O', ch, lb5='\0', choice4;
int choice1=0, i=0, j=0, k=0, num=0, flag1=0, flag2=0, lb1=0,
    lb2=0, lb3=0, lb4=0, Xwins=0, Owins=0, lb6=0, lbb=0, tie=0;


void makegrid();
void initiater();
int randnumgen();
int checkempty(int b);                          //Core functions of
void check();                                   //the program
void entry(int a, char q);
void game();
void windecl();
void guide();

void totalscore(char lb5);                        //File handling
void scoreboard(int choice2);                    // functions
void playerlist(int choice3);

void buzzer();
void welsound();                                 //Sound functions
void beeper();


void main()
{
 clrscr();
 welsound();
 playerlist(0);
 guide();
 delay(12754);

 ch='y';
 while(ch=='y'||ch=='Y')
 {
  lb1:
  ;
  clrscr();
  choice1=0; i=0; j=0; k=0; num=0; flag1=0; flag2=0; lb1=0;
  lb2=0; lb3=0; lb4=0;  lb6=0; lbb=0; tie=0;
  clrscr();
  cout<<"\n\t\t\t  MENU- "
      <<"\n\t\t\t  1-Player vs. Player (PvP)"
      <<"\n\t\t\t  2-Player vs. Computer (PvC)"
      <<"\n\t\t\t  3-Game Guide"
      <<"\n\t\t\t  4-High Score"
      <<"\n\t\t\t  5-EXIT"
      <<"\n\n\t\t\t  Enter choice....";
  cin>>choice1;

  if((choice1<1||choice1>5))
  {
   cout<<"\nWrong choice!!\nRe-enter.";
   delay(1000);
   goto lb1;
  }
  else if(choice1==5)
  {
   buzzer();
   exit(0);
  }
  else if(choice1==4)
  {
   scoreboard(1);
   beeper();
  }
  else if(choice1==3)
  {
   beeper();
   guide();
   delay(12500);
   beeper();
  }
  else if(choice1==1||choice1==2)
  {
   delay(100);
   initiater();

   makegrid();

   game();
				  // totalscore(lb5);
   scoreboard(0);                 // To check how many wins
   scoreboard(1);                 // of both X and O are registered
  }                               // Easter Egg or Coder's tool
  delay(1500);
  clrscr();
  cout<<"\n\n\n\nGo to Main Menu?(Y/N)";
  cin>>ch;
  delay(1000);
 }
 exit(0);
 getch();
}
void makegrid()
{
	int gd=DETECT, gm;
	initgraph(&gd,&gm,"//turboc3//bgi");
	cout<<"\n\n\n\n\n\t\t\t     "           // Forms a 3*3 grid using
	    <<grid[0][0]<<"\t\t  "              // line() function of
	    <<grid[0][1]<<"\t      "            // graphics module
	    <<grid[0][2]<<"  \n"

	    <<"\n\n\n\n\n\t\t\t     "
	    <<grid[1][0]<<"\t\t  "
	    <<grid[1][1]<<"\t      "
	    <<grid[1][2]<<"  \n"

	    <<"\n\n\n\n\n\t\t\t     "
	    <<grid[2][0]<<"\t\t  "
	    <<grid[2][1]<<"\t      "
	    <<grid[2][2]<<"  \n";

	for(i=190;i<490;i++)
	{
		 line(190,50,i,50);
		 delay(0.2);
		 line(188,48,i+2,48);    //Top-Horizontal
		 delay(0.2);
		 line(186,46,i+4,46);
		 delay(0.2);
	}

	for(i=50;i<320;i++)
	{
		line(490,50,490,i);
		delay(0.2);
		line(492,48,492,i+2);    //Right-Vertical
		delay(0.2);
		line(494,46,494,i+4);
		delay(0.2);
	}

	for(i=490;i>190;i--)
	{
		line(490,320,i,320);
		delay(0.2);
		line(492,322,i-2,322);   //Down-Horizontal
		delay(0.2);
		line(494,324,i-4,324);
		delay(0.2);
	}

	for(i=320;i>50;i--)
	{
		line(190,320,190,i);
		delay(0.2);
		line(188,322,188,i-2);   //Left-Vertical
		delay(0.2);
		line(186,324,186,i-4);
		delay(0.2);
	}

		line(290,50,290,320);    //Horizontal1
		line(390,50,390,320);    //Horizontal2
		line(190,140,490,140);   //Vertical1
		line(190,230,490,230);   //Vertical2

		getch();
		closegraph();
}

void initiater()
{
 int asgn=49;   //49='1'
 for(i=0;i<3;i++)                  // Assigns values 1 to 9 to all
  for(j=0;j<3;j++)                 // blocks of grid[][], and
  {                                // also assigns 1 to 9 values to
   grid[i][j]=asgn;                // temp[]
   asgn++;
  }
 asgn=49;
 for(i=0;i<9;i++)
 {
  temp[i]=asgn;
  asgn++;
 }
}

int randnumgen()                                   // This module generates
{                                                  // a random number between
 randomize();                                      // 1-9, this(random number)
 int t, randnum=0;                                 // operates as the
 lb4:                                              // computer's input choice
 t=0;                                              // in PvC mode.
 randnum=random(2)+random(3)+random(3)+random(4)+1; //Primitive, yet effective
 t=checkempty(randnum);                            // and works good.
 if(t!=1)
  goto lb4;
 else
  return randnum;

}

void entry(int v, char q)
{
 switch(v)                                 // Enter the desired character('q')
 {                                         // at the desired places
  case 1: grid[0][0]=q; temp[0]=q;         // referred to by parameter 'v'
	  break;                           // Stores values to the
  case 2: grid[0][1]=q; temp[1]=q;         // corresponding element of temp[]
	  break;
  case 3: grid[0][2]=q; temp[2]=q;
	  break;
  case 4: grid[1][0]=q; temp[3]=q;
	  break;
  case 5: grid[1][1]=q; temp[4]=q;
	  break;
  case 6: grid[1][2]=q; temp[5]=q;
	  break;
  case 7: grid[2][0]=q; temp[6]=q;
	  break;
  case 8: grid[2][1]=q; temp[7]=q;
	  break;
  case 9: grid[2][2]=q; temp[8]=q;
	  break;
  default:clrscr();
	  delay(100);
	  cout<<"\t\tWrong choice!!";
	  delay(900);
	  lb6=1;
 }
}


void game()                              // Controls user input
{                                        // runs the game through
 tie=0;
 for(int i=0;i<9;i++)                    // different function calls
 {                                       // Registers the winning player(X/O)
  tie++;
  if(i%2==0)
  {
   flag1=0;
   k=0;
   lb1:
   ;
   lb6=0;
   cout<<"\n\n\n\n\n\n\tPlayer 1(X)- Enter number: ";
   cin>>num;
   beeper();
   k=checkempty(num);
   if(k==1)
   {
    entry(num,x);
    if(lb6==1) goto lb1;
    makegrid();
    check();
    if(lbb==1)
    {
     goto lb7;
    }
    lb5=o;
   }
   else if(k!=1)
   {
    cout<<"Box is already occupied, choose another.....";
    buzzer();
    delay(1000);
    goto lb1;
   }
  }

  else if(i%2!=0)
  {
   flag1=0;
   k=0;
   lb2:
   ;
   lb6=0;
   if(choice1==1)
   {
    cout<<"\n\n\n\n\n\n\tPlayer 2(O)- Enter number: ";
    cin>>num;
    beeper();
   }
   else if(choice1==2)
   {
    num=randnumgen();
   }
   k=checkempty(num);
   if(k==1)
   {
   entry(num,o);
   if(lb6==1)
   {
    goto lb2;
   }
   makegrid();
   check();
   if(lbb==1)
   {
    goto lb7;
   }
   lb5=x;
   }
   else if(k!=1)
   {
    cout<<"Box is already occupied, choose another.....";
    buzzer();
    delay(1000);
    goto lb2;
   }
  }
 }

 lb7:
 ;
}


void windecl()                     // Declares a win by greeting users with
{                                  // a message
 if(choice1==2&&lb5==o)
 {
  cout<<"\n"
      <<"\n\t\t|\\------------------------------/|"
      <<"\n\t\t||                              ||"
      <<"\n\t\t||     Computer Wins            ||"
      <<"\n\t\t||                              ||"
      <<"\n\t\t|/------------------------------\\|";
 }
 else if(choice1==1||(choice1==2&&lb5==x))
 {
  cout<<"\n"
      <<"\n\t\t|\\------------------------------/|"
      <<"\n\t\t||    Player-"<<lb5<<" wins             ||"
      <<"\n\t\t||      CONGRATULATIONS         ||"
      <<"\n\t\t||                              ||"
      <<"\n\t\t|/------------------------------\\|";
 }
 delay(2000);
}

void check()           // Checks for winning condition
{                      // For all rows, columns and diagonals
 for(i=0;i<3;i++)
 {
  if((grid[i][0]==grid[i][1])&&(grid[i][0]==grid[i][2])&&(grid[i][1]==grid[i][2]))
  {
   flag1=1;  //Comparision for all rows
  }
  else if((grid[0][i]==grid[1][i])&&(grid[0][i]==grid[2][i])&&(grid[1][i]==grid[2][i]))
  {
   flag1=1;  //Comparision for all columns
  }
  else if((grid[0][0]==grid[1][1])&&(grid[0][0]==grid[2][2])&&(grid[1][1]==grid[2][2]))
  {
   flag1=1;  //Comparision for Main diagonal
  }
  else if((grid[0][2]==grid[1][1])&&(grid[0][2]==grid[2][0])&&(grid[1][1]==grid[2][0]))
  {
   flag1=1;  //Comparision for Secondary diagonal
  }
 }

 if(flag1==1)
 {
  delay(800);
  windecl();
  lbb=1;
 }
 if(flag1==0&&tie>=9)
 {
  cout<<"\n\n\t\t\t\t\IT'S A TIE!!"<<"\nBETTER LUCK NEXT TIME!";
 }
}

int checkempty(int a)                  // Check if the place referred to
{                                      // by passed argument is empty or not
 if(temp[a-1]==x||temp[a-1]==o)        // in the grid[][] through
  flag2=0;                             // ananlysing temp[]
 else
  flag2=1;

 return flag2;
}

void guide()                        //GUIDE
{
 cout<<"\nThe TIC-TAC-TOE game's board is similar to that of "
     <<"# key\nor it looks something like this:\n "
     <<"\t\t\t    _|_|_"<<endl
     <<"\t\t\t    _|_|_ "<<endl
     <<"\t\t\t     | |  "
     <<"\nIn this gaps turn by turn crosses "
     <<"and zeroes have to be filled up "
     <<"TIC-TAC-TOE is basically a X and O "
     <<"game in which the player has to complete 3 "
     <<"\ncrosses or zeros which may be horizontal "
     <<"vertical or even  diagonal\n\n"
     <<"\t\t\t     x|x|x"<<endl
     <<"\t\t\t     -|-|-"<<endl
     <<"\t\t\t      | | "<<endl
     <<endl<<endl
     <<"OR\t\t\t     x|_|_  "<<endl
     <<"\t\t\t     -|x|_   "<<endl
     <<"\t\t\t     -|-|x"
     <<endl<<endl
     <<"OR\t\t\t     x|_|_"<<endl
     <<"\t\t\t     x|_|_"<<endl
     <<"\t\t\t     x| | ";
}


void totalscore(char lb5)               // Registers the total score
{                                       // Tool for the coder/developer
 if(lb5==o) Xwins++;
 else if(lb5==x) Owins++;
 else delay(1);
 cout<<"\nTotal Score: "
     <<"Total X wins- "<<Xwins
     <<"Total O wins- "<<Owins;
}


void scoreboard(int choice2)              // Registers the score in a
{                                         // single run, with ot without
 ofstream inout;                          // multiplae iterations
 if(choice2==0)
 {
  if(lb5==x)
  {
   inout.open("score_x.dat",ios::out|ios::binary|ios::app);
   char ch1='a';
   inout.put(ch1);
   inout.close();
  }

  if(lb5==o)
  {
   inout.open("score_o.dat",ios::out|ios::binary|ios::app);
   char ch2='b';
   inout.put(ch2);
   inout.close();
  }
 }

 else if(choice2==1)
 {
  ifstream in1, in2;
  in1.open("score_x.dat",ios::in|ios::binary);
  in2.open("score_o.dat",ios::in|ios::binary);
  char ch1='\0', ch2='\0';
  int count1=0, count2=0;
  while(!in1.eof())
  {
   in1.get(ch1);
   if(islower(ch1))
    count1+=1;
  }
  while(!in2.eof())
  {
   in2.get(ch2);
   if(islower(ch2))
    count2+=1;
  }

  in1.close();
  in2.close();
  clrscr();
  cout<<"\n*SCOREBOARD*"
      <<"\n ---------- ";
  cout<<"\nX- "<<count1;
  cout<<"\nO- "<<count2;
  delay(1000);
 }

 else
 {
  cout<<"*FATAL ERROR DETECTED*";
  delay(100);
  exit(0);
 }
}


void playerlist(int choice3)                     // Stores names of all players
{                                                // who played the game
 char name1[40], name2[40];
 fstream inout;
 if(choice3==0)
 {
  inout.open("PLAYERLIST.dat",ios::out|ios::app);
  cout<<"\nEnter name of Player 1: ";
  cin.getline(name2,40);
  inout<<"\n"<<name2;
  cout<<"\nEnter name of Player 2: ";
  cin.getline(name2,40);
  inout<<"\n"<<name2;
 }
}




void welsound()        // Welcome sound module
{
 for(i=0;i<2;i++)
 {
  sound(220);
  delay(90);
  sound(277);
  delay(90);
  sound(330);
  delay(300);
  sound(440);
  delay(90);
 }
 for(i=0;i<2;i++)
 {
  sound(196);
  delay(90);
  sound(247);
  delay(90);
  sound(294);
  delay(90);
  sound(392);
  delay(90);
 }
 for(i=0;i<2;i++)
 {
  sound(174);
  delay(90);
  sound(220);
  delay(90);
  sound(262);
  delay(90);
  sound(349);
  delay(90);
 }
 nosound();
}

void buzzer()                   // Buzzer module
 {
  for(int j=0;j<5;j++)
  {
   for(int i=659;i<880;i++)
  {
  sound(i);
  delay(1);
  nosound();
  }
 }
}

void beeper()                   // Beep sound module
{
 for(i=880;i>220;i--)
 {
  sound(i);
  delay(1);
  nosound();
 }
}