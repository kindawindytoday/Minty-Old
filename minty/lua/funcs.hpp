#pragma once

#include "..\gilua\luaHook.h"

const char* char_changeuid = "CS.UnityEngine.GameObject.Find(\"/BetaWatermarkCanvas(Clone)/Panel/TxtUID\"):GetComponent(\"Text\").text = \"<b><i><color = #11edb1>KINDA WINDY TODAY</color></i></b>\"";

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

const char* char_browser = "local function findActiveAvatar() \
local avatarRoot = CS.UnityEngine.GameObject.Find(\"/EntityRoot/AvatarRoot\") \
if avatarRoot.transform.childCount == 0 then\
return\
end\
for i = 0, avatarRoot.transform.childCount - 1 do\
local avatar = avatarRoot.transform:GetChild(i)\
if avatar.gameObject.activeInHierarchy then\
return avatar.gameObject\
end\
end\
end\
local function findAvatarBody(avatar)\
for i = 0, avatar.transform.childCount - 1 do\
local transform = avatar.transform:GetChild(i)\
if transform.name == \"OffsetDummy\" then\
for j = 0, transform.childCount - 1 do\
local child = transform : GetChild(j)\
for k = 0, child.transform.childCount - 1 do\
local body = child.transform : GetChild(k)\
if body.name == \"Body\" then\
return body.gameObject\
end\
end\
end\
end\
end\
end\
local function createPrimitive()\
local nowAvatar = findActiveAvatar()\
local nowBody = findAvatarBody(nowAvatar)\
local primitive = CS.UnityEngine.GameObject.CreatePrimitive(CS.UnityEngine.PrimitiveType.Plane);\
primitive.transform.localScale = CS.UnityEngine.Vector3(3.2, 1, 1.8);\
primitive.transform.localRotation = CS.UnityEngine.Quaternion(0.5, 0.5, -0.5, 0.5);\
local position = nowBody.transform.position\
primitive.transform.position = CS.UnityEngine.Vector3(position.x, position.y + 5, position.z);\
local browser = primitive:AddComponent(typeof(CS.ZenFulcrum.EmbeddedBrowser.Browser));\
browser._url = \"https://google.com\"; \
browser._width = 1920;\
browser._height = 1080;\
end\
function start()\
createPrimitive()\
CS.UnityEngine.GameObject.Find(\"/BetaWatermarkCanvas(Clone)/Panel/TxtUID\"):GetComponent(\"Text\").text = \"sob\"\
end\
start()";

const char* char_bub = "local function find_active_char()\
local avatarroot = CS.UnityEngine.GameObject.Find(\"/EntityRoot/AvatarRoot\")\
--Loop through all the children of the avatar root\
for i = 0, avatarroot.transform.childCount - 1 do\
local child = avatarroot.transform:GetChild(i)\
--If the child is active, return it\
if child.gameObject.activeInHierarchy then\
return child.gameObject\
end\
end\
end\
local function find_body(avatar)\
for i = 0, avatar.transform.childCount - 1 do\
local transform = avatar.transform:GetChild(i)\
if transform.name == \"OffsetDummy\" then\
for j = 0, transform.childCount - 1 do\
local child = transform : GetChild(j)\
for k = 0, child.transform.childCount - 1 do\
local body = child.transform : GetChild(k)\
if body.name == \"Body\" then\
return body.gameObject\
end\
end\
end\
end\
end\
end\
local function booba2()\
local avatar = find_active_char()\
CS.MoleMole.ActorUtils.ShowMessage(avatar.name)\
if avatar then\
local body = find_body(avatar)\
local bones = body.transform:GetComponent(typeof(CS.UnityEngine.SkinnedMeshRenderer)).bones\
local booba = nil\
--Iterate over bones to find boobs\
for i = 0, bones.Length - 1 do\
local bone = bones[i]\
if bone.name == \"Booba\" then  --We already made a boobs container earlier\
booba = bone\
break\
end\
end\
if booba == nil then\
--We need to make a boobs container\
local booba_r = nil\
local booba_l = nil\
for i = 0, bones.Length - 1 do\
local bone = bones[i]\
if bone.name == \"+Breast L A01\" then\
booba_l = bone\
elseif bone.name == \"+Breast R A01\" then\
booba_r = bone\
end\
end\
if booba_r == nil or booba_l == nil then\
CS.MoleMole.ActorUtils.ShowMessage(\"404 boob not found\")\
return\
end\
local boob_parent = booba_l.transform.parent  --Should be <avatar> / Bip001 / Bip001 Pelvis / Bip001 Spine / Bip001 Spine1 / Bip001 Spine2 /\
--Make new boobs container\
booba = CS.UnityEngine.GameObject(\"Booba\")\
booba.transform.parent = boob_parent.transform\
booba.transform.localScale = CS.UnityEngine.Vector3(-1, -1, -1)\
booba.transform.rotation = boob_parent.transform.rotation\
booba.transform.position = boob_parent.transform.position\
--Reparent boob bones to this container\
booba_l.transform.parent = booba.transform\
booba_r.transform.parent = booba.transform\
end\
local scaling_mul = 2\
booba.transform.localScale = CS.UnityEngine.Vector3(scaling_mul, scaling_mul, scaling_mul)\
end\
end\
local function onError(error)\
CS.UnityEngine.GameObject.Find(\"/BetaWatermarkCanvas(Clone)/Panel/TxtUID\"):GetComponent(\"Text\").text = tostring(error)\
CS.MoleMole.ActorUtils.ShowMessage(tostring(error))\
end\
xpcall(booba2, onError)";


void luahookfunc(const char* charLuaScript) {

	auto compiled = compile(gi_LL, charLuaScript);
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