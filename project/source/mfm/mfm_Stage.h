#pragma once

#include "r2/r2_GridBasedOnVector.h"

namespace mfm
{
	struct Tile
	{
		enum class eType {
			Empty,
			Mine,
		};

		eType type;
	};



	class Stage
	{
	public:
		using Terrain = r2::GridBasedOnVector<Tile>;



		Stage( const uint32_t width, const uint32_t height );



		//
		// Getter
		//
		std::size_t GetWidth() const
		{
			return mTerrain.GetWidth();
		}
		std::size_t GetHeight() const
		{
			return mTerrain.GetHeight();
		}
		std::size_t GetSize() const
		{
			return mTerrain.GetSize();
		}
		std::size_t GetMaxX() const
		{
			return mTerrain.GetMaxX();
		}
		std::size_t GetMaxY() const
		{
			return mTerrain.GetMaxY();
		}



		//
		// Terrain
		//
		const Terrain::CellT& GetTile( const std::size_t x, const std::size_t y ) const
		{
			return mTerrain.Get( x, y );
		}
		void SetTile( const std::size_t x, const std::size_t y, const Terrain::CellT& new_value )
		{
			mTerrain.Set( x, y, new_value );
		}



		//
		//
		//
		void Build();



	private:
		Terrain mTerrain;
	};
}