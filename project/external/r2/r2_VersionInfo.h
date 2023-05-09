#pragma once

namespace r2
{

	//
	// 2022.05.06 by R
	//
	// 무리하지 않고 즐겁게 작업을 이어나갈 수 있도록 모든 방안을 강구할 것.
	//

	const struct
	{

		const char* const String4NameSpaceRule =
					"## Name Space Rule ##"
			"\n"
			"\n"	"[   r2    ] 멤버 변수와 함수로 구성"
			"\n"	"[r2utility] 함수로만 구성"
		;



		const char VersionNumber_1 = '0';
		const char VersionNumber_2 = '0';
		const char VersionNumber_3 = '6';
		const char VersionNumber_4 = '1';

		const char* const String4VersionRule =
					"### Version Rule ###"
			"\n"
			"\n"	"> " "1.0.0.0"  " : "  "완성?"
			"\n"	"> " "0.1.0.0"  " : "  "Road 10개 완료"
			"\n"	"> " "0.0.1.0"  " : "  "Road 1개 완료"
			"\n"	"> " "0.0.0.1"  " : "  "자잘한 수정"
		;

		const char String4Version[14] = { 'R', '2', ' ', ':', ' ', 'v', VersionNumber_1, '.', VersionNumber_2, '.', VersionNumber_3, '.', VersionNumber_4, '\0' };



		const char* const String4Road2Version_0_0_7_0 =
					"### Road 2 Version 0.0.7.0 ###"
			"\n"
			"\n"	"[o] " "Add : r2 - ValueWithHistory1AndCallback"
			"\n"	"[o] " "Add : geometry2d - Direction4SequentialState"
			"\n"	"[ ] " "Add : geometry2d - Direction8SequentialState"
			"\n"	"[ ] " "Add : geometry2d - Direction"
			"\n"	"[ ] " "Add : geometry2d - Direction4BitwiseState"
			"\n"	"[ ] " "Add : geometry2d - Direction8BitwiseState"
			"\n"
			"\n"	"----------------------------------"
			"\n"
			"\n"	"[ ] " "Add : r2 - ArrayIterator"
			"\n"	"[o] " "Add : r2 - RemovePointer"
			"\n"	"[ ] " "Add : r2 - BitSet"
			"\n"
			"\n"	"----------------------------------"
			"\n"
			"\n"	"[o] " "Update : r2 - ListBasedOnGrid - Overload Constructor, Overload Method : Erase"
			"\n"
			"\n"	"----------------------------------"
			"\n"
			"\n"	"[ ] " "Vector2"
			"\n"	"[ ] " "Vector3"
			"\n"	"[ ] " "Matrix4"
			"\n"
			"\n"	"----------------------------------"
			"\n"
			"\n"	"[ ] " "Crypto Machine"
		;

		const char* const String4Road2Version_0_0_6_0 =
					"### Road 2 Version 0.0.6.0 ###"
			"\n"
			"\n"	"[o] " "Node4GridConstIterator 추가"
			"\n"	"[o] " "Node4GridConstReverseIterator 추가"
			"\n"	"[o] " "ListBasedOnGrid 에 Const Iterator 적용"
			"\n"	"[o] " "Node4ListConstIterator 추가"
			"\n"	"[o] " "Node4ListConstReverseIterator 추가"
			"\n"	"[o] " "ListBasedOnArray 에 Const Iterator 적용"
			"\n"	"[o] " "ListBasedOnVector 에 Const Iterator 적용"
			"\n"	"[o] " "LinkedQueueBasedOnArray 에 Const Iterator 적용"
			"\n"	"[o] " "LinkedQueueBasedOnVector 에 Const Iterator 적용"
			"\n"	"[o] " "LinkedQueueBasedOnGrid 에 Const Iterator 적용"
		;

		const char* const String4Road2Version_0_0_5 =
					"### Road 2 Version 0.0.5.0 ###"
			"\n"
			"\n"	"[o] " "Linked List Based On Vector"
			"\n"	"[o] " "Linked Queue Based On Vector"
			"\n"	"[o] " "ListNode Allocator Based On Vector"
		;

		const char* const String4Road2Version_0_0_4_1 =
			"### Road 2 Version 0.0.4.1 ###"
			"\n"
			"\n"	"[o] " "Fix : GridIndexConverter"
		;

		const char* const String4Road2Version_0_0_4 =
					"### Road 2 Version 0.0.4 ###"
			"\n"
			"\n"	"[o] " "Linked List Based On Grid"
			"\n"	"[o] " "Grid Based On Array"
		;

		const char* const String4Road2Version_0_0_3 =
					"### Road 2 Version 0.0.3 ###"
			"\n"
			"\n"	"[o] " "Linked Queue Based On Array"
			"\n"	"[o] " "Linked Queue Based On Grid"
			"\n"	"[o] " "Grid : Test 작성"
		;

		const char* const String4Road2Version_0_0_2 =
					"### Road 2 Version 0.0.2 ###"
			"\n"
			"\n"	"[o] " "Value with Tracking"
			"\n"	"[o] " "Value with Dirty"
			"\n"	"[o] " "Value with Dirty and Tracking"
		;

		const char* const String4Road2Version_0_0_1 =
					"### Road 2 Version 0.0.1 ###"
			"\n"
			"\n"	"[o] " "Index Enumerator"
		;

		const char* const String4Road2Version_0_0_0 =
					"### Road 2 Version 0.0.0 ###"
			"\n"
			"\n"	"[o] " "Make Project"
			"\n"	"[o] " "Cleanup"
		;

	} VersionInfo;
}