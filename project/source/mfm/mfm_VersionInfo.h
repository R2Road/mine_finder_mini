#pragma once

namespace mfm
{

	//
	// 2022.05.06 by R
	//
	// �������� �ʰ� ��̰� �۾��� �̾�� �� �ֵ��� ��� ����� ������ ��.
	//

	static struct
	{

		const char VersionNumber_1 = '0';
		const char VersionNumber_2 = '0';
		const char VersionNumber_3 = '0';
		const char VersionNumber_4 = '0';

		const char* const String4VersionRule = {
					"### Version Rule ###"
			"\n"
			"\n"	"> " "1.0.0.0"  " : "  "���"
			"\n"	"> " "0.1.0.0"  " : "  "10���� Road ���� 1�� ����"
			"\n"	"> " "0.0.1.0"  " : "  "Road �� �����ߴ�."
			"\n"	"> " "0.0.0.1"  " : "  "������ ������ �־���."
		};

		const char String4Version[28] = { 'M', 'i', 'n', 'e', '-', 'F', 'i', 'n', 'd', 'e', 'r', ' ', 'M', 'i', 'n', 'i', ' ', ':', ' ', 'v', VersionNumber_1, '.', VersionNumber_2, '.', VersionNumber_3, '.', VersionNumber_4, '\0' };



		const char* const String4DevelopementRule = {
					"### Game ���� ###"
			"\n"
			"\n"	"> " "Game               "  " : "  "..."
			"\n"	"> " "Zone               "  " : "  "..."
			"\n"	"> " "Mine               "
			"\n"	"\t - "		"Grid�� Linear Index�� Ȱ��."
			"\n"	"\t - "		"���� Index, �� Index �� ����� ������ ���� Struct �� �����"
			"\n"	"\t - "		"���� �ȿ��� random �Լ��� ���� ��ġ�� ���� �ϴ� ���� �⺻."
			"\n"	"\t - "		"���� ��ġ�� �������� ������ ������ �ΰ��� ������ ����."
			"\n"	"\t - "		"���� ����, ���� ��ġ ����, ���� ������ �ݺ��ؼ� �� ����"
			"\n"	"\t - "		"������ ����-�� ���� �������� ����"
		};
		
		
		
		const char* const String4Road2Version_0_0_0_0 = {
			"### Road 2 Version 0.0.0.0 ###"
			"\n"
			"\n"	"[o] " "Make Project"
			"\n"	"[o] " "Copy Project \"mini-rogue\""
			"\n"	"[o] " "Cleanup"
		};

	} VersionInfo;
}