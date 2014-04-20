/*
===========================================================================

  Copyright (c) 2010-2014 Darkstar Dev Teams

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see http://www.gnu.org/licenses/

  This file is part of DarkStar-server source code.

===========================================================================
*/

#ifndef _BATTLEUTILS_H
#define _BATTLEUTILS_H

#include "../../common/cbasetypes.h"
#include "../blue_spell.h"

#include <list>

#include "../entities/battleentity.h"
#include "../merit.h"

class CAbility;
class CItemWeapon;
class CMobSkill;
class CSpell;
class CTrait;
class CWeaponSkill;

enum ENSPELL
{
	ENSPELL_NONE			= 0,
	ENSPELL_I_FIRE			= 1,
	ENSPELL_I_EARTH			= 2,
	ENSPELL_I_WATER			= 3,
	ENSPELL_I_WIND			= 4,
	ENSPELL_I_ICE			= 5,
	ENSPELL_I_THUNDER		= 6,
	ENSPELL_I_LIGHT			= 7,
	ENSPELL_I_DARK			= 8,
	ENSPELL_II_FIRE			= 9,
	ENSPELL_II_EARTH		= 10,
	ENSPELL_II_WATER		= 11,
	ENSPELL_II_WIND			= 12,
	ENSPELL_II_ICE			= 13,
	ENSPELL_II_THUNDER		= 14,
	ENSPELL_II_LIGHT		= 15,
	ENSPELL_BLOOD_WEAPON	= 16,
	ENSPELL_ROLLING_THUNDER = 17,
	ENSPELL_AUSPICE			= 18,
	ENSPELL_DRAIN_SAMBA		= 19,
	ENSPELL_ASPIR_SAMBA		= 20,
	ENSPELL_HASTE_SAMBA		= 21
};

enum SPIKES
{
    SPIKE_NONE            = 0,
    SPIKE_BLAZE           = 1,
    SPIKE_ICE             = 2,
    SPIKE_DREAD           = 3,
    SPIKE_CURSE           = 4,
    SPIKE_SHOCK           = 5,
    SPIKE_REPRISAL        = 6
};

enum ELEMENT
{
    ELEMENT_NONE = 0,
    ELEMENT_FIRE = 1,
    ELEMENT_EARTH = 2,
    ELEMENT_WATER = 3,
    ELEMENT_WIND = 4,
    ELEMENT_ICE = 5,
    ELEMENT_THUNDER = 6,
    ELEMENT_LIGHT = 7,
    ELEMENT_DARK = 8
};


namespace battleutils
{
	void			LoadSkillTable();
	void			LoadWeaponSkillsList();
	void			LoadMobSkillsList();
	void			LoadEnmityTable();
    void			LoadSkillChainDamageModifiers();

	uint8			CheckMultiHits(CBattleEntity* PEntity, CItemWeapon* PWeapon);

	uint8			getHitCount(uint8 hits);
	uint8			CheckMobMultiHits(CBattleEntity* PEntity);

	void			GetSnapshotReduction(CCharEntity* m_PChar);
	int32			GetRangedAttackBonuses(CBattleEntity* battleEntity);
	int32			GetRangedAccuracyBonuses(CBattleEntity* battleEntity);

	void			SetMonsterTreasureHunterLevel(CCharEntity* PChar, CMobEntity* Monster);

	uint8			GetSkillRank(SKILLTYPE SkillID, JOBTYPE JobID);
	uint16			GetMaxSkill(SKILLTYPE SkillID, JOBTYPE JobID, uint8 level);
    uint16          GetMaxSkill(uint8 rank, uint8 level);

	CWeaponSkill*	GetWeaponSkill(uint16 WSkillID);
	CMobSkill*		GetMobSkill(uint16 SkillID);

	std::list<CWeaponSkill*> GetWeaponSkills(uint8 skill);
	std::vector<CMobSkill*>  GetMobSkillsByFamily(uint16 FamilyID);

	void				FreeWeaponSkillsList();
	void				FreeMobSkillsList();
    void				FreeSkillChainDamageModifiers();

    SUBEFFECT			GetSkillChainEffect(CBattleEntity* PDefender, CWeaponSkill* PWeaponSkill);
    SUBEFFECT			GetSkillChainEffect(CBattleEntity* PDefender, CBlueSpell* PSpell);
    SKILLCHAIN_ELEMENT  FormSkillchain(std::list<SKILLCHAIN_ELEMENT> resonance, std::list<SKILLCHAIN_ELEMENT> skill);
    uint8				GetSkillchainTier(SKILLCHAIN_ELEMENT skillchain);
    uint8				GetSkillchainSubeffect(SKILLCHAIN_ELEMENT skillchain);
    uint16				GetSkillchainMinimumResistance(SKILLCHAIN_ELEMENT element, CBattleEntity* PDefender);

	bool			IsParalised(CBattleEntity* PAttacker);
    bool			IsAbsorbByShadow(CBattleEntity* PDefender);
	bool			IsIntimidated(CBattleEntity* PAttacker, CBattleEntity* PDefender);
	bool			IsAnticipated(CBattleEntity* PDefender, bool forceRemove, bool ignore);

	int32				GetFSTR(CBattleEntity* PAttacker, CBattleEntity* PDefender, uint8 SlotID);
	uint8				GetHitRateEx(CBattleEntity* PAttacker, CBattleEntity* PDefender, uint8 attackNumber, uint8 offsetAccuracy);
	uint8				GetHitRate(CBattleEntity* PAttacker, CBattleEntity* PDefender);
	uint8				GetHitRate(CBattleEntity* PAttacker, CBattleEntity* PDefender, uint8 attackNumber);
	uint8				GetHitRate(CBattleEntity* PAttacker, CBattleEntity* PDefender, uint8 attackNumber, uint8 offsetAccuracy);
	uint8				GetCritHitRate(CBattleEntity* PAttacker, CBattleEntity* PDefender, bool ignoreSneakTrickAttack);
	uint8				GetBlockRate(CBattleEntity* PAttacker, CBattleEntity* PDefender);
    uint8				GetParryRate(CBattleEntity* PAttacker, CBattleEntity* PDefender);
    uint8				GetGuardRate(CBattleEntity* PAttacker, CBattleEntity* PDefender);
	float				GetDamageRatio(CBattleEntity* PAttacker, CBattleEntity* PDefender, bool isCritical, uint16 bonusAttPercent);

	uint32				TakePhysicalDamage(CBattleEntity* PAttacker, CBattleEntity* PDefender, int32 damage, bool isBlocked, uint8 slot, uint16 tpMultiplier, CBattleEntity* taChar, bool giveTPtoVictim);
    uint16				TakeSkillchainDamage(CBattleEntity* PAttacker, CBattleEntity* PDefender, uint16 lastSkillDamage);
	uint32				MagicCalculateCure(CBattleEntity* PCaster, CBattleEntity* PTarget, CSpell* PSpell, int8 targetNumber, CZone* PZone);

	bool                TryInterruptSpell(CBattleEntity* PAttacker, CBattleEntity* PDefender);
	float				GetRangedPDIF(CBattleEntity* PAttacker, CBattleEntity* PDefender);
	void				HandleRangedAdditionalEffect(CCharEntity* PAttacker, CBattleEntity* PDefender,apAction_t* Action);
    uint16              CalculateSpikeDamage(CBattleEntity* PAttacker, CBattleEntity* PDefender, uint8 spikesType);
    bool                HandleSpikesDamage(CBattleEntity* PAttacker, CBattleEntity* PDefender,apAction_t* Action, uint32 damage);
    bool                HandleSpikesEquip(CBattleEntity* PAttacker, CBattleEntity* PDefender, apAction_t* Action, uint8 damage, SUBEFFECT spikesType, uint8 chance);
    void                HandleSpikesStatusEffect(CBattleEntity* PAttacker, apAction_t* Action);
	void				HandleEnspell(CBattleEntity* PAttacker, CBattleEntity* PDefender,apAction_t* Action, uint8 hitNumber, CItemWeapon* weapon, uint32 damage);
	uint8				GetRangedHitRate(CBattleEntity* PAttacker, CBattleEntity* PDefender, bool isBarrage);
	int32				CalculateEnspellDamage(CBattleEntity* PAttacker, CBattleEntity* PDefender, uint8 Tier, uint8 element);

    uint8				GetEnmityMod(uint8 level, uint8 modType);
	bool				Enfeeble(CBattleEntity* PCaster, CBattleEntity* PDefender, EFFECT Effect);
	bool				isValidSelfTargetWeaponskill(int wsid);
	float				CalculateBaseTP(int delay, int stp);
    void				GenerateCureEnmity(CBattleEntity* PSource, CBattleEntity* PTarget, uint16 amount);

    CItemWeapon*		GetEntityWeapon(CBattleEntity* PEntity, SLOTTYPE Slot);
    CItemArmor*			GetEntityArmor(CBattleEntity* PEntity, SLOTTYPE Slot);

	uint32				HandleSpecialPhysicalDamageReduction(CCharEntity* PAttacker, uint32 damage, apAction_t* Action);
    void				MakeEntityStandUp(CBattleEntity* PEntity);
    bool				IsEngauged(CBattleEntity* PEntity);
	CBattleEntity*		getAvailableTrickAttackChar(CBattleEntity* taUser, CBattleEntity* PMob);

    bool				HasNinjaTool(CBattleEntity* PEntity, CSpell* PSpell, bool ConsumeTool);

	bool				TryCharm(CBattleEntity* PCharmer, CBattleEntity* PVictim, uint32 base);
	void				tryToCharm(CBattleEntity* PCharmer, CBattleEntity* PVictim);

	uint16				doSoulEaterEffect(CCharEntity* m_PChar, uint32 damage);
	uint16				getOverWhelmDamageBonus(CCharEntity* m_PChar, CBattleEntity* PDefender, uint16 damage);
	uint16				jumpAbility(CBattleEntity* PAttacker, CBattleEntity* PVictim, uint8 tier);

	void				TransferEnmity(CBattleEntity* CharHateReceiver, CBattleEntity* CharHateGiver, CMobEntity* PMob, uint8 percentToTransfer);
	uint8				getBarrageShotCount(CCharEntity* PChar);
	uint8				getStoreTPbonusFromMerit(CBattleEntity* PEntity);

	EFFECT				getCorsairRollEffect(uint16 id);
    void                ClaimMob(CBattleEntity* PDefender, CBattleEntity* PAttacker);

    int32               DmgTaken(CBattleEntity* PDefender, int32 damage);
    int32               BreathDmgTaken(CBattleEntity* PDefender, int32 damage);
    int32               MagicDmgTaken(CBattleEntity* PDefender, int32 damage);
    int32               PhysicalDmgTaken(CBattleEntity* PDefender, int32 damage);
    int32               RangedDmgTaken(CBattleEntity* PDefender, int32 damage);

    // returns damage taken
    int32               HandleStoneskin(CBattleEntity* PDefender, int32 damage);

	// handles enmity loss calculations for tranquil heart
	float               HandleTranquilHeart(CBattleEntity* PEntity);

	void				assistTarget(CCharEntity* PChar, uint16 TargID);
    CMobSkill*          GetTwoHourMobSkill(JOBTYPE job);

    uint8               GetSpellAoEType(CBattleEntity* PCaster, CSpell* PSpell);
    WEATHER             GetWeather(CBattleEntity* PEntity, bool ignoreScholar);
    void				DrawIn(CBattleEntity* PEntity, position_t* pos, float offset);
	void				DoWildCardToEntity(CCharEntity* PCaster, CCharEntity* PTarget, uint8 roll);
};

#endif
