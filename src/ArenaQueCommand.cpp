/*
 Arena Queue Commands
*/
#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "MapManager.h"
#include "Chat.h"
#include "Common.h"
#include "Language.h"
 
class arenaqueue : public CommandScript
{
public:
  arenaqueue() : CommandScript("arenaqueue") { }
 
  std::vector<ChatCommand> GetCommands() const override
	{
      static std::vector<ChatCommand> arenaCommandTable =
      {
         { "2v2",            SEC_PLAYER, false, &Handle2v2Command,          "" },
         { "3v3",            SEC_PLAYER, false, &Handle3v3Command,          "" },
         { "5v5",            SEC_PLAYER, false, &Handle5v5Command,          "" },
	  };
 
      static std::vector<ChatCommand> commandTable =
      {
          { "arena",       SEC_PLAYER,  false, nullptr,               "", arenaCommandTable }
      };
		return commandTable;
 
	}
 
	static bool Handle2v2Command(ChatHandler* handler, const char* args)
		{
		Player* me = handler->GetSession()->GetPlayer();
			if(me->GetArenaTeamId(1) != 0)
					{
					me->AddBattlegroundQueueId(BATTLEGROUND_QUEUE_2v2);
					}
			else
					{
					handler->PSendSysMessage("You aren't in an arena team.");
					}
			return true;
		}
 
	static bool Handle3v3Command(ChatHandler* handler, const char* args)
		{
		Player* me = handler->GetSession()->GetPlayer();
			if(me->GetArenaTeamId(1) != 0)
					{
					me->AddBattlegroundQueueId(BATTLEGROUND_QUEUE_3v3);
					}
			else
					{
					handler->PSendSysMessage("You aren't in an arena team.");
					}
			return true;
		}
 
    static bool Handle5v5Command(ChatHandler* handler, const char* args)
    {
        Player* me = handler->GetSession()->GetPlayer();
        if (me->GetArenaTeamId(1) != 0)
        {
            me->AddBattlegroundQueueId(BATTLEGROUND_QUEUE_5v5);
        }
        else
        {
            handler->PSendSysMessage("You aren't in an arena team.");
        }
        return true;
    }
 };
 
void AddSC_arenaqueue()
{
    new arenaqueue();
}
