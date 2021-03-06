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

// 主函数
int main(int argc, char**argv)
{
	initializeDatabase();   // 初始化数据库
	
	if (getSystemAdmin((char*)"ADMIN1") == NULL) { // 如果数据库中不存在默认管理员，则说明数据库为新建，添加默认管理员
		printf("提示: 检测到您第一次运行本系统, 系统已默认创建管理员账户ADMIN1, 密码123321\n请按回车进入\n\n");

		SystemAdmin a;
		strcpy(a.id, "ADMIN1");    // 默认管理员信息
		strcpy(a.password, "123321");
		strcpy(a.phone, "18800006782");
		strcpy(a.email, "example@bupt.edu.cn");

		addSystemAdmin(&a);       // 添加默认管理员账户到数据库
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
		while (!(choice = readKey()) || choice > '5' || choice < '1') // 读取用户选项，并验证
			printf(COLOR_RED_B "您的按键有误, 请重试\n" COLOR_RESET);


		switch (choice)
		{
			case '1':
				TouristGroupLogin();      // 旅游团登录
				break;
			case '2':
				TouristGroupRegister();   // 旅游团注册
				break;
			case '3':
				Admin();                  // 管理员登录
				break;
			case '4':
				closeDatabase();          // 退出前关闭数据库
				return 1;                 // 退出程序
		}
	}

}
