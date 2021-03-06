-----------------------------------------
-- ID: 18270
-- Item: Mandau
-- Additional Effect: Poison
-----------------------------------------

require("scripts/globals/status");
require("scripts/globals/magic");

-----------------------------------
-- onAdditionalEffect Action
-----------------------------------

function onAdditionalEffect(player,target,damage)
    local chance = 10;
    if (math.random(0,99) >= chance or applyResistanceAddEffect(player,target,ELE_WATER,0) <= 0.5) then
        return 0,0,0;
    else
        target:delStatusEffect(EFFECT_POISON);
        if (not target:hasStatusEffect(EFFECT_POISON)) then
            target:addStatusEffect(EFFECT_POISON, 10, 3, 30);
        end
        return SUBEFFECT_POISON, 160, EFFECT_POISON;
    end
end;