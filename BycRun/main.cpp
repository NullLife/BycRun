//
//  main.cpp
//  BycRun
//
//  Created by FengMap on 2017/12/26.
//  Copyright © 2017年 huaisukongshe@163.com. All rights reserved.
//

#include "./demos/deferred/BycDeferredLightApp.h"
#include "./demos/math/BycOBBApp.h"

int main(int argc, const char * argv[]) {
    BycDeferredLightApp app("deferred");
    app.running();
    return 0;
}
