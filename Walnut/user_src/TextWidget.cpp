//
// Created by MrMam on 25.04.2022.
//

#include "TextWidget.h"

void TextWidget::OnUIRender() {
    ImGui::Begin("##1");
    ImGui::InputTextMultiline("##2", _strings.front().data(), 15, ImVec2(1200,800));
    ImGui::End();
}

TextWidget::TextWidget(int lines): _strings(lines, "\n") {}
