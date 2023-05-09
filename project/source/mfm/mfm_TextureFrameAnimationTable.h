#pragma once

#include "r2/r2_SingletonWithStaticFunction.h"
#include "r2bix/r2bix_table_TextureFrameAnimationTableBase.h"

namespace mfm
{
	class TextureFrameAnimationTable : public r2bix_table::TextureFrameAnimationTableBase, public r2::SingletonWithStaticFunction<TextureFrameAnimationTable>
	{
	public:
		void Load() override;
	};
}