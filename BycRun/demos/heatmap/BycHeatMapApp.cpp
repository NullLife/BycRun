//
//  BycHeatMapApp.cpp
//  BycRun
//
//  Created by FengMap on 2017/12/29.
//  Copyright © 2017年 huaisukongshe@163.com. All rights reserved.
//

#include "BycHeatMapApp.h"

HeatMapApp::HeatMapApp(const String& name, int width, int height) :
BycApp(name, width, height)
{
    _window->setMouseClickEvent(this);
}

HeatMapApp::~HeatMapApp()
{
}

void HeatMapApp::initScene() {
    
}

void HeatMapApp::onMouseClick(int btnType, double x, double y)
{
    if (btnType == MOUSE_BUTTON_RIGHT)
    {
        printf("HeatMapApp Click: [%f, %f]\n", x, y);
    }
}
