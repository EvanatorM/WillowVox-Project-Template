#pragma once

#include <WillowVox/WillowVox.h>
#include <WillowVox/core/EntryPoint.h>
#include <WillowVox/rendering/Camera.h>
#include <TemplateWorld.h>

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