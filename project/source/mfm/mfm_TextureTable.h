#pragma once

#include "r2/r2_SingletonWithStaticFunction.h"
#include "r2bix/r2bix_table_TextureTableBase.h"

namespace mfm
{
	class TextureTable : public r2bix_table::TextureTableBase, public r2::SingletonWithStaticFunction<TextureTable>
	{
	public:
		void Load() override;
	};
}