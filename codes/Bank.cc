//Language: C\C++
//downloaded from www.cbseportal.com

//****************************************************************
//PROJECT BANKING SYSTEM 
//****************************************************************
//INCLUDES HEADER FILES
//****************************************************************

#include <iostream.h>
#include <fstream.h>
#include <process.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <iomanip.h>
#include <graphics.h>


typedef char option[15];
const int ROW = 10,COL = 10;

int scan;    // To hold the special characters for moving the prompt in menu
int ascii;
//****************************************************************
// To display the main menu options
//****************************************************************
option a[]= {
			 "NewAccount",
			 "ListofAccounts",
			 "IndAccount",
			 "DailyTrans",
			 "MonthlyReport",
			 "EditAccount",
			 "Exit"};

// Displays the modify menu options
option b[] = {
				"Modify Account",
				"Closeaccount",
				"Quit"
			};

// Function used to do screening
class main_menu
{
	int i,done;

	public:
		void normalvideo(int x,int y,char *str);
		void reversevideo(int x,int y,char *str);
		void box(int x1,int y1,int x2,int y2);
		char menu();
		void control_menu();
		char e_menu();
		void edit_menu();
		void help(void);
};




//****************************************************************
/* Class member functions for drawing boxes */
//****************************************************************

class shape
{
	public:
		void line_hor(int, int, int, char);
		void line_ver(int, int, int, char);
		void box(int, int, int, int, char);
};


// Class contains the initial deposit of customers
class initial
{
 public:
     void add_to_file(int, char t_name[30], char t_address[30], float);
	    // For initial deposits in customers account
     void display_list(void); // Displaying customers account list
     void delete_account(int); // Deleting customers account
     void update_balance(int, char t_name[30], char t_address[30], float);
	    // For updating the customer account
     void modify(void);      // To modify the customer account information
     int last_accno(void); // To know the last account number
     int found_account(int);
	    // To found the account is in "INITIAL.dat" or not
     char *return_name(int);
	    // Function for validation entry of customer name
     char *return_address(int);
	    // Function for validation entry of customer address
     float give_balance(int);
	    // To print the balance amount of a particular customer
     int recordno(int);
     void display(int); // To display the customer account

 private:
     void modify_account(int, char t_name[30], char t_address[30]);
	    // Function to modify the customer account
     int accno;
     char name[30], address[30];
     float balance;
};

// Class contains the customers daily transaction entry
class account
{
 public:
     void new_account(void);    // Function to create a new account
     void close_account(void);  // Function to close an account
     void display_account(void);// Function to display the accounts
     void transaction(void);    // To display the transaction process
     void clear(int, int);      // Function to perform a clear screen function
     void month_report(void);   // Function to list monthly transaction report

 private:
     void add_to_file(int,int,int,int,char,char t_type[10],float,float,float);
	    // Function to add transaction records
     void delete_account(int);  // Function to delete a transaction record
     int no_of_days(int, int, int, int, int, int);
	    // Function to find the total days
     float calculate_interest(int, float);
	    // Function for calculating interest of an account
     void display(int);         // Function to display a transaction account
     void box_for_display(int); // Function for displaying box
     int accno;
     char type[10];             // Account type as Cheque or Cash
     int dd, mm, yy;            // To store the system date/ Enter date
     char tran;                 // As the account type is Deposit or Withdraw
     float interest, amount, balance;
};

// Function to displays all the menu prompt messages from the pointer array of
// option a[]
void main_menu::normalvideo(int x,int y,char *str)
{
     gotoxy(x,y);
     cprintf("%s",str);
}

// Function to move the cursor on the menu prompt with a reverse video color
void main_menu::reversevideo(int x,int y,char *str)
{
     textcolor(5+143);
     textbackground(WHITE);
     gotoxy(x,y);
     cprintf("%s",str);
     textcolor(GREEN);
     textbackground(BLACK);
}

void main_menu::box(int x1,int y1,int x2,int y2)
{
     for(int col=x1;col<x2;col++)
     {
      gotoxy(col,y1);
      cprintf("%c",196);
      gotoxy(col,y2);
      cprintf("%c",196);
      }

     for(int row=y1;row<y2;row++)
     {
      gotoxy(x1,row);
      cprintf("%c",179);
      gotoxy(x2,row);
      cprintf("%c",179);
      }
     gotoxy(x1,y1);
     cprintf("%c",218);
     gotoxy(x1,y2);
     cprintf("%c",192);
     gotoxy(x2,y1);
     cprintf("%c",191);
     gotoxy(x2,y2);
     cprintf("%c",217);
}

char main_menu::menu()
{
     clrscr();
     textcolor(22);
     box(20, 6, 65, 20);
     box(18, 4, 67, 22);
     textcolor(5+143);
     gotoxy(36, 5);
     textbackground(BLUE);
     cprintf("B A N K I N G");
     textbackground(BLACK);
     textcolor(22);
     for(i = 1; i < 7; i++)
     normalvideo(32, i+10, a[i]);
     reversevideo(32, 10, a[0]);
     i = done = 0;
     _setcursortype(_NOCURSOR);
     do
     {
      int key = getch();
      switch (key)
      {
       case 00:
	       key = getch();
	       switch (key)
	       {
		case 72:
		  normalvideo(32, i+10, a[i]);
		  i--;
		  if (i == -1)
		  i = 6;
		  reversevideo(32,i+10,a[i]);
		  break;
		case 80:
		  normalvideo(32, i+10, a[i]);
		  i++;
		  if (i == 7)
		  i = 0;
		  reversevideo(32, i+10, a[i]);
		  break;
		  }
	       break;
       case 13:
	       done = 1;
       }
      }
     while (!done);
     _setcursortype(_NOCURSOR);
     return(i+49);
}

// The function main_menu() is used to display the main menu of banking system
void main_menu::control_menu()
{
     char choice;
     account a;
     do
     {
      choice = menu();
      clrscr();
      switch (choice)
      {
       case '1':
		_setcursortype(_NORMALCURSOR);
		box(3, 1, 75, 24);
		box(5, 2, 73, 23);
		a.new_account(); // New account member function
		break;
       case '2':
		box(3, 1, 75, 24);
		box(5, 2, 73, 23);
		initial ini;
		ini.display_list(); // Global list of account function
		break;
       case '3':
		box(3, 1, 75, 24);
		box(5, 2, 73, 23);
		_setcursortype(_NORMALCURSOR);
		a.display_account();
		// Displaying individual accounts all transactions
		break;
       case '4':
		box(3, 1, 75, 24);
		box(5, 2, 73, 23);
		account a;
		_setcursortype(_NORMALCURSOR);
		a.transaction(); // Daily transaction for individual account
		break;
       case '5':
		box(3, 1, 75, 24);
		box(5, 2, 73, 23);
		_setcursortype(_NORMALCURSOR);
		a.month_report(); // Monthly report for any account
		break;
       case '6':
		box(3, 1, 75, 24);
		box(5, 2, 73, 23);
		gotoxy(10,10);
		edit_menu();// Sub menu for modifying or deleting any account
		break;
       case '7' :exit(0);
       }
      } while (choice != 6);
}

// This function is used to return the cursor position to the edit menu
// function where the menu prompt will valid
char main_menu::e_menu()
{
      clrscr();
      textcolor(22);
      box(25,6,60,15);
      box(23,4,62,17);
      textcolor(5+143);
      gotoxy(34,5);
      textbackground(GREEN);
      cprintf("E D I T  -  M E N U");
      textcolor(22);
      textbackground(BLACK);
      for (i = 1;i < 3; i++)
      normalvideo(32, i+10, b[i]);
      reversevideo(32, 10, b[0]);
      i = done = 0;
      _setcursortype(_NOCURSOR);
      do
      {
       int key = getch();
       switch (key)
       {
	case 00:
		key = getch();
		switch (key)
		{
		 case 72:
		   normalvideo(32, i+10, b[i]);
		   i--;
		   if (i == -1)
		   i = 2;
		   reversevideo(32, i+10, b[i]);
		   break;
	case 80:
		normalvideo(32, i+10, b[i]);
		i++;
		if (i == 3)
		i=0;
		reversevideo(32, i+10, b[i]);
		break;
	}
	break;
	case 13:
		done = 1;
	}
       }while (!done);
       _setcursortype(_NOCURSOR);
       return(i+49);
}

/* Function for edit menu with account modification and close */
void main_menu::edit_menu()
{
      char choice;
      account a;
      do
      {
       choice = e_menu();
       clrscr();
       switch (choice)
       {
	case '1':
		 box(3, 1, 75, 24);
		 box(5, 2, 73, 23);
		 initial ini;
		 _setcursortype(_NORMALCURSOR);
		 ini.modify();
		 break;
	case '2':
		 box(3, 1, 75, 24);
		 box(5, 2, 73, 23);
		 account a;
		 _setcursortype(_NORMALCURSOR);
		 a.close_account();
		 break;
	case '3':
		 return;
	}
       } while (choice != 6);
}

/* Function to draw horizontal line */
void shape::line_hor(int column1, int column2, int row, char c)
{
      for (column1; column1 <= column2; column1++)
      {
       gotoxy(column1, row);
       cout << c;
       }
}

/* Function to draw vertical line */
void shape::line_ver(int row1, int row2, int column, char c)
{
      for (row1; row1 <= row2; row1++)
      {
       gotoxy(column, row1);
       cout << c;
       }
}

/* function for drawing box */
void shape::box(int column1, int row1, int column2, int row2, char c)
{
      char ch = 218;
      char c1, c2, c3, c4;
      char l1 = 196, l2 = 179;
      if (c == ch)
      {
       c1 = 218;
       c2 = 191;
       c3 = 217;
       c4 = 217;
       l1 = 196;
       l2 = 179;
       }
      else
      {
       c1 = c;
       c2 = c;
       c3 = c;
       c4 = c;
       l1 = c;
       c2 = c;
       }
      gotoxy(column1, row1);
      cout << c1;
      gotoxy(column2, row1);
      cout << c2;
      gotoxy(column1, row2);
      cout << c3;
      gotoxy(column2, row2);
      cout << c4;
      column1++;
      column2--;
      line_hor(column1, column2, row1, l1); //Horizontal line
      line_hor(column1, column2, row2, l1);
      column1--;
      column2++;
      row1++;
      row2--;
      line_ver(row1, row2, column1, l2); // Vertical line
      line_ver(row1, row2, column2, l2);
}


/* Function to display help about this project */
void main_menu::help(void)
{
      clrscr();
      setbkcolor(7);
      settextstyle(7,HORIZ_DIR,4);
      outtextxy(70,20,"Welcome to Banking System");
      settextstyle(2,HORIZ_DIR,5);
      outtextxy(60,100,"You can keep record of daily banking transaction");
      delay(2);
      outtextxy(60,130,"This program is capable of holding any no. of A/c");
      delay(2);
      outtextxy(60,160,"-In first option you can open new A/c");
      delay(2);
      outtextxy(60,190,"-In second option you can see the list of all A/c's");
      delay(2);
      outtextxy(60,220,"-In third option you can see all trans. of ind. A/c");
      delay(2);
      outtextxy(60,250,"-In fourth optiion you can do banking transactions");
      delay(2);
      outtextxy(60,280,"(Deposit/Withdraw)");
      delay(2);
      outtextxy(60,310,"-In fifth opt. you can take monthly ind. A/c report");
      delay(2);
      outtextxy(60,340,"-In sixth opt. you can modify or delete any account");
      delay(2);
      outtextxy(60,370,"Note-:Opening amount should not less that Rs. 500/-");
      delay(2);
      outtextxy(60,400,"-And last option is Quit (Exit to Window)");
      delay(2);
      settextstyle(7,HORIZ_DIR,4);
      outtextxy(80,420,"Press any key to continue...");
      getch();
}

/* Function for modifying the existing accounts */
void initial::modify(void)
{
      clrscr();
      int j;
      char t_acc[10
