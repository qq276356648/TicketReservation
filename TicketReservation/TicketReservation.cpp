// TicketReservation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#include "Database.h"
#include "Models.h"
#define _DEBUG_
int main(int argc, char**argv)
{
    initializeDatabase();

	TouristGroup tg;
	sprintf(tg.id, "%s", "654321");
	sprintf(tg.password, "%s", "亚丝娜我的");
	sprintf(tg.phone, "%s", "18876363773");
	tg.peopleCount = 10;
	tg.age = 25;

	addTourstGroup(&tg);

	char cond[] = "id = '654321'";
	char id[] = "654321";
	char p[] = "亚丝娜永远是我的";
	updateData("TouristGroup", cond, "password", p, 0);

	TouristGroup *tg2;

	
	tg2 = getTouristGroup(id);

	printf("%s", tg2->password);
	printf("\n");
	system("pause");
	return 0;

}
