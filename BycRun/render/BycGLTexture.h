//
//  BycGLTexture.h
//  BycRun
//
//  Created by FengMap on 2018/1/22.
//  Copyright © 2018年 huaisukongshe@163.com. All rights reserved.
//

#ifndef BycGLTexture_h
#define BycGLTexture_h

#include "../common/BycDefinitions.h"

class BycGLTexture {
public:
    /// Texture type. (GL_TEXTURE_2D, GL_TEXTURE_CUBIC...)
    BycGLTexture(const String& name, GLenum texType = GL_TEXTURE_2D);
    ~BycGLTexture();
    
    const GLenum getType() const;
    
    const String& getName() const;
    
    const GLuint getId() const;
      
private:
    String _name;
    GLenum _type;
    GLuint _id;
};

#endif /* BycGLTexture_h */
