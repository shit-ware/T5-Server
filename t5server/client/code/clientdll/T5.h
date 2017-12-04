// ==========================================================
// alterOps project
// 
// Component: t5cli
// Sub-component: clientdll
// Purpose: General definitions for T5.
//
// Initial author: NTAuthority
// Started: 2012-01-18
// ==========================================================

#pragma once

#define DVAR_ARCHIVE 1
#define DVAR_LATCHED 32
#define DVAR_PROTECTED 128

typedef union
{
	char* string;
	int integer;
	float value;
	bool boolean;
} dvar_value;

typedef struct dvar_s
{
	const char* name;
	char unknown[20];
	dvar_value current;
} dvar_t;

typedef struct cmd_function_s
{
	char pad[24];
} cmd_function_t;

// DVAR registering defintions

typedef dvar_t* (__cdecl * Dvar_RegisterString_t)(const char* name, const char* default, int flags, const char* description);
extern Dvar_RegisterString_t Dvar_RegisterString;

typedef dvar_t* (__cdecl* Dvar_RegisterBool_t)(const char* name, bool default, int flags, const char* description);
extern Dvar_RegisterBool_t Dvar_RegisterBool;

typedef dvar_t* (__cdecl * Dvar_RegisterInt_t)(const char* name, int default, int min, int max, int flags, const char* description);
extern Dvar_RegisterInt_t Dvar_RegisterInt;

typedef dvar_t* (__cdecl * Dvar_FindVar_t)(char* dvar);
extern Dvar_FindVar_t Dvar_FindVar;

typedef void (__cdecl* Cmd_AddCommand_t)(const char* name, void (__cdecl* callback)(void), cmd_function_s*);
extern Cmd_AddCommand_t Cmd_AddCommand;

typedef bool (__cdecl * DW_ReadLicenseKey_t)(char* buffer, size_t buflen);
extern DW_ReadLicenseKey_t DW_ReadLicenseKey;

typedef void (__cdecl * Com_Error_t)(int type, const char* message, ...);
extern Com_Error_t Com_Error;

typedef void (__cdecl * Cbuf_AddText_t)(int controller, const char* text);
extern Cbuf_AddText_t Cbuf_AddText;


typedef void (__cdecl * Com_Printf_t)(int, const char*, ...);
extern Com_Printf_t Com_Printf;

typedef enum
{
	DVAR_FLAG_NONE = 0x0,			//no flags
	DVAR_FLAG_SAVED = 0x1,			//saves in config_mp.cfg for clients
	DVAR_FLAG_LATCHED = 0x2,			//no changing apart from initial value (although it might apply on a map reload, I think)
	DVAR_FLAG_CHEAT = 0x4,			//cheat
	DVAR_FLAG_REPLICATED = 0x8,			//on change, this is sent to all clients (if you are host)
	DVAR_FLAG_UNKNOWN10 = 0x10,			//unknown
	DVAR_FLAG_UNKNOWN20 = 0x20,			//unknown
	DVAR_FLAG_UNKNOWN40 = 0x40,			//unknown
	DVAR_FLAG_UNKNOWN80 = 0x80,			//unknown
	DVAR_FLAG_USERCREATED = 0x100,		//a 'set' type command created it
	DVAR_FLAG_USERINFO = 0x200,		//userinfo?
	DVAR_FLAG_SERVERINFO = 0x400,		//in the getstatus oob
	DVAR_FLAG_WRITEPROTECTED = 0x800,		//write protected
	DVAR_FLAG_UNKNOWN1000 = 0x1000,		//unknown
	DVAR_FLAG_READONLY = 0x2000,		//read only (same as 0x800?)
	DVAR_FLAG_UNKNOWN4000 = 0x4000,		//unknown
	DVAR_FLAG_UNKNOWN8000 = 0x8000,		//unknown
	DVAR_FLAG_UNKNOWN10000 = 0x10000,		//unknown
	DVAR_FLAG_DEDISAVED = 0x1000000,		//unknown
	DVAR_FLAG_NONEXISTENT = 0xFFFFFFFF	//no such dvar
} dvar_flag;