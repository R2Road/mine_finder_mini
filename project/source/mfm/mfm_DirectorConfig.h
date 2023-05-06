#pragma once

#include "r2bix/r2bix_director_Config.h"

namespace mfm
{
	const r2bix_director::Config DirectorConfig
	{
			57	// Screen Buffer Width
		,	27	// Screen Buffer Height
		,	r2bix_director::Config::eScheduleType::Infinite
		,	30u // FPS
	};
}