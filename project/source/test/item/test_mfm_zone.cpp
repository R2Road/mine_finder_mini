#include "test_mfm_zone.h"

#include <conio.h>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_WindowUtility.h"

#include "mfm/mfm_Zone.h"

namespace test_mfm_zone
{
	std::ostream& operator<<( std::ostream& o, mfm::Tile t )
	{
		return o << static_cast<int>( t );
	}

	void PrintRoom( const mfm::Zone& z )
	{
		const auto pivot = r2cm::WindowUtility::GetCursorPoint();

		for( int y = 0; z.GetHeight() > y; ++y )
		{
			for( int x = 0; z.GetWidth() > x; ++x )
			{
				std::cout << z.GetTile( x, y ) << " ";
			}
			std::cout << r2cm::linefeed;
		}

		r2cm::WindowUtility::MoveCursorPoint( { 0, pivot.y + (short)z.GetHeight() } );
	}

	r2cm::TitleFunctionT Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Zone : Declaration";
		};
	}
	r2cm::DoFunctionT Declaration::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			LS();

			{
				DECLARATION_MAIN( const mfm::Zone z( 2, 2 ) );

				std::cout << r2cm::linefeed;

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
			return "Zone : Builder";
		};
	}
	r2cm::DoFunctionT Builder::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			LS();

			{
				DECLARATION_MAIN( mfm::Zone z( 10, 10 ) );

				std::cout << r2cm::linefeed;

				for( int y = 0; z.GetHeight() > y; ++y )
				{
					for( int x = 0; z.GetWidth() > x; ++x )
					{
						std::cout << z.GetTile( x, y ) << " ";
					}
					std::cout << r2cm::linefeed;
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
			return "Zone : Demo";
		};
	}
	r2cm::DoFunctionT Demo::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( mfm::Zone z( 10, 10 ) );

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