#include "test_mfm_mine_position_generator.h"

#include <list>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_WindowUtility.h"

#include "mfm/mfm_MinePositionGenerator.h"

namespace test_mfm_mine_position_generator
{
	std::ostream& operator<<( std::ostream& o, const mfm::MinePositionGenerator::ElementT& r )
	{
		return o << r.GetStart() << "   " << r.GetEnd();
	}


	void PrintList( const mfm::MinePositionGenerator& m )
	{
		const auto cursor_point = r2cm::WindowUtility::GetCursorPoint();

		for( int cur = m.GetStart(), end = m.GetEnd(); end >= cur; ++cur )
		{
			r2cm::WindowUtility::FillColor( cursor_point.x + ( cur * 2 ), cursor_point.y, r2cm::WindowUtility::eColor::FG_White | r2cm::WindowUtility::eColor::BG_Blue );
		}

		for( const auto& r : m.GetRangeContainer() )
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
			LS();

			{
				DECLARATION_MAIN( mfm::MinePositionGenerator m( 0, 9 ) );

				LF();

				EXPECT_EQ( 0, m.GetStart() );
				EXPECT_EQ( 9, m.GetEnd() );

				LF();

				EXPECT_EQ( 1u, m.GetRangeContainer().size() );
				EXPECT_EQ( m.GetRange(), *m.GetRangeContainer().begin() );
			}

			LS();

			{
				OUTPUT_SUBJECT( "생성자의 start 인자가 end 인자 보다 큰 경우." );

				LF();

				DECLARATION_MAIN( mfm::MinePositionGenerator m( 9, 0 ) );

				LF();

				EXPECT_EQ( 0, m.GetStart() );
				EXPECT_EQ( 9, m.GetEnd() );

				LF();

				EXPECT_EQ( 1u, m.GetRangeContainer().size() );
				EXPECT_EQ( m.GetRange(), *m.GetRangeContainer().begin() );
			}

			LS();

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
			LS();

			{
				DECLARATION_MAIN( mfm::MinePositionGenerator m( 0, 0 ) );
				PrintList( m );

				LF();

				DECLARATION_MAIN( mfm::MinePositionGenerator::ValueT position );
				EXPECT_TRUE( m.Get( &position ) );
				EXPECT_EQ( 0u, position );
				EXPECT_TRUE( m.GetRangeContainer().empty() );

				LF();

				PrintList( m );
			}

			LS();

			{
				DECLARATION_MAIN( mfm::MinePositionGenerator m( 9, 9 ) );
				PrintList( m );

				LF();

				DECLARATION_MAIN( mfm::MinePositionGenerator::ValueT position );
				EXPECT_TRUE( m.Get( &position ) );
				EXPECT_EQ( 9u, position );
				EXPECT_TRUE( m.GetRangeContainer().empty() );

				LF();

				PrintList( m );
			}

			LS();

			{
				DECLARATION_MAIN( mfm::MinePositionGenerator m( 0, 3 ) );
				DECLARATION_MAIN( mfm::MinePositionGenerator::ValueT position );

				LF();

				EXPECT_TRUE( m.Get( &position ) );
				OUTPUT_VALUE( position );
				PrintList( m );

				LF();

				EXPECT_TRUE( m.Get( &position ) );
				OUTPUT_VALUE( position );
				PrintList( m );

				LF();

				EXPECT_TRUE( m.Get( &position ) );
				OUTPUT_VALUE( position );
				PrintList( m );

				LF();

				EXPECT_TRUE( m.Get( &position ) );
				OUTPUT_VALUE( position );
				PrintList( m );
			}

			LS();

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT Clear::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Mine Generator : Clear";
		};
	}
	r2cm::DoFunctionT Clear::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( mfm::MinePositionGenerator m( 0, 9 ) );
			DECLARATION_MAIN( mfm::MinePositionGenerator::ValueT position );

			LS();

			{
				PROCESS_MAIN( m.Get( &position ) );
				OUTPUT_VALUE( position );
				PrintList( m );

				LF();

				PROCESS_MAIN( m.Get( &position ) );
				OUTPUT_VALUE( position );
				PrintList( m );

				LF();

				PROCESS_MAIN( m.Get( &position ) );
				OUTPUT_VALUE( position );
				PrintList( m );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Clear() : Range 컨테이너를 비우고, 생성자에서 주어진 Range 를 채워넣는다." );

				LF();

				PROCESS_MAIN( m.Clear() );

				LF();

				EXPECT_EQ( 1u, m.GetRangeContainer().size() );
				EXPECT_EQ( m.GetRange(), *m.GetRangeContainer().begin() );
				PrintList( m );
			}

			LS();

			return r2cm::eDoLeaveAction::Pause;
		};
	}
}