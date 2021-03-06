#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
char arr[10]={'0','1','2','3','4','5','6','7','8','9'},mark;    //mark is X or O
int count=1,num,score1=0,score2=0,i=-1,j=-1;
void init()                   //To start the game again,assigning initial values to variables
{
 for(int i=0;i<10;i++)
 arr[i]=i+48;                //ASCII code of 0 is 48
 i=-1;
 j=-1;
 count=1;
}
void disp()                                      //To display in Tic-Tac-Toe format
{
  clrscr();
  cout<<"\n\n\t\t     Player 1- X     :     Player 2 - O";
  cout<<endl<<"\n\n";
  cout<<"\t\t\t\t "<<arr[1]<<" | "<<arr[2]<<" | "<<arr[3]<<endl;
  cout<<"\t\t\t\t---|---|---"<<endl;
  cout<<"\t\t\t\t "<<arr[4]<<" | "<<arr[5]<<" | "<<arr[6]<<endl;
  cout<<"\t\t\t\t---|---|---"<<endl;
  cout<<"\t\t\t\t "<<arr[7]<<" | "<<arr[8]<<" | "<<arr[9]<<endl;
}
void input();                                    //To input X or O fro user  
int checkwin();                                  //To check if the game is over or not
int main()
{
 char choice;                                     //To play another game or not
 cout<<"\n\n\n\n\t\tWelcome to Tic-Tac-Toe game.";
 cout<<endl<<"\t\tThis is a 2 player Tic Tac Toe game.";
 cout<<endl<<"\t\tPlayer 1 is X and Player 2 is O by default.";
 getch();
 do
 {
   init();
   do
     {
       disp();
       if(count%2 ==1)
	{
	 mark = 'X';
	 cout<<"\n\n\t\t\t\tPlayer 1 enter a number ";
	 cin>>num;
	 comp();
	 i=checkwin();
	}
	 else
	{
	 mark = 'O';
	 cout<<"\n\n\t\t\t\tPlayer 2 enter a number ";
	 cin>>num;
	 comp();
	j=checkwin();
	}
	count++;
	}while(j==-1 && i==-1);
	disp();
	if(i==1)
	{
	cout<<"\n\t\t\t\tPlayer 1 wins. ";
	score1++;
	 }
	else if(j==1)
	 {
	cout<<"\n\t\t\t\tPlayer 2 wins. ";
	score2++;
	 }
	else cout<<"\n\t\t\t\tMatch tied";
	cout<<"\n\t\t\t\tPlayer 1 : "<<score1<<"\tPlayer 2 : "<<score2;
 cout<<"\n\nDo you want to play again (y/n)?";
 cin>>choice;
 }while(choice=='y' || choice == 'Y');
 if(score1>score2)
 cout<<"\n\n\t\t\t\tSeries Winner is Player 1";
 else if(score2>score1)
 cout<<"\n\n\t\tSeries Winner is Player 2";
 else cout<<"\n\n\t\tSeries is tied";
 return 0;
}
/*Function to enter the players choice at right place
   and avoiding repetition*/
void input()
{
 if(num==1 && arr[1]=='1')
	arr[1]=mark;
 else if(num==2 && arr[2]=='2')
	arr[2]=mark;
 else if(num==3 && arr[3]=='3')
	arr[3]=mark;
 else if(num==4 && arr[4]=='4')
	arr[4]=mark;
 else if(num==5 && arr[5]=='5')
	arr[5]=mark;
 else if(num==6 && arr[6]=='6')
	arr[6]=mark;
 else if(num==7 && arr[7]=='7')
	arr[7]=mark;
 else if(num==8 && arr[8]=='8')
	arr[8]=mark;
 else if(num==9 && arr[9]=='9')
	arr[9]=mark;
 else
  {
     cout<<"Invalid Move.";
     count--;
     cin.ignore();
     cin.get();
  }
}
/*Function to check game result
  1 for game over with result
  2 for game in progress
  0 for game over with draw */
int checkwin()
 {
     if (arr[1] == arr[2] && arr[2] == arr[3])

		return 1;
	else if (arr[4] == arr[5] && arr[5] == arr[6])

		return 1;
	else if (arr[7] == arr[8] && arr[8] == arr[9])

		return 1;
	else if (arr[1] == arr[4] && arr[4] == arr[7])

		return 1;
	else if (arr[2] == arr[5] && arr[5] == arr[8])

		return 1;
	else if (arr[3] == arr[6] && arr[6] == arr[9])

		return 1;
	else if (arr[1] == arr[5] && arr[5] == arr[9])

		return 1;
	else if (arr[3] == arr[5] && arr[5] == arr[7])

		return 1;
	else if (arr[1] != '1' && arr[2] != '2' && arr[3] != '3'
		    && arr[4] != '4' && arr[5] != '5' && arr[6] != '6'
		  && arr[7] != '7' && arr[8] != '8' && arr[9] != '9')

		return 0;
	else
		return -1;
}
