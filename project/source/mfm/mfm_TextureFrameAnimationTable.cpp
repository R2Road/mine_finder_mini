#include "mfm_TextureFrameAnimationTable.h"

#include <utility>

#include "mfm_TextureTable.h"

namespace mfm
{
	void TextureFrameAnimationTable::Load()
	{
		if( !mContainer.empty() )
		{
			return;
		}

		r2bix_table::TextureFrameAnimationInfo::Animation animation;
		r2bix_table::TextureFrameAnimationInfo::AnimationPackageT animation_package;

		//
		// Number
		//
		{
			{
				animation.Index = r2bix_animation::eIndex::Idle_1;
				animation.Container.push_back( r2bix_table::TextureFrameAnimationInfo::AnimationFrame{ 0.f, TextureTable::GetInstance().GetTextureFrame( "number_1" ) } );
				animation_package.push_back( std::move( animation ) );
			}

			mContainer.emplace( 1, std::move( animation_package ) );
		}
	}
}