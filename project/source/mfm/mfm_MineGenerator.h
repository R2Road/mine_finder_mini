#pragma once

#include <list>

#include "r2/r2_Range.h"

namespace mfm
{
	class MineGenerator
	{
	public:
		using ValueT = unsigned int;
		using ElementT = r2::Range<ValueT>;
		using ContainerT = std::list<ElementT>;



		MineGenerator( const unsigned int start, const unsigned int end );



		const ValueT GetStart() const
		{
			return mRange.GetStart();
		}
		const ValueT GetEnd() const
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



	private:
		const ElementT mRange;
		ContainerT mRangeContainer;
	};
}