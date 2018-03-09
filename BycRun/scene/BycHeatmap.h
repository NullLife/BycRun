//
//  BycHeatmap.h
//  BycRun
//
//  Created by FengMap on 2017/12/30.
//  Copyright © 2017年 huaisukongshe@163.com. All rights reserved.
//

#ifndef BycHeatmap_h
#define BycHeatmap_h

#include "../common/BycDefinitions.h"

class BycHeatmap {
public:
    struct Gradient {
    public:
        Gradient(float v, const Vec3& color) : _v(v), _color(color) {}
        
        float _v;
        Vec3 _color;
    };
    
    struct Config {
    public:
        ~Config() { _gradients.clear(); }
        
        Vec4 _bgColor;
        
        Vector<Gradient>_gradients;
        
        float _radius;
        
        // If set the opacity value, then the max opacity and min opacity will be replaced.
        float _opacity;
        float _maxOpacity;
        float _minOpacity;
        
        float _blur;
    };
    
    struct Hot {
        // Position
        Vec2 _pos;
        
        // Value [0.0-1.0]
        float _v;
        float _r;
        
    };
    
    typedef Vector<Hot> HotData;
    
    
public:
    BycHeatmap();
    BycHeatmap(const Config& config);
    ~BycHeatmap();
    
    void addHot(const Hot& hot);
    
    void generate();
    
private:
    
    void prepareData();
    
    void clear();
    
    void drawImage(int width, int height);
    
    void getColorPalette(Config& config);
    
private:
    Config _config;
    
    HotData _hotData;
    
    HotData _renderData;
};

#endif /* BycHeatmap_h */
