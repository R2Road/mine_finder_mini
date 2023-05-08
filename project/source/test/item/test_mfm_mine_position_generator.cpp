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
				DECLARATION_MAIN( mfm::MinePositionGenerator m( 0, 9, []( int )->bool { return true; } ) );

				LF();

				EXPECT_EQ( 0, m.GetStart() );
				EXPECT_EQ( 9, m.GetEnd() );

				LF();

				EXPECT_EQ( 1u, m.GetRangeContainer().size() );
				EXPECT_EQ( m.GetRange(), *m.GetRangeContainer().begin() );
			}

			LS();

			{
				OUTPUT_SUBJECT( "�������� start ���ڰ� end ���� ���� ū ���." );

				LF();

				DECLARATION_MAIN( mfm::MinePositionGenerator m( 9, 0, []( int )->bool { return true; } ) );

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



	r2cm::TitleFunctionT Get::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Mine Generator : Get";
		};
	}
	r2cm::DoFunctionT Get::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			LS();

			{
				DECLARATION_MAIN( mfm::MinePositionGenerator m( 0, 0, []( int )->bool { return true; } ) );
				PrintList( m );

				LF();

				DECLARATION_MAIN( mfm::MinePositionGenerator::ValueT position );
				EXPECT_TRUE( m.Get( &position ) );
				EXPECT_EQ( 0u, position );
				EXPECT_TRUE( m.GetRangeContainer().empty() );
				PrintList( m );
			}

			LS();

			{
				DECLARATION_MAIN( mfm::MinePositionGenerator m( 9, 9, []( int )->bool { return true; } ) );
				PrintList( m );

				LF();

				DECLARATION_MAIN( mfm::MinePositionGenerator::ValueT position );
				EXPECT_TRUE( m.Get( &position ) );
				EXPECT_EQ( 9u, position );
				EXPECT_TRUE( m.GetRangeContainer().empty() );
				PrintList( m );
			}

			LS();

			{
				DECLARATION_MAIN( mfm::MinePositionGenerator m( 0, 3, []( int )->bool { return true; } ) );
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

				LF();

				EXPECT_FALSE( m.Get( &position ) );
				EXPECT_TRUE( m.GetRangeContainer().empty() );
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

			DECLARATION_MAIN( mfm::MinePositionGenerator m( 0, 9, []( int )->bool { return true; } ) );
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
				OUTPUT_SUBJECT( "Clear() : Range �����̳ʸ� ����, �����ڿ��� �־��� Range �� ä���ִ´�." );

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