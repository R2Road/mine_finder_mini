#include "test_mfm_mine_generator.h"

#include <list>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_WindowUtility.h"

#include "mfm/mfm_MineGenerator.h"

namespace test_mfm_mine_generator
{
	std::ostream& operator<<( std::ostream& o, const mfm::MineGenerator::ElementT& r )
	{
		return o << r.GetStart() << "   " << r.GetEnd();
	}


	void PrintList( const mfm::MineGenerator::ContainerT& l )
	{
		const auto cursor_point = r2cm::WindowUtility::GetCursorPoint();

		for( const auto& r : l )
		{
			for( int cur = r.GetStart(), end = r.GetEnd(); end >= cur; ++cur )
			{
				r2cm::WindowUtility::FillCharacter( cursor_point.x + ( cur * 2 ), cursor_point.y, 'o' );
			}
		}

		LF();
	}



	r2cm::TitleFunctionT Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Mine Generator : Declaration";
		};
	}
	r2cm::DoFunctionT Declaration::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( mfm::MineGenerator m( 0, 9 ) );

				LF();

				EXPECT_EQ( 0, m.GetStart() );
				EXPECT_EQ( 9, m.GetEnd() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( mfm::MineGenerator m( 9, 0 ) );

				LF();

				EXPECT_EQ( 0, m.GetStart() );
				EXPECT_EQ( 9, m.GetEnd() );
			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT Ready_Clear::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Mine Generator : Ready, Clear";
		};
	}
	r2cm::DoFunctionT Ready_Clear::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( mfm::MineGenerator m( 0, 9 ) );

			LF();

			EXPECT_TRUE( m.GetRangeContainer().empty() );

			std::cout << r2cm::split;

			{
				OUTPUT_SUBJECT( "Ready 함수는 생성자에서 주어진 Range 를 내부의 Range 컨테이너에 넣는다." );

				LF();

				PROCESS_MAIN( m.Ready() );

				LF();

				EXPECT_EQ( 1u, m.GetRangeContainer().size() );
				EXPECT_EQ( m.GetRange(), *m.GetRangeContainer().begin() );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_SUBJECT( "Clear 내부의 Range 컨테이너를 비운다." );

				LF();

				PROCESS_MAIN( m.Clear() );

				LF();

				EXPECT_TRUE( m.GetRangeContainer().empty() );
			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT Do::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Mine Generator : Do";
		};
	}
	r2cm::DoFunctionT Do::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( mfm::MineGenerator m( 0, 9 ) );
			PrintList( m.GetRangeContainer() );

			std::cout << r2cm::split;

			{

			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}
}