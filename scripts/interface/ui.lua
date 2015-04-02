--ui.lua

--Create Variables
currentLevel = 1




--Current Level
	local e = Entity.Create("CURRENTLEVEL")	
	local trans = Transform.Create()
	Transform.SetPosition(trans, Vec3.Create(-0.95,0.9,-0.5))
	Entity.SetTransform(e,trans)	
	local g = CGraphics.Create()
	CGraphics.AddText(g, "Current level: " .. tostring(currentLevel), 10)
	CGraphics.SetRenderMode(g, "RENDER_2D")	
	Entity.AddComponent(e, g, "Graphics")
	State.AddEntity(e, "SOKOBAN")
	
--Time taken
	local e = Entity.Create("TIMETAKEN")	
	local trans = Transform.Create()
	Transform.SetPosition(trans, Vec3.Create(-0.95,0.8,-0.5))
	Entity.SetTransform(e,trans)	
	local g = CGraphics.Create()
	CGraphics.AddText(g, "Time Elapsed: ", 8)
	CGraphics.SetRenderMode(g, "RENDER_2D")	
	Entity.AddComponent(e, g, "Graphics")
	State.AddEntity(e, "SOKOBAN")