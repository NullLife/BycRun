//
//  BycSceneManager.h
//  BycRun
//
//  Created by FengMap on 2018/1/19.
//  Copyright © 2018年 huaisukongshe@163.com. All rights reserved.
//

#ifndef BycSceneManager_h
#define BycSceneManager_h

#include "BycLight.h"

class BycCamera;
class BycCommponent;
class BycEntity;
class BycSubEntity;

class BycParamsDataSource;
class BycGLTextureCache;
class BycGLRenderSystem;

class BycPointLight;
class BycDirectionalLight;
class BycSpotLight;

class BycSceneManager {
public:
    typedef HashMap<String, BycCommponent*> CommponentKV;
    typedef HashMap<String, BycCamera*> CameraKV;
    typedef Vector<BycLight*> LightArr;
    
    BycSceneManager();  
    virtual ~BycSceneManager();
    
    /// If it is not exit in scene, then will create it.
    BycCommponent* getCommponent(const String& name);
    bool destoryCommponent(const String& name);
    
    /// If it is not exit in scene, then will create it.
    BycCamera* getCamera(const String& name);
    bool destroyCamera(const String& name);
    
    /// Set current camera.
    void setCurrentCamera(BycCamera* camera);
    BycCamera* getCurrentCamera();
    
    /// Add Light to the scene.
    BycPointLight* addPointLight(const String& name);
    BycDirectionalLight* addDirectionalLight(const String& name);
    BycSpotLight* addSpotLight(const String& name);
    
    const LightArr& getLights() const;
    
    /// Set ambient light color.
    void setAmbientLightColor(const Vec4& ambientColor);
    const Vec4& getAmbientLightColor() const;
    
    BycParamsDataSource* getParamsDataSource();
    
    BycGLTextureCache* getGLTextureCache();
    
    void drawScene();
    
private:
    void destroyCommponentKV();
    void destroyCameraKV();
    
    void drawCommponent(BycCommponent* commp);
    void drawEntity(BycEntity* entity);
    void drawSubEntity(BycSubEntity* sub);
      
protected:  
    CommponentKV _commps;
    CameraKV _cameras;
    
    BycCamera* _currCamera;
    
    LightArr _lights;
    Vec4 _ambientColor;
    
    BycParamsDataSource* _parmsDS;
    BycGLTextureCache* _texCache;
    
    BycGLRenderSystem* _renderSystem;
};

#endif /* BycSceneManager_h */
