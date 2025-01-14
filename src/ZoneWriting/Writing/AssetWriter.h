#pragma once

#include "ContentWriterBase.h"
#include "Pool/XAssetInfo.h"
#include "Utils/ClassUtils.h"
#include "Zone/Zone.h"
#include "Zone/ZoneTypes.h"

class AssetWriter : public ContentWriterBase
{
protected:
    AssetWriter(XAssetInfoGeneric* asset, const Zone& zone, IZoneOutputStream& stream);

    _NODISCARD scr_string_t UseScriptString(scr_string_t scrString) const;
    void WriteScriptStringArray(bool atStreamStart, size_t count);

    XAssetInfoGeneric* m_asset;

    scr_string_t* varScriptString;
    scr_string_t* varScriptStringWritten;
};
