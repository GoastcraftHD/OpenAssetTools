#pragma once

// clang-format off: Order of includes matters here

// #include <d3d9.h>
#include "Game/IAsset.h"

#include "IW4_Assets.h"

// clang-format on

namespace IW4
{
    struct DB_AuthHash
    {
        char bytes[32];
    };

    struct DB_AuthSignature
    {
        char bytes[256];
    };

    struct DB_AuthSubHeader
    {
        char fastfileName[32];
        unsigned int reserved;
        DB_AuthHash masterBlockHashes[244];
    };

    struct DB_AuthHeader
    {
        char magic[8];                        // + 0
        unsigned int reserved;                // + 8
        DB_AuthHash subheaderHash;            // + 12
        DB_AuthSignature signedSubheaderHash; // + 44
        DB_AuthSubHeader subheader;           // + 300
    };

    struct ScriptStringList
    {
        int count;
        const char** strings;
    };

    struct XAsset
    {
        XAssetType type;
        XAssetHeader header;
    };

    struct XAssetList
    {
        ScriptStringList stringList;
        int assetCount;
        XAsset* assets;
    };

    struct cspField_t
    {
        const char* szName;
        int iOffset;
        int iFieldType;
    };

    enum csParseFieldType_t
    {
        CSPFT_STRING = 0,
        CSPFT_STRING_MAX_STRING_CHARS,
        CSPFT_STRING_MAX_QPATH,
        CSPFT_STRING_MAX_OSPATH,
        CSPFT_INT,
        CSPFT_QBOOLEAN,
        CSPFT_BOOL,
        CSPFT_FLOAT,
        CSPFT_MPH_TO_INCHES_PER_SEC,
        CSPFT_MILLISECONDS,
        CSPFT_FX,
        CSPFT_XMODEL,
        CSPFT_MATERIAL,
        CSPFT_PHYS_COLLMAP,
        CSPFT_SOUND,
        CSPFT_TRACER,

        CSPFT_NUM_BASE_FIELD_TYPES,
    };

    enum weapFieldType_t
    {
        WFT_WEAPONTYPE = CSPFT_NUM_BASE_FIELD_TYPES,
        WFT_WEAPONCLASS,
        WFT_OVERLAYRETICLE,
        WFT_PENETRATE_TYPE,
        WFT_IMPACT_TYPE,
        WFT_STANCE,
        WFT_PROJ_EXPLOSION,
        WFT_OFFHAND_CLASS,
        WFT_ANIMTYPE,
        WFT_ACTIVE_RETICLE_TYPE,
        WFT_GUIDED_MISSILE_TYPE,
        WFT_BOUNCE_SOUND,
        WFT_STICKINESS,
        WFT_OVERLAYINTERFACE,
        WFT_INVENTORYTYPE,
        WFT_FIRETYPE,
        WFT_AMMOCOUNTER_CLIPTYPE,
        WFT_ICONRATIO_HUD,
        WFT_ICONRATIO_PICKUP,
        WFT_ICONRATIO_AMMOCOUNTER,
        WFT_ICONRATIO_KILL,
        WFT_ICONRATIO_DPAD,
        WFT_HIDETAGS,
        WFT_NOTETRACKSOUNDMAP,
        WFT_NOTETRACKRUMBLEMAP,

        // Custom
        WFT_ANIM_NAME,

        WFT_NUM_FIELD_TYPES,
    };

    enum VehicleFieldType
    {
        VFT_TYPE = CSPFT_NUM_BASE_FIELD_TYPES,
        VFT_AXLE_STEERING,
        VFT_AXLE_POWER,
        VFT_AXLE_BRAKING,
        VFT_TROPHY_TAGS,

        VFT_NUM,
    };

    using AssetPhysPreset = Asset<ASSET_TYPE_PHYSPRESET, PhysPreset>;
    using AssetPhysCollMap = Asset<ASSET_TYPE_PHYSCOLLMAP, PhysCollmap>;
    using AssetXAnim = Asset<ASSET_TYPE_XANIMPARTS, XAnimParts>;
    using AssetXModelSurfs = Asset<ASSET_TYPE_XMODEL_SURFS, XModelSurfs>;
    using AssetXModel = Asset<ASSET_TYPE_XMODEL, XModel>;
    using AssetMaterial = Asset<ASSET_TYPE_MATERIAL, Material>;
    using AssetPixelShader = Asset<ASSET_TYPE_PIXELSHADER, MaterialPixelShader>;
    using AssetVertexShader = Asset<ASSET_TYPE_VERTEXSHADER, MaterialVertexShader>;
    using AssetVertexDecl = Asset<ASSET_TYPE_VERTEXDECL, MaterialVertexDeclaration>;
    using AssetTechniqueSet = Asset<ASSET_TYPE_TECHNIQUE_SET, MaterialTechniqueSet>;
    using AssetImage = Asset<ASSET_TYPE_IMAGE, GfxImage>;
    using AssetSound = Asset<ASSET_TYPE_SOUND, snd_alias_list_t>;
    using AssetSoundCurve = Asset<ASSET_TYPE_SOUND_CURVE, SndCurve>;
    using AssetLoadedSound = Asset<ASSET_TYPE_LOADED_SOUND, LoadedSound>;
    using AssetClipMapSp = Asset<ASSET_TYPE_CLIPMAP_SP, clipMap_t>;
    using AssetClipMapMp = Asset<ASSET_TYPE_CLIPMAP_MP, clipMap_t>;
    using AssetComWorld = Asset<ASSET_TYPE_COMWORLD, ComWorld>;
    using AssetGameWorldSp = Asset<ASSET_TYPE_GAMEWORLD_SP, GameWorldSp>;
    using AssetGameWorldMp = Asset<ASSET_TYPE_GAMEWORLD_MP, GameWorldMp>;
    using AssetMapEnts = Asset<ASSET_TYPE_MAP_ENTS, MapEnts>;
    using AssetFxWorld = Asset<ASSET_TYPE_FXWORLD, FxWorld>;
    using AssetGfxWorld = Asset<ASSET_TYPE_GFXWORLD, GfxWorld>;
    using AssetLightDef = Asset<ASSET_TYPE_LIGHT_DEF, GfxLightDef>;
    using AssetFont = Asset<ASSET_TYPE_FONT, Font_s>;
    using AssetMenuList = Asset<ASSET_TYPE_MENULIST, MenuList>;
    using AssetMenu = Asset<ASSET_TYPE_MENU, menuDef_t>;
    using AssetLocalize = Asset<ASSET_TYPE_LOCALIZE_ENTRY, LocalizeEntry>;
    using AssetWeapon = Asset<ASSET_TYPE_WEAPON, WeaponCompleteDef>;
    using AssetFx = Asset<ASSET_TYPE_FX, FxEffectDef>;
    using AssetImpactFx = Asset<ASSET_TYPE_IMPACT_FX, FxImpactTable>;
    using AssetRawFile = Asset<ASSET_TYPE_RAWFILE, RawFile>;
    using AssetStringTable = Asset<ASSET_TYPE_STRINGTABLE, StringTable>;
    using AssetLeaderboard = Asset<ASSET_TYPE_LEADERBOARD, LeaderboardDef>;
    using AssetStructuredDataDef = Asset<ASSET_TYPE_STRUCTURED_DATA_DEF, StructuredDataDefSet>;
    using AssetTracer = Asset<ASSET_TYPE_TRACER, TracerDef>;
    using AssetVehicle = Asset<ASSET_TYPE_VEHICLE, VehicleDef>;
    using AssetAddonMapEnts = Asset<ASSET_TYPE_ADDON_MAP_ENTS, AddonMapEnts>;
} // namespace IW4

DEFINE_ASSET_NAME_ACCESSOR(IW4::AssetPhysPreset, name);
DEFINE_ASSET_NAME_ACCESSOR(IW4::AssetPhysCollMap, name);
DEFINE_ASSET_NAME_ACCESSOR(IW4::AssetXAnim, name);
DEFINE_ASSET_NAME_ACCESSOR(IW4::AssetXModelSurfs, name);
DEFINE_ASSET_NAME_ACCESSOR(IW4::AssetXModel, name);
DEFINE_ASSET_NAME_ACCESSOR(IW4::AssetMaterial, info.name);
DEFINE_ASSET_NAME_ACCESSOR(IW4::AssetPixelShader, name);
DEFINE_ASSET_NAME_ACCESSOR(IW4::AssetVertexShader, name);
DEFINE_ASSET_NAME_ACCESSOR(IW4::AssetVertexDecl, name);
DEFINE_ASSET_NAME_ACCESSOR(IW4::AssetTechniqueSet, name);
DEFINE_ASSET_NAME_ACCESSOR(IW4::AssetImage, name);
DEFINE_ASSET_NAME_ACCESSOR(IW4::AssetSound, aliasName);
DEFINE_ASSET_NAME_ACCESSOR(IW4::AssetSoundCurve, filename);
DEFINE_ASSET_NAME_ACCESSOR(IW4::AssetLoadedSound, name);
DEFINE_ASSET_NAME_ACCESSOR(IW4::AssetClipMapSp, name);
DEFINE_ASSET_NAME_ACCESSOR(IW4::AssetClipMapMp, name);
DEFINE_ASSET_NAME_ACCESSOR(IW4::AssetComWorld, name);
DEFINE_ASSET_NAME_ACCESSOR(IW4::AssetGameWorldSp, name);
DEFINE_ASSET_NAME_ACCESSOR(IW4::AssetGameWorldMp, name);
DEFINE_ASSET_NAME_ACCESSOR(IW4::AssetMapEnts, name);
DEFINE_ASSET_NAME_ACCESSOR(IW4::AssetFxWorld, name);
DEFINE_ASSET_NAME_ACCESSOR(IW4::AssetGfxWorld, name);
DEFINE_ASSET_NAME_ACCESSOR(IW4::AssetLightDef, name);
DEFINE_ASSET_NAME_ACCESSOR(IW4::AssetFont, fontName);
DEFINE_ASSET_NAME_ACCESSOR(IW4::AssetMenuList, name);
DEFINE_ASSET_NAME_ACCESSOR(IW4::AssetMenu, window.name);
DEFINE_ASSET_NAME_ACCESSOR(IW4::AssetLocalize, name);
DEFINE_ASSET_NAME_ACCESSOR(IW4::AssetWeapon, szInternalName);
DEFINE_ASSET_NAME_ACCESSOR(IW4::AssetFx, name);
DEFINE_ASSET_NAME_ACCESSOR(IW4::AssetImpactFx, name);
DEFINE_ASSET_NAME_ACCESSOR(IW4::AssetRawFile, name);
DEFINE_ASSET_NAME_ACCESSOR(IW4::AssetStringTable, name);
DEFINE_ASSET_NAME_ACCESSOR(IW4::AssetLeaderboard, name);
DEFINE_ASSET_NAME_ACCESSOR(IW4::AssetStructuredDataDef, name);
DEFINE_ASSET_NAME_ACCESSOR(IW4::AssetTracer, name);
DEFINE_ASSET_NAME_ACCESSOR(IW4::AssetVehicle, name);
DEFINE_ASSET_NAME_ACCESSOR(IW4::AssetAddonMapEnts, name);
