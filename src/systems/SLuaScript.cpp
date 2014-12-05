#include "SLuaScript.h"

SLuaScript::SLuaScript(){
	m_masterLuaState = nullptr;
}

SLuaScript::~SLuaScript(){
}

void SLuaScript::initialize(){
	m_masterLuaState = luaL_newstate();
	luaL_openlibs( m_masterLuaState );
	m_luaBinds.setLuaState(m_masterLuaState);
	m_luaBinds.bindObjects();
}

lua_State* SLuaScript::getMasterState(){
	return m_masterLuaState;
}

LuaScript* SLuaScript::createScript(){
	LuaScript* l = new LuaScript(m_masterLuaState);
	m_globalScripts.push_back(l);
	return l;
}

void SLuaScript::update(float dt){
	std::map<std::string, Entity*> entityList = m_CurrentState->getEntities();

	auto it = m_CurrentState->getEntities().begin();
	while(it != m_CurrentState->getEntities().end()) 
	{
		std::vector<Component*> cList = (*it).second->getComponentsByType("LuaScript");
		auto CIterator = cList.begin();
		while(CIterator != cList.end())
		{
			static_cast<CLuaScript*>((*CIterator))->getScript()->update(dt);
			++CIterator;
		}
		++it;
	}


	auto it2 = m_CurrentState->getCameras().begin();
	while (it2 != m_CurrentState->getCameras().end())
	{
		std::vector<Component*> cList = (*it2)->getComponentsByType("LuaScript");
		auto CIterator = cList.begin();
		while (CIterator != cList.end())
		{
			static_cast<CLuaScript*>((*CIterator))->getScript()->update(dt);
			++CIterator;
		}
		++it2;
	}
	

	auto itRaw = m_globalScripts.begin();
	while(itRaw != m_globalScripts.end()) {
		(*itRaw)->update(dt);
		++itRaw;
	}
}


void SLuaScript::deleteScript(LuaScript* scriptptr)
{
	for( unsigned int i=0; i < m_globalScripts.size(); ++i)
	{
		if (m_globalScripts[i] == scriptptr)
		{
			delete m_globalScripts[i];
			m_globalScripts.erase(m_globalScripts.begin()+i);
			return;
		}
	}
}