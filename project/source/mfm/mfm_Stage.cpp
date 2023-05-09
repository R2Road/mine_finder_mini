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
				// ������ 4 == temp �� ����� ���� ��� ��� ���´�.
				// ���⼺�� ���� �� �� �ִ� �˰����� ���� ����� ���?
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