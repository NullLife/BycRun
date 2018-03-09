//
//  BycOBBApp.cpp
//  BycRun
//
//  Created by FengMap on 2018/1/21.
//  Copyright © 2018年 huaisukongshe@163.com. All rights reserved.
//

#include "./BycOBBApp.h"

#include "../../scene/BycSceneManager.h"
#include "../../scene/BycCamera.h"
#include "../../scene/BycCommponent.h"
#include "../../scene/BycEntity.h"

#include "../../render/BycMesh.h"
#include "../../render/BycMaterial.h"
#include "../../render/BycPass.h"
#include "../../render/BycGLShader.h"
#include "../../render/BycGLShaderParameters.h"

static String sBycResPath = "/Users/FengMap/projects/BycRun/BycRun/demos/resources";

BycOBBApp::BycOBBApp(const String& name) :
BycSuperApp(name) {
} 

BycOBBApp::~BycOBBApp() {
}

void BycOBBApp::initScene() {
    // Get or create commponent.
    BycCommponent* commp = _sceneManager->getCommponent("obb");
    
    // Create entities.
    BycEntity* entity = new BycEntity();
    // Add to the commponent.
    commp->addEntity(entity);
    
    entity->setName("test");
    
    // Create mesh data.
    BycMesh* mesh = new BycMesh();
    // Add mesh for the entity.
    entity->addMesh(mesh);
    
    BycMesh::VertexDeclaration decl(BycMesh::VertexPacketWrapping::CROSS);
    decl.addField(BycMesh::VertexPacketField::VERTEX_3F);
    mesh->setVertexDeclaration(decl);
    
    BycMesh::Vertices vertices;
    vertices.push_back(-1);vertices.push_back(1);vertices.push_back(0);
    vertices.push_back(-1);vertices.push_back(0);vertices.push_back(0);
    vertices.push_back(1);vertices.push_back(0);vertices.push_back(0);
    vertices.push_back(1);vertices.push_back(1);vertices.push_back(0);
    
    BycMesh::Indices indices;
    indices.push_back(0);indices.push_back(1);indices.push_back(2);
    indices.push_back(0);indices.push_back(2);indices.push_back(3);
    
    mesh->setVertices(vertices);
    mesh->setIndices(indices);
    
    // Create material.
    BycMaterial* mtl = new BycMaterial();
    entity->setMaterial(mtl);
    
    // Create pass.
    BycPass* pass = mtl->createPass("diffuseTex");
    
    // Vertex shader.
    BycGLShader* verShader = new BycGLShader(GL_VERTEX_SHADER, sBycResPath + "/shaders/base_vs.glsl");
    verShader->getParameters()->addUniformParameter(BycGLShaderParamField::FieldContent::MVP_MATRIX,
                                                    BycGLShaderParamField::FieldDataType::MATRIX_4X4);
    
    // Fragment shader.
    BycGLShader* fragShader = new BycGLShader(GL_FRAGMENT_SHADER, sBycResPath + "/shaders/base_fs.glsl");
    
    // Add shaders to pass.
    pass->addShader(verShader);
    pass->addShader(fragShader);
}

