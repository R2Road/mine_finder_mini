#include "mfm_MinePositionGenerator.h"

#include "r2/r2_Random.h"

namespace mfm
{
	MinePositionGenerator::MinePositionGenerator( const unsigned int start, const unsigned int end, const ValidationCheckerT& validation_checker ) :
		mRange(
			start < end ? start : end
			, start < end ? end : start
		)
		, mValidationChecker( validation_checker )
		, mRangeContainer()
	{
		Clear();
	}

	void MinePositionGenerator::Clear()
	{
		mRangeContainer.clear();
		mRangeContainer.push_back( mRange );
	}

	bool MinePositionGenerator::Get( ValueT* out_mine_linear_index )
	{
		bool ret = false;

		if( !mRangeContainer.empty() )
		{
			ret = true;

			ContainerT::iterator range_itr;

			//
			// Select Mine Position
			//
			{
				int range_index = 0;

				int attempt_count = 0;
				do
				{
					++attempt_count;

					range_index = r2::Random::GetInt( 0, static_cast<int>( mRangeContainer.size() - 1u ) );
					range_itr = mRangeContainer.begin();
					for( int i = 0; range_index > i; ++i )
					{
						++range_itr;
					}

					*out_mine_linear_index = r2::Random::GetInt( range_itr->GetStart(), range_itr->GetEnd() );
					if( 10 > attempt_count && !mValidationChecker( *out_mine_linear_index ) )
					{
						continue;
					}
					else
					{
						break;
					}

				} while( true );
			}

			const ElementT temp = *range_itr;

			//
			// 사용한 Range 는 삭제.
			//
			mRangeContainer.erase( range_itr );

			if( 0 < temp.GetDistance() )
			{
				//
				// Add Head Range
				//
				if( temp.GetStart() < ( *out_mine_linear_index ) )
				{
					mRangeContainer.push_back( ElementT{ temp.GetStart(), ( *out_mine_linear_index ) - 1 } );
				}

				//
				// Add Tail Range
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