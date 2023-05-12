#include "test_mfm_cursor_indicator.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

#include "mfm/mfm_CursorIndicator.h"

namespace test_mfm_cursor_indicator
{
	r2cm::TitleFunctionT Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "CursorIndicator : Declaration";
		};
	}
	r2cm::DoFunctionT Declaration::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			LS();

			{
				DECLARATION_MAIN( const mfm::CursorIndicator s( 2, 2 ) );

				LF();

				EXPECT_EQ( 2, s.GetWidth() );
				EXPECT_EQ( 2, s.GetHeight() );
				EXPECT_EQ( 0, s.GetCursorX() );
				EXPECT_EQ( 0, s.GetCursorY() );
			}

			LS();

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT Move::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "CursorIndicator : Move";
		};
	}
	r2cm::DoFunctionT Move::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( mfm::CursorIndicator c( 2, 2 ) );
			EXPECT_EQ( 0, c.GetCursorX() );
			EXPECT_EQ( 0, c.GetCursorY() );

			LS();

			{
				PROCESS_MAIN( c.Move( mfm::CursorIndicator::eMoveDirection::Right ) );
				EXPECT_EQ( 1, c.GetCursorX() );
				EXPECT_EQ( 0, c.GetCursorY() );
			}

			LS();

			{
				PROCESS_MAIN( c.Move( mfm::CursorIndicator::eMoveDirection::Down ) );
				EXPECT_EQ( 1, c.GetCursorX() );
				EXPECT_EQ( 1, c.GetCursorY() );
			}

			LS();

			{
				PROCESS_MAIN( c.Move( mfm::CursorIndicator::eMoveDirection::Left ) );
				EXPECT_EQ( 0, c.GetCursorX() );
				EXPECT_EQ( 1, c.GetCursorY() );
			}

			LS();

			{
				PROCESS_MAIN( c.Move( mfm::CursorIndicator::eMoveDirection::Up ) );
				EXPECT_EQ( 0, c.GetCursorX() );
				EXPECT_EQ( 0, c.GetCursorY() );
			}

			LS();

			return r2cm::eDoLeaveAction::Pause;
		};
	}
}