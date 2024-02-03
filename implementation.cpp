#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>  // To detect key press
#include"Header.h"
using namespace std;

void Player::add_Player() {}
void Player::remove_Player() {}
void Player::search_Player() {}
void Player::update_Player() {}
//class: TEAM

Team::Team()
{
	currentNumberOfPlayers = 0;
}

//player addition
void Team::add_Player(string teamName)
{
	string Data = teamName;
	Data += "_data.txt";
	ifstream readFile(Data);
	if (!readFile.is_open())
	{
		cout << "\n\n\t\t\t\t\t    An error occured opening '" << Data << "' file\n";
		return;
	}
	string line;

	bool found1 = false;
	while (getline(readFile, line))
	{
		if (line == teamName)
		{
			found1 = true;
		}
	}
	if (1)
	{
		string fileName2 = teamName + "_data.txt";
		ofstream teamName(fileName2, ios::app);
		if (!teamName.is_open())
		{
			cout << "\n\n\t\t\t\t\t    An error occured opening '" << fileName2 << "' file during ofstream\n";
			return;
		}
		{
			if (currentNumberOfPlayers >= 11)
			{
				cout << "\n\t\t\t\t\t\t   The team already has 11 players\n";
				return;
			}

			this->currentNumberOfPlayers++;
			cout << "\n\t\t\t\t\t\t   Enter PLAYER NAME: ";
			cin >> name;
			teamName << name << endl;
			cout << "\n\t\t\t\t\t\t   Enter PLAYER SHIRT NO: ";
			cin >> shirt_no;
			teamName << shirt_no << endl;
			cout << "\n\t\t\t\t\t\t   Enter average: ";
			cin >> average;
			teamName << average << endl;
			cout << "\n\t\t\t\t\t\t   Enter PLAYER RANKING: ";
			cin >> ranking;
			teamName << ranking << endl;
			cout << "\n\t\t\t\t\t\t   Enter TOTAL RUNS: ";
			cin >> total_runs;
			teamName << total_runs << endl;
			cout << "\n\t\t\t\t\t\t   Enter TOTAL MATCHES: ";
			cin >> total_matches;
			teamName << total_matches << endl;
			cout << "\n\t\t\t\t\t\t   Enter TOTAL WICKETS: ";
			cin >> total_wickets;
			teamName << total_wickets << endl;
			cout << "\n\t\t\t\t\t\t   PLAYER DATA ADDED SUCCESSFULLY!" << "\n\n";
			teamName << name << "end" << endl;
		}
		teamName.close();
	}
	else
	{
		cout << "\n\n\t\t\t\t\t\t    No such team exists\n: ";
	}
}

void Team::remove_Player(string playerName, string teamName)
{
	teamName += "_data.txt";
	string playersData[11];  // At max 11 players
	string line;
	int playersCounter = 0;
	ifstream readFile(teamName);
	if (!readFile.is_open())
	{
		cout << "\n\n\t\t\t\t\t    An error occured opening '" << teamName << "' file\n";
		return;
	}


	while (getline(readFile, line))
	{
		bool skip = false;
		if (line != playerName)
		{
			playersData[playersCounter] += line;
			playersData[playersCounter] += "\n";
		}
		else
			skip = true;

		for (int i = 0;i < 7;i++)
		{
			getline(readFile, line);
			if (!skip)
			{
				playersData[playersCounter] += line;
				playersData[playersCounter] += "\n";
			}
		}
		if (!skip)
		{
			playersCounter++;
		}
	}

	ofstream writeFile(teamName);
	for (int i = 0;i < playersCounter;i++)
	{
		writeFile << playersData[i];
	}

	cout << "\n\n\t\t\t\t\t\tPLAYER REMOVED SUCCESSFULLY\n: ";
	this->currentNumberOfPlayers--;
}

void Team::add_team(string teamName)
{
	this->team_name = teamName;
	string filename = "data.txt";
	ofstream data(filename, ios::app);
	data << teamName << endl;
	data.close();
}

void Team::search_Player(string playerName, string teamName)
{
	teamName += "_data.txt";
	ifstream readFile(teamName);
	if (!readFile.is_open())
	{
		cout << "\n\n\t\t\t\t\t    An error occured opening '" << teamName << "' file\n";
		return;
	}
	string line;

	bool found = false;
	while (getline(readFile, line))
	{
		if (line == playerName)
		{
			found = true;
			cout << "\n\t\t\t\t\t\t   Player Name: " << line << endl;

			getline(readFile, line);
			cout << "\n\t\t\t\t\t\t   Shirt Number: " << line << endl;

			getline(readFile, line);
			cout << "\n\t\t\t\t\t\t   Average: " << line << endl;

			getline(readFile, line);
			cout << "\n\t\t\t\t\t\t   Ranking: " << line << endl;

			getline(readFile, line);
			cout << "\n\t\t\t\t\t\t   Total Runs: " << line << endl;

			getline(readFile, line);
			cout << "\n\t\t\t\t\t\t   Total Matches: " << line << endl;

			getline(readFile, line);
			cout << "\n\t\t\t\t\t\t   Total Wickets: " << line << endl;

			getline(readFile, line);
		}
	}

	if (!found)
	{
		cout << "\n\t\t\t\t\t\t   | No such player exists |\n";
	}
}

void Team::update_Player(string playerName, string teamName)
{
	teamName += "_data.txt";
	string playersData[11];  // At max 11 players
	string line;
	string temp;
	int playersCounter = 0;
	ifstream readFile(teamName);
	if (!readFile.is_open())
	{
		cout << "\n\n\t\t\t\t\t    An error occured opening '" << teamName << "' file\n";
		return;
	}

	while (getline(readFile, line))
	{
		playersData[playersCounter] += line;
		playersData[playersCounter] += "\n";

		bool found = false;
		if (line == playerName)
		{
			found = true;
		}

		if (found)
		{
			getline(readFile, line);
			cout << "\n\t\t\t\t\t\t   Enter PLAYER SHIRT NO: ";
			cin >> temp;
			playersData[playersCounter] += temp;
			playersData[playersCounter] += "\n";

			getline(readFile, line);
			cout << "\n\t\t\t\t\t\t   Enter average: ";
			cin >> temp;
			playersData[playersCounter] += temp;
			playersData[playersCounter] += "\n";

			getline(readFile, line);
			cout << "\n\t\t\t\t\t\t   Enter PLAYER RANKING: ";
			cin >> temp;
			playersData[playersCounter] += temp;
			playersData[playersCounter] += "\n";

			getline(readFile, line);
			cout << "\n\t\t\t\t\t\t   Enter TOTAL RUNS: ";
			cin >> temp;
			playersData[playersCounter] += temp;
			playersData[playersCounter] += "\n";

			getline(readFile, line);
			cout << "\n\t\t\t\t\t\t   Enter TOTAL MATCHES: ";
			cin >> temp;
			playersData[playersCounter] += temp;
			playersData[playersCounter] += "\n";

			getline(readFile, line);
			cout << "\n\t\t\t\t\t\t   Enter TOTAL WICKETS: ";
			cin >> temp;
			playersData[playersCounter] += temp;
			playersData[playersCounter] += "\n";

			getline(readFile, line);
			playersData[playersCounter] += line;
			playersData[playersCounter] += "\n";

		}

		else if (!found)
		{
			for (int i = 0;i < 7;i++)
			{
				getline(readFile, line);
				playersData[playersCounter] += line;
				playersData[playersCounter] += "\n";
			}
		}
		playersCounter++;
	}

	ofstream writeFile(teamName);
	for (int i = 0;i < playersCounter;i++)
	{
		writeFile << playersData[i];
	}

	cout << "\n\t\t\t\t\t\t   PLAYER DATA UPDATED SUCCESSFULLY!" << "\n\n";
}

void Team::update_Captain(string teamName)
{
	ifstream readFile("captains.txt");
	string data[20];
	int dataCounter = 0;
	if (!readFile.is_open())
	{
		cout << "\n\n\t\t\t\t\t    An error occured opening 'captains.txt' file\n";
		return;
	}
	string line;
	string newName;

	cout << "\n\t\t\t\t\t\t   Enter new captain's name: ";
	cin >> newName;

	while (getline(readFile, line))
	{
		data[dataCounter] += line;
		data[dataCounter] += "\n";

		if (line == teamName)
		{
			getline(readFile, line);
			data[dataCounter] += newName;
			data[dataCounter] += "\n";
		}
		else
		{
			getline(readFile, line);
			data[dataCounter] += line;
			data[dataCounter] += "\n";
		}
		dataCounter++;
	}

	ofstream writeFile("captains.txt");
	for (int i = 0;i < dataCounter;i++)
	{
		writeFile << data[i];
	}
	cout << "\n\n\t\t\t\t\t\tCAPTAIN UPDATED SUCCESSFULLY\n: ";
}

void Team::update_Coach(string teamName)
{
	ifstream readFile("coaches.txt");
	string data[20];
	int dataCounter = 0;
	if (!readFile.is_open())
	{
		cout << "\n\n\t\t\t\t\t    An error occured opening 'captains.txt' file\n";
		return;
	}
	string line;
	string newName;

	cout << "\n\t\t\t\t\t\t   Enter new coach's name: ";
	cin >> newName;

	while (getline(readFile, line))
	{
		data[dataCounter] += line;
		data[dataCounter] += "\n";

		if (line == teamName)
		{
			getline(readFile, line);
			data[dataCounter] += newName;
			data[dataCounter] += "\n";
		}
		else
		{
			getline(readFile, line);
			data[dataCounter] += line;
			data[dataCounter] += "\n";
		}
		dataCounter++;
	}

	ofstream writeFile("coaches.txt");
	for (int i = 0;i < dataCounter;i++)
	{
		writeFile << data[i];
	}

	cout << "\n\n\t\t\t\t\t\tCOACH UPDATED SUCCESSFULLY\n: ";

}

void Team::display_Team(string teamName)
{
	teamName += "_data.txt";
	string line;
	ifstream readFile(teamName);
	if (!readFile.is_open())
	{
		cout << "\n\n\t\t\t\t\t    An error occured opening '" << teamName << "' file\n";
		return;
	}

	while (getline(readFile, line))
	{
		cout << "\n\n\t\t\t\t\t\t    " << line << endl << endl;
		for (int i = 0;i < 7;i++)
		{
			getline(readFile, line);
		}
	}
}
//class match
void Match::conductMatch()
{
	updateTeamRanking();
	string teamName1, teamName2;
	cout << "\n\t\t\t\t\t\t   Enter team name 1: ";
	cin >> teamName1;
	cout << "\n\t\t\t\t\t\t   Enter team name 2: ";
	cin >> teamName2;
	string Data;
	Data += "data.txt";
	ifstream readFile(Data);
	if (!readFile.is_open())
	{
		cout << "\n\n\t\t\t\t\t    An error occured opening '" << Data << "' file\n";
		return;
	}
	string line;

	bool found1 = false;
	while (getline(readFile, line))
	{
		if (line == teamName1)
		{
			found1 = true;
		}
	}
	bool found2 = false;
	while (getline(readFile, line))
	{
		if (line == teamName1)
		{
			found2 = true;
		}
	}
	if (found1 != true && found2 != true)
	{
		cout << "\n\t\t\t\t\t\t   No such teams exists";
	}
	else
	{
		srand(time(0));
		bool num;
		num = rand() % 1;
		if (num == 1)
		{
			cout << "\n\t\t\t\t\t\t   Team " << teamName1 << " won!!!";
			for (int i = 0;i < 5;i++)
			{
				if (teamName1 == teamrankings[i])
				{
					teamRankings[i] += 50;
				}
			}
		}
		else
		{
			cout << "\n\t\t\t\t\t\t   Team " << teamName2 << " won!!!";
			for (int i = 0;i < 5;i++)
			{
				if (teamName2 == teamrankings[i])
				{
					teamRankings[i] += 50;
				}
			}
		}
	}
	sortAndUpdate();
}
void Match::scheduleMatch()
{
	string teamName1, teamName2;
	cout << "\n\t\t\t\t\t\t   Enter team name 1: ";
	cin >> teamName1;
	cout << "\n\t\t\t\t\t\t   Enter team name 2: ";
	cin >> teamName2;
	cout << "\n\t\t\t\t\t\t   Enter Venue: ";
	cin >> venue;
	cout << "\n\t\t\t\t\t\t   Enter Match_Type: ";
	cin >> match_type;
	cout << "\n\t\t\t\t\t\t   Enter Tournamnet Name: ";
	cin >> tournament_Name;
	cout << "\n\t\t\t\t\t\t   Enter Comentator name: ";
	cin >> commentators;
	cout << "\n\t\t\t\t\t\t   Enter Match status: ";
	cin >> match_status;

	string filename = "schedule.txt";
	ofstream data(filename, ios::app);
	data << teamName1 << endl;
	data << teamName2 << endl;
	data << venue << endl;
	data << match_type << endl;
	data << tournament_Name << endl;
	data << commentators << endl;
	data << match_status << endl;
	data.close();
}
void Match::updateTeamRanking()
{
	string line;
	ifstream readFile("teamRankings.txt");
	for (int i = 0;i < 5;i++)
	{
		getline(readFile, line);
		teamRankings[i] = stoi(line);
		getline(readFile, teamrankings[i]);
		teamrankings[i] += "\n";
	}
}

void Match::sortAndUpdate()
{
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 4 - i;j++)
		{
			if (teamRankings[i] > teamRankings[i + 1])
			{
				string temp1;
				int temp2;
				temp2 = teamRankings[i];
				teamRankings[i] = teamRankings[i + 1];
				teamRankings[i + 1] = temp2;

				temp1 = teamrankings[i];
				teamrankings[i] = teamrankings[i + 1];
				teamrankings[i + 1] = temp1;
			}
		}
	}

	ofstream writeFile("teamRankings.txt");
	for (int i = 0;i < 5;i++)
	{
		writeFile << teamRankings[i] << endl;
		writeFile << teamrankings[i] << endl;
	}
}
/*updateWorldRecords();
updateTeamRanking();
updatePlayerRanking();
displayUpcomingMatches();
displayRecentMatches();*/