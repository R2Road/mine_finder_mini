#include "mfm_MineGenerator.h"

#include "r2/r2_Random.h"

namespace mfm
{
	MineGenerator::MineGenerator( const unsigned int start, const unsigned int end ) :
		mRange(
			start < end ? start : end
			, start < end ? end : start
		)
		, mRangeContainer()
	{
		Clear();
	}

	void MineGenerator::Clear()
	{
		mRangeContainer.clear();
		mRangeContainer.push_back( mRange );
	}

	bool MineGenerator::Get( ValueT* out_mine_linear_index )
	{
		bool ret = false;

		if( !mRangeContainer.empty() )
		{
			ret = true;

			const int range_index = r2::Random::GetInt( 0u, mRangeContainer.size() - 1u );
			auto range_itr = mRangeContainer.begin();
			for( int i = 0; range_index > i; ++i )
			{
				++range_itr;
			}

			*out_mine_linear_index = r2::Random::GetInt( range_itr->GetStart(), range_itr->GetEnd() );

			const ElementT temp = *range_itr;

			//
			// 사용한 Range 는 삭제.
			//
			mRangeContainer.erase( range_itr );

			if( 0 < temp.GetDistance() )
			{
				//
				// Head
				//
				if( temp.GetStart() < ( *out_mine_linear_index ) )
				{
					mRangeContainer.push_back( ElementT{ temp.GetStart(), ( *out_mine_linear_index ) - 1 } );
				}

				//
				// Tail
				//
				if( temp.GetEnd() > ( *out_mine_linear_index ) )
				{
					mRangeContainer.push_back( ElementT{ ( *out_mine_linear_index ) + 1, temp.GetEnd() } );
				}
			}
		}

		return ret;
	}
}