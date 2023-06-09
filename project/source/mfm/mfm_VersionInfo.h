#pragma once

namespace mfm
{

	//
	// 2022.05.06 by R
	//
	// 무리하지 않고 즐겁게 작업을 이어나갈 수 있도록 모든 방안을 강구할 것.
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
			"\n"	"> " "1.0.0.0"  " : "  "출시"
			"\n"	"> " "0.1.0.0"  " : "  "10개의 Road 마다 1씩 증가"
			"\n"	"> " "0.0.1.0"  " : "  "Road 를 완주했다."
			"\n"	"> " "0.0.0.1"  " : "  "자잘한 수정이 있었다."
		};

		const char String4Version[28] = { 'M', 'i', 'n', 'e', '-', 'F', 'i', 'n', 'd', 'e', 'r', ' ', 'M', 'i', 'n', 'i', ' ', ':', ' ', 'v', VersionNumber_1, '.', VersionNumber_2, '.', VersionNumber_3, '.', VersionNumber_4, '\0' };



		const char* const String4SubjectAsAProgrammer = {
			"### 프로젝트 목표 | Subject Of A Project ###"
			"\n"
			"\n"	"1. 임의의 Grid Point를 선택 하는 과정에서 범위 분할을 통한 난수 생성 횟수 감소."
			"\n"	"    "    "> 0 ~ 9 범위에서 난수를 생성하는 경우"
			"\n"	"    "    "> 첫 난수가 5 면 0 ~ 4, 6 ~ 9 두개의 범위로 분할"
			"\n"	"2. FloodFill Algorithm 사용"
			"\n"	"    "    "> 다른 프로젝트에서 사용한 FolldFill Algorithm 코드를 가져와 이 곳에 맞게 조정"
		};



		const char* const String4DevelopementRule = {
					"### Game 구성 ###"
			"\n"
			"\n"	"> " "Game               "  " : "  "..."
			"\n"	"> " "Stage              "  " : "  "..."
			"\n"	"> " "Mine               "
			"\n"	"\t - "		"Grid의 Linear Index를 활용."
			"\n"	"\t - "		"시작 Index, 끝 Index 를 멤버로 가지는 범위 Struct 를 만든다"
			"\n"	"\t - "		"범위 안에서 random 함수로 지뢰 위치를 결정 하는 것이 기본."
			"\n"	"\t - "		"지뢰 위치를 기준으로 최초의 범위를 두개의 범위로 분할."
			"\n"	"\t - "		"범위 선택, 지뢰 위치 결정, 범위 분할을 반복해서 맵 구성"
			"\n"	"\t - "		"범위의 시작-끝 점이 같아지면 제거"
		};
		
		
		
		const char* const String4Road2Version_0_0_1_0 = {
			"### Road 2 Version 0.0.1.0 ###"
			"\n"
			"\n"	"[ ] " "Stage"
			"\n"	"    " "[ ] " "Add Class : Stage"
			"\n"	"    " "[o] " "Add Class : Mine Generator"
			"\n"	"    " "[ ] " "Update Class : Stage : Build"
			"\n"	"[ ] " "Stage View"
		};

		const char* const String4Road2Version_0_0_0_0 = {
			"### Road 2 Version 0.0.0.0 ###"
			"\n"
			"\n"	"[o] " "Make Project"
			"\n"	"[o] " "Copy Project \"mini-rogue\""
			"\n"	"[o] " "Cleanup"
		};

		const char* const String4Road2NextVersion = String4Road2Version_0_0_1_0;

	} VersionInfo;
}