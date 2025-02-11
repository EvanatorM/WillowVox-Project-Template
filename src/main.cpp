#pragma once

#include <WillowVox/core/Application.h>
#include <WillowVox/rendering/Mesh.h>
#include <WillowVox/rendering/BaseMaterial.h>
#include <WillowVox/rendering/Camera.h>
#include <WillowVox/rendering/Texture.h>
#include <WillowVox/core/EntryPoint.h>
#include <WillowVox/core/Logger.h>
#include <WillowVox/rendering/engine-default/TextureMaterial.h>
#include <WillowVox/rendering/engine-default/Vertex.h>
#include <WillowVox/rendering/engine-default/ChunkVertex.h>
#include <WillowVox/rendering/engine-default/ChunkSolidMaterial.h>
#include <WillowVox/rendering/engine-default/TextureMaterial.h>
#include <WillowVox/physics/Physics.h>
#include <WillowVox/resources/Blocks.h>
#include <TemplateWorld.h>
#include <imgui/imgui.h>
#include <cstdint>

using namespace WillowVox;

namespace TemplateGame
{
	class TestGameApp : public Application
	{
	public:
		TestGameApp()
		{
			_applicationName = "Template Game";
			_defaultWindowWidth = 1920;
			_defaultWindowHeight = 1080;
		}

		void LoadAssets() override
		{

		}

		void RegisterBlocks() override
		{

		}

		void Start() override
		{
			_renderingAPI->SetCullFace(true);
			_renderingAPI->SetDepthTest(true);

			_camera = new WillowVox::Camera(_window);

			m_world = new TemplateWorld(_camera);
		}

		void Update() override
		{

		}

		void Render() override
		{
			
		}

		void ConfigurePostProcessing() override
		{
			
		}

		void RenderUI() override
		{
			
		}

	private:
		Camera* _camera;
	};
}


WillowVox::Application* WillowVox::CreateApplication()
{
	return new TemplateGame::TestGameApp();
}