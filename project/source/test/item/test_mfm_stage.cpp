#include "test_mfm_stage.h"

#include <conio.h>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_WindowUtility.h"

#include "mfm/mfmhelper_Printer4Stage.h"

namespace test_mfm_stage
{
	r2cm::TitleFunctionT Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Stage : Declaration";
		};
	}
	r2cm::DoFunctionT Declaration::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			LS();

			{
				DECLARATION_MAIN( const mfm::Stage s( 2, 2 ) );

				LF();

				EXPECT_EQ( 2, s.GetWidth() );
				EXPECT_EQ( 2, s.GetHeight() );
				EXPECT_EQ( 4, s.GetSize() );

				LF();

				mfmhelper::Printer4Stage_CharOX::Print( 2, 0, s );
			}

			LS();

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT Builder::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Stage : Builder";
		};
	}
	r2cm::DoFunctionT Builder::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( mfm::Stage s( 10, 10 ) );

			LS();

			{
				mfmhelper::Printer4Stage_CharOX::Print( 2, 0, s );
			}

			LS();

			{
				PROCESS_MAIN( s.Build() );

				LF();

				mfmhelper::Printer4Stage_CharOX::Print( 2, 0, s );
			}

			LS();

			{
				PROCESS_MAIN( s.Build() );

				LF();

				mfmhelper::Printer4Stage_CharOX::Print( 2, 0, s );
			}

			LS();

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT Demo::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Stage : Demo";
		};
	}
	r2cm::DoFunctionT Demo::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( mfm::Stage s( 10, 10 ) );

			LS();

			{
				const auto pivot_point = r2cm::WindowUtility::GetCursorPoint();
				int input = 0;

				do
				{
					switch( input )
					{
						//
						// Arrow
						//
					case 'w':
						break;
					case 'a':
						break;
					case 's':
						break;
					case 'd':
						break;

						//
						//
						//


					default:
						break;
					}

					//
					// View
					//
					r2cm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_point );
					mfmhelper::Printer4Stage_CharOX::Print( 2, 0, s );

					//
					// Input
					//
					input = _getch();

				} while( 27 != input );
			}

			LS();

			return r2cm::eDoLeaveAction::Pause;
		};
	}
}