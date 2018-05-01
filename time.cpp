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
using namespace std;


void playSound()
{
	/*for(int i=0;i<20;i++)
	{
		PlaySound(TEXT("recycle.wav"), NULL, SND_SYNC);
	}*/
	int j;
	for(int i=0;i<8;i++)
	{
		j = rand();
		Beep(100*j,200);	
	}
}

int main()
{
	time_t t;
	tm* timeinfo;
	int h;
	int m;
	
	cin >> h;
	cin >> m;
	
	while(1)
	{
		time(&t);
		timeinfo = localtime(&t);
		if(timeinfo->tm_hour==h && timeinfo->tm_min==m)
		{
			//MessageBeep(MB_OK);
			playSound();
			cout << "Alarm" << endl;
			break;
		}
		cout << asctime(timeinfo) << endl;
		system("cls");
	}
	
	return 0;
}
