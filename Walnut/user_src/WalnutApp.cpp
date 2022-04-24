#pragma once
#include "TextWidget.h"

Walnut::Application* Walnut::CreateApplication(int argc, char** argv)
{
	ApplicationSpecification spec;
	spec.Name = "Text Editor";

	auto app = new Application(spec);
    app->PushLayer<TextWidget>(15);
	// TODO: Set menu menubarCallback
	return app;
}