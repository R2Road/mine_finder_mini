#pragma once

#include <vector>

#include "r2_GridIndexConverter.h"
#include "r2_PointInt.h"

//
// # Version Rule
// - 1.0.0 : 사용 가능
// - 0.1.0 : 사용자가 코드를 바꿀 정도의 변화
// - 0.0.1 : 자잘한 변화
//
// # Last Update		: 2023.05.07 AM.08.26
// # Version			: 1.0.1
//

namespace r2
{
	template<typename T>
	class GridBasedOnVector
	{
	public:
		//
		// Base
		//
		using SizeT = std::size_t; // width, height, size
		using CoordinateT = std::size_t; // x, y, linear



		//
		// Value, Container
		//
		using CellT = T;
		using ContainerT = std::vector<CellT>;
		using IteratorT = typename ContainerT::iterator;
		using ConstIteratorT = typename ContainerT::const_iterator;



		//
		//
		//
		GridBasedOnVector() :
			mWidth( 1 )
			, mHeight( 1 )
			, mContainer( 1 * 1 )
			, mIndexConverter( 1, 1 )
		{}

		GridBasedOnVector( const SizeT width, const SizeT height ) :
			mWidth( width )
			, mHeight( height )
			, mContainer( width * height )
			, mIndexConverter( static_cast<int>( width ), static_cast<int>( height ) )
		{}

		GridBasedOnVector( const SizeT width, const SizeT height, const CellT value ) :
			mWidth( width )
			, mHeight( height )
			, mContainer( width * height, value )
			, mIndexConverter( static_cast<int>( width ), static_cast<int>( height ) )
		{}

		GridBasedOnVector( const SizeT width, const SizeT height, const std::initializer_list<CellT> data ) :
			mWidth( width )
			, mHeight( height )
			, mContainer( width * height )
			, mIndexConverter( static_cast<int>( width ), static_cast<int>( height ) )
		{
			memcpy_s(
				&mContainer[0]
				, mContainer.size() * sizeof( CellT )
				, &( *data.begin() )
				, ( data.size() > mContainer.size() ? mContainer.size() * sizeof( CellT ) : data.size() * sizeof( CellT ) )
			);
		}



		//
		// Iteration
		//
		ConstIteratorT begin() const
		{
			return mContainer.begin();
		}
		ConstIteratorT end() const
		{
			return mContainer.end();
		}
		IteratorT begin()
		{
			return mContainer.begin();
		}
		IteratorT end()
		{
			return mContainer.end();
		}



		//
		//
		//
		SizeT GetWidth() const
		{
			return mWidth;
		}
		SizeT GetHeight() const
		{
			return mHeight;
		}
		SizeT GetSize() const
		{
			return mContainer.size();
		}
		CoordinateT GetMaxX() const
		{
			return GetWidth() - 1;
		}
		CoordinateT GetMaxY() const
		{
			return GetHeight() - 1;
		}



		//
		//
		//
		const r2::GridIndexConverter& GetIndexConverter() const
		{
			return mIndexConverter;
		}



		//
		//
		//
		bool IsIn( const CoordinateT linear_index ) const
		{
			return ( GetSize() > linear_index );
		}
		bool IsIn( const CoordinateT x, const CoordinateT y ) const
		{
			return ( GetWidth() > x && GetHeight() > y );
		}
		bool IsIn( const r2::PointInt& p ) const
		{
			return IsIn( p.GetX(), p.GetY() );
		}
		bool IsOut( const CoordinateT linear_index ) const
		{
			return !IsIn( linear_index );
		}
		bool IsOut( const CoordinateT x, const CoordinateT y ) const
		{
			return !IsIn( x, y );
		}
		bool IsOut( const r2::PointInt& p ) const
		{
			return !IsIn( p.GetX(), p.GetY() );
		}



		//
		//
		//
		void Reset( const SizeT width, const SizeT height )
		{
			mWidth = width;
			mHeight = height;

			mContainer.clear();
			mContainer.resize( width * height );

			mIndexConverter = r2::GridIndexConverter( static_cast<int>( width ), static_cast<int>( height ) );
		}
		void Reset( const SizeT width, const SizeT height, const CellT fill_data )
		{
			mWidth = width;
			mHeight = height;

			mContainer.clear();
			mContainer.resize( width * height, fill_data );

			mIndexConverter = r2::GridIndexConverter( static_cast<int>( width ), static_cast<int>( height ) );
		}
		void Reset( const SizeT width, const SizeT height, const std::initializer_list<CellT> data )
		{
			Reset( width, height );
			memcpy_s(
				&mContainer[0]
				, mContainer.size() * sizeof( CellT )
				, &( *data.begin() )
				, ( data.size() > mContainer.size() ? mContainer.size() * sizeof( CellT ) : data.size() * sizeof( CellT ) )
			);
		}
		void Reset( const CellT fill_data )
		{
			Reset( mWidth, mHeight, fill_data );
		}
		void Reset()
		{
			Reset( mWidth, mHeight );
		}



		//
		// Getter
		//
		CellT& Get( const CoordinateT linear_idx )
		{
#if defined( DEBUG ) || defined( _DEBUG )
			if( linear_idx >= static_cast<int>( mContainer.size() ) )
			{
				static CellT dummy;
				return dummy;
			}
#endif

			return mContainer[linear_idx];
		}
		CellT& Get( const CoordinateT x, const CoordinateT y )
		{
			return Get( mIndexConverter.To_Linear( static_cast<int>( x ), static_cast<int>( y ) ) );
		}
		CellT& Get( const r2::PointInt& p )
		{
			return Get( mIndexConverter.To_Linear( p.GetX(), p.GetY() ) );
		}
		const CellT& Get( const CoordinateT linear_idx ) const
		{
#if defined( DEBUG ) || defined( _DEBUG )
			if( linear_idx >= static_cast<int>( mContainer.size() ) )
			{
				static CellT dummy;
				return dummy;
			}
#endif

			return mContainer[linear_idx];
		}
		const CellT& Get( const CoordinateT x, const CoordinateT y ) const
		{
			return Get( mIndexConverter.To_Linear( static_cast<int>( x ), static_cast<int>( y ) ) );
		}
		const CellT& Get( const r2::PointInt& p ) const
		{
			return Get( mIndexConverter.To_Linear( p.GetX(), p.GetY() ) );
		}



		//
		// Setter
		//
		void Set( const CoordinateT linear_idx, const CellT& new_value )
		{
#if defined( DEBUG ) || defined( _DEBUG )
			if( linear_idx >= static_cast<int>( mContainer.size() ) )
			{
				return;
			}
#endif

			mContainer[linear_idx] = new_value;
		}
		void Set( const CoordinateT x, const CoordinateT y, const CellT& new_value )
		{
			Set(
				mIndexConverter.To_Linear( static_cast<int>( x ), static_cast<int>( y ) )
				, new_value
			);
		}
		void Set( const r2::PointInt& p, const CellT& new_value )
		{
			Set(
				mIndexConverter.To_Linear( p.GetX(), p.GetY() )
				, new_value
			);
		}



	private:
		SizeT mWidth;
		SizeT mHeight;
		ContainerT mContainer;

		r2::GridIndexConverter mIndexConverter;
	};
}