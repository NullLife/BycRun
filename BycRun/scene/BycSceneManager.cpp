//
//  BycSceneManager.cpp
//  BycRun
//
//  Created by FengMap on 2018/1/19.
//  Copyright © 2018年 huaisukongshe@163.com. All rights reserved.
//

#include "./BycSceneManager.h"

#include "./BycCamera.h"
#include "./BycParamsDataSource.h"

#include "./BycCommponent.h"
#include "./BycEntity.h"

#include "./BycPointLight.h"
#include "./BycDirectionalLight.h"
#include "./BycSpotLight.h"

#include "../render/BycGLRenderSystem.h"
#include "../render/BycMaterial.h"
#include "../render/BycPass.h"
#include "../render/BycGLTextureCache.h"

BycSceneManager::BycSceneManager() : _currCamera(nullptr), _ambientColor(Vec4(1.0f)) {
    _renderSystem = new BycGLRenderSystem(this);
    
    _parmsDS = new BycParamsDataSource();
    _texCache = new BycGLTextureCache();
}

BycSceneManager::~BycSceneManager() {
    destroyCommponentKV();
    destroyCameraKV();
    
    _currCamera = nullptr;
    
    delete _renderSystem;
    _renderSystem = nullptr;
    
    delete _parmsDS;
    _parmsDS = nullptr;
    
    delete _texCache;
    _texCache = nullptr;
}

BycParamsDataSource* BycSceneManager::getParamsDataSource() {
    return _parmsDS;
}

BycGLTextureCache* BycSceneManager::getGLTextureCache() {
    return _texCache;
}

BycCommponent* BycSceneManager::getCommponent(const String& name) {
    auto iter = _commps.find(name);
    if (iter != _commps.end())
        return iter->second;
    
    // Create it.
    BycCommponent* commp = new BycCommponent(name);
    _commps.insert(CommponentKV::value_type(name, commp));
    return commp;
}

bool BycSceneManager::destoryCommponent(const String& name) {
    auto iter = _commps.find(name);
    if (iter == _commps.end())
        return false;
    
    delete iter->second;
    _commps.erase(iter);
    return true;
}

BycCamera* BycSceneManager::getCamera(const String& name) {
    auto iter = _cameras.find(name);
    if (iter != _cameras.end())
        return iter->second;
    
    // Create it.
    BycCamera* cam = new BycCamera(name);
    _cameras.insert(CameraKV::value_type(name, cam));
    return cam;
}

bool BycSceneManager::destroyCamera(const String& name) {
    auto iter = _cameras.find(name);
    if (iter == _cameras.end())
        return false;
    
    delete iter->second;
    _cameras.erase(iter);
    return true;
}

void BycSceneManager::setCurrentCamera(BycCamera* camera) {
    _currCamera = camera;
}

BycCamera* BycSceneManager::getCurrentCamera() {
    return _currCamera;
}

BycPointLight* BycSceneManager::addPointLight(const String& name) {
    for (BycLight* light : _lights) {
        if (light->getLightType() == BycLight::LightType::POINT && light->getName() == name) {
            assert(false);
        }
    }
    BycPointLight* light = new BycPointLight(name);
    _lights.push_back(light);
    return light;
}

BycDirectionalLight* BycSceneManager::addDirectionalLight(const String& name) {
    for (BycLight* light : _lights) {
        if (light->getLightType() == BycLight::LightType::DIRECTION && light->getName() == name) {
            assert(false);
        }
    }
    BycDirectionalLight* light = new BycDirectionalLight(name);
    _lights.push_back(light);
    return light;
}

BycSpotLight* BycSceneManager::addSpotLight(const String& name) {
    for (BycLight* light : _lights) {
        if (light->getLightType() == BycLight::LightType::SPOT && light->getName() == name) {
            assert(false);
        }
    }
    BycSpotLight* light = new BycSpotLight(name);
    _lights.push_back(light);
    return light;
}

const LightArr& BycSceneManager::getLights() const {
    return _lights;
}

void BycSceneManager::setAmbientLightColor(const Vec4& ambientColor) {
    _ambientColor = ambientColor;
}

const Vec4& BycSceneManager::getAmbientLightColor() const {
    return _ambientColor;
}

void BycSceneManager::destroyCommponentKV() {
    auto iter = _commps.begin();
    for (; iter!= _commps.end(); ++iter) {
        delete iter->second;
        _commps.erase(iter);
    }
}

void BycSceneManager::destroyCameraKV() {
    auto iter = _cameras.begin();
    for (; iter!= _cameras.end(); ++iter) {
        delete iter->second;
        _cameras.erase(iter);
    }
}

void BycSceneManager::drawScene() {
    glEnable(GL_PROGRAM_POINT_SIZE);
    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_ALPHA_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    for (CommponentKV::value_type& pair : _commps) {
        drawCommponent(pair.second);
    }
}

void BycSceneManager::drawCommponent(BycCommponent* commp) {
    for (BycEntity* entity : commp->_entities) {
        drawEntity(entity);
    }
}

void BycSceneManager::drawEntity(BycEntity* entity) {
    for (BycSubEntity* sub : entity->getSubEntityArray()) {
        drawSubEntity(sub);
    }
}

void BycSceneManager::drawSubEntity(BycSubEntity* sub) {
    // Set uniforms data.
    _parmsDS->setModelMatrix(sub->getModelMatrix());
    _parmsDS->setCurrentCamera(_currCamera);
        
    // Get material.
    BycMaterial* mtl = sub->getMaterial();
    if (mtl == nullptr)
        mtl = sub->getParent()->getMaterial();
    
    BycPass* pass = mtl->getPass(0);
    
    pass->updateGLShaderParameters(_parmsDS);
    
    _renderSystem->_usePass(pass);
    
    sub->commitData();
    sub->bindData();
    
    BycRenderOpt opt;
    sub->getRenderOpt(opt);

    _renderSystem->draw(opt, pass);
}


