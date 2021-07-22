#pragma once

#include "Dumping/AbstractAssetDumper.h"
#include "Game/IW5/IW5.h"

namespace IW5
{
    class AssetDumperLoadedSound final : public AbstractAssetDumper<LoadedSound>
    {
        static void DumpWavPcm(AssetDumpingContext& context, const LoadedSound* asset, std::ostream& stream);
    protected:
        bool ShouldDump(XAssetInfo<LoadedSound>* asset) override;
        bool CanDumpAsRaw() override;
        std::string GetFileNameForAsset(Zone* zone, XAssetInfo<LoadedSound>* asset) override;
        void DumpRaw(AssetDumpingContext& context, XAssetInfo<LoadedSound>* asset, std::ostream& stream) override;
    };
}
