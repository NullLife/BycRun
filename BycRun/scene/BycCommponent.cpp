//
//  BycCommponent.cpp
//  BycRun
//
//  Created by FengMap on 2018/1/19.
//  Copyright © 2018年 huaisukongshe@163.com. All rights reserved.
//

#include "./BycCommponent.h"
#include "./BycEntity.h"

BycCommponent::BycCommponent(const String& name) : _name(name) {

}

BycCommponent::~BycCommponent() {
    clearEntities();
}

const String& BycCommponent::getUniqueName() const {
    return _name;
}

unsigned int BycCommponent::addEntity(BycEntity *entity) {
    unsigned int index = (unsigned int) _entities.size();
    _entities.push_back(entity);
    return index;
}


BycEntity *BycCommponent::removeEntity(unsigned int index) {
    assert(index >=0 && index < _entities.size());
    return *_entities.erase(_entities.begin() + index);
}


bool BycCommponent::removeEntity(BycEntity *entity) { 
    EntityArr::iterator iter = std::find(_entities.begin(), _entities.end(), entity);
    if (iter == _entities.end())
        return false;
    
    _entities.erase(iter);
    
    return true;
}


bool BycCommponent::destroyEntity(unsigned int index) {
    BycEntity *e = removeEntity(index);
    delete e;
    e = nullptr;
    return true;
}


bool BycCommponent::destroyEntity(BycEntity *entity) {
    if (!removeEntity(entity))
        return false;
    
    delete entity;
    entity = nullptr;
    
    return true;
}

void BycCommponent::clearEntities() {
    _entities.clear();
    _entities.shrink_to_fit();
}

