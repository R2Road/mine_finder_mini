#include "TestMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/test_mfm_mine_position_generator.h"
#include "item/test_mfm_stage.h"

r2cm::TitleFunctionT TestMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Test Menu";
	};
}
r2cm::DescriptionFunctionT TestMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2cm::WriteFunctionT TestMenu::GetWriteFunction() const
{
	return []( r2cm::MenuProcessor* ret )
	{
		ret->AddItem( '1', test_mfm_mine_position_generator::Declaration() );
		ret->AddItem( '2', test_mfm_mine_position_generator::Get() );
		ret->AddItem( '3', test_mfm_mine_position_generator::Clear() );



		ret->AddLineFeed();



		ret->AddItem( 'q', test_mfm_stage::Declaration() );
		ret->AddItem( 'w', test_mfm_stage::Builder() );
		ret->AddItem( 'e', test_mfm_stage::Demo() );



		ret->AddSplit();



		ret->AddItem(
			27
			, r2cm::eColor::BG_Purple
			, []()->const char* { return "Exit"; }
			, []()->r2cm::eDoLeaveAction
			{
				return r2cm::eDoLeaveAction::Exit;
			}
		);
	};
}