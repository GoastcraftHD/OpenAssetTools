#pragma once
#include "Zone/Zone.h"

class IZoneAssetLoaderState
{
protected:
    IZoneAssetLoaderState() = default;

public:
    virtual ~IZoneAssetLoaderState() = default;
    IZoneAssetLoaderState(const IZoneAssetLoaderState& other) = default;
    IZoneAssetLoaderState(IZoneAssetLoaderState&& other) noexcept = default;
    IZoneAssetLoaderState& operator=(const IZoneAssetLoaderState& other) = default;
    IZoneAssetLoaderState& operator=(IZoneAssetLoaderState&& other) noexcept = default;

    virtual void SetZone(Zone* zone)
    {
        // Do nothing by default
    }
};
