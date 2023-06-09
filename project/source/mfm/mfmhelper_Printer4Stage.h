#pragma once

#include "mfm_Stage.h"
#include "r2/r2_NoneCopyable.h"
#include "r2cm/r2cm_WindowUtility.h"

namespace mfmhelper
{
	class Printer4Stage_CharOX : private r2::NoneCopyable
	{
	private:
		using TargetT = mfm::Stage;

		Printer4Stage_CharOX() = delete;

	public:
		inline static void Print( short pivot_x, short pivot_y, const short offset_x, const short offset_y, uint16_t space_h, uint16_t space_v, const TargetT& container )
		{
			//
			//
			//
			pivot_x += offset_x;
			pivot_y += offset_y;

			//
			//
			//
			space_h = ( space_h > 0 ? space_h : 1 );
			space_v = ( space_v > 0 ? space_v : 1 );

			//
			// Draw
			//
			for( uint32_t cy = 0; cy < container.GetHeight(); ++cy )
			{
				for( uint32_t cx = 0; cx < container.GetWidth(); ++cx )
				{
					const auto& tile = container.GetTile( cx, cy );

					if( mfm::Tile::eType::Mine == tile.type )
					{
						r2cm::WindowUtility::FillColor(
							{
									static_cast<short>( pivot_x + ( cx * space_h ) )
								,	static_cast<short>( pivot_y + ( cy * space_v ) )
							}
							, r2cm::WindowUtility::eColor::BG_Black | r2cm::WindowUtility::eColor::FG_Red
						);
						r2cm::WindowUtility::FillCharacter(
							{
									static_cast<short>( pivot_x + ( cx * space_h ) )
								,	static_cast<short>( pivot_y + ( cy * space_v ) )
							}
							, 'o'
						);
					}
					else if( 0 < tile.sum )
					{
						r2cm::WindowUtility::FillColor(
							{
									static_cast<short>( pivot_x + ( cx * space_h ) )
								,	static_cast<short>( pivot_y + ( cy * space_v ) )
							}
							, r2cm::WindowUtility::eColor::BG_Black | r2cm::WindowUtility::eColor::FG_Green
						);
						r2cm::WindowUtility::FillCharacter(
							{
									static_cast<short>( pivot_x + ( cx * space_h ) )
								,	static_cast<short>( pivot_y + ( cy * space_v ) )
							}
							, 48 + tile.sum // number 2 char number
						);
					}
					else //if( 0 == tile.sum )
					{
						r2cm::WindowUtility::FillCharacter(
							{
									static_cast<short>( pivot_x + ( cx * space_h ) )
								,	static_cast<short>( pivot_y + ( cy * space_v ) )
							}
							, 48 + tile.sum // number 2 char number
						);
					}
				}
			}

			//
			// Move Cursor
			//
			r2cm::WindowUtility::MoveCursorPoint( {
					0
				,	static_cast<short>( pivot_y + ( container.GetMaxY() * space_v ) + 1 )
			} );
		}

		inline static void Print( const short offset_x, const short offset_y, uint16_t space_h, uint16_t space_v, const TargetT& container )
		{
			const auto pivot_point = r2cm::WindowUtility::GetCursorPoint();
			Print( pivot_point.x, pivot_point.y, offset_x, offset_y, space_h, space_v, container );
		}

		inline static void Print( const short offset_x, const short offset_y, const TargetT& container )
		{
			Print( offset_x, offset_y, 2, 1, container );
		}

		inline static void Print( const TargetT& container )
		{
			Print( 0, 0, 2, 1, container );
		}
	};
}