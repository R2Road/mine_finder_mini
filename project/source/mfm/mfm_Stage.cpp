#include "mfm_Stage.h"

#include "r2/r2_RectInt.h"

namespace mfm
{
	Stage::Stage( const uint32_t width, const uint32_t height ) :
		mTerrain( width, height, Tile::Empty )
	{}



	void RoomBuilder( Stage* out_room )
	{
		const r2::RectInt rect( 1, 1, static_cast<int>( out_room->GetWidth() ) - 3, static_cast<int>( out_room->GetHeight() ) - 3 );

		for( int y = 0; out_room->GetHeight() > y; ++y )
		{
			for( int x = 0; out_room->GetWidth() > x; ++x )
			{
				if( rect.ContainsPoint( x, y ) )
				{
					out_room->SetTile( x, y, Tile::Empty );
				}
				else
				{
					out_room->SetTile( x, y, Tile::Mine );
				}
			}
		}
	}
}