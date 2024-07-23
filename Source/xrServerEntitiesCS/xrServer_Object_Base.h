﻿////////////////////////////////////////////////////////////////////////////
//	Module 		: xrServer_Object_Base.h
//	Created 	: 19.09.2002
//  Modified 	: 16.07.2004
//	Author		: Oles Shyshkovtsov, Alexander Maksimchuk, Victor Reutskiy and Dmitriy Iassenev
//	Description : Server base object
////////////////////////////////////////////////////////////////////////////

#pragma once

#include "xrServer_Objects_Abstract.h"
#include "../xrEngine/object_interfaces.h"
#include "script_value_container.h"
#include "../xrEngine/alife_space.h"
#include "../xrCore/client_id.h"

class NET_Packet;
class xrClientData;
class CSE_ALifeGroupAbstract;
class CSE_ALifeSchedulable;
class CSE_ALifeInventoryItem;
class CSE_ALifeTraderAbstract;
class CSE_ALifeObject;
class CSE_ALifeDynamicObject;
class CSE_ALifeItemAmmo;
class CSE_ALifeItemWeapon;
class CSE_ALifeItemDetector;
class CSE_ALifeMonsterAbstract;
class CSE_ALifeHumanAbstract;
class CSE_ALifeAnomalousZone;
class CSE_ALifeTrader;
class CSE_ALifeCreatureAbstract;
class CSE_ALifeSmartZone;
class CSE_ALifeOnlineOfflineGroup;
class CSE_ALifeItemPDA;

#pragma warning(push)
#pragma warning(disable:4005)

SERVER_ENTITY_DECLARE_BEGIN(CPureServerObject, IPureServerObject)
virtual ~CPureServerObject() {}
virtual void load(IReader& tFileStream);
virtual void save(IWriter& tMemoryStream);
virtual void load(NET_Packet& tNetPacket);
virtual void save(NET_Packet& tNetPacket);
};

add_to_type_list(CPureServerObject)
#define script_type_list save_type_list(CPureServerObject)

    SERVER_ENTITY_DECLARE_BEGIN3(CSE_Abstract, ISE_Abstract, CPureServerObject, CScriptValueContainer) public: enum ESpawnFlags
{
    flSpawnEnabled         = u32(1 << 0),
    flSpawnOnSurgeOnly     = u32(1 << 1),
    flSpawnSingleItemOnly  = u32(1 << 2),
    flSpawnIfDestroyedOnly = u32(1 << 3),
    flSpawnInfiniteCount   = u32(1 << 4),
    flSpawnDestroyOnSpawn  = u32(1 << 5),
};

private:
LPSTR s_name_replace;

public:
virtual void load(NET_Packet& tNetPacket);

//////////////////////////////////////////////////////////////////////////

CSE_Abstract(LPCSTR caSection);
virtual ~CSE_Abstract();
virtual void OnEvent(NET_Packet& tNetPacket, u16 type, u32 time, ClientID sender){};
#ifndef XRGAME_EXPORTS
virtual void         FillProps(LPCSTR pref, PropItemVec& items);
virtual void         FillProp(LPCSTR pref, PropItemVec& items);
virtual void         on_render(CDUInterface* du, ISE_AbstractLEOwner* owner, bool bSelected, const Fmatrix& parent, int priority, bool strictB2F) {}
virtual visual_data* visual_collection() const
{
    return 0;
}
virtual u32 visual_collection_size() const
{
    return 0;
}
virtual void set_additional_info(void* info){};
#endif   // #ifndef XRGAME_EXPORTS
virtual BOOL Net_Relevant()
{
    return FALSE;
};   // !!!! WARNING!!!
//
virtual void   Spawn_Write(NET_Packet& tNetPacket, BOOL bLocal);
virtual BOOL   Spawn_Read(NET_Packet& tNetPacket);
virtual LPCSTR name() const;
virtual LPCSTR name_replace() const;
virtual void   set_name(LPCSTR s)
{
    s_name = s;
};

virtual void set_name_replace(LPCSTR s)
{
    xr_free(s_name_replace);
    s_name_replace = xr_strdup(s);
};
virtual Fvector&    position();
virtual Fvector&    angle();
virtual Flags16&    flags();
virtual ISE_Visual* visual();
virtual ISE_Shape*  shape();
virtual ISE_Motion* motion();
virtual bool        validate();
//

IC const Fvector&   Position() const
{
    return o_Position;
};
// we need this to prevent virtual inheritance :-(
virtual CSE_Abstract*       base();
virtual const CSE_Abstract* base() const;
virtual CSE_Abstract*       init();
virtual bool                match_configuration() const
{
    return true;
}
// end of the virtual inheritance dependant code
IC int script_clsid() const
{
    VERIFY(m_script_clsid >= 0);
    return (m_script_clsid);
}
CInifile&                       spawn_ini();

// for smart cast
virtual CSE_ALifeGroupAbstract* cast_group_abstract()
{
    return 0;
};
virtual CSE_ALifeSchedulable* cast_schedulable()
{
    return 0;
};
virtual CSE_ALifeInventoryItem* cast_inventory_item()
{
    return 0;
};
virtual CSE_ALifeTraderAbstract* cast_trader_abstract()
{
    return 0;
};

virtual CSE_ALifeObject* cast_alife_object()
{
    return 0;
}
virtual CSE_ALifeDynamicObject* cast_alife_dynamic_object()
{
    return 0;
}
virtual CSE_ALifeItemAmmo* cast_item_ammo()
{
    return 0;
}
virtual CSE_ALifeItemWeapon* cast_item_weapon()
{
    return 0;
}
virtual CSE_ALifeItemDetector* cast_item_detector()
{
    return 0;
}
virtual CSE_ALifeMonsterAbstract* cast_monster_abstract()
{
    return 0;
};
virtual CSE_ALifeHumanAbstract* cast_human_abstract()
{
    return 0;
};
virtual CSE_ALifeAnomalousZone* cast_anomalous_zone()
{
    return 0;
};
virtual CSE_ALifeTrader* cast_trader()
{
    return 0;
};

virtual CSE_ALifeCreatureAbstract* cast_creature_abstract()
{
    return 0;
};
virtual CSE_ALifeSmartZone* cast_smart_zone()
{
    return 0;
};
virtual CSE_ALifeOnlineOfflineGroup* cast_online_offline_group()
{
    return 0;
};
virtual CSE_ALifeItemPDA* cast_item_pda()
{
    return 0;
};

virtual void UPDATE_Read(NET_Packet& tNetPacket);
virtual void UPDATE_Write(NET_Packet& tNetPacket);
}
;
add_to_type_list(CSE_Abstract)
#define script_type_list save_type_list(CSE_Abstract)

#pragma warning(pop)
