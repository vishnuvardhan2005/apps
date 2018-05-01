/*
Alarm Clock - A simple clock where it plays a sound after X number of minutes/seconds or at a particular time.

Displays time
Able to set alarms on a specific time
Plays sound at set time
*/

#include <iostream>
#include <time.h>
#include <windows.h>
#include <MMSystem.h>
#include <process.h>

using namespace std;

#define MAX_ALARMS 10

struct Alarm
{
	int hr;
	int min;
};

Alarm alarms[MAX_ALARMS+1];
int alarmCount;

void playSound()
{
	int j;
	for(int i=0;i<8;i++)
	{
		j = rand();
		Beep(100*j,200);	
	}
}

void init()
{
	alarmCount = 0;
}

void displayMenu()
{
	cout << "1. Show time" << endl;
	cout << "2. Add alarm" << endl;
	cout << "3. Show alarms set" << endl;
	cout << "4. Exit" << endl;
	cout << "Enter option : ";
}

bool validateOption(int opt)
{
	if(opt==1||opt==2||opt==3||opt==4)
		return true;
	return false;
}

bool exitOpt(int opt)
{
	return opt==4 ?  true : false;
}

void displayTime()
{
	time_t t;
	tm* timeinfo;
	
	time(&t);
	timeinfo = localtime(&t);
	cout << asctime(timeinfo) << endl;
}

void addAlarm()
{
	if(alarmCount==MAX_ALARMS)
	{
		cout << "Max alarms : " << MAX_ALARMS << "Cannot add more" << endl;
		return;
	}
	alarmCount++;
	cout << "Enter hour(0-23) : ";
	cin >> alarms[alarmCount].hr;
	cout << "Enter mins(0-59) : ";
	cin >> alarms[alarmCount].min;
	cout << "Alarm added at : " << alarms[alarmCount].hr << ":" << alarms[alarmCount].min << endl;
}

void showAlarms()
{
	for(int i=1;i<=alarmCount;i++)
	{
		cout << alarms[i].hr << ":" << alarms[i].min << endl;
	}
}

void handleInput(int opt)
{
	system("cls");
	switch(opt)
	{
		case 1:
			displayTime();
			break;
		case 2:
			addAlarm();
			break;
		case 3:
			showAlarms();
			break;
		default:
			//nothing to do
			break;		
	}
}

void handleAlarm(void* number)
{
	time_t t;
	tm* timeinfo;

	while(1)
	{
		if(alarmCount==0)
			continue;
		time(&t);
		timeinfo = localtime(&t);
		
		for(int i=1;i<=alarmCount;i++)
		{
			if(timeinfo->tm_hour==alarms[i].hr && timeinfo->tm_min==alarms[i].min)
			{
				playSound();
			}
		}
	}
}

int main()
{
	int opt;
	init();
	_beginthread(handleAlarm, 0, NULL);
	while(1)
	{
		displayMenu();
		cin >> opt;
		
		if(validateOption(opt)==false)
			continue;
			
		if(exitOpt(opt)==true)
		{
			cout << "Exiting..." << endl;
			break;
		}
			
		handleInput(opt);
		
	}	
	return 0;
}
