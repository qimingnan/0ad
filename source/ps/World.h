#ifndef _ps_World_H
#define _ps_World_H

#include "graphics/Terrain.h"

#include "ps/Errors.h"

#ifndef ERROR_GROUP_GAME_DEFINED
#define ERROR_GROUP_GAME_DEFINED
ERROR_GROUP(Game);
#endif
ERROR_SUBGROUP(Game, World);
ERROR_TYPE(Game_World, MapLoadFailed);

class CGame;
class CGameAttributes;
class CUnitManager;
class CEntityManager;
class CProjectileManager;
class CLOSManager;

class CWorld
{
	CGame *m_pGame;
	
	CTerrain m_Terrain;

	CUnitManager *m_UnitManager;
	CEntityManager *m_EntityManager;
	CProjectileManager *m_ProjectileManager;
	CLOSManager *m_LOSManager;

public:
	CWorld(CGame *pGame);
	~CWorld();

	void RegisterInit(CGameAttributes *pGameAttributes);
	/*
	Initialize the World - load the map and all objects
	*/
	void Initialize(CGameAttributes *pGameAttributes);

	// provided for JS _rewritemaps function
	void RewriteMap();

	inline CTerrain *GetTerrain()
	{	return &m_Terrain; }
	inline CUnitManager *GetUnitManager()
	{	return m_UnitManager; }
	inline CEntityManager *GetEntityManager()
	{	return m_EntityManager; }
	inline CProjectileManager *GetProjectileManager()
	{	return m_ProjectileManager; }
	inline CLOSManager *GetLOSManager()
	{	return m_LOSManager; }

private:
	// squelch "unable to generate" warnings
	CWorld(const CWorld& rhs);
	const CWorld& operator=(const CWorld& rhs);
};

// rationale: see definition.
class CLightEnv;
extern CLightEnv g_LightEnv;

#endif
