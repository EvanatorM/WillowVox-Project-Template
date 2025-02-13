#pragma once

#include <WillowVox/WillowVox.h>
#include <WillowVox/core/EntryPoint.h>
#include <WillowVox/rendering/Camera.h>
#include <TemplateWorld.h>

using namespace WillowVox;

namespace TemplateProject
{
	class TemplateApp : public Application
	{
	public:
		TemplateApp()
		{
			_applicationName = "Template App";
			//_defaultWindowWidth = 1920; // Default window width
			//_defaultWindowHeight = 1080; // Default window height
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

			_camera = new Camera(_window);

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
	return new TemplateProject::TemplateApp();
}