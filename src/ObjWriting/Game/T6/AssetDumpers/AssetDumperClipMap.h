#pragma once

#include "Dumping/AbstractAssetDumper.h"
#include "Game/T6/T6.h"

namespace T6
{
    class AssetDumperClipMap final : public AbstractAssetDumper<clipMap_t>
    {
    protected:
        bool ShouldDump(XAssetInfo<clipMap_t>* asset) override;
        void DumpAsset(AssetDumpingContext& context, XAssetInfo<clipMap_t>* asset) override;

    private:
        const std::string m_MapModelTemplate = "// entity {}\n"
                                               "{}\n"
                                               "\"origin\" \"{} {} {}\"\n"
                                               "\"angles\" \"{} {} {}\"\n"
                                               "\"modelscale\" \"{}\"\n"
                                               "\"model\" \"{}\"\n"
                                               "\"classname\" \"misc_model\"\n"
                                               "{}\n";
    };
} // namespace T6
