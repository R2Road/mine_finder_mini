#include "mfm_Stage.h"

#include "mfm_MinePositionGenerator.h"

namespace mfm
{
	Stage::Stage( const uint32_t width, const uint32_t height ) :
		mTerrain( width, height, Tile::Empty )
	{}



	void Stage::Build()
	{
		mTerrain.Reset();

		const int required_mine_count = static_cast<int>( mTerrain.GetSize() * 0.1f );
		mfm::MinePositionGenerator mpg( 0, static_cast<unsigned int>( mTerrain.GetSize() ) - 1 );
		mfm::MinePositionGenerator::ValueT position = 0;

		for( int i = 0; required_mine_count > i; ++i )
		{
			mpg.Get( &position );
			mTerrain.Set( position, Tile::Mine );
		}
	}
}