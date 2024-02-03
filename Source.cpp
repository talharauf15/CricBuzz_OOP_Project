#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
#include<conio.h>  // To detect key press
#include"Header.h"
using namespace std;

int main()
{
	int choice, choice1;  //for access team
	Team obj1, obj2;
	Match m_obj1;

mainMenu:   // label specifying main menu

	system("cls");
	cout << "\n\n\n\n\n\t\t\t\t--------------------| WELCOME TO CRICBUZZ APP |--------------------\n" << endl;
	cout << "\t\t\t\t\t\t1)     ACCESS TEAM\n" << endl;
	cout << "\t\t\t\t\t\t2)     ADD TEAM\n" << endl;
	cout << "\t\t\t\t\t\t3)     CONDUCT MATCH\n" << endl;
	cout << "\t\t\t\t\t\t4)     SCHEDULE MATCH\n" << endl;
	cout << "\t\t\t\t\t\t5)     Exit\n\n" << endl;
	cout << "\t\t\t\t\t\t       CHOICE: ";
	do
	{
		cin >> choice;
		cout << "ENTER AGAIN!!!" << endl;
	} while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5);

	//greater(for team class)
	if (choice == 1)
	{
		do 
		{
			cout << "Enter USERNAME: ";
			cin >> obj1.admin_username;
			cout << "Enter PASSWORD: ";
			cin >> obj1.admin_password;
			cout << "WRONG! ENTER AGAIN!!!!!" << endl;
		} while ((obj1.admin_username != "admin") || (obj1.admin_password != "admin"));
		
	playerMenu:  // label specifying access team menu

		system("cls");
		cout << "\n\n\n\n\n\t\t\t\t--------------------|   ACCESS TEAM   |--------------------\n" << endl;
		cout << "\t\t\t\t\t\t1)      ADD PLAYER\n" << endl;
		cout << "\t\t\t\t\t\t2)      REMOVE PLAYER\n" << endl;
		cout << "\t\t\t\t\t\t3)      SEARCH PLAYER\n" << endl;
		cout << "\t\t\t\t\t\t4)      UPDATE PLAYER\n" << endl;
		cout << "\t\t\t\t\t\t5)      DISPLAY PLAYERS\n" << endl;
		cout << "\t\t\t\t\t\t6)      UPDATE CAPATAIN\n" << endl;
		cout << "\t\t\t\t\t\t7)      UPDATE COACH\n" << endl;
		cout << "\t\t\t\t\t\t8)      MAIN MENU\n\n" << endl;
		cout << "\t\t\t\t\t\t        CHOICE: ";
		do
		{
			cin >> choice1;
			cout << "ENTER AGAIN!!!" << endl;
		} while (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 4 && choice1 != 5 && choice1 != 6 && choice1 != 7 && choice1 != 8);


		if (choice1 == 1)
		{
			system("cls");
			cout << "\n\n\n\n\n\t\t\t\t--------------------|   ADD PLAYER   |--------------------\n" << endl;
			cout << "\n\t\t\t\t\t\t   Enter team name: ";
			string teamName;
			cin >> teamName;
			obj1.add_Player(teamName);
			cout << "\n\n\t\t(Press 'R' to return to ACCESS TEAM menu)\n\n";

			while (1)  // Wait until the user presses Enter key
			{
				int ch = _getch();
				if (ch == 98 || ch == 114)
				{
					break;
				}
			}
			system("cls");
			goto playerMenu;

		}
		else if (choice1 == 2)
		{
			system("cls");
			cout << "\n\n\n\n\n\t\t\t\t--------------------|   REMOVE PLAYER   |--------------------\n" << endl;

			string playerName, teamName;
			cout << "\t\t\t\t\t\tName of player to be removed: ";
			cin >> playerName;
			cout << "\n\t\t\t\t\t\tTeam of the player: ";
			cin >> teamName;

			obj1.remove_Player(playerName, teamName);

			cout << "\n\n\t\t(Press 'R' to return to ACCESS TEAM menu)\n\n";

			while (1)  // Wait until the user presses Enter key
			{
				int ch = _getch();
				if (ch == 98 || ch == 114)
				{
					break;
				}
			}
			system("cls");
			goto playerMenu;

		}
		else if (choice1 == 3)
		{
			system("cls");
			cout << "\n\n\n\n\n\t\t\t\t--------------------|   SEARCH PLAYER   |--------------------\n" << endl;

			string playerName, teamName;
			cout << "\n\t\t\t\t\t\tName of player to be searched: ";
			cin >> playerName;
			cout << "\n\t\t\t\t\t\tTeam of the player: ";
			cin >> teamName;


			{
				obj1.search_Player(playerName,teamName);
			}

			cout << "\n\n\t\t(Press 'R' to return to ACCESS TEAM menu)\n\n";

			while (1)  // Wait until the user presses Enter key
			{
				int ch = _getch();
				if (ch == 98 || ch == 114)
				{
					break;
				}
			}
			system("cls");
			goto playerMenu;
		}

		else if (choice1 == 4)
		{
			system("cls");
			cout << "\n\n\n\n\n\t\t\t\t--------------------|   UPDATE PLAYER   |--------------------\n" << endl;

			string playerName, teamName;
			cout << "\n\t\t\t\t\t\tName of player to be updated: ";
			cin >> playerName;
			cout << "\n\t\t\t\t\t\tTeam of the player: ";
			cin >> teamName;


			{
				obj1.update_Player(playerName,teamName);
			}


			cout << "\n\n\t\t(Press 'R' to return to ACCESS TEAM menu)\n\n";

			while (1)  // Wait until the user presses Enter key
			{
				int ch = _getch();
				if (ch == 98 || ch == 114)
				{
					break;
				}
			}
			system("cls");
			goto playerMenu;
		}


		else if (choice1 == 5)
		{
			system("cls");
			cout << "\n\n\n\n\n\t\t\t\t--------------------|   DISPLAY TEAM   |--------------------\n" << endl;

			string teamName;
			cout << "\n\t\t\t\t\t\tEnter team's name to display its players: ";
			cin >> teamName;


			{
				obj1.display_Team(teamName);
			}

			cout << "\n\n\t\t(Press 'R' to return to ACCESS TEAM menu)\n\n";

			while (1)  // Wait until the user presses Enter key
			{
				int ch = _getch();
				if (ch == 98 || ch == 114)
				{
					break;
				}
			}
			system("cls");
			goto playerMenu;
		}

		else if (choice1 == 6)
		{
			system("cls");
			cout << "\n\n\n\n\n\t\t\t\t--------------------|   UPDATE CAPTAIN   |--------------------\n" << endl;

			string teamName;
			cout << "\n\t\t\t\t\t\tEnter team's name to update its captain: ";
			cin >> teamName;


			{
				obj1.update_Captain(teamName);
			}


			cout << "\n\n\t\t(Press 'R' to return to ACCESS TEAM menu)\n\n";

			while (1)  // Wait until the user presses Enter key
			{
				int ch = _getch();
				if (ch == 98 || ch == 114)
				{
					break;
				}
			}
			system("cls");
			goto playerMenu;

		}

		else if (choice1 == 7)
		{

			system("cls");
			cout << "\n\n\n\n\n\t\t\t\t--------------------|   UPDATE COACH   |--------------------\n" << endl;

			string teamName;
			cout << "\n\t\t\t\t\t\tEnter team's name to update its coach: ";
			cin >> teamName;


			{
				obj1.update_Coach(teamName);
			}

			cout << "\n\n\t\t(Press 'R' to return to ACCESS TEAM menu)\n\n";

			while (1)  // Wait until the user presses Enter key
			{
				int ch = _getch();
				if (ch == 98 || ch == 114)
				{
					break;
				}
			}
			system("cls");
			goto playerMenu;
		}

		else if (choice1 == 8)
		{
			system("cls");
			goto mainMenu;
		}

	}
	else if (choice == 2)
	{
		system("cls");
		cout << "\n\n\n\n\n\t\t\t\t--------------------|   ADD TEAM   |--------------------\n" << endl;
		cout << "\n\t\t\t\t\t\t   Enter team name: ";
		string teamName;
		cin >> teamName;
		obj1.add_team(teamName);
		cout << "\n\t\t\t\t\t\t   TEAM ADDED SUCCESSFULLY";

		cout << "\n\n\t\t(Press 'R' to return to ACCESS TEAM menu)\n\n";

		while (1)  // Wait until the user presses Enter key
		{
			int ch = _getch();
			if (ch == 98 || ch == 114)
			{
				break;
			}
		}
		system("cls");
		goto mainMenu;
	}
	else if (choice == 3)
	{
		system("cls");
		cout << "\n\n\n\n\n\t\t\t\t--------------------|   CONDUCTING MATCH   |--------------------\n" << endl;
		m_obj1.conductMatch();
		cout << "\n\n\t\t(Press 'R' to return to ACCESS TEAM menu)\n\n";

		while (1)  // Wait until the user presses Enter key
		{
			int ch = _getch();
			if (ch == 98 || ch == 114)
			{
				break;
			}
		}
		system("cls");
		goto mainMenu;
	}
	else if (choice == 4)
	{
		system("cls");
		cout << "\n\n\n\n\n\t\t\t\t--------------------|   SCHEDULING MATCH   |--------------------\n" << endl;
		m_obj1.scheduleMatch();
		cout << "\n\n\t\t(Press 'R' to return to ACCESS TEAM menu)\n\n";

		while (1)  // Wait until the user presses Enter key
		{
			int ch = _getch();
			if (ch == 98 || ch == 114)
			{
				break;
			}
		}
		system("cls");
		goto mainMenu;
	}
	return 0;
}