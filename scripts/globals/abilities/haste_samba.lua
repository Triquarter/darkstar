-----------------------------------
-- Ability: Haste Samba
-----------------------------------
 
require("scripts/globals/status");

-----------------------------------
-- onUseAbility
-----------------------------------
 
function onAbilityCheck(player,target,ability)
    if(player:hasStatusEffect(EFFECT_FAN_DANCE)) then
        return MSGBASIC_UNABLE_TO_USE_JA2, 0;
    elseif (player:hasStatusEffect(EFFECT_TRANCE)) then
        return 0,0;
	elseif (player:getTP() < 35) then
		return MSGBASIC_NOT_ENOUGH_TP,0;
	else
		player:delTP(35);
		return 0,0;
	end;
end;

function onUseAbility(player, target, ability)
    local duration = 120 + player:getMod(MOD_SAMBA_DURATION);
    duration = duration * (100 + player:getMod(MOD_SAMBA_PDURATION))/100;
	player:delStatusEffect(EFFECT_DRAIN_SAMBA);
	player:delStatusEffect(EFFECT_ASPIR_SAMBA);
	player:addStatusEffect(EFFECT_HASTE_SAMBA,player:getMerit(MERIT_HASTE_SAMBA_EFFECT)+52,0,duration);
end;