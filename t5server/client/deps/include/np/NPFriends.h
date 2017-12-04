// ==========================================================
// alterIWnet project
// 
// Component: xnp
// Sub-component: libnp
// Purpose: definitions for the NP friends service
//
// Initial author: NTAuthority
// Started: 2012-01-16
// ==========================================================

struct NPGetUserAvatarResult
{
	EGetFileResult result;
	int32_t guid;
	uint32_t fileSize;
	uint8_t* buffer;
};

enum FriendsRosterMessageResult
{
	RosterSuccess = 1,
	RosterFailed = 0,
};

struct NPFriend
{
	int id;
	char username[256];
	int isonline;
	char hostname[256];
	char current_server[1024];
};

struct NPFriendResult
{
	FriendsRosterMessageResult result;
	int32_t numResults;
	NPFriend* friends;
};

//Used by the steam api (t5)
enum EPresenceState
{
	PresenceStateUnknown,
	PresenceStateOnline,
	PresenceStateAway,
	PresenceStateExtendedAway,
	PresenceStateOffline
};