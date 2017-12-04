// ==========================================================
// RepZ
// 
// Component: steam_api
// Sub-component: clientdll
// Purpose: Some simple branding for the T5 client.
//
// Initial author: Terminator
// Started: 2012-04-28
// ==========================================================

#include "StdInc.h"

void PatchT5_Branding()
{
#ifdef USE_STUPID_BRANDING
	// window title
	//strcpy((char*)0xA575A4, "Call of Duty: RepZ");
    
	// change console text
	strcpy((char*)0xA92684, "COD_RepZ_MP");
	
	//strcpy((char*)0xA59C0C, GetMOTD("")); // TICKER_MESSAGE_CATEGORY_CLAN_CAPS
	strcpy((char*)0xA8BA78, "RepZ"); // TICKER_MESSAGE_CATEGORY_COD_CAPS (COD)

	// server name changes
	strcpy((char*)0xA28DF4, "RepZPublic"); // er, not sure about this?
	strcpy((char*)0xA2CA70, "RepZPrivate"); // private match

	// this isn't how it's meant to be done but it's 04:23 and i want to sleep
	strcpy((char*)0xA52590, "Welcome to Call of Duty: RepZ!\n----- Initializing Renderer ----\n");

	// and that should be it?
#endif
}