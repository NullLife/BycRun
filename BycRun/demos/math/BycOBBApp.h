//
//  BycOBBApp.h
//  BycRun
//
//  Created by FengMap on 2018/1/21.
//  Copyright © 2018年 huaisukongshe@163.com. All rights reserved.
//

#ifndef BycOBBApp_h
#define BycOBBApp_h

#include "../BycSuperApp.h"

class BycOBBApp : public BycSuperApp {
public:
    BycOBBApp(const String& name);
    ~BycOBBApp();
private:
     void initScene();
};

#endif /* BycOBBApp_h */
