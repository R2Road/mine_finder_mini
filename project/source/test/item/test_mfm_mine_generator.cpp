#include "test_mfm_mine_generator.h"

#include <list>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_WindowUtility.h"

#include "mfm/mfm_MineGenerator.h"

namespace test_mfm_mine_generator
{
	void PrintList( const std::list<r2::RangeUInt>& l )
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

			DECLARATION_MAIN( std::list<r2::RangeUInt> l );
			PROCESS_MAIN( l.push_back( r2::RangeUInt( 0, 9 ) ) );
			PrintList( l );

			std::cout << r2cm::split;

			{

			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}
}