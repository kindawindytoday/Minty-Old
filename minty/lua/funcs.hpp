#pragma once

#include "..\gilua\luaHook.h"
#include "../json/json.hpp"
//using json = nlohmann::json;
//config json;

const char* animation_options[] = { 
"ActivitySkill_ElectricCoreFly",
"Akimbo02AS",
"Akimbo02BS",
"Akimbo02Loop",
"Attack01",
"Attack02",
"Attack03",
"Attack04",
"Attack05",
"ChannelAS",
"ChannelBS",
"ChannelLoop",
"ClimbDownToGround",
"ClimbIdle",
"ClimbJump",
"ClimbMove0",
"ClimbMove1",
"CrouchDrop",
"CrouchIdle",
"CrouchMove",
"CrouchRoll",
"CrouchToStandby",
"DropDown",
"ExtraAttack",
"ExtraAttack_AS",
"FallDie",
"FallDie_AS",
"FallOnGround",
"FallOnGroundLit",
"FallToGroundRun",
"FallToGroundRunHard",
"FallToGroundSprint",
"FallingAnthem_AS_1",
"FallingAnthem_AS_2",
"FallingAnthem_BS_1",
"FallingAnthem_BS_2",
"FallingAnthem_Loop",
"FallingAnthem_Loop_Low",
"Fly",
"FlyStart",
"FrozenWindmill",
"FrozenWindmill_AS",
"HitGroundDie",
"Hit_H",
"Hit_L",
"Hit_Throw",
"Hit_ThrowAir",
"Hit_Throw_Ground",
"Icespine",
"Icespine_Out",
"Jump",
"JumpForRun",
"JumpForSprint",
"JumpForWalk",
"JumpOffWall",
"JumpUpWallForStandby",
"JumpUpWallReady",
"LiquidStrike_AS",
"LiquidStrike_AS_OnWater",
"LiquidStrike_BS",
"LiquidStrike_BS1",
"LiquidStrike_BS_0",
"LiquidStrike_FatalMove",
"LiquidStrike_FatalStandby",
"LiquidStrike_Move",
"LiquidStrike_MoveStandby",
"LiquidStrike_Strike",
"NormalDie",
"PlayMusic_Lyre_AS",
"PlayMusic_Lyre_BS",
"PlayMusic_Lyre_Loop",
"PlayMusic_Qin_AS",
"PlayMusic_Qin_BS",
"PlayMusic_Qin_Loop",
"Run",
"RunToIdle",
"RunToWalk",
"ShowUp",
"SitBDown",
"SitBLoop",
"SitBUp",
"SitDown",
"SitLoop",
"SitUp",
"SkiffNormal",
"SlipBackWall",
"SlipFaceWall",
"Sprint",
"SprintBS",
"SprintToIdle",
"SprintToRun",
"Standby",
"Standby2ClimbA",
"Standby2ClimbB",
"StandbyPutaway",
"StandbyPutawayOver",
"StandbyShow_01",
"StandbyShow_02",
"StandbyVoice",
"StandbyWeapon",
"Struggle",
"SwimDash",
"SwimDie",
"SwimIdle",
"SwimJump",
"SwimJumpDrop",
"SwimJumpToWater",
"SwimMove",
"Think01AS",
"Think01BS",
"Think01Loop",
"TurnDir",
"Upstairs",
"Walk",
"WalkToIdle",
"WalkToRun"
};

const char* emo_options[] = {
    "Angry05",
    "Angry06",
    "Closed01",
    "Closed02",
    "Closed03",
    "Closed04",
    "Closed05",
    "Happy01",
    "Happy02",
    "Happy03",
    "Happy04",
    "Happy05",
    "Normal01",
    "Normal02",
    "Normal03",
    "Normal04",
    "Normal05",
    "Normal06",
    "Sad01",
    "Sad02",
    "Sad03",
    "Sad04",
    "Sad05",
    "Surprise01",
    "Surprise02",
    "Surprise03",
    "Surprise04",
    "Surprise05",
    "Sweat01",
    "Sweat02",
    "Sweat03",
    "Sweat04",
    "Sweat05",
    "Tired01",
    "Tired02",
    "Tired03",
    "Tired04",
    "Tired05",
    "Default",
    "Angry_01",
    "Angry_02",
    "Angry_03",
    "Angry_04",
    "Default_01",
    "Doubt_01",
    "Doubt_02",
    "Doubt_03",
    "Doubt_04",
    "Gentle_01",
    "Gentle_02",
    "Gentle_03",
    "Gentle_04",
    "HiClosed_01",
    "HiClosed_02",
    "HiClosed_03",
    "HiClosed_04",
    "HiClosed_05",
    "HiClosed_06",
    "HiClosed_07",
    "LowClosed_01",
    "LowClosed_02",
    "LowClosed_03",
    "LowClosed_04",
    "LowClosed_05",
    "LowClosed_06",
    "LowClosed_07",
    "MidClosed_01",
    "MidClosed_02",
    "MidClosed_03",
    "MidClosed_04",
    "MidClosed_05",
    "MidClosed_06",
    "MidClosed_07",
    "Normal_01",
    "Normal_02",
    "Normal_03",
    "Normal_04",
    "Normal_05",
    "Surprise_01",
    "Surprise_02",
    "Sweat_01",
    "Sweat_02",
    "Sweat_03",
    "Sweat_04"
};

const char* pho_options[] = {
    "P_None",
    "P_A",
    "P_O",
    "P_E",
    "P_I",
    "P_U",
    "P_N",
    "P_Smile01",
    "P_Smile02",
    "P_Smile03",
    "P_Smile04",
    "P_Smile05",
    "P_Smile06",
    "P_Angry01",
    "P_Angry02",
    "P_Angry03",
    "P_Angry04",
    "P_Doya01",
    "P_Doya02",
    "P_Pero01",
    "P_Pero02",
    "P_Neko01",
    "P_Neko02",
    "P_Delta01",
    "P_Delta02",
    "P_Square01",
    "P_Line01",
    "P_TalkNone01",
    "P_TalkNone02",
    "P_TalkNone03",
    "P_TalkSmile01",
    "P_TalkSmile02",
    "P_TalkSmile03",
    "P_TalkAngry01",
    "P_TalkAngry02",
    "P_TalkAngry03",
    "P_TalkNone04",
    "P_TalkDoya01",
    "P_TalkSquare01",
    "P_TalkDelta01",
    "P_TalkSmile04",
    "P_Default",
    "P_Default01",
    "P_Normal01",
    "P_Doya03",
    "P_Angry05",
    "P_Fury01",
    "P_A01",
    "P_I01",
    "P_U01",
    "P_E01",
    "P_O01",
    "P_N01",
    "P_TalkNormal121",
    "P_TalkNormal122",
    "P_TalkNormal131",
    "P_TalkNormal132",
    "P_TalkNormal221",
    "P_TalkNormal222",
    "P_TalkNormal231",
    "P_TalkNormal232",
    "P_TalkNormal321",
    "P_TalkNormal322",
    "P_TalkNormal331",
    "P_TalkSmile121",
    "P_TalkSmile122",
    "P_TalkSmile131",
    "P_TalkSmile132",
    "P_TalkSmile221",
    "P_TalkSmile222",
    "P_TalkSmile231",
    "P_TalkSmile232",
    "P_TalkSmile321",
    "P_TalkSmile322",
    "P_TalkSmile331",
    "P_TalkAngry121",
    "P_TalkAngry122",
    "P_TalkAngry131",
    "P_TalkAngry132",
    "P_TalkAngry221",
    "P_TalkAngry222",
    "P_TalkAngry231",
    "P_TalkAngry232",
    "P_TalkAngry321",
    "P_TalkAngry322",
    "P_TalkAngry331",
    "P_Default_01",
    "P_A_01",
    "P_I_01",
    "P_U_01",
    "P_E_01",
    "P_O_01",
    "P_N_01",
    "P_Angry_01",
    "P_Angry_02",
    "P_Angry_03",
    "P_Angry_04",
    "P_Angry_05",
    "P_Doya_01",
    "P_Doya_02",
    "P_Doya_03",
    "P_Fury_01",
    "P_Neko_01",
    "P_Neko_02",
    "P_Normal_01",
    "P_Smile_01",
    "P_Smile_02",
    "P_Smile_03",
    "P_Smile_04",
    "P_Smile_05",
    "P_Talk_Angry_121",
    "P_Talk_Angry_122",
    "P_Talk_Angry_131",
    "P_Talk_Angry_132",
    "P_Talk_Angry_221",
    "P_Talk_Angry_222",
    "P_Talk_Angry_231",
    "P_Talk_Angry_232",
    "P_Talk_Angry_321",
    "P_Talk_Angry_322",
    "P_Talk_Angry_331",
    "P_Talk_Normal_121",
    "P_Talk_Normal_122",
    "P_Talk_Normal_131",
    "P_Talk_Normal_132",
    "P_Talk_Normal_221",
    "P_Talk_Normal_222",
    "P_Talk_Normal_231",
    "P_Talk_Normal_232",
    "P_Talk_Normal_321",
    "P_Talk_Normal_322",
    "P_Talk_Normal_331",
    "P_Talk_Smile_121",
    "P_Talk_Smile_122",
    "P_Talk_Smile_131",
    "P_Talk_Smile_132",
    "P_Talk_Smile_221",
    "P_Talk_Smile_222",
    "P_Talk_Smile_231",
    "P_Talk_Smile_232",
    "P_Talk_Smile_321",
    "P_Talk_Smile_322",
    "P_Talk_Smile_331",
    "P_Pero_01",
    "P_Pero_02"
};

const char* char_changeuid = "CS.UnityEngine.GameObject.Find(\"/BetaWatermarkCanvas(Clone)/Panel/TxtUID\"):GetComponent(\"Text\").text = \"<b><i><color=#11edb1>KINDA WINDY TODAY</color></i></b>\"";

const char* char_eleminf = R"MY_DELIMITER(
local function normalattack()
local effectpool = CS.UnityEngine.GameObject.Find("/EffectPool")
--loop through all the children of the effectpool
for i = 0, effectpool.transform.childCount - 1 do
local child = effectpool.transform:GetChild(i)
if string.match(child.gameObject.name, "Attack") then
for k = 0, child.transform.childCount - 1 do
local bladechild = child.transform : GetChild(k)
if string.match(bladechild.gameObject.name, "e") then
local success, result = pcall(function()
    bladechild.gameObject:GetComponent(typeof(CS.UnityEngine.ParticleSystem)).main.startColor = CS.UnityEngine.ParticleSystem.MinMaxGradient(CS.UnityEngine.Color()MY_DELIMITER";

const char* char_eleminf_end = R"MY_DELIMITER(
))
    end)
    if not success then
        end
        end
        end
        end
        end
        end
        function onError(error)
        CS.MoleMole.ActorUtils.ShowMessage(tostring(error))
        end
        xpcall(normalattack, onError)
)MY_DELIMITER";

const char* char_browser_on = R"MY_DELIMITER(

local function findActiveAvatar()
    local avatarRoot = CS.UnityEngine.GameObject.Find("/EntityRoot/AvatarRoot")
    if avatarRoot.transform.childCount == 0 then
        return
    end
    for i = 0, avatarRoot.transform.childCount - 1 do
        local avatar = avatarRoot.transform:GetChild(i)
        if avatar.gameObject.activeInHierarchy then
            return avatar.gameObject
        end
    end
end

local function findAvatarBody(avatar)
    for i = 0, avatar.transform.childCount - 1 do
        local transform = avatar.transform:GetChild(i)
        if transform.name == "OffsetDummy" then
            for j = 0, transform.childCount - 1 do
                local child = transform:GetChild(j)
                for k = 0, child.transform.childCount - 1 do
                    local body = child.transform:GetChild(k)
                    if body.name == "Body" then
                        return body.gameObject
                    end
                end
            end
        end
    end
end
local function createPrimitive()
    local nowAvatar = findActiveAvatar()
    local nowBody = findAvatarBody(nowAvatar)
    local primitive = CS.UnityEngine.GameObject.CreatePrimitive(CS.UnityEngine.PrimitiveType.Plane);
    primitive.transform.localScale = CS.UnityEngine.Vector3(3.2,1,1.8);
    primitive.transform.localRotation = CS.UnityEngine.Quaternion(0.5, 0.5,-0.5, 0.5);
	primitive.name = "BrowserObject"
    local position = nowBody.transform.position
    primitive.transform.position = CS.UnityEngine.Vector3(position.x, position.y + 5, position.z);
    local browser = primitive:AddComponent(typeof(CS.ZenFulcrum.EmbeddedBrowser.Browser));
	browser._width = 1920;
    browser._height = 1080;
    browser._url = "https://google.com";

end
function start()
    createPrimitive()
end

start()

)MY_DELIMITER";
const char* char_browser_off = R"MY_DELIMITER(
CS.UnityEngine.Object.Destroy(CS.UnityEngine.GameObject.Find("/BrowserObject"))
)MY_DELIMITER";

const char* char_bub_initiate = R"MY_DELIMITER(
local function findHierarchyPath(child)
	local path = "/" .. child.name
	while child.transform.parent ~= nil do
	   child = child.transform.parent.gameObject
	   path = "/" .. child.name .. path
	end
	return path
 end

local function FindOffsetDummy()
	local avatarRoot = CS.UnityEngine.GameObject.Find("/EntityRoot/AvatarRoot")
	if avatarRoot.transform.childCount == 0 then
	   return
	end
	for i = 0, avatarRoot.transform.childCount - 1 do
	   local getCurrAvatar = avatarRoot.transform:GetChild(i)
	   if getCurrAvatar.gameObject.activeInHierarchy then
		  for j = 0, getCurrAvatar.transform.childCount - 1 do
			 local getOffsetDummy = getCurrAvatar.transform:GetChild(j)
			 if getOffsetDummy.name:find("OffsetDummy") then
				for k = 0, getOffsetDummy.transform.childCount - 1 do
				   local avatarModel = getOffsetDummy.transform:GetChild(k)
				   if avatarModel.name:find("Avatar") then
					  return findHierarchyPath(avatarModel.gameObject)
				   end
				end
			 end
		  end
	   end
	end
 end

local targetscale = CS.UnityEngine.Vector3(1,1,1)
local spine2 = "/Bip001/Bip001 Pelvis/Bip001 Spine/Bip001 Spine1/Bip001 Spine2"
local findboba = CS.UnityEngine.GameObject.Find(FindOffsetDummy() .. spine2 .. "/boba")
local left = CS.UnityEngine.GameObject.Find(FindOffsetDummy() .. spine2 .. "/+Breast L A01")
local right = CS.UnityEngine.GameObject.Find(FindOffsetDummy() .. spine2 .. "/+Breast R A01")

local function booba()    
    if CS.UnityEngine.GameObject.Find(FindOffsetDummy() .. spine2 .. "/boba") == nil then
        if right and left ~= nil then
            spineidk = CS.UnityEngine.GameObject.Find(FindOffsetDummy() .. spine2)
            bobaOBJ = CS.UnityEngine.GameObject("boba")
            bobaOBJ.transform.parent = spineidk.transform
            bobaOBJ.transform.localPosition = CS.UnityEngine.Vector3(0,0,0)
            bobaOBJ.transform.localRotation = CS.UnityEngine.Quaternion.Euler(0,0,0)
            right.transform.parent = bobaOBJ.transform
            left.transform.parent = bobaOBJ.transform
            bobaOBJ.transform.localScale = targetscale
            CS.MoleMole.ActorUtils.ShowMessage("Initiated")
        else
            CS.MoleMole.ActorUtils.ShowMessage("No boob found")
        end
    else
        bobaOBJ.transform.localScale = CS.UnityEngine.Vector3(1,1,1)
        CS.MoleMole.ActorUtils.ShowMessage("Initiated")
    end
 end

 local function onError(error)
    CS.MoleMole.ActorUtils.ShowMessage(tostring(error))
end

xpcall(booba, onError)
)MY_DELIMITER";

const char* char_bub_resize = R"MY_DELIMITER(

local function findHierarchyPath(child)
	local path = "/" .. child.name
	while child.transform.parent ~= nil do
	   child = child.transform.parent.gameObject
	   path = "/" .. child.name .. path
	end
	return path
 end

local function FindOffsetDummy()
	local avatarRoot = CS.UnityEngine.GameObject.Find("/EntityRoot/AvatarRoot")
	if avatarRoot.transform.childCount == 0 then
	   return
	end
	for i = 0, avatarRoot.transform.childCount - 1 do
	   local getCurrAvatar = avatarRoot.transform:GetChild(i)
	   if getCurrAvatar.gameObject.activeInHierarchy then
		  for j = 0, getCurrAvatar.transform.childCount - 1 do
			 local getOffsetDummy = getCurrAvatar.transform:GetChild(j)
			 if getOffsetDummy.name:find("OffsetDummy") then
				for k = 0, getOffsetDummy.transform.childCount - 1 do
				   local avatarModel = getOffsetDummy.transform:GetChild(k)
				   if avatarModel.name:find("Avatar") then
					  return findHierarchyPath(avatarModel.gameObject) .. "/Bip001/Bip001 Pelvis/Bip001 Spine/Bip001 Spine1/Bip001 Spine2/boba"
				   end
				end
			 end
		  end
	   end
	end
 end

CS.UnityEngine.GameObject.Find(FindOffsetDummy()).transform.localScale = CS.UnityEngine.Vector3()MY_DELIMITER";

const char* char_openarea_fog = R"MY_DELIMITER(CS.UnityEngine.GameObject.Find("/LevelMapUIManager(Clone)/Canvas3D/MapBackContainer/BigWorld_Map(Clone)/MapArea/OpenArea_Fog"):SetActive()MY_DELIMITER";

const char* char_guidearea_fog = R"MY_DELIMITER(CS.UnityEngine.GameObject.Find("/LevelMapUIManager(Clone)/Canvas3D/MapBackContainer/BigWorld_Map(Clone)/GuideArea"):SetActive()MY_DELIMITER";

const char* char_avatarresize = R"MY_DELIMITER(
CS.UnityEngine.GameObject.Find("/EntityRoot/AvatarRoot").transform.localScale = CS.UnityEngine.Vector3()MY_DELIMITER";

const char* char_modelswap_clone = R"MY_DELIMITER(
    local function findBodyPartWithName(model,queryName)
	for i = 0, model.transform.childCount - 1 do
		local child = model.transform:GetChild(i)
		if child.name:find(queryName) then
			return child.gameObject
		end
	end
end

local function getOtherAvatarBipLocalRotation(avatar)
	for i = 0, avatar.transform.childCount - 1 do
		local checkbip = avatar.transform:GetChild(i)
		if checkbip.name == "Bip001" then
			return checkbip.gameObject.transform.localRotation
		end
	end
end

local function getOtherAvatarBipRotation(avatar)
	for i = 0, avatar.transform.childCount - 1 do
		local checkbip = avatar.transform:GetChild(i)
		if checkbip.name == "Bip001" then
			return checkbip.gameObject.transform.rotation
		end
	end
end

local function findActiveCharacter() --get parent of offsetdummy
	local avatarRoot = CS.UnityEngine.GameObject.Find("/EntityRoot/AvatarRoot")
    if avatarRoot.transform.childCount == 0 then
		return
	end
	for i = 0, avatarRoot.transform.childCount - 1 do
        local getCurrAvatar = avatarRoot.transform:GetChild(i)
        if getCurrAvatar.gameObject.activeInHierarchy then --ensure that is active avatar rn
			return getCurrAvatar.gameObject
		end
    end	
end

local function findActiveCharacterBody(avatar)
	for i = 0, avatar.transform.childCount - 1 do
		local checkbody = avatar.transform:GetChild(i)
		if checkbody.name == "Body" then
			return checkbody.gameObject
		end
	end
end

local function findActiveCharacterModel() --get child of offsetdummy
	local avatarRoot = CS.UnityEngine.GameObject.Find("/EntityRoot/AvatarRoot")
    if avatarRoot.transform.childCount == 0 then
		return
	end
	for i = 0, avatarRoot.transform.childCount - 1 do
        local getCurrAvatar = avatarRoot.transform:GetChild(i)
        if getCurrAvatar.gameObject.activeInHierarchy then --ensure that is active avatar rn
			for j = 0, getCurrAvatar.transform.childCount - 1 do
				local getOffsetDummy = getCurrAvatar.transform:GetChild(j)
				if getOffsetDummy.name:find("OffsetDummy") then
					for k = 0, getOffsetDummy.transform.childCount - 1 do
						local avatarModel = getOffsetDummy.transform:GetChild(k)
						if avatarModel.name:find("Avatar") then
							return avatarModel.gameObject
						end
					end
				end
			end
		end
    end	
end

local function findHierarchyPath(child)
	local path = "/" .. child.name
	while child.transform.parent ~= nil do
		child = child.transform.parent.gameObject
		path = "/" .. child.name .. path
	end
	return path
end
		
local function swap()
	local currAvatarModel = findActiveCharacterModel()
		
	--clone
	local clonedModel = CS.UnityEngine.GameObject.Instantiate(currAvatarModel)
	clonedModel.transform.position = currAvatarModel.transform.position
	--clonedModel.transform.position.x = clonedModel.transform.position.x + 2
	
	--cloneroot for later reference
	local avatarRoot = CS.UnityEngine.GameObject.Find("/EntityRoot/AvatarRoot")
	local cloneAvatarRoot = CS.UnityEngine.GameObject.Instantiate(avatarRoot)
	for i = 0, cloneAvatarRoot.transform.childCount - 1 do
		local avatars = cloneAvatarRoot.transform:GetChild(i).gameObject
		avatars:SetActive(false)
	end
	cloneAvatarRoot.transform.parent = CS.UnityEngine.GameObject.Find("/EntityRoot").transform
	
	--destroy if exist
	local checkIfCloneRootExist = CS.UnityEngine.GameObject.Find("/EntityRoot/CloneRoot")
	if checkIfCloneRootExist ~= nil then
		CS.UnityEngine.Object.Destroy(checkIfCloneRootExist.gameObject)
	end
	
	cloneAvatarRoot.name = "CloneRoot"
	
	--set parent to this clone root
	clonedModel.transform.parent = cloneAvatarRoot.transform
	CS.MoleMole.ActorUtils.ShowMessage("cloned at" .. findHierarchyPath(clonedModel))
end

local function onError(error)
	CS.MoleMole.ActorUtils.ShowMessage(tostring(error))
end

xpcall(swap, onError)
)MY_DELIMITER";

const char* char_modelswap_paste = R"MY_DELIMITER(
    local function findBodyPartWithName(model,queryName)
	for i = 0, model.transform.childCount - 1 do
		local child = model.transform:GetChild(i)
		if child.name:find(queryName) then
			return child.gameObject
		end
	end
end

local function getOtherAvatarBipLocalRotation(avatar)
	for i = 0, avatar.transform.childCount - 1 do
		local checkbip = avatar.transform:GetChild(i)
		if checkbip.name == "Bip001" then
			return checkbip.gameObject.transform.localRotation
		end
	end
end

local function getOtherAvatarBipRotation(avatar)
	for i = 0, avatar.transform.childCount - 1 do
		local checkbip = avatar.transform:GetChild(i)
		if checkbip.name == "Bip001" then
			return checkbip.gameObject.transform.rotation
		end
	end
end

local function findActiveCharacterBody(avatar)
	for i = 0, avatar.transform.childCount - 1 do
		local checkbody = avatar.transform:GetChild(i)
		if checkbody.name == "Body" then
			return checkbody.gameObject
		end
	end
end

local function findActiveCharacter(path) --get parent of offsetdummy
	local avatarRoot = CS.UnityEngine.GameObject.Find("/EntityRoot/" .. path);
    if avatarRoot.transform.childCount == 0 then
		return
	end
	for i = 0, avatarRoot.transform.childCount - 1 do
        local getCurrAvatar = avatarRoot.transform:GetChild(i)
        if getCurrAvatar.gameObject.activeInHierarchy then --ensure that is active avatar rn
			return getCurrAvatar.gameObject
		end
    end	
end

local function findActiveCharacterModel() --get child of offsetdummy
	local avatarRoot = CS.UnityEngine.GameObject.Find("/EntityRoot/AvatarRoot");
    if avatarRoot.transform.childCount == 0 then
		return
	end
	for i = 0, avatarRoot.transform.childCount - 1 do
        local getCurrAvatar = avatarRoot.transform:GetChild(i)
        if getCurrAvatar.gameObject.activeInHierarchy then --ensure that is active avatar rn
			for j = 0, getCurrAvatar.transform.childCount - 1 do
				local getOffsetDummy = getCurrAvatar.transform:GetChild(j)
				if getOffsetDummy.name:find("OffsetDummy") then
					for k = 0, getOffsetDummy.transform.childCount - 1 do
						local avatarModel = getOffsetDummy.transform:GetChild(k)
						if avatarModel.name:find("Avatar") then
							return avatarModel.gameObject
						end
					end
				end
			end
		end
    end	
end

local function findCharacterObj(path , part_name) --get child of offsetdummy
	local avatarRoot = CS.UnityEngine.GameObject.Find("/EntityRoot/" .. path);
    if avatarRoot.transform.childCount == 0 then
		return
	end
	for i = 0, avatarRoot.transform.childCount - 1 do
        local getCurrAvatar = avatarRoot.transform:GetChild(i)
        if getCurrAvatar.gameObject.activeInHierarchy then --ensure that is active avatar rn
			local components = getCurrAvatar.gameObject:GetComponentsInChildren(typeof(CS.UnityEngine.Transform))
			for j = 0, components.Length - 1 do
				local component = components[j]
				if component.name:find(part_name) then
					return component.gameObject
				end
			end
		end
    end	
end

local function swap()
	--get current and destroy?
	local currAvatarModel = findActiveCharacterModel()
	
	--now get other onfield
	local clonedAvatarModel = findActiveCharacter("CloneRoot")
	
	--get weaponroot of chars
	local currAvatarWeaponRoot = findCharacterObj("AvatarRoot", "WeaponRoot")
	local currAvatarWeaponL = findCharacterObj("AvatarRoot", "WeaponL")
	local currAvatarWeaponR = findCharacterObj("AvatarRoot", "WeaponR")
	
	local clonedAvatarWeaponRoot = findCharacterObj("CloneRoot","Bip001 Spine1")
	local clonedAvatarWeaponL = findCharacterObj("CloneRoot","Bip001 L Hand")
	local clonedAvatarWeaponR = findCharacterObj("CloneRoot","Bip001 R Hand")
	
	--eye fix finding
	local currAvatarEyeL = findCharacterObj("AvatarRoot", "+EyeBone L A01")
	local currAvatarEyeR = findCharacterObj("AvatarRoot", "+EyeBone R A01")
	local currAvatarToothD = findCharacterObj("AvatarRoot", "+ToothBone D A01")
	local currAvatarToothU = findCharacterObj("AvatarRoot", "+ToothBone U A01")
	local currAvatarFlyCloak = findCharacterObj("AvatarRoot", "+FlycloakRootB CB A01")
	
	local clonedAvatarHeadBone = findCharacterObj("CloneRoot","Bip001 Head")
	local clonedAvatarGlider = findCharacterObj("CloneRoot","Bip001 Spine2")
	
	if clonedAvatarModel == nil then
		CS.MoleMole.ActorUtils.ShowMessage("no cloned avatar found")
		return
	end

	--animator get for now later swap
	--local active_char_anim = currAvatarModel:GetComponent(typeof(CS.UnityEngine.Animator))
	--local cloned_char_anim = clonedAvatarModel:GetComponent(typeof(CS.UnityEngine.Animator))
	--active_char_anim:SetAvatar(cloned_char_anim.avatar)
	
		
	--destroy current avatar parts coz why not
	for index = 0, currAvatarModel.transform.childCount - 1 do
		local currBodyPart = currAvatarModel.transform:GetChild(index).transform
		if currBodyPart.name == "Brow" then
			CS.UnityEngine.Object.Destroy(currBodyPart.gameObject)
			--currBodyPart.gameObject:SetActive(false)
		elseif currBodyPart.name == "Face" then
			CS.UnityEngine.Object.Destroy(currBodyPart.gameObject)
			--currBodyPart.gameObject:SetActive(false)
		elseif currBodyPart.name == "Face_Eye" then
			CS.UnityEngine.Object.Destroy(currBodyPart.gameObject)
			--currBodyPart.gameObject:SetActive(false)
		elseif currBodyPart.name == "Root" then
			--donothing but i want keep this active
		elseif currBodyPart.name == "Bip001" then
			--currBodyPart:AddComponent(RotationController)
			--currBodyPart.localRotation = CS.UnityEngine.Quaternion.Euler(CS.UnityEngine.Vector3(90.0,getOtherAvatarBipLocalRotation(clonedAvatarModel).y,getOtherAvatarBipLocalRotation(clonedAvatarModel).z))
			--currBodyPart.rotation = CS.UnityEngine.Quaternion.Euler(CS.UnityEngine.Vector3(90.0,getOtherAvatarBipRotation(clonedAvatarModel).y,getOtherAvatarBipRotation(clonedAvatarModel).z))
		else
			currBodyPart.gameObject:SetActive(false) --default setinactive
		end
	end
			
	--clone and replace
	for i = 0, clonedAvatarModel.transform.childCount - 1 do
		local originalPart = clonedAvatarModel.transform:GetChild(0).gameObject
		--refixes roots for weaps TODO CYNO AND YAE SEX
		if originalPart.name:find("Root") then
			originalPart.name = "Root_OLD"
		end
		originalPart.transform:SetParent(currAvatarModel.transform)
		originalPart.transform:SetSiblingIndex(0)
	end

	--swap weapon root
	currAvatarWeaponRoot.transform.parent = clonedAvatarWeaponRoot.transform
	currAvatarWeaponL.transform.parent = clonedAvatarWeaponL.transform
	currAvatarWeaponR.transform.parent = clonedAvatarWeaponR.transform
	currAvatarWeaponRoot.transform:SetSiblingIndex(0)
	currAvatarWeaponL.transform:SetSiblingIndex(0)
	currAvatarWeaponR.transform:SetSiblingIndex(0)
	
	--setclip this will fix no blink
	local originClip = clonedAvatarModel:GetComponent(typeof(CS.miHoYoEmotion.ClipShapeManager))
    local targetClip = currAvatarModel:GetComponent(typeof(CS.miHoYoEmotion.ClipShapeManager))
    targetClip.currModelBindingList = originClip.currModelBindingList
    targetClip.faceMaterial = originClip.faceMaterial
	
	--set eyekey
	local originEyeKey = clonedAvatarModel:GetComponent(typeof(CS.miHoYoEmotion.EyeKey))
    local targetEyeKey = currAvatarModel:GetComponent(typeof(CS.miHoYoEmotion.EyeKey))
	targetEyeKey._leftEyeBoneHash = originEyeKey._leftEyeBoneHash;
    targetEyeKey._leftEyeBallScaleTarget = originEyeKey._leftEyeBallScaleTarget;
    targetEyeKey._leftEyeBoneHash = originEyeKey._leftEyeBoneHash;
    targetEyeKey._leftEyeRotTarget = originEyeKey._leftEyeRotTarget;
    targetEyeKey._originDownTeethPos = originEyeKey._originDownTeethPos;
    targetEyeKey._originDownTeethRot = originEyeKey._originDownTeethRot;
    targetEyeKey._originDownTeethScale = originEyeKey._originDownTeethScale;
    targetEyeKey._originLeftEyeBallRot = originEyeKey._originLeftEyeBallRot;
    targetEyeKey._originLeftEyeBallScale = originEyeKey._originLeftEyeBallScale;
    targetEyeKey._originLeftEyeRot = originEyeKey._originLeftEyeRot;
    targetEyeKey._originLeftEyeScale = originEyeKey._originLeftEyeScale;
    targetEyeKey._originRightEyeBallRot = originEyeKey._originRightEyeBallRot;
    targetEyeKey._originRightEyeBallScale = originEyeKey._originRightEyeBallScale;
    targetEyeKey._originRightEyeRot = originEyeKey._originRightEyeRot;
    targetEyeKey._originRightEyeScale = originEyeKey._originRightEyeScale;
    targetEyeKey._originUpTeethRot = originEyeKey._originUpTeethRot;
    targetEyeKey._originUpTeethScale = originEyeKey._originUpTeethScale;
    targetEyeKey._rightEyeBallBoneHash = originEyeKey._rightEyeBallBoneHash;
    targetEyeKey._rightEyeBallScaleTarget = originEyeKey._rightEyeBallScaleTarget;
    targetEyeKey._rightEyeBoneHash = originEyeKey._rightEyeBoneHash;
    targetEyeKey._rightEyeRotTarget = originEyeKey._rightEyeRotTarget;
    targetEyeKey._rotDuration = originEyeKey._rotDuration;
    targetEyeKey._rotTargetCurrtime = originEyeKey._rotTargetCurrtime;
    targetEyeKey._scaleDuration = originEyeKey._scaleDuration;
    targetEyeKey._scaleTargetCurrtime = originEyeKey._scaleTargetCurrtime;
    targetEyeKey._teethDownHash = originEyeKey._teethDownHash;
    targetEyeKey._teethUpHash = originEyeKey._teethUpHash;
    targetEyeKey.currentController = originEyeKey.currentController;
    targetEyeKey.leftEyeBallBone = originEyeKey.leftEyeBallBone;
    targetEyeKey.leftEyeBallRot = originEyeKey.leftEyeBallRot;
    targetEyeKey.leftEyeBallScale = originEyeKey.leftEyeBallScale;
    targetEyeKey.leftEyeBone = originEyeKey.leftEyeBone;
    targetEyeKey.leftEyeRot = originEyeKey.leftEyeRot;
    targetEyeKey.leftEyeScale = originEyeKey.leftEyeScale;
    targetEyeKey.rightEyeBallBone = originEyeKey.rightEyeBallBone;
    targetEyeKey.rightEyeBallRot = originEyeKey.rightEyeBallRot;
    targetEyeKey.rightEyeBallScale = originEyeKey.rightEyeBallScale;
    targetEyeKey.rightEyeBone = originEyeKey.rightEyeBone;
    targetEyeKey.rightEyeRot = originEyeKey.rightEyeRot;
    targetEyeKey.rightEyeScale = originEyeKey.rightEyeScale;
    targetEyeKey.teethDownBone = originEyeKey.teethDownBone;
    targetEyeKey.teethDownPos = originEyeKey.teethDownPos;
    targetEyeKey.teethDownRot = originEyeKey.teethDownRot;
    targetEyeKey.teethDownScale = originEyeKey.teethDownScale;
    targetEyeKey.teethUpBone = originEyeKey.teethUpBone;
    targetEyeKey.teethUpRot = originEyeKey.teethUpRot;
    targetEyeKey.teethUpScale = originEyeKey.teethUpScale;
	
	--eye tooth and glider fix
	currAvatarEyeL.transform.parent = clonedAvatarHeadBone.transform
	currAvatarEyeR.transform.parent = clonedAvatarHeadBone.transform
	currAvatarToothD.transform.parent = clonedAvatarHeadBone.transform
	currAvatarToothU.transform.parent = clonedAvatarHeadBone.transform
	currAvatarFlyCloak.transform.parent = clonedAvatarGlider.transform
	currAvatarEyeL.transform:SetSiblingIndex(0)
	currAvatarEyeR.transform:SetSiblingIndex(0)
	currAvatarToothD.transform:SetSiblingIndex(0)
	currAvatarToothU.transform:SetSiblingIndex(0)
	currAvatarFlyCloak.transform:SetSiblingIndex(0)
	
	--toggle on off refresh?
	local activeAvatar = findActiveCharacter("AvatarRoot")
	local activeAvatarBody = findActiveCharacterBody(currAvatarModel)
	activeAvatar:SetActive(false)
	activeAvatar:SetActive(true)
	--activeAvatarBody:SetActive(false)
	
	CS.MoleMole.ActorUtils.ShowMessage("Swapped!")
end

local function onError(error)
	CS.MoleMole.ActorUtils.ShowMessage(tostring(error))
end

xpcall(swap, onError)
)MY_DELIMITER";

// thanks DiXiao#6611 for this script
const char* char_moloader = R"MY_DELIMITER(

local PlayerPosition = false

local TypeRotation = 0 -- 0 - CustomRotate | 1 - CameraRotate | 2 - PlayerRotate

local CreateCollider = true

local ModelPosition = {0.0,500.0,0.0} -- If PlayerPosition = true then does nothing

local ModelRotation = {0.0,0.0,0.0} -- If TypeRotation == 1 or 2 then does nothing

local ModelScale = {5.0,5.0,-5.0}

local TextureScale = {1024,1024}
-- <<<

local function list_length( t )
 
    local len = 0
    for _,_ in pairs( t ) do
        len = len + 1
    end
 
    return len
end

local function jsonlua()
	local json = { _version = "0.1.2" }

	-------------------------------------------------------------------------------
	-- Encode
	-------------------------------------------------------------------------------

	local encode

	local escape_char_map = {
	  [ "\\" ] = "\\",
	  [ "\"" ] = "\"",
	  [ "\b" ] = "b",
	  [ "\f" ] = "f",
	  [ "\n" ] = "n",
	  [ "\r" ] = "r",
	  [ "\t" ] = "t",
	}

	local escape_char_map_inv = { [ "/" ] = "/" }
	for k, v in pairs(escape_char_map) do
	  escape_char_map_inv[v] = k
	end


	local function escape_char(c)
	  return "\\" .. (escape_char_map[c] or string.format("u%04x", c:byte()))
	end


	local function encode_nil(val)
	  return "null"
	end


	local function encode_table(val, stack)
	  local res = {}
	  stack = stack or {}

	  -- Circular reference?
	  if stack[val] then error("circular reference") end

	  stack[val] = true

	  if rawget(val, 1) ~= nil or next(val) == nil then
		-- Treat as array -- check keys are valid and it is not sparse
		local n = 0
		for k in pairs(val) do
		  if type(k) ~= "number" then
			error("invalid table: mixed or invalid key types")
		  end
		  n = n + 1
		end
		if n ~= #val then
		  error("invalid table: sparse array")
		end
		-- Encode
		for i, v in ipairs(val) do
		  table.insert(res, encode(v, stack))
		end
		stack[val] = nil
		return "[" .. table.concat(res, ",") .. "]"

	  else
		-- Treat as an object
		for k, v in pairs(val) do
		  if type(k) ~= "string" then
			error("invalid table: mixed or invalid key types")
		  end
		  table.insert(res, encode(k, stack) .. ":" .. encode(v, stack))
		end
		stack[val] = nil
		return "{" .. table.concat(res, ",") .. "}"
	  end
	end


	local function encode_string(val)
	  return '"' .. val:gsub('[%z\1-\31\\"]', escape_char) .. '"'
	end


	local function encode_number(val)
	  -- Check for NaN, -inf and inf
	  if val ~= val or val <= -math.huge or val >= math.huge then
		error("unexpected number value '" .. tostring(val) .. "'")
	  end
	  return string.format("%.14g", val)
	end


	local type_func_map = {
	  [ "nil"     ] = encode_nil,
	  [ "table"   ] = encode_table,
	  [ "string"  ] = encode_string,
	  [ "number"  ] = encode_number,
	  [ "boolean" ] = tostring,
	}


	encode = function(val, stack)
	  local t = type(val)
	  local f = type_func_map[t]
	  if f then
		return f(val, stack)
	  end
	  error("unexpected type '" .. t .. "'")
	end


	function json.encode(val)
	  return ( encode(val) )
	end


	-------------------------------------------------------------------------------
	-- Decode
	-------------------------------------------------------------------------------

	local parse

	local function create_set(...)
	  local res = {}
	  for i = 1, select("#", ...) do
		res[ select(i, ...) ] = true
	  end
	  return res
	end

	local space_chars   = create_set(" ", "\t", "\r", "\n")
	local delim_chars   = create_set(" ", "\t", "\r", "\n", "]", "}", ",")
	local escape_chars  = create_set("\\", "/", '"', "b", "f", "n", "r", "t", "u")
	local literals      = create_set("true", "false", "null")

	local literal_map = {
	  [ "true"  ] = true,
	  [ "false" ] = false,
	  [ "null"  ] = nil,
	}


	local function next_char(str, idx, set, negate)
	  for i = idx, #str do
		if set[str:sub(i, i)] ~= negate then
		  return i
		end
	  end
	  return #str + 1
	end


	local function decode_error(str, idx, msg)
	  local line_count = 1
	  local col_count = 1
	  for i = 1, idx - 1 do
		col_count = col_count + 1
		if str:sub(i, i) == "\n" then
		  line_count = line_count + 1
		  col_count = 1
		end
	  end
	  error( string.format("%s at line %d col %d", msg, line_count, col_count) )
	end


	local function codepoint_to_utf8(n)
	  -- http://scripts.sil.org/cms/scripts/page.php?site_id=nrsi&id=iws-appendixa
	  local f = math.floor
	  if n <= 0x7f then
		return string.char(n)
	  elseif n <= 0x7ff then
		return string.char(f(n / 64) + 192, n % 64 + 128)
	  elseif n <= 0xffff then
		return string.char(f(n / 4096) + 224, f(n % 4096 / 64) + 128, n % 64 + 128)
	  elseif n <= 0x10ffff then
		return string.char(f(n / 262144) + 240, f(n % 262144 / 4096) + 128,
						   f(n % 4096 / 64) + 128, n % 64 + 128)
	  end
	  error( string.format("invalid unicode codepoint '%x'", n) )
	end


	local function parse_unicode_escape(s)
	  local n1 = tonumber( s:sub(1, 4),  16 )
	  local n2 = tonumber( s:sub(7, 10), 16 )
	   -- Surrogate pair?
	  if n2 then
		return codepoint_to_utf8((n1 - 0xd800) * 0x400 + (n2 - 0xdc00) + 0x10000)
	  else
		return codepoint_to_utf8(n1)
	  end
	end


	local function parse_string(str, i)
	  local res = ""
	  local j = i + 1
	  local k = j

	  while j <= #str do
		local x = str:byte(j)

		if x < 32 then
		  decode_error(str, j, "control character in string")

		elseif x == 92 then -- `\`: Escape
		  res = res .. str:sub(k, j - 1)
		  j = j + 1
		  local c = str:sub(j, j)
		  if c == "u" then
			local hex = str:match("^[dD][89aAbB]%x%x\\u%x%x%x%x", j + 1)
					 or str:match("^%x%x%x%x", j + 1)
					 or decode_error(str, j - 1, "invalid unicode escape in string")
			res = res .. parse_unicode_escape(hex)
			j = j + #hex
		  else
			if not escape_chars[c] then
			  decode_error(str, j - 1, "invalid escape char '" .. c .. "' in string")
			end
			res = res .. escape_char_map_inv[c]
		  end
		  k = j + 1

		elseif x == 34 then -- `"`: End of string
		  res = res .. str:sub(k, j - 1)
		  return res, j + 1
		end

		j = j + 1
	  end

	  decode_error(str, i, "expected closing quote for string")
	end


	local function parse_number(str, i)
	  local x = next_char(str, i, delim_chars)
	  local s = str:sub(i, x - 1)
	  local n = tonumber(s)
	  if not n then
		decode_error(str, i, "invalid number '" .. s .. "'")
	  end
	  return n, x
	end


	local function parse_literal(str, i)
	  local x = next_char(str, i, delim_chars)
	  local word = str:sub(i, x - 1)
	  if not literals[word] then
		decode_error(str, i, "invalid literal '" .. word .. "'")
	  end
	  return literal_map[word], x
	end


	local function parse_array(str, i)
	  local res = {}
	  local n = 1
	  i = i + 1
	  while 1 do
		local x
		i = next_char(str, i, space_chars, true)
		-- Empty / end of array?
		if str:sub(i, i) == "]" then
		  i = i + 1
		  break
		end
		-- Read token
		x, i = parse(str, i)
		res[n] = x
		n = n + 1
		-- Next token
		i = next_char(str, i, space_chars, true)
		local chr = str:sub(i, i)
		i = i + 1
		if chr == "]" then break end
		if chr ~= "," then decode_error(str, i, "expected ']' or ','") end
	  end
	  return res, i
	end


	local function parse_object(str, i)
	  local res = {}
	  i = i + 1
	  while 1 do
		local key, val
		i = next_char(str, i, space_chars, true)
		-- Empty / end of object?
		if str:sub(i, i) == "}" then
		  i = i + 1
		  break
		end
		-- Read key
		if str:sub(i, i) ~= '"' then
		  decode_error(str, i, "expected string for key")
		end
		key, i = parse(str, i)
		-- Read ':' delimiter
		i = next_char(str, i, space_chars, true)
		if str:sub(i, i) ~= ":" then
		  decode_error(str, i, "expected ':' after key")
		end
		i = next_char(str, i + 1, space_chars, true)
		-- Read value
		val, i = parse(str, i)
		-- Set
		res[key] = val
		-- Next token
		i = next_char(str, i, space_chars, true)
		local chr = str:sub(i, i)
		i = i + 1
		if chr == "}" then break end
		if chr ~= "," then decode_error(str, i, "expected '}' or ','") end
	  end
	  return res, i
	end


	local char_func_map = {
	  [ '"' ] = parse_string,
	  [ "0" ] = parse_number,
	  [ "1" ] = parse_number,
	  [ "2" ] = parse_number,
	  [ "3" ] = parse_number,
	  [ "4" ] = parse_number,
	  [ "5" ] = parse_number,
	  [ "6" ] = parse_number,
	  [ "7" ] = parse_number,
	  [ "8" ] = parse_number,
	  [ "9" ] = parse_number,
	  [ "-" ] = parse_number,
	  [ "t" ] = parse_literal,
	  [ "f" ] = parse_literal,
	  [ "n" ] = parse_literal,
	  [ "[" ] = parse_array,
	  [ "{" ] = parse_object,
	}


	parse = function(str, idx)
	  local chr = str:sub(idx, idx)
	  local f = char_func_map[chr]
	  if f then
		return f(str, idx)
	  end
	  decode_error(str, idx, "unexpected character '" .. chr .. "'")
	end


	function json.decode(str)
	  if type(str) ~= "string" then
		error("expected argument of type string, got " .. type(str))
	  end
	  local res, idx = parse(str, next_char(str, 1, space_chars, true))
	  idx = next_char(str, idx, space_chars, true)
	  if idx <= #str then
		decode_error(str, idx, "trailing garbage")
	  end
	  return res
	end


	return json
end
)MY_DELIMITER";
		const char* char_moloader2 = R"MY_DELIMITER(
local function DowMO()
	
	local MoPath = CS.UnityEngine.GameObject.Find("/BigWorld(Clone)/MoModels")
	if MoPath == nil then
		MoPath = CS.UnityEngine.GameObject("MoModels")
		CS.UnityEngine.Object:DontDestroyOnLoad(MoPath)
		MoPath.transform:SetParent(CS.UnityEngine.GameObject.Find("/BigWorld(Clone)").transform)
		MoPath.transform.localPosition = CS.UnityEngine.Vector3(0,0,0)
		CS.MoleMole.ActorUtils.ShowMessage("MoPath created")	
	else
		CS.MoleMole.ActorUtils.ShowMessage("MoPath exists")
	end
	
	local WorldPath = CS.UnityEngine.GameObject.Find("/BigWorld(Clone)").transform.gameObject
	
	local newObject = CS.UnityEngine.GameObject.CreatePrimitive(CS.UnityEngine.PrimitiveType.Cube)
	
	newObject.transform:SetParent(MoPath.transform)
	
	-- local ObjPath = newObject
	-- local path = "/" .. ObjPath.transform.name
	-- while ObjPath.transform.parent ~= nil do
        -- ObjPath = ObjPath.transform.parent.gameObject
        -- path = "/" .. ObjPath.name .. path
    -- end
	-- CS.MoleMole.ActorUtils.ShowMessage(path)
	
	local worldpos = WorldPath.transform.localPosition
	

	if PlayerPosition then
		local PlayerPos = CS.MoleMole.ActorUtils.GetAvatarPos()
		newObject.transform.localPosition = CS.UnityEngine.Vector3(PlayerPos[0]-worldpos.x,PlayerPos[1],PlayerPos[2]-worldpos.z)
	else	
		newObject.transform.localPosition = CS.UnityEngine.Vector3(ModelPosition[1]-worldpos.x,ModelPosition[2],ModelPosition[3]-worldpos.z)
	end
	
	if TypeRotation == 1 then
		local CameraRot = CS.MoleMole.ActorUtils.GetCameraEuler()
		newObject.transform.rotation = CS.UnityEngine.Quaternion.Euler(CameraRot[0],CameraRot[1],CameraRot[2])
	elseif TypeRotation == 2 then
		local PlayerRot = CS.MoleMole.ActorUtils.GetAvatarForward()
		newObject.transform.rotation = CS.UnityEngine.Quaternion.Euler(PlayerRot[0],PlayerRot[1],PlayerRot[2])
	else
		newObject.transform.rotation = CS.UnityEngine.Quaternion.Euler(ModelRotation[1],ModelRotation[2],ModelRotation[3])
	end
	
	newObject.transform.localScale = CS.UnityEngine.Vector3(ModelScale[1],ModelScale[2],ModelScale[3])

	
	local jsonString = CS.System.IO.File.ReadAllText(moFilePath)
			
	local json = jsonlua()
	
	local data = json.decode(jsonString)
		
	local VertexArray = CS.UnityEngine.Vector3[list_length(data.VertexArray)]
	local UVArray = CS.UnityEngine.Vector3[list_length(data.UVArray)]
	local NormalArray = CS.UnityEngine.Vector3[list_length(data.NormalArray)]
	local TriangleArray = CS.UnityEngine.Vector3[list_length(data.TriangleArray)]
	local VertexArray = {}
	local UVArray = {}
	local NormalArray = {}
	local TriangleArray = {}
	
	local start_nul = 1
	
	local i = start_nul
	
	for k,items in pairs(data.VertexArray) do
		VertexArray[i] = CS.UnityEngine.Vector3(items.x, items.y, items.z)
		i = i + 1
	end
	
	i = start_nul
	for k,items in pairs(data.UVArray) do
		UVArray[i] = CS.UnityEngine.Vector2(items.x, items.y)
		i = i + 1
	end
	
	i = start_nul
	for k,items in pairs(data.NormalArray) do
		NormalArray[i] = CS.UnityEngine.Vector3(items.x, items.y, items.z)
		i = i + 1
	end
	
	i = start_nul
	for k,items in pairs(data.TriangleArray) do
		TriangleArray[i] = items
		i = i + 1
	end
	
	local mesh = CS.UnityEngine.Mesh()
	mesh.vertices = VertexArray
	mesh.triangles = TriangleArray
	if list_length( UVArray ) > 0 then
		mesh.uv = UVArray
	end
	if list_length(NormalArray) > 0 then
		mesh.normals = NormalArray
	end
	
	mesh:RecalculateBounds()

	local meshFilter = newObject:GetComponent(typeof(CS.UnityEngine.MeshFilter))
	meshFilter.mesh = mesh
	

	newObject:GetComponent(typeof(CS.UnityEngine.BoxCollider)).enabled = false
	
	if CreateCollider then
		newObject:AddComponent(typeof(CS.UnityEngine.MeshCollider))
		newObject.layer = 8
	end

	local _fileData = CS.System.IO.File.ReadAllBytes(TextPath)
	local _tex = CS.UnityEngine.Texture2D(TextureScale[1], TextureScale[2])
	CS.UnityEngine.ImageConversion.LoadImage(_tex, _fileData)

	newObject:GetComponent(typeof(CS.UnityEngine.MeshRenderer)).materials[0].mainTexture = _tex
	
	
	CS.MoleMole.ActorUtils.ShowMessage(".mo Loaded")
end

local function onError(error)
    --CS.UnityEngine.GameObject.Find("/BetaWatermarkCanvas(Clone)/Panel/TxtUID"):GetComponent("Text").text = tostring(error)
	CS.MoleMole.ActorUtils.ShowMessage(tostring(error))
end

xpcall(DowMO, onError)
)MY_DELIMITER";

const char* char_dmgnum_on = R"MY_DELIMITER(CS.UnityEngine.GameObject.Find("Canvas/Pages/InLevelMainPage/GrpMainPage/ParticleDamageTextContainer"):SetActive(true))MY_DELIMITER";

const char* char_dmgnum_off = R"MY_DELIMITER(CS.UnityEngine.GameObject.Find("Canvas/Pages/InLevelMainPage/GrpMainPage/ParticleDamageTextContainer"):SetActive(false))MY_DELIMITER";

const char* char_uicamera_on = R"MY_DELIMITER(CS.UnityEngine.GameObject.Find("/UICamera"):GetComponent("Camera").enabled = true)MY_DELIMITER";

const char* char_uicamera_off = R"MY_DELIMITER(CS.UnityEngine.GameObject.Find("/UICamera"):GetComponent("Camera").enabled = false)MY_DELIMITER";

const char* enablepeeking = R"MY_DELIMITER(CS.UnityEngine.GameObject.Find("EntityRoot/MainCamera(Clone)"):GetComponent("Camera").ditherValue = 0)MY_DELIMITER";

const char* disablepeeking = R"MY_DELIMITER(CS.UnityEngine.GameObject.Find("EntityRoot/MainCamera(Clone)"):GetComponent("Camera").ditherValue = 1)MY_DELIMITER";

const char* animchangerreturn = R"MY_DELIMITER(
local function find_active_char()
    local avatarroot = CS.UnityEngine.GameObject.Find("/EntityRoot/AvatarRoot")
    for i = 0, avatarroot.transform.childCount - 1 do
        local child = avatarroot.transform:GetChild(i)
        if child.gameObject.activeInHierarchy then
            return child.gameObject
        end
    end
end

local function find_body(avatar)
    for i = 0, avatar.transform.childCount - 1 do
        local transform = avatar.transform:GetChild(i)

        if transform.name == "OffsetDummy" then
            return transform
        end
    end
end

local function AnimChanger()
	local avatar = find_active_char()
	CS.MoleMole.ActorUtils.ShowMessage(find_body(avatar):GetChild(0).name)
	local obj = find_body(avatar):GetChild(0)
	local ac = obj:GetComponent("Animator")
	ac:Rebind()
end

local function onError(error)
    CS.UnityEngine.GameObject.Find("/BetaWatermarkCanvas(Clone)/Panel/TxtUID"):GetComponent("Text").text = tostring(error)
	CS.MoleMole.ActorUtils.ShowMessage(tostring(error))
end

xpcall(AnimChanger, onError)
)MY_DELIMITER";

const char* animchanger = R"MY_DELIMITER(
local function find_active_char()
    local avatarroot = CS.UnityEngine.GameObject.Find("/EntityRoot/AvatarRoot")
    for i = 0, avatarroot.transform.childCount - 1 do
        local child = avatarroot.transform:GetChild(i)
        if child.gameObject.activeInHierarchy then
            return child.gameObject
        end
    end
end

local function find_body(avatar)
    for i = 0, avatar.transform.childCount - 1 do
        local transform = avatar.transform:GetChild(i)

        if transform.name == "OffsetDummy" then
            return transform
        end
    end
end

local function AnimChanger()
	local avatar = find_active_char()
	CS.MoleMole.ActorUtils.ShowMessage(find_body(avatar):GetChild(0).name)
	local obj = find_body(avatar):GetChild(0)
	local ac = obj:GetComponent("Animator")
	ac:Play(")MY_DELIMITER";

const char* animchanger2 = R"MY_DELIMITER(", 0) -- turn on
	--ac:Rebind() -- turn off
end

local function onError(error)
	CS.MoleMole.ActorUtils.ShowMessage(tostring(error))
end

xpcall(AnimChanger, onError)
)MY_DELIMITER";

const char* emochengemo1 = R"MY_DELIMITER(
local function find_active_char()
    local avatarroot = CS.UnityEngine.GameObject.Find("/EntityRoot/AvatarRoot")
    for i = 0, avatarroot.transform.childCount - 1 do
        local child = avatarroot.transform:GetChild(i)
        if child.gameObject.activeInHierarchy then
            return child.gameObject
        end
    end
end

local function find_body(avatar)
    for i = 0, avatar.transform.childCount - 1 do
        local transform = avatar.transform:GetChild(i)

        if transform.name == "OffsetDummy" then
            return transform
        end
    end
end

local function EmoChanger()
	local avatar = find_active_char()
	CS.MoleMole.ActorUtils.ShowMessage(find_body(avatar):GetChild(0).name)
	local obj = find_body(avatar):GetChild(0)
	local emo = obj:GetComponent("EmoSync")
	emo:SetEmotion(")MY_DELIMITER";

const char* emochengemo2 = R"MY_DELIMITER(",0)
	emo:SetPhoneme(")MY_DELIMITER";

const char* emochengpho2 = R"MY_DELIMITER(",0)
	emo:EmoFinish()
end

local function onError(error)
	CS.MoleMole.ActorUtils.ShowMessage(tostring(error))
end

xpcall(EmoChanger, onError)
)MY_DELIMITER";

//DumpCS License
/*
                                 Apache License
                           Version 2.0, January 2004
                        http://www.apache.org/licenses/

   TERMS AND CONDITIONS FOR USE, REPRODUCTION, AND DISTRIBUTION

   1. Definitions.

      "License" shall mean the terms and conditions for use, reproduction,
      and distribution as defined by Sections 1 through 9 of this document.

      "Licensor" shall mean the copyright owner or entity authorized by
      the copyright owner that is granting the License.

      "Legal Entity" shall mean the union of the acting entity and all
      other entities that control, are controlled by, or are under common
      control with that entity. For the purposes of this definition,
      "control" means (i) the power, direct or indirect, to cause the
      direction or management of such entity, whether by contract or
      otherwise, or (ii) ownership of fifty percent (50%) or more of the
      outstanding shares, or (iii) beneficial ownership of such entity.

      "You" (or "Your") shall mean an individual or Legal Entity
      exercising permissions granted by this License.

      "Source" form shall mean the preferred form for making modifications,
      including but not limited to software source code, documentation
      source, and configuration files.

      "Object" form shall mean any form resulting from mechanical
      transformation or translation of a Source form, including but
      not limited to compiled object code, generated documentation,
      and conversions to other media types.

      "Work" shall mean the work of authorship, whether in Source or
      Object form, made available under the License, as indicated by a
      copyright notice that is included in or attached to the work
      (an example is provided in the Appendix below).

      "Derivative Works" shall mean any work, whether in Source or Object
      form, that is based on (or derived from) the Work and for which the
      editorial revisions, annotations, elaborations, or other modifications
      represent, as a whole, an original work of authorship. For the purposes
      of this License, Derivative Works shall not include works that remain
      separable from, or merely link (or bind by name) to the interfaces of,
      the Work and Derivative Works thereof.

      "Contribution" shall mean any work of authorship, including
      the original version of the Work and any modifications or additions
      to that Work or Derivative Works thereof, that is intentionally
      submitted to Licensor for inclusion in the Work by the copyright owner
      or by an individual or Legal Entity authorized to submit on behalf of
      the copyright owner. For the purposes of this definition, "submitted"
      means any form of electronic, verbal, or written communication sent
      to the Licensor or its representatives, including but not limited to
      communication on electronic mailing lists, source code control systems,
      and issue tracking systems that are managed by, or on behalf of, the
      Licensor for the purpose of discussing and improving the Work, but
      excluding communication that is conspicuously marked or otherwise
      designated in writing by the copyright owner as "Not a Contribution."

      "Contributor" shall mean Licensor and any individual or Legal Entity
      on behalf of whom a Contribution has been received by Licensor and
      subsequently incorporated within the Work.

   2. Grant of Copyright License. Subject to the terms and conditions of
      this License, each Contributor hereby grants to You a perpetual,
      worldwide, non-exclusive, no-charge, royalty-free, irrevocable
      copyright license to reproduce, prepare Derivative Works of,
      publicly display, publicly perform, sublicense, and distribute the
      Work and such Derivative Works in Source or Object form.

   3. Grant of Patent License. Subject to the terms and conditions of
      this License, each Contributor hereby grants to You a perpetual,
      worldwide, non-exclusive, no-charge, royalty-free, irrevocable
      (except as stated in this section) patent license to make, have made,
      use, offer to sell, sell, import, and otherwise transfer the Work,
      where such license applies only to those patent claims licensable
      by such Contributor that are necessarily infringed by their
      Contribution(s) alone or by combination of their Contribution(s)
      with the Work to which such Contribution(s) was submitted. If You
      institute patent litigation against any entity (including a
      cross-claim or counterclaim in a lawsuit) alleging that the Work
      or a Contribution incorporated within the Work constitutes direct
      or contributory patent infringement, then any patent licenses
      granted to You under this License for that Work shall terminate
      as of the date such litigation is filed.

   4. Redistribution. You may reproduce and distribute copies of the
      Work or Derivative Works thereof in any medium, with or without
      modifications, and in Source or Object form, provided that You
      meet the following conditions:

      (a) You must give any other recipients of the Work or
          Derivative Works a copy of this License; and

      (b) You must cause any modified files to carry prominent notices
          stating that You changed the files; and

      (c) You must retain, in the Source form of any Derivative Works
          that You distribute, all copyright, patent, trademark, and
          attribution notices from the Source form of the Work,
          excluding those notices that do not pertain to any part of
          the Derivative Works; and

      (d) If the Work includes a "NOTICE" text file as part of its
          distribution, then any Derivative Works that You distribute must
          include a readable copy of the attribution notices contained
          within such NOTICE file, excluding those notices that do not
          pertain to any part of the Derivative Works, in at least one
          of the following places: within a NOTICE text file distributed
          as part of the Derivative Works; within the Source form or
          documentation, if provided along with the Derivative Works; or,
          within a display generated by the Derivative Works, if and
          wherever such third-party notices normally appear. The contents
          of the NOTICE file are for informational purposes only and
          do not modify the License. You may add Your own attribution
          notices within Derivative Works that You distribute, alongside
          or as an addendum to the NOTICE text from the Work, provided
          that such additional attribution notices cannot be construed
          as modifying the License.

      You may add Your own copyright statement to Your modifications and
      may provide additional or different license terms and conditions
      for use, reproduction, or distribution of Your modifications, or
      for any such Derivative Works as a whole, provided Your use,
      reproduction, and distribution of the Work otherwise complies with
      the conditions stated in this License.

   5. Submission of Contributions. Unless You explicitly state otherwise,
      any Contribution intentionally submitted for inclusion in the Work
      by You to the Licensor shall be under the terms and conditions of
      this License, without any additional terms or conditions.
      Notwithstanding the above, nothing herein shall supersede or modify
      the terms of any separate license agreement you may have executed
      with Licensor regarding such Contributions.

   6. Trademarks. This License does not grant permission to use the trade
      names, trademarks, service marks, or product names of the Licensor,
      except as required for reasonable and customary use in describing the
      origin of the Work and reproducing the content of the NOTICE file.

   7. Disclaimer of Warranty. Unless required by applicable law or
      agreed to in writing, Licensor provides the Work (and each
      Contributor provides its Contributions) on an "AS IS" BASIS,
      WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
      implied, including, without limitation, any warranties or conditions
      of TITLE, NON-INFRINGEMENT, MERCHANTABILITY, or FITNESS FOR A
      PARTICULAR PURPOSE. You are solely responsible for determining the
      appropriateness of using or redistributing the Work and assume any
      risks associated with Your exercise of permissions under this License.

   8. Limitation of Liability. In no event and under no legal theory,
      whether in tort (including negligence), contract, or otherwise,
      unless required by applicable law (such as deliberate and grossly
      negligent acts) or agreed to in writing, shall any Contributor be
      liable to You for damages, including any direct, indirect, special,
      incidental, or consequential damages of any character arising as a
      result of this License or out of the use or inability to use the
      Work (including but not limited to damages for loss of goodwill,
      work stoppage, computer failure or malfunction, or any and all
      other commercial damages or losses), even if such Contributor
      has been advised of the possibility of such damages.

   9. Accepting Warranty or Additional Liability. While redistributing
      the Work or Derivative Works thereof, You may choose to offer,
      and charge a fee for, acceptance of support, warranty, indemnity,
      or other liability obligations and/or rights consistent with this
      License. However, in accepting such obligations, You may act only
      on Your own behalf and on Your sole responsibility, not on behalf
      of any other Contributor, and only if You agree to indemnify,
      defend, and hold each Contributor harmless for any liability
      incurred by, or claims asserted against, such Contributor by reason
      of your accepting any such warranty or additional liability.

   END OF TERMS AND CONDITIONS

   APPENDIX: How to apply the Apache License to your work.

      To apply the Apache License to your work, attach the following
      boilerplate notice, with the fields enclosed by brackets "[]"
      replaced with your own identifying information. (Don't include
      the brackets!)  The text should be enclosed in the appropriate
      comment syntax for the file format. We also recommend that a
      file or class name and description of purpose be included on the
      same "printed page" as the copyright notice for easier
      identification within third-party archives.

   Copyright [yyyy] [name of copyright owner]

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
/*
Modifications: The first line of "lua-dump-scripts" script has been modified to provide a dumping path that our users enter. 

Original creator: Jx2f / Jack on github.com

Original Project source code https://github.com/Jx2f/lua-dump-scripts

Copyright 2023 Jx2f

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

DISCLAIMER OF WARRANTIES

The software is provided "AS IS", without warranty of any kind, express or
implied, including but not limited to the warranties of merchantability,
fitness for a particular purpose and noninfringement. In no event shall the
authors or copyright holders be liable for any claim, damages or other
liability, whether in an action of contract, tort or otherwise, arising
from, out of or in connection with the software or the use or other dealings
in the software.
*/
//local DUMP_FOLDER = "X:/dump"
const char* char_dumpcs_part1 = R"MY_DELIMITER(
local DUMP_LOG_FILE = DUMP_FOLDER .. "/dump-csharp.log"
local DUMP_CS_FILE = DUMP_FOLDER .. "/dump-csharp.cs"

local log = io.open(DUMP_LOG_FILE, "w")

local SYSTEM_NAMES = {
    ["System.Int32"] = "int",
    ["System.UInt32"] = "uint",
    ["System.Int16"] = "short",
    ["System.UInt16"] = "ushort",
    ["System.Int64"] = "long",
    ["System.UInt64"] = "ulong",
    ["System.Byte"] = "byte",
    ["System.SByte"] = "sbyte",
    ["System.Boolean"] = "bool",
    ["System.Single"] = "float",
    ["System.Double"] = "double",
    ["System.String"] = "string",
    ["System.Char"] = "char",
    ["System.Object"] = "object",
    ["System.Void"] = "void"
}

local TypeAttributes = CS.System.Reflection.TypeAttributes

local function get_type_visibility_string(type)
    local visibility = type.Attributes & TypeAttributes.VisibilityMask
    if (visibility == TypeAttributes.Public) --
    or (visibility == TypeAttributes.NestedPublic) then
        return "public "
    elseif (visibility == TypeAttributes.NotPublic) --
    or (visibility == TypeAttributes.NestedFamANDAssem) --
    or (visibility == TypeAttributes.NestedAssembly) then
        return "internal "
    elseif (visibility == TypeAttributes.NestedPrivate) then
        return "private "
    elseif (visibility == TypeAttributes.NestedFamily) then
        return "protected "
    elseif (visibility == TypeAttributes.NestedFamORAssem) then
        return "protected internal "
    else
        return ""
    end
end

local function get_type_string(type)
    local out = get_type_visibility_string(type)
    local attributes = type.Attributes
    if (attributes & TypeAttributes.Abstract).value__ ~= 0 --
    and (attributes & TypeAttributes.Sealed).value__ ~= 0 then
        out = out .. "static "
    elseif (attributes & TypeAttributes.Abstract).value__ ~= 0 --
    and (attributes & TypeAttributes.Interface).value__ == 0 then
        out = out .. "abstract "
    elseif (attributes & TypeAttributes.Sealed).value__ ~= 0 --
    and (not type.IsEnum or not type.IsValueType) then
        out = out .. "sealed "
    end
    if (attributes & TypeAttributes.Interface).value__ ~= 0 then
        out = out .. "interface "
    elseif type.IsEnum then
        out = out .. "enum "
    elseif type.IsValueType then
        out = out .. "struct "
    else
        out = out .. "class "
    end
    return out
end

local function get_reflected_type(type)
    local name = type.Name
    if type.ReflectedType ~= nil --
    and not type.ReflectedType.IsGenericType then
        name = get_reflected_type(type.ReflectedType) .. "." .. name
    end
    return name
end

local function get_runtime_type_name(type, alias)
    if type.IsArray then
        local out = get_runtime_type_name(type:GetElementType(), alias)
        out = out .. "["
        for i = 2, type:GetArrayRank() do
            out = out .. ","
        end
        out = out .. "]"
        return out
    elseif type.IsPointer then
        return get_runtime_type_name(type:GetElementType(), alias) .. "*"
    elseif type.IsByRef then
        return get_runtime_type_name(type:GetElementType(), alias) .. "&"
    elseif type.IsGenericType then
        local name = type:GetGenericTypeDefinition().Name
        local pos = name:find("`")
        if pos ~= nil then
            name = name:sub(1, pos - 1)
        end
        local generic_args = type:GetGenericArguments()
        name = name .. "<"
        for i = 0, generic_args.Length - 1 do
            if i ~= 0 then
                name = name .. ", "
            end
            name = name .. get_runtime_type_name(generic_args[i], alias)
        end
        name = name .. ">"
        return name
    else
        if alias and type.Namespace == "System" then
            local name = SYSTEM_NAMES[type.FullName]
            if name ~= nil then
                return name
            end
        end
        return get_reflected_type(type)
    end
end

local function get_runtime_type_name_alias(type)
    return get_runtime_type_name(type, true)
end

local FieldAttributes = CS.System.Reflection.FieldAttributes

local function get_field_type_string(field)
    local out = ""
    local access = field.Attributes & FieldAttributes.FieldAccessMask
    if (access == FieldAttributes.Private) then
        out = out .. "private "
    elseif (access == FieldAttributes.Public) then
        out = out .. "public "
    elseif (access == FieldAttributes.Family) then
        out = out .. "protected "
    elseif (access == FieldAttributes.Assembly) --
    or (access == FieldAttributes.FamANDAssem) then
        out = out .. "internal "
    elseif (access == FieldAttributes.FamORAssem) then
        out = out .. "protected internal "
    end
    if field.IsLiteral then
        out = out .. "const "
    else
        if field.IsStatic then
            out = out .. "static "
        end
        if field.IsInitOnly then
            out = out .. "readonly "
        end
    end
    return out
end

local MethodAttributes = CS.System.Reflection.MethodAttributes

local function get_method_type_string(method)
    local out = ""
    local attributes = method.Attributes
    local access = attributes & MethodAttributes.MemberAccessMask
    if (access == MethodAttributes.Private) then
        out = out .. "private "
    elseif (access == MethodAttributes.Public) then
        out = out .. "public "
    elseif (access == MethodAttributes.Family) then
        out = out .. "protected "
    elseif (access == MethodAttributes.Assembly) --
    or (access == MethodAttributes.FamANDAssem) then
        out = out .. "internal "
    elseif (access == MethodAttributes.FamORAssem) then
        out = out .. "protected internal "
    end
    if (attributes & MethodAttributes.Static).value__ ~= 0 then
        out = out .. "static "
    end
    if (attributes & MethodAttributes.Abstract).value__ ~= 0 then
        out = out .. "abstract "
        if (attributes & MethodAttributes.VtableLayoutMask) == MethodAttributes.ReuseSlot then
            out = out .. "override "
        end
    elseif (attributes & MethodAttributes.Final).value__ ~= 0 then
        if (attributes & MethodAttributes.VtableLayoutMask) == MethodAttributes.ReuseSlot then
            out = out .. "sealed override "
        end
    elseif (attributes & MethodAttributes.Virtual).value__ ~= 0 then
        if (attributes & MethodAttributes.VtableLayoutMask) == MethodAttributes.NewSlot then
            out = out .. "virtual "
        else
            out = out .. "override "
        end
    end
    if (attributes & MethodAttributes.PinvokeImpl).value__ ~= 0 then
        out = out .. "extern "
    end
    return out
end

local function do_dump_csharp_field(file, field)
    file:write(get_field_type_string(field))
    file:write(get_runtime_type_name_alias(field.FieldType) .. " ")
    file:write(field.Name)
    if field.IsLiteral then
        local value = field:GetRawConstantValue()
        if field.FieldType.FullName == "System.String" then
            -- TODO: fix utf-8 encoding
            file:write(string.format(" = \"%s\";", value))
        elseif field.FieldType.FullName == "System.Char" then
            file:write(string.format(" = '\\x%X';", value))
        else
            file:write(string.format(" = %s;", value))
        end
    else
        local value = field:GetFieldOffset()
        if value & 0x8000000000000000 ~= 0 then
            value = -value
        end
        value = value + 0x10
        if value < 0 then
            file:write(string.format("; // -0x%X", value))
        else
            file:write(string.format("; // 0x%X", value))
        end
    end
    file:write("\n")
end

local function do_dump_csharp_property(file, property)
    if property.CanRead then
        local method = property:GetGetMethod(true)
        if method ~= nil then
            file:write(get_method_type_string(method))
        else
            log:write("property " .. property.Name .. " has no getter\n")
            file:write(get_type_visibility_string(property.PropertyType))
        end
    elseif property.CanWrite then
        local method = property:GetSetMethod(true)
        if method ~= nil then
            file:write(get_method_type_string(method))
        else
            log:write("property " .. property.Name .. " has no setter\n")
            file:write(get_type_visibility_string(property.PropertyType))
        end
    else
        file:write(get_type_visibility_string(property.PropertyType))
    end
    file:write(get_runtime_type_name_alias(property.PropertyType) .. " ")
    file:write(property.Name .. " { ")
    if property.CanRead then
        file:write("get; ")
    end
    if property.CanWrite then
        file:write("set; ")
    end
    file:write("}\n")
end

local function do_dump_csharp_method(file, type, method, rva, is_ctor)
    if is_ctor then
        file:write(get_method_type_string(method))
        file:write("void " .. method.Name)
    else
        file:write(get_method_type_string(method))
        file:write(get_runtime_type_name_alias(method.ReturnType) .. " ")
        file:write(method.Name)
        local arguments = method:GetGenericArguments()
        if arguments.Length > 0 then
            file:write("<")
            for i = 0, arguments.Length - 1 do
                local argument = arguments[i]
                if i ~= 0 then
                    file:write(", ")
                end
                file:write(get_runtime_type_name_alias(argument))
            end
            file:write(">")
        end
    end
    file:write("(")
    local parameters = method:GetParameters()
    for i = 0, parameters.Length - 1 do
        local parameter = parameters[i]
        if i ~= 0 then
            file:write(", ")
        end
        local name = get_runtime_type_name_alias(parameter.ParameterType)
        local pos = name:find("&")
        if pos ~= nil then
            name = name:sub(1, pos - 1)
            if parameter.IsIn then
                name = "in " .. name
            elseif parameter.IsOut then
                name = "out " .. name
            else
                name = "ref " .. name
            end
        else
            if parameter.IsIn then
                name = "[In] " .. name
            end
            if parameter.IsOut then
                name = "[Out] " .. name
            end
        end
        file:write(name .. " " .. parameter.Name)
        local status, err = pcall(function()
            if parameter.IsOptional then
                local type = parameter.ParameterType
                local value = parameter.DefaultValue
                if type.IsEnum then
                    if value.value__ == nil then
                        file:write(" = 0")
                    else
                        file:write(string.format(" = %d", value.value__))
                    end
                else
                    if type.FullName == "System.String" then
                        -- TODO: fix utf-8 encoding
                        file:write(string.format(" = \"%s\"", value))
                    elseif type.FullName == "System.Char" then
                        file:write(string.format(" = '\\x%X'", value))
                    else
                        file:write(string.format(" = %s", value))
                    end
                end
            end
        end)
        if not status then
            log:write(err .. "\n")
        end
    end
    file:write(") { }")
    if rva ~= nil then
        file:write(" // RVA: " .. rva)
    end
    file:write("\n")
    if not is_ctor then
        local generic_method = method:GetGenericMethodDefinition_impl()
        if generic_method ~= nil then
            file:write("\t/* GenericMethodDefinition :\n")
            file:write("\t |\n")
            file:write("\t */\n")
        end
    end
end

)MY_DELIMITER";

const char* char_dumpcs_part2 = R"MY_DELIMITER(
local flags = CS.System.Reflection.BindingFlags.Instance | --
CS.System.Reflection.BindingFlags.Static | --
CS.System.Reflection.BindingFlags.Public | --
CS.System.Reflection.BindingFlags.NonPublic

local function do_dump_csharp_type(file, type, index, rvas)
    file:write(string.format("// TypeDefIndex: %d\n", index))
    file:write(string.format("// Module: %s\n", type.Module.name))
    local namespace = type.Namespace
    if namespace == nil then
        file:write("// Namespace:\n")
    else
        file:write(string.format("// Namespace: %s\n", namespace))
    end
    local index = 2

    local attributes = type:GetCustomAttributes(true)
    for i = 0, attributes.Length - 1 do
        local text = get_runtime_type_name(attributes[i]:GetType())
        file:write(string.format("[%s]\n", text))
    end

    file:write(get_type_string(type) .. get_runtime_type_name(type, false))
    if not type.IsEnum then
        local once = false
        local base_type = type.BaseType
        if base_type ~= nil then
            local name = get_runtime_type_name_alias(base_type)
            if name ~= "object" and name ~= "ValueType" then
                once = true
            end
            if once then
                file:write(" : " .. name)
            end
        end
        local interfaces = type:GetInterfaces()
        if interfaces.Length > 0 then
            for i = 0, interfaces.Length - 1 do
                local interface = interfaces[i]
                local name = get_runtime_type_name_alias(interface)
                if interface.FullName ~= nil then
                    local full = interface.FullName
                    if base_type ~= nil then
                        local base_interfaces = base_type:GetInterfaces()
                        for i = 0, base_interfaces.Length - 1 do
                            local base_interface = base_interfaces[i]
                            if base_interface.FullName == interface.FullName then
                                goto continue
                            end
                        end
                    end
                end
                if not once then
                    once = true
                    file:write(" : " .. name)
                else
                    file:write(", " .. name)
                end
                ::continue::
            end
        end
    end

    file:write("\n{")

    local fields = type:GetFields(flags)
    if fields.Length > 0 then
        local once = false
        for j = 0, fields.Length - 1 do
            local field = fields[j]
            if field.DeclaringType == type then
                if not once then
                    file:write("\n")
                    file:write("\t// Fields\n")
                    once = true
                end
                local attributes = field:GetCustomAttributes(true)
                for i = 0, attributes.Length - 1 do
                    local text = get_runtime_type_name(attributes[i]:GetType())
                    file:write(string.format("\t[%s]\n", text))
                end
                file:write("\t")
                do_dump_csharp_field(file, field)
            end
        end
    end

    local properties = type:GetProperties(flags)
    if properties.Length > 0 then
        local once = false
        for j = 0, properties.Length - 1 do
            local property = properties[j]
            if property.DeclaringType == type then
                if not once then
                    file:write("\n")
                    file:write("\t// Properties\n")
                    once = true
                end
                local attributes = property:GetCustomAttributes(true)
                for i = 0, attributes.Length - 1 do
                    local text = get_runtime_type_name(attributes[i]:GetType())
                    file:write(string.format("\t[%s]\n", text))
                end
                file:write("\t")
                do_dump_csharp_property(file, property)
            end
        end
    end

    local constructors = type:GetConstructors(flags)
    if constructors.Length > 0 then
        local once = false
        for j = 0, constructors.Length - 1 do
            local constructor = constructors[j]
            if constructor.DeclaringType == type then
                if not once then
                    file:write("\n")
                    file:write("\t// Constructors\n")
                    once = true
                end
                local attributes = constructor:GetCustomAttributes(true)
                for i = 0, attributes.Length - 1 do
                    local text = get_runtime_type_name(attributes[i]:GetType())
                    file:write(string.format("\t[%s]\n", text))
                end
                file:write("\t")
                do_dump_csharp_method(file, type, constructor, rvas[index], true)
                index = index + 1
            end
        end
    end

    local methods = type:GetMethods(flags)
    if methods.Length > 0 then
        local once = false
        for j = 0, methods.Length - 1 do
            local method = methods[j]
            if method.DeclaringType == type then
                if not once then
                    file:write("\n")
                    file:write("\t// Methods\n")
                    once = true
                end
                local attributes = method:GetCustomAttributes(true)
                for i = 0, attributes.Length - 1 do
                    local text = get_runtime_type_name(attributes[i]:GetType())
                    file:write(string.format("\t[%s]\n", text))
                end
                file:write("\t")
                do_dump_csharp_method(file, type, method, rvas[index], false)
                index = index + 1
            end
        end
    end

    file:write("}\n")
end

local function split(inputstr, sep)
    if sep == nil then
        sep = "%s"
    end
    local t={}
    for str in string.gmatch(inputstr, "([^"..sep.."]+)") do
        table.insert(t, str)
    end
    return t
end

local function get_rvas(index)
    return {}
    -- return split(CS.MiHoYo.SDK.SDKUtil.RSAEncrypt("get_rva", string.format("%d", index)), ";")
end

local function do_dump_csharp()
    local file = io.open(DUMP_CS_FILE, "w")

    local assemblies = CS.System.AppDomain.CurrentDomain:GetAssemblies()
    for i = 0, assemblies.Length - 1 do
        local assembly = assemblies[i]
        file:write(string.format("// Assembly %d: %s\n", i, assembly:ToString()))
    end

    local index = 0

    for i = 0, assemblies.Length - 1 do
        local assembly = assemblies[i]
        local types = assembly:GetTypes()
        log:write(string.format("dumping types in assembly %d: %s, total: %d\n", --
        i, assembly:ToString(), types.Length))
        for j = 0, types.Length - 1 do
            local type = types[j]
            file:write("\n")
            local rvas = {}
            while true do
                rvas = get_rvas(index)
                if rvas[1] ~= "<Module>" then
                    break
                end
                file:write(string.format("// TypeDefIndex: %d\n", index))
                file:write(string.format("// Module: %s\n", type.Module.name))
                local namespace = type.Namespace
                if namespace == nil then
                    file:write("// Namespace:\n")
                else
                    file:write(string.format("// Namespace: %s\n", namespace))
                end
                file:write("internal class <Module>\n{}\n\n")
                index = index + 1
            end
            do_dump_csharp_type(file, type, index, rvas)
            index = index + 1
        end
    end

    file:close()
end

local function main()
    log:write("start dumping csharp to " .. DUMP_CS_FILE .. "\n")
    do_dump_csharp()
    log:write("dumping csharp done\n")
end

local function on_error(error)
    log:write("dumping csharp failed, error: " .. error .. "\n")
end

xpcall(main, on_error)

log:close()
)MY_DELIMITER";

//local dump_path = ""
const char* char_dump_hierarchy = R"MY_DELIMITER(

function writeToFile(text)
    local file = io.open(dump_path .. "/logs.txt", "a")
    file:write("/".. text.."\n")
    file:close()
end

function getParents(obj)
    local parents = ""
    local parent = obj.transform.parent
    while parent ~= nil do
        parents =  parent.name .. "/" .. parents       
        parent = parent.parent
    end
    return parents
end

function printAllUnityObjects(object)
    if object ~= nil then
        writeToFile(getParents(object) .. object.name)      
        for i = 0, object.transform.childCount - 1 do
            printAllUnityObjects(object.transform:GetChild(i).gameObject)
        end
    end
end
local function start()
    for i = 0, CS.UnityEngine.SceneManagement.SceneManager.sceneCount - 1 do
        local scene = CS.UnityEngine.SceneManagement.SceneManager.GetSceneAt(i)
        
        for j = 0, scene.rootCount - 1 do
            local root = scene:GetRootGameObjects()[j]
            printAllUnityObjects(root)
        end
    end
    
end
local function onError(error)
    writeToFile(error)
end

xpcall(start, onError)
)MY_DELIMITER";



void luahookfunc(const char* charLuaScript) {

	auto compiled = compile(gi_LL, charLuaScript);
    if (!compiled)
    return;
	auto copy = new std::string(compiled.value());
	auto execute = [](ULONG_PTR compiled)
	{
		auto str = (const std::string*)compiled;
		exec(*str);
		delete str;
	};
	QueueUserAPC(execute, main_thread, (ULONG_PTR)copy);
};
