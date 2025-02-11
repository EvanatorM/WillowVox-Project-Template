#pragma once

#include <WillowVox/WillowVox.h>
#include <WillowVox/math/NoiseSettings.h>
#include <WillowVox/world/TerrainGen.h>

using namespace WillowVox;

namespace TemplateGame {
    class TemplateWorld : public World
    {
    public:
        TemplateWorld(Camera* player)
        {
            m_mainCamera = player;

            _worldGen = new WorldGen();
            m_chunkManager = new ChunkManager(*_worldGen);
        }

        ~TemplateWorld()
        {
            delete _worldGen;
        }

    private:
        WorldGen* _worldGen;
    };
}