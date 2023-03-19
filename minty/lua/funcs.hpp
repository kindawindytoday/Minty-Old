#pragma once

#include "..\gilua\luaHook.h"
#include "../json/json.hpp"
//using json = nlohmann::json;
//config json;

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

const char* char_uicamera_on = R"MY_DELIMITER(CS.UnityEngine.GameObject.Find("/UICamera"):GetComponent("Camera").enabled = true)MY_DELIMITER";

const char* char_uicamera_off = R"MY_DELIMITER(CS.UnityEngine.GameObject.Find("/UICamera"):GetComponent("Camera").enabled = false)MY_DELIMITER";

const char* license_ImGui = R"MY_DELIMITER(The MIT License (MIT)

Copyright (c) 2014-2023 Omar Cornut)MY_DELIMITER";
const char* license_ColorTextEdit = R"MY_DELIMITER(MIT License

Copyright (c) 2017 BalazsJako)MY_DELIMITER";
const char* license_FileDialog = R"MY_DELIMITER(MIT License

Copyright (c) 2018-2022 Stephane Cuillerdier (aka Aiekick)
)MY_DELIMITER";

const char* license_json = R"MY_DELIMITER(MIT License 

Copyright (c) 2013-2022 Niels Lohmann
)MY_DELIMITER";

const char* license_Generic = R"MY_DELIMITER(
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.)MY_DELIMITER";

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
