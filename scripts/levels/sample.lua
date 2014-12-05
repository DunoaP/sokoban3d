 -- Create a sample ground
    local e = Entity.Create("1")
	local trans = Transform.Create()	
	
	Transform.SetPosition(trans, Vec3.Create(0, 0, 0))	
	Transform.SetOrientation(trans, Vec3.Create(0, 0, 0))	
	Transform.SetScale(trans, Vec3.Create(512, 1, 512))
	Entity.SetTransform(e,trans)
	
	local graphics = CGraphics.Create()
	CGraphics.AddModel(graphics, "shapes/plane.obj")
	CGraphics.AddTexture(graphics, "ground/white.jpg")
	
	Entity.AddComponent(e, graphics, "Graphics")
	State.AddEntity(e, "game")
	
	
	
	constructWall(-4,4)
	constructWall(-3,4)
	constructWall(-2,4)
	constructWall(-1,4)
	constructWall(0,4)
	
	constructWall(-4,3)
	constructWall(0,3)
	
	constructWall(-4,2)
	constructWall(0,2)
	
	constructWall(-6,1)
	constructWall(-5,1)
	constructWall(0,1)
	constructWall(1,1)
	constructWall(2,1)
	
	constructWall(-6,0)
	constructWall(2,0)
	
	
	constructWall(-8,-1)
	constructWall(-7,-1)
	constructWall(-6,-1)
	constructWall(-4,-1)
	constructWall(-2,-1)
	constructWall(-1,-1)
	constructWall(1,-1)
	constructWall(5,-1)
	constructWall(6,-1)
	constructWall(7,-1)
	constructWall(8,-1)
	constructWall(9,-1)
	constructWall(10,-1)
	
	constructWall(-8,-2)
	constructWall(-4,-2)
	constructWall(-2,-2)
	constructWall(-1,-2)
	constructWall(1,-2)
	constructWall(2,-2)
	constructWall(3,-2)
	constructWall(4,-2)
	constructWall(5,-2)
	constructWall(10,-2)
	
	constructWall(-8,-3)
	constructWall(10,-3)
	
	constructWall(-8,-4)
	constructWall(-7,-4)
	constructWall(-6,-4)
	constructWall(-5,-4)
	constructWall(-4,-4)
	constructWall(-2,-4)
	constructWall(-1,-4)
	constructWall(0,-4)
	constructWall(2,-4)
	constructWall(4,-4)
	constructWall(5,-4)
	constructWall(10,-4)
	
	constructWall(-4,-5)
	constructWall(2,-5)
	constructWall(3,-5)
	constructWall(4,-5)
	constructWall(5,-5)
	constructWall(6,-5)
	constructWall(7,-5)
	constructWall(8,-5)
	constructWall(9,-5)
	constructWall(10,-5)
	
	constructWall(-4,-6)
	constructWall(-3,-6)
	constructWall(-2,-6)
	constructWall(-1,-6)
	constructWall(0,-6)
	constructWall(1,-6)
	constructWall(2,-6)
	
	local light = PointLight.Create()
	local pos = Vec3.Create(0, 16, 0)
	PointLight.SetPosition(light, pos)
	
	State.AddPointLight(light, "game")
	
	
	
	