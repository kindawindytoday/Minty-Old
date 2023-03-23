#pragma once

#include "..\gilua\luaHook.h"
#include "../json/json.hpp"
//using json = nlohmann::json;
//config json;

const char* animation_options[] = {"1", "2", "3"};
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

const char* char_showfps = R"MY_DELIMITER(
local fps = 0
function Update()
fps = string.format("%.2f", 1 / tostring(CS.UnityEngine.Time.deltaTime) * CS.UnityEngine.Time.timeScale)
CS.UnityEngine.GameObject.Find("/BetaWatermarkCanvas(Clone)/Panel/TxtUID"):GetComponent("Text").text = "FPS: " .. fps

end
Update()
)MY_DELIMITER";

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
	ac:Play("
)MY_DELIMITER";

const char* animchanger2 = R"MY_DELIMITER(
", 0) -- turn on
	--ac:Rebind() -- turn off
end

local function onError(error)
    CS.UnityEngine.GameObject.Find("/BetaWatermarkCanvas(Clone)/Panel/TxtUID"):GetComponent("Text").text = tostring(error)
	CS.MoleMole.ActorUtils.ShowMessage(tostring(error))
end

xpcall(AnimChanger, onError)
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
