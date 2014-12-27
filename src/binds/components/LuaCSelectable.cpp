#include "LuaCSelectable.h"

LuaCSelectable::LuaCSelectable(){}
LuaCSelectable::~LuaCSelectable(){}

const luaL_Reg LuaCSelectable::luaBinds_f[] = {
	{ "new", lua_Create },
	{ NULL, NULL }
};

const luaL_Reg LuaCSelectable::luaBinds_m[] = {
	{"IsSelected", lua_GetSelected},
	{"HoveredOver", lua_GetHovered},
	{NULL, NULL}
};

int LuaCSelectable::lua_Create(lua_State* L)
{
	LuaBinder binder(L);
	CSelectable* v = new CSelectable();
	binder.pushusertype(v, "CSelectable", sizeof(CSelectable));

	return 1;
}


int LuaCSelectable::lua_GetHovered(lua_State* L)
{
	LuaBinder binder(L);

	CSelectable* c = static_cast<CSelectable*>(binder.checkusertype(1, "CSelectable"));

	binder.pushnumber(c->getHovered());
	return 1;
}

int LuaCSelectable::lua_GetSelected(lua_State* L)
{
	LuaBinder binder(L);

	CSelectable* c = static_cast<CSelectable*>(binder.checkusertype(1, "CSelectable"));

	binder.pushnumber(c->getSelected());
	return 1;

}