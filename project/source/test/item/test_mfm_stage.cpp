#include "test_mfm_stage.h"

#include <conio.h>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_WindowUtility.h"

#include "mfm/mfm_Stage.h"

namespace test_mfm_stage
{
	std::ostream& operator<<( std::ostream& o, mfm::Tile t )
	{
		return o << static_cast<int>( t );
	}

	void PrintRoom( const mfm::Stage& z )
	{
		const auto pivot = r2cm::WindowUtility::GetCursorPoint();

		for( int y = 0; z.GetHeight() > y; ++y )
		{
			for( int x = 0; z.GetWidth() > x; ++x )
			{
				std::cout << z.GetTile( x, y ) << " ";
			}
			LF();
		}

		r2cm::WindowUtility::MoveCursorPoint( { 0, pivot.y + (short)z.GetHeight() } );
	}

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
				DECLARATION_MAIN( const mfm::Stage z( 2, 2 ) );

				LF();

				EXPECT_EQ( 2, z.GetWidth() );
				EXPECT_EQ( 2, z.GetHeight() );
				EXPECT_EQ( 4, z.GetSize() );
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

			{
				DECLARATION_MAIN( mfm::Stage z( 10, 10 ) );

				LF();

				for( int y = 0; z.GetHeight() > y; ++y )
				{
					for( int x = 0; z.GetWidth() > x; ++x )
					{
						std::cout << z.GetTile( x, y ) << " ";
					}
					LF();
				}
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

			DECLARATION_MAIN( mfm::Stage z( 10, 10 ) );

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
					PrintRoom( z );

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