#include "LuaCamera.h"

LuaCamera::LuaCamera(){
}

LuaCamera::~LuaCamera(){
}

const luaL_Reg LuaCamera::luaBinds[] = {
	{"Create", lua_Create},
	{"Destroy", lua_Destroy},
	{"SetParent", lua_SetParent},
	{"AddSkybox", lua_AddSkybox},
	{"ActiveCamera", lua_ActiveCamera},
	{"GoForward", lua_GoForward},
	{"GoBackward", lua_GoBackward},
	{"GoLeft", lua_GoLeft},
	{"GoRight", lua_GoRight},
	{"GetTransform", lua_GetTransform},
	{"SetTransform", lua_SetTransform},
	{ "ToggleMouseControl", lua_ToggleMouse },
	{ "Find", lua_Find },
	{ "SetActive", lua_SetActive },
	{NULL, NULL}
};


int LuaCamera::lua_Create(lua_State* L)
{
	LuaBinder binder(L);
	Camera* entity = new Camera(binder.checkstring(1));
	binder.pushusertype(entity, "Camera");
	return 1;
}

int LuaCamera::lua_Destroy(lua_State* L)
{
	LuaBinder binder(L);
	Camera* entity = (Camera*)binder.checkusertype(1, "Camera");
	delete entity;
	return 0;
}

int LuaCamera::lua_SetParent(lua_State* L)
{
	LuaBinder binder(L);
	Camera* entity = (Camera*)binder.checkusertype(1, "Camera");
	entity->setParent(static_cast<Entity*>(binder.checkusertype(2, "Camera")));
	return 0;
}

int LuaCamera::lua_AddSkybox(lua_State* L)
{
	LuaBinder binder(L);
	Camera* entity = (Camera*)binder.checkusertype(1, "Camera");
	Skybox* sky = new Skybox;
	sky->load(binder.checkstring(2));
	entity->addSkybox(sky);
	return 0;
}

int LuaCamera::lua_ActiveCamera(lua_State* L)
{
	LuaBinder binder(L);

	Camera* cam = StateManager::getActiveState()->getCurrentCamera();
	binder.pushusertype(cam, "Camera");

	return 1;
}

int LuaCamera::lua_GoForward(lua_State* L){
	LuaBinder binder(L);
	Camera* entity = (Camera*)binder.checkusertype(1, "Camera");
	entity->goForward();
	return 0;
}

int LuaCamera::lua_GoBackward(lua_State* L){
	LuaBinder binder(L);
	Camera* entity = (Camera*)binder.checkusertype(1, "Camera");
	entity->goBackward();
	return 0;
}

int LuaCamera::lua_GoLeft(lua_State* L){
	LuaBinder binder(L);
	Camera* entity = (Camera*)binder.checkusertype(1, "Camera");
	entity->goLeft();
	return 0;
}

int LuaCamera::lua_GoRight(lua_State* L)
{
	LuaBinder binder(L);
	Camera* entity = (Camera*)binder.checkusertype(1, "Camera");
	entity->goRight();
	return 0;
}

int LuaCamera::lua_GetTransform(lua_State* L)
{
	LuaBinder binder(L);

	Camera* entity = (Camera*)binder.checkusertype(1, "Camera");
	binder.pushusertype(entity->GetTransform(), "Transform");

	return 1;
}

int LuaCamera::lua_SetTransform(lua_State* L)
{
	LuaBinder binder(L);

	Camera* entity = (Camera*)binder.checkusertype(1, "Camera");
	CTransform* component = (CTransform*)binder.checkusertype(2, "Component");

	entity->SetTransform(component);
	return 0;
}

int LuaCamera::lua_ToggleMouse(lua_State* L)
{
	LuaBinder binder(L);

	Camera* entity = (Camera*)binder.checkusertype(1, "Camera");

	entity->toggleMouseControl();
	return 0;
}

int LuaCamera::lua_Find(lua_State* L){
	LuaBinder binder(L);

	State* state = StateManager::getActiveState();
	Camera* e = state->getCamera(binder.checkstring(1));

	binder.pushusertype(e, "Camera");
	return 1;
}

int LuaCamera::lua_SetActive(lua_State* L){
	LuaBinder binder(L);

	State* state = StateManager::getActiveState();
	Camera* e = state->getCamera(binder.checkstring(1));
	if (e != nullptr) {
		state->setCurrentCamera(e);
	}

	return 0;
}