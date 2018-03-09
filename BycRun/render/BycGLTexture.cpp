//
//  BycGLTexture.cpp
//  BycRun
//
//  Created by FengMap on 2018/1/22.
//  Copyright © 2018年 huaisukongshe@163.com. All rights reserved.
//

#include "BycGLTexture.h"

BycGLTexture::BycGLTexture(const String& name, GLenum type) :
_name(name),
_type(type) {
    glGenTextures(1, &_id);
}

BycGLTexture::~BycGLTexture() {
    glDeleteTextures(1, &_id);
}

const String& BycGLTexture::getName() const {
    return _name;
}

const GLenum BycGLTexture::getType() const {
    return _type;
}

const GLuint BycGLTexture::getId() const {
    return _id;
}
