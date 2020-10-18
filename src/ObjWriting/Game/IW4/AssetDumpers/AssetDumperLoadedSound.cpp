#include "AssetDumperLoadedSound.h"

#include "Sound/WavTypes.h"

using namespace IW4;

bool AssetDumperLoadedSound::ShouldDump(LoadedSound* asset)
{
    return true;
}

std::string AssetDumperLoadedSound::GetFileNameForAsset(Zone* zone, LoadedSound* asset)
{
    return "sound/" + std::string(asset->name);
}

void AssetDumperLoadedSound::DumpWavPcm(Zone* zone, LoadedSound* asset, FileAPI::File* out)
{
    const uint32_t riffMasterChunkSize = sizeof WAV_CHUNK_ID_RIFF
        + sizeof uint32_t
        + sizeof WAV_WAVE_ID
        + sizeof WavChunkHeader
        + sizeof WavFormatChunkPcm
        + sizeof WavChunkHeader
        + sizeof asset->sound.info.data_len;

    out->Write(&WAV_CHUNK_ID_RIFF, sizeof WAV_CHUNK_ID_RIFF, 1);
    out->Write(&riffMasterChunkSize, sizeof riffMasterChunkSize, 1);
    out->Write(&WAV_WAVE_ID, sizeof WAV_WAVE_ID, 1);

    const WavChunkHeader formatChunkHeader
    {
        WAV_CHUNK_ID_FMT,
        sizeof WavFormatChunkPcm
    };
    out->Write(&formatChunkHeader, sizeof formatChunkHeader, 1);

    WavFormatChunkPcm formatChunk
    {
        WavFormat::PCM,
        static_cast<uint16_t>(asset->sound.info.channels),
        asset->sound.info.rate,
        asset->sound.info.rate * asset->sound.info.channels * asset->sound.info.bits / 8,
        static_cast<uint16_t>(asset->sound.info.block_size),
        static_cast<uint16_t>(asset->sound.info.bits)
    };
    out->Write(&formatChunk, sizeof formatChunk, 1);

    const WavChunkHeader dataChunkHeader
    {
        WAV_CHUNK_ID_DATA,
        asset->sound.info.data_len
    };
    out->Write(&dataChunkHeader, sizeof dataChunkHeader, 1);
    out->Write(asset->sound.data, 1, asset->sound.info.data_len);
}

void AssetDumperLoadedSound::DumpAsset(Zone* zone, LoadedSound* asset, FileAPI::File* out)
{
    switch (static_cast<WavFormat>(asset->sound.info.format))
    {
    case WavFormat::PCM:
        DumpWavPcm(zone, asset, out);
        break;

    default:
        printf("Unknown format %i for loaded sound: %s\n", asset->sound.info.format, asset->name);
        break;
    }
}
