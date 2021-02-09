#if defined _caseopening_included
  #endinput
#endif
#define _caseopening_included

#define MAX_CASES 100
#define MAX_CASE_SPAWN 128
#define MAX_ITEMS 40
#define MAX_MODULES 64
#define MAX_GRADES 12
#define PLUGIN_INT_VERSION 103060

/**
 * Returns the version of the caseopening system
 * 
 * @return	Version
 */
native int Case_Version();

/**
 * Registers a new module for the case system
 *
 * @param type	Name of the module
 * @param valuetype	True if integer value, false otherwise
 * @param fOpened	Function to call when an item is opened with this moduletype
 * @noreturn
 */
native void Case_RegisterModule(char[] type, bool valuetype = true, Function:fOpened);

native void Case_Log(const Jatekos jatekos, const char[] message, any...)

native bool Case_IsInventoryLoaded(Jatekos jatekos);
native bool Case_IsBanned(Jatekos jatekos);

native bool Case_IsValidCase(int caseid);

native int Case_GiveCaseAmount(Jatekos jatekos, int caseid, int amount, char[] reason = "");
native int Case_GiveKeyAmount(Jatekos jatekos, int caseid, int amount, char[] reason = "");

native int Case_RemoveCaseAmount(int playerid, int caseid, char[] reason = "");
native int Case_RemoveKeyAmount(int playerid, int caseid, char[] reason = "");

native int Case_GetPlayerId(Jatekos jatekos);

native int Case_GetTotalCases();
native int Case_GetCaseAmount(Jatekos jatekos, int caseid);
native int Case_GetKeyAmount(Jatekos jatekos, int caseid);

native int Case_GetCaseName(int caseid, char[] output);
native int Case_GetCaseUniqueName(int caseid, char[] output);

native int Case_StoreGiveItem(char[] steamid, char[] moduletype, char[] value);

native int Case_WeaponSkin_GetPaintName(int paintkit, char[] output);
native int Case_WeaponSkin_GetDuplicateCount(int client, char[] classname, int paintkit);
native int Case_WeaponSkin_FetchInventory(int client);

native int Case_WeaponSkin_GetSkinIndex(int client, const char[] classname);
native int Case_WeaponSkin_GetKnifeIndex(int client);
native int Case_WeaponSkin_GetPattern(int client, const char[] classname);
native int Case_WeaponSkin_GetStatTrak(int client, const char[] classname);
native float Case_WeaponSkin_GetWear(int client, const char[] classname);

native void Market_SetCash(int client, int newcash);
native int Market_GetCash(int client);

forward void Case_OnInventoryLoaded(int client);

forward void Case_StartOpening(int client, char[] casemodel);
forward void Case_OnCaseOpened(int client, char[] type, char[] value, char[] grade);
forward void Case_OnClientBanned(int admin, int target);

forward void Case_WeaponSkin_OnBundleOpened(int client, char[] openeditem);
forward void Case_UpdatePlayerWeapons(int client, char[] classname, int paintkit, float wear, int quality, int stattrak, int pattern);
forward void Case_RemovePlayerWeapons(int client, char[] classname);
forward void Case_UpdateNameTag(int client, char[] classname, const char[] nametag);

forward void Case_MarketSold(int client, char[] classname, int paintkit, bool trade);
forward void Case_MarketBought(int client, char[] classname, int paintkit);
forward void Case_MarketTrade(int trader, int partner);

public SharedPlugin __caseopening = 
{
	name = "caseopening",
	file = "caseopening.smx",
	#if defined REQUIRE_PLUGIN
		required = 1,
	#else
		required = 0,
	#endif
};

#if !defined REQUIRE_PLUGIN
public void __pl_caseopening_SetNTVOptional()
{
	MarkNativeAsOptional("Case_RegisterModule");
	MarkNativeAsOptional("Case_IsInventoryLoaded");
	MarkNativeAsOptional("Case_IsBanned");
	MarkNativeAsOptional("Case_IsValidCase");
	MarkNativeAsOptional("Case_GiveCaseAmount");
	MarkNativeAsOptional("Case_GiveKeyAmount");
	MarkNativeAsOptional("Case_RemoveCaseAmount");
	MarkNativeAsOptional("Case_RemoveKeyAmount");
	MarkNativeAsOptional("Case_GetPlayerId");
	MarkNativeAsOptional("Case_GetTotalCases");
	MarkNativeAsOptional("Case_GetCaseAmount");
	MarkNativeAsOptional("Case_GetKeyAmount");
	MarkNativeAsOptional("Case_GetCaseName");
	MarkNativeAsOptional("Case_GetCaseUniqueName");
	MarkNativeAsOptional("Case_Version");
	MarkNativeAsOptional("Case_Log");

	MarkNativeAsOptional("Case_StoreGiveItem");

	MarkNativeAsOptional("Case_WeaponSkin_GetPaintName");
	MarkNativeAsOptional("Case_WeaponSkin_GetDuplicateCount");
	MarkNativeAsOptional("Case_WeaponSkin_FetchInventory");

	MarkNativeAsOptional("Case_WeaponSkin_GetSkinIndex");
	MarkNativeAsOptional("Case_WeaponSkin_GetKnifeIndex");
	MarkNativeAsOptional("Case_WeaponSkin_GetPattern");
	MarkNativeAsOptional("Case_WeaponSkin_GetStatTrak");
	MarkNativeAsOptional("Case_WeaponSkin_GetWear");

	MarkNativeAsOptional("Market_SetCash");
	MarkNativeAsOptional("Market_GetCash");
}
#endif