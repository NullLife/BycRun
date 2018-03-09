//
//  BycHeatmap.cpp
//  BycRun
//
//  Created by FengMap on 2017/12/30.
//  Copyright © 2017年 huaisukongshe@163.com. All rights reserved.
//

#include "BycHeatmap.h"

BycHeatmap::BycHeatmap() {
    _config._bgColor = Vec4(1.0, 1.0f, 1.0f, 1.0f);
    
    _config._gradients.push_back(BycHeatmap::Gradient(0.25f, Vec3(0, 0, 1)));
    _config._gradients.push_back(BycHeatmap::Gradient(0.55f, Vec3(0, 1, 0)));
    _config._gradients.push_back(BycHeatmap::Gradient(0.85f, Vec3(1, 0, 0)));
    
    _config._radius = 2.0f;
    _config._opacity = 0.0f;
    _config._minOpacity = 0.0f;
    _config._maxOpacity = 1.0f;
    _config._blur = 0.85f;
}


BycHeatmap::BycHeatmap(const Config& config) {
    _config = config;
}

BycHeatmap::~BycHeatmap() {
    _renderData.clear();
    _hotData.clear();
}

void BycHeatmap::addHot(const Hot& hot) {
    _hotData.push_back(hot);
}

void BycHeatmap::generate() {
    clear();
    prepareData();
}

void BycHeatmap::prepareData() {
    size_t len = _hotData.size();
    while (len--) {
        Hot hot = _hotData[len];
        
        hot._v = hot._v > 1.0f ? 1.0f : hot._v < 0.01f ? 0.01f : hot._v;
        
        _renderData.push_back(hot);
    }
}

void BycHeatmap::clear() {
    _renderData.clear();
}
