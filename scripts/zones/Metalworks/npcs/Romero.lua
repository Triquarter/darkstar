-----------------------------------
--  Area: Metalworks
--  NPC:  Romero
--  Type: Smithing Synthesis Image Support
--  @pos -106.336 2.000 26.117 237
-----------------------------------
package.loaded["scripts/zones/Metalworks/TextIDs"] = nil;
-----------------------------------

require("scripts/zones/Metalworks/TextIDs");
require("scripts/globals/status");
require("scripts/globals/crafting");

-----------------------------------
-- onTrade Action
-----------------------------------

function onTrade(player,npc,trade)
end; 

-----------------------------------
-- onTrigger Action
-----------------------------------

function onTrigger(player,npc)
	local guildMember = isGuildMember(player,8);
    local SkillCap = getCraftSkillCap(player,256);
    local SkillLevel = player:getSkillLevel(256);
    
	if (guildMember == 1) then
        if (player:hasStatusEffect(EFFECT_SMITHING_IMAGERY) == false) then
			player:startEvent(0x0069,SkillCap,SkillLevel,2,207,player:getGil(),0,0,0);
	    else
            player:startEvent(0x0069,SkillCap,SkillLevel,2,207,player:getGil(),7127,0,0);
	    end
	else
        player:startEvent(0x0069); -- Standard Dialogue
	end
end; 

-----------------------------------
-- onEventUpdate
-----------------------------------

function onEventUpdate(player,csid,option)
--printf("CSID: %u",csid);
--printf("RESULT: %u",option);
end;

-----------------------------------
-- onEventFinish
-----------------------------------

function onEventFinish(player,csid,option)
--printf("CSID: %u",csid);
--printf("RESULT: %u",option);

    if (csid == 0x0069 and option == 1) then
        player:messageSpecial(SMITHING_SUPPORT,0,2,2);
		player:addStatusEffect(EFFECT_SMITHING_IMAGERY,1,0,120);
    end
end;




