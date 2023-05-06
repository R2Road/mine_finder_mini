#pragma once

#include <list>

#include "r2/r2_RangeUInt.h"

namespace mfm
{
	class MineGenerator
	{
	public:
		using ElementT = r2::RangeUInt;
		using ContainerT = std::list<ElementT>;



		MineGenerator( const unsigned int start, const unsigned int end );



		const ElementT::ValueT GetStart() const
		{
			return mRange.GetStart();
		}
		const ElementT::ValueT GetEnd() const
		{
			return mRange.GetEnd();
		}
		const ElementT& GetRange() const
		{
			return mRange;
		}
		const ContainerT& GetRangeContainer() const
		{
			return mRangeContainer;
		}



		void Clear();
		void Ready();



	private:
		const ElementT mRange;
		ContainerT mRangeContainer;
	};
}