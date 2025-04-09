#include "AssetDumperClipMap.h"

#pragma warning(push, 0)
#include <Eigen>
#pragma warning(pop)

#include <format>

using namespace T6;

bool AssetDumperClipMap::ShouldDump(XAssetInfo<clipMap_t>* asset)
{
    return true;
}

void AssetDumperClipMap::DumpAsset(AssetDumpingContext& context, XAssetInfo<clipMap_t>* asset)
{
    const auto* clipMap = asset->Asset();
    const auto clipMapFile = context.OpenAssetFile(std::format("{}.clip", clipMap->name));

    if (!clipMapFile)
        return;

    auto& stream = *clipMapFile;

    for (auto i = 0; i < clipMap->numStaticModels; i++)
    {
        const cStaticModel_s& staticModel = clipMap->staticModelList[i];

        float rotX = std::atan2(staticModel.invScaledAxis[2].y, staticModel.invScaledAxis[2].z);
        float rotY = std::asin(-staticModel.invScaledAxis[2].x);
        float rotZ = std::atan2(staticModel.invScaledAxis[1].x, staticModel.invScaledAxis[0].x);

        // Convert radians to degrees
        rotX *= 180 / EIGEN_PI;
        rotY *= 180 / EIGEN_PI;
        rotZ *= 180 / EIGEN_PI;

        // Scale is uniform, so no need to calculate the other axis
        float scale = Eigen::Vector3f(staticModel.invScaledAxis[0].x, staticModel.invScaledAxis[0].y, staticModel.invScaledAxis[0].z).norm();

        std::string mapModel =
            std::vformat(m_MapModelTemplate,
                         std::make_format_args(
                             i, "{", staticModel.origin.x, staticModel.origin.y, staticModel.origin.z, rotX, rotY, rotZ, scale, staticModel.xmodel->name, "}"));

        stream.write(mapModel.c_str(), mapModel.size());
    }
}
