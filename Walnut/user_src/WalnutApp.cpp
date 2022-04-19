#pragma once
#include <iostream>

#include <Application.h>
#include <Image.h>

class ExampleLayer : public Walnut::Layer
{
private:
    Walnut::Application* app;
public:
    ExampleLayer(Walnut::Application* app) {
        app = app;
    }

	void OnAttach() override {
		std::cout << "OnAttach\n";
	}

	void OnUIRender() override
    {
	}
};

class TextLayer : public Walnut::Layer {
private:
    std::string label{};
public:
    void OnAttach() override {
        label = "Attached!";
    }
    void OnUIRender() override {
        ImGui::Begin("Redactor");
        ImGui::TextUnformatted(label.data());
        if (ImGui::Button("Press me")) {
            label = "Button pew pew! " + std::to_string(rand()%100);
        }
        ImGui::End();
    }
};

Walnut::Application* Walnut::CreateApplication(int argc, char** argv)
{
	ApplicationSpecification spec;
	spec.Name = "Walnut Example";

	auto app = new Application(spec);
    auto exit_layer = std::make_shared<ExampleLayer>(app);
    auto text_layer = std::make_shared<TextLayer>();
    app->PushLayer(exit_layer);
    app->PushLayer(text_layer);
	app->SetMenubarCallback([app]()
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Exit"))
			{
				app->Close();
			}
			ImGui::EndMenu();
		}
	});
	return app;
}