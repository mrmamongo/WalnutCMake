//
// Created by MrMam on 25.04.2022.
//

#pragma once
#include <Application.h>

class TextWidget : public Walnut::Layer {
private:
    std::vector<std::string> _strings{};
public:
    void OnUIRender() override;
    explicit TextWidget(int lines);
};
