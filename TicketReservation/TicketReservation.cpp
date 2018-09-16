// TicketReservation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#define NOCOLOR
#include "Database.h"
#include "Validation.h"
#include "Models.h"
#include "Color.h"
#include "Admin.h"
#include "TouristGroup.h"
#define _DEBUG_



int main(int argc, char**argv)
{
	initializeDatabase();
	
	if (getSystemAdmin((char*)"admin") == NULL) {
		printf("提示: 检测到您第一次运行本系统, 系统已默认创建管理员账户admin, 密码123321\n请按回车进入\n\n");

		SystemAdmin a;
		strcpy(a.id, "admin");
		strcpy(a.password, "123321");
		strcpy(a.phone, "18876363653");
		strcpy(a.email, "2017212783@bupt.edu.cn");

		addSystemAdmin(&a);
		while (readKey() != '\r');
	}

	while (1) {
		system("cls");
		printf("┌──────────────────────────────────────────────────┐\n");
		printf("│              团体游景点门票预订系统              │\n");
		printf("├──────────────────────────────────────────────────┤\n");
		printf("│               " COLOR_YELLOW_B "[1]" COLOR_RESET " 游客团登录                     │\n");
		printf("│               " COLOR_YELLOW_B "[2]" COLOR_RESET " 游客团注册                     │\n");
		printf("│               " COLOR_YELLOW_B "[3]" COLOR_RESET " 管理员登录                     │\n");
		printf("│               " COLOR_YELLOW_B "[4]" COLOR_RESET " 退出系统                       │\n");
		printf("└──────────────────────────────────────────────────┘\n");
		printf(COLOR_YELLOW_B "请按数字键选择功能\n" COLOR_RESET);

		char choice = '\0';
		while (!(choice = readKey()) || choice > '5' || choice < '1')
			printf(COLOR_RED_B "您的按键有误, 请重试\n" COLOR_RESET);


		switch (choice)
		{
			case '1':
				TouristGroupLogin();
				break;
			case '2':
				TouristGroupRegister();
				break;
			case '3':
				Admin();
				break;
			case '4':
				closeDatabase();
				return 1;
			break;
		}
	}

}
