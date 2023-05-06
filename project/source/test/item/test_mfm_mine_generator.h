#pragma once

#include "r2cm/r2cm_iItem.h"

namespace test_mfm_mine_generator
{
	class Do : public r2cm::iItem
	{
	public:
		r2cm::TitleFunctionT GetTitleFunction() const override;
		r2cm::DoFunctionT GetDoFunction() const override;
	};
}