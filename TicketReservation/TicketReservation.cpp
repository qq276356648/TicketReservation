// TicketReservation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include "Validation.h"

int main()
{
	
	printf("%d", initializeRegex());
	char a[] = "qq276356648@126.com";
	printf("%d", vaildateEmail(a));

	system("pause");
    return 0;
}
