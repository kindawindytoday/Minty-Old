#pragma once

#include "..\gilua\luaHook.h"

const char* char_changeuid = "CS.UnityEngine.GameObject.Find(\"/BetaWatermarkCanvas(Clone)/Panel/TxtUID\"):GetComponent(\"Text\").text = \"<b><i><color=#11edb1>KINDA WINDY TODAY</color></i></b>\"";

const char* char_eleminf = "local function normalattack() \
local effectpool = CS.UnityEngine.GameObject.Find(\"/EffectPool\") \
--loop through all the children of the effectpool \
for i = 0, effectpool.transform.childCount - 1 do \
local child = effectpool.transform:GetChild(i) \
if string.match(child.gameObject.name, \"Attack\") then \
for k = 0, child.transform.childCount - 1 do \
local bladechild = child.transform : GetChild(k) \
if string.match(bladechild.gameObject.name, \"e\") then \
local success, result = pcall(function() \
    bladechild.gameObject:GetComponent(typeof(CS.UnityEngine.ParticleSystem)).main.startColor = CS.UnityEngine.ParticleSystem.MinMaxGradient(CS.UnityEngine.Color(1, 0, 1, 1)) \
    end) \
    if not success then \
        end \
        end \
        end \
        end \
        end \
        end \
        function onError(error) \
        CS.MoleMole.ActorUtils.ShowMessage(tostring(error)) \
        end \
        xpcall(normalattack, onError)";

const char* char_browser_on = "";
const char* char_browser_off = "";

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

local function booba()
    
    local left = CS.UnityEngine.GameObject.Find(FindOffsetDummy() .. spine2 .. "/+Breast L A01")
    local right = CS.UnityEngine.GameObject.Find(FindOffsetDummy() .. spine2 .. "/+Breast R A01")
    
    if findboba == nil then
        if right ~= nil then
            bobaOBJ = CS.UnityEngine.GameObject("boba")
            spineidk = CS.UnityEngine.GameObject.Find(FindOffsetDummy() .. spine2)
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

booba()

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
					  return findHierarchyPath(avatarModel.gameObject)
				   end
				end
			 end
		  end
	   end
	end
 end

CS.UnityEngine.GameObject.Find(FindOffsetDummy() .. "/Bip001/Bip001 Pelvis/Bip001 Spine/Bip001 Spine1/Bip001 Spine2/boba").transform.localScale = CS.UnityEngine.Vector3()MY_DELIMITER";

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

//void func_changeuid() {
//
//	auto compiled = compile(gi_LL, "CS.UnityEngine.GameObject.Find(\"/BetaWatermarkCanvas(Clone)/Panel/TxtUID\"):GetComponent(\"Text\").text = \"<b><i><color = #11edb1>KINDA WINDY TODAY</color></i></b>\"");
//	auto copy = new std::string(compiled.value());
//	auto execute = [](ULONG_PTR compiled)
//	{
//		auto str = (const std::string*)compiled;
//		exec(*str);
//		delete str;
//	};
//	QueueUserAPC(execute, main_thread, (ULONG_PTR)copy);
//};