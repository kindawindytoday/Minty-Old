local function createbuttons()
    local canvas = CS.UnityEngine.GameObject.Find("/Canvas")
    local backgroundbox = CS.UnityEngine.GameObject("backgroundbox")

    CS.UnityEngine.Object.DontDestroyOnLoad(backgroundbox)

    CS.UnityEngine.Object.DontDestroyOnLoad(canvas)

    backgroundbox.transform:SetParent(canvas.transform, false)
    backgroundbox.transform.localPosition = CS.UnityEngine.Vector3(380, 865, 5)
    backgroundbox.transform.localScale = CS.UnityEngine.Vector3(0.6, 0.6, 0.6)
    local rectTransform1 = backgroundbox:AddComponent(typeof(CS.UnityEngine.RectTransform))
    rectTransform1.anchorMin = CS.UnityEngine.Vector2(0, 0)
    rectTransform1.anchorMax = CS.UnityEngine.Vector2(0, 0)
    rectTransform1.sizeDelta = CS.UnityEngine.Vector2(100, 100)
    backgroundbox:AddComponent(typeof(CS.UnityEngine.Renderer)).material.SetColor("_Color", Color.red);
end

function onError(error)
    CS.MoleMole.ActorUtils.ShowMessage(tostring(error))
end

xpcall(createbuttons, onError)