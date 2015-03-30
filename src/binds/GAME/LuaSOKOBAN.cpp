#include "LuaSOKOBAN.h"

LuaSokoban::LuaSokoban(){
}

LuaSokoban::~LuaSokoban(){
}

const luaL_Reg LuaSokoban::luaBinds[] = {
	{ "CanPlayerMove", lua_CanPlayerMove },
	{ "CurrentFace", lua_GetCurrentFace },
	{NULL, NULL}
};

int LuaSokoban::lua_CanPlayerMove(lua_State* L)
{
	LuaBinder binder(L);
	Sokoban& state = static_cast<Sokoban&>(StateManager::getState("SOKOBAN"));

	GameBoard g = state.getGameBoard((int)state.getPlayerPosition().z);

	bool move = g.canPlayerMove((int)state.getPlayerPosition().x, (int)state.getPlayerPosition().y, (int)binder.checknumber(1));
	if (move)
	{
		binder.pushnumber(1);
	}
	else {
		binder.pushnumber(0);
	}
	

	return 1;
}

int LuaSokoban::lua_CanBlockMove(lua_State* L)
{
	return 1;
}

int LuaSokoban::lua_PlayerMove(lua_State* L)
{
	return 1;
}

int LuaSokoban::lua_BlockMove(lua_State* L)
{
	return 1;
}


int LuaSokoban::lua_GetCurrentFace(lua_State* L)
{
	LuaBinder binder(L);
	Sokoban& state = static_cast<Sokoban&>(StateManager::getState("SOKOBAN"));

	binder.pushnumber(state.getPlayerPosition().z);

	return 1;
}