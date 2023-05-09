#include "mfm_Stage.h"

#include "mfm_MinePositionGenerator.h"

namespace mfm
{
	Stage::Stage( const uint32_t width, const uint32_t height ) :
		mTerrain( width, height, Tile{ Tile::eType::Empty } )
	{}



	void Stage::Build()
	{
		mTerrain.Reset();

		const int required_mine_count = static_cast<int>( mTerrain.GetSize() * 0.15f );
		mfm::MinePositionGenerator mpg(
			0
			, static_cast<unsigned int>( mTerrain.GetSize() ) - 1
			, [&t = mTerrain]( int linear_index )->bool
			{
				int temp = 0;

				temp += ( Tile::eType::Empty == t.Get( linear_index - 1 ).type ? 1 : 0 );
				temp += ( Tile::eType::Empty == t.Get( linear_index + 1 ).type ? 1 : 0 );
				temp += ( Tile::eType::Empty == t.Get( linear_index - t.GetWidth() ).type ? 1 : 0 );
				temp += ( Tile::eType::Empty == t.Get( linear_index + t.GetWidth() ).type ? 1 : 0 );

				//
				// 조건을 4 == temp 로 만들면 제법 띄엄 띄엄 나온다.
				// 경향성을 조절 할 수 있는 알고리즘을 따로 만들면 어떨까?
				//
				return 3 <= temp;
			}
		);
		mfm::MinePositionGenerator::ValueT position = 0;

		for( int i = 0; required_mine_count > i; ++i )
		{
			mpg.Get( &position );
			mTerrain.Set( position, Tile{ Tile::eType::Mine } );
		}
	}
}