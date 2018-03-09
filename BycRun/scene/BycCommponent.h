//
//  BycCommponent.h
//  BycRun
//
//  Created by FengMap on 2018/1/19.
//  Copyright © 2018年 huaisukongshe@163.com. All rights reserved.
//

#ifndef BycCommponent_h
#define BycCommponent_h

#include "../common/BycDefinitions.h"

class BycEntity;
class BycSceneManager;

class BycCommponent {
    friend class BycSceneManager;
public:
    typedef Vector<BycEntity*> EntityArr;
    
    const String& getUniqueName() const;
    
    virtual unsigned int addEntity(BycEntity* entity);
    virtual BycEntity* removeEntity(unsigned int index);
    virtual bool removeEntity(BycEntity* entity);
    virtual bool destroyEntity(unsigned int index);
    virtual bool destroyEntity(BycEntity* entity);
    
    void clearEntities();
      
protected:
    BycCommponent(const String& name);
    virtual ~BycCommponent();
    
    String _name;
    EntityArr _entities;
};

#endif /* BycCommponent_h */
