#pragma once

enum Menu
{
	SORT = 1,
	PRINT,
	COMPARE,
	SETTINGS,
	EXIT,
};

enum Sorting
{
	BUBBLE = 1,
	SHAKER,
	GNOME,
	SELECT,
	INSERT,
	SHELL,
	MENU
};

enum Settings	//�� ���� ������������ static_cast � ����
{
	LANGUAGE = 1,
	GENERATE,
	RESIZE,
	MAIN_MENU
};
