//
//  main.cpp
//  WrapperDemo
//
//  Created by michael on 25/05/2018.
//  Copyright © 2018 michael.laifx. All rights reserved.
//

#include <iostream>
#include <OpenGL/gl3.h>
#include "LFXOpenGLES.hpp"

static const char *kTextureSamplerNameString = "inputImageTexture1";

static const char *kPassThroughVertexShaderString = R"(
attribute vec3 attPosition;
attribute vec2 attUV;
varying vec2   textureCoordinate;
void main(void) {
    gl_Position = vec4(attPosition, 1.);
    textureCoordinate = attUV;
}
)";

static const char *kPassThroughFragmentShaderString = R"( precision highp float;
uniform sampler2D inputImageTexture1;
varying vec2 textureCoordinate;

void main() {
    gl_FragColor = texture2D(inputImageTexture1, textureCoordinate);
}
)";

int main(int argc, const char *argv[]) {
    auto label = "ParticleVertexShader";
    GLuint program;
    GLuint vShader;
    GLboolean isVShader;
    GLuint fShader;
    GLboolean isFShader;
    GLuint bufferSize = 1024;
    GLchar infolog[1024];
    GLint param;
    GLenum gl_enum;
    const GLint *params;
//    gl.CreateShader(label, GL_VERTEX_SHADER, vShader)
//            .ShaderSource(label, vShader, 1, &kPassThroughVertexShaderString, nullptr)
//            .CompileShader(label, vShader)
//            .GetShaderInfoLog(label, vShader, bufferSize, nullptr, infolog)
//            .GetShaderiv(label, vShader, GL_COMPILE_STATUS, &param)
//            .DeleteShader(label, vShader)
//        .IsShader(label, vShader, isVShader)
//        .ShaderBinary(1, &vShader, GL_SHADER_BINARY_FORMATS, nullptr, 0)
//        .ReleaseShaderCompiler()
//            ;

//
//    gl.CreateProgram(label, program)
//            .AttachShader(label, program, vShader)
//            .AttachShader(label, program, fShader)
//            .LinkProgram(label, program)
//            .GetProgramInfoLog(label, program, bufferSize, nullptr, infolog);

#pragma mark VertexAttrib
    GLfloat *fValues = nullptr;
    GLint *iValues = nullptr;
    gl.VertexAttrib4fv(label, 0, fValues)
            .VertexAttrib3fv(label, 0, fValues)
            .VertexAttrib2fv(label, 0, fValues)
            .VertexAttrib1fv(label, 0, fValues)
            .VertexAttrib4f(label, 0, 1, 2, 3, 4)
            .VertexAttrib3f(label, 0, 1, 2, 3)
            .VertexAttrib2f(label, 0, 1, 2)
            .VertexAttrib1f(label, 0, 1);
            .VertexAttrib1f(label, 0, 1)
#pragma mark Uniform
            .Uniform1fv(label, 0, 0, fValues)
            .Uniform2fv(label, 0, 0, fValues)
            .Uniform3fv(label, 0, 0, fValues)
            .Uniform4fv(label, 0, 0, fValues)
            .Uniform1iv(label, 0, 0, iValues)
            .Uniform2iv(label, 0, 0, iValues)
            .Uniform3iv(label, 0, 0, iValues)
            .Uniform4iv(label, 0, 0, iValues)
            .Uniform1i(label, 0, 0)
            .Uniform2i(label, 0, 0, 0)
            .Uniform3i(label, 0, 0, 0, 0)
            .Uniform4i(label, 0, 0, 0, 0, 0)
            .Uniform1f(label, 0, 0.f)
            .Uniform2f(label, 0, 0.f, 0.f)
            .Uniform3f(label, 0, 0.f, 0.f, 0.f)
            .Uniform4f(label, 0, 0.f, 0.f, 0.f, 0.f)
            .UniformMatrix2fv(label, 0, 1, GL_FALSE, fValues)
            .UniformMatrix3fv(label, 0, 1, GL_FALSE, fValues)
            .UniformMatrix4fv(label, 0, 1, GL_FALSE, fValues)
            .GetUniformLocation(<#const string & label#>, <#GLuint program#>, <#const GLchar* name#>, <#int location#>)
            ;
#pragma mark Stencil
      gl.StencilOpSeparate(label, 1, 2, 3, 4)
    .StencilOp(label, 1, 2, 3)
    .StencilMaskSeparate(label, 1, 2)
    .StencilMask(label, 1)
    .StencilFuncSeparate(label, 1, 2, 3, 4);

    return 0;
}
