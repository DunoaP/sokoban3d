#include "LuaCGraphics.h"

LuaCGraphics::LuaCGraphics(){}
LuaCGraphics::~LuaCGraphics(){}

const luaL_Reg LuaCGraphics::luaBinds[] = {
	{"Create", lua_Create},
	{"GetModel", lua_GetModel},
	{"SetModel", lua_SetModel},
	{"AddModel", lua_AddModel},
	{"AddTexture", lua_AddTexture},
	{NULL, NULL}
};

int LuaCGraphics::lua_Create(lua_State* L)
{
	LuaBinder binder(L);
	CGraphics* v = new CGraphics();
	binder.pushusertype(v, "CGraphics");
	return 1;
}

int LuaCGraphics::lua_GetModel(lua_State* L)
{
	LuaBinder binder(L);
	CGraphics* component = (CGraphics*)binder.checkusertype(1, "CGraphics");
	Model* v = component->getModel();
	binder.pushusertype(v, "Model");
	return 1;
}

int LuaCGraphics::lua_SetModel(lua_State* L)
{
	LuaBinder binder(L);
	CGraphics* component = (CGraphics*)binder.checkusertype(1, "CGraphics");

	component->setModel((Model*)binder.checkusertype(2, "Model") );
	return 0;
}

int LuaCGraphics::lua_AddModel(lua_State* L)
{
	LuaBinder binder(L);
	CGraphics* component = (CGraphics*)binder.checkusertype(1, "CGraphics");

	component->addModel(binder.checkstring(2));
	return 0;
}

int LuaCGraphics::lua_AddTexture(lua_State* L)
{
	LuaBinder binder(L);
	CGraphics* component = (CGraphics*)binder.checkusertype(1, "CGraphics");
	component->addTexture(binder.checkstring(2));
	return 0;
}