//
//  BycHeatMapApp.h
//  BycRun
//
//  Created by FengMap on 2017/12/29.
//  Copyright © 2017年 huaisukongshe@163.com. All rights reserved.
//

#ifndef BycHeatMapApp_h
#define BycHeatMapApp_h

#include "../../app/BycApp.h"

class HeatMapApp : public BycApp, public BycMouseClikEvent {
public:
    HeatMapApp(const String& name, int width = 800, int height = 600);
    ~HeatMapApp();
    
    virtual void initScene();
    virtual void onMouseClick(int btnType, double x, double y);
};

#endif /* BycHeatMapApp_h */
