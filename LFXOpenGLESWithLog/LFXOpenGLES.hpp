#ifndef LFXOpenGLES_hpp
#define LFXOpenGLES_hpp

#include <iostream>
#include <string>

using std::string;

#include <OpenGL/glu.h>
#   include <OpenGL/OpenGL.h>
#   include <OpenGL/gl3.h>

//#ifdef __APPLE__
////! Apple iOS Header files for OpenGLES 3.0
//#    include <OpenGLES/ES3/gl.h>
//#    include <OpenGLES/ES3/glext.h>
////#define LOGI printf
////#define LOGE printf
//#elif __ANDROID__
////! Android Header files for NDK and OpenGLES 3.0
//#    include <jni.h>
//#    include <android/log.h>
//#    include <GLES3/gl3.h>
//#    include <GLES3/gl3ext.h>
//
////! JNI Information and Error Log
//#    define  LOG_TAG    "glOpenGLES3Native"
//#    define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG,__VA_ARGS__)
//#    define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
//#endif// End of __ANDROID__ scope


// works
//#define LogInfo(fmt, ...) printf("%s[%d]%s" fmt, __FILE__, __LINE__, __func__, ##   __VA_ARGS__)
#define LogTrace(fmt, ...)         printf("TRACE: %s: " fmt, __func__, ##   __VA_ARGS__)
#define LogInfo(fmt, ...)         printf("INFO: %s: " fmt, __func__, ##   __VA_ARGS__);printf("\n");
//#define LogDebug(fmt, ...)        printf("DEBUG: %s: " fmt, __func__, ##   __VA_ARGS__);printf("\n");

#define LogDebug(fmt, ...)        printf(fmt, ##   __VA_ARGS__);printf("\n");

//#define LogError(...)   fprintf(stderr, __VA_ARGS__)
#define LogError(fmt, ...)   fprintf(stderr, "ERROR: %s: " fmt, __func__, ##   __VA_ARGS__);printf("\n");
#define LogFatal(fmt, ...)   fprintf(stderr, "FATAL: %s: " fmt, __func__, ##   __VA_ARGS__)

//enum PrimitiveType
//{
//    PrimitiveTypePoint,
//    PrimitiveTypeLine,
//    PrimitiveTypeLineStrip,
//    PrimitiveTypeTriangle,
//    PrimitiveTypeTriangleStrip,
//};
//
//enum ShaderArgumentDataType
//{
//    ShaderArgumentDataTypeInteger,
//    ShaderArgumentDataTypeIntegerArray,
//    ShaderArgumentDataTypeFloat,
//    ShaderArgumentDataTypeFloatArray,
//    ShaderArgumentDataTypeVector2,
//    ShaderArgumentDataTypeVector2Array,
//    ShaderArgumentDataTypeVector3,
//    ShaderArgumentDataTypeVector3Array,
//    ShaderArgumentDataTypeVector4,
//    ShaderArgumentDataTypeVector4Array,
//    ShaderArgumentDataTypeMatrix2,
//    ShaderArgumentDataTypeMatrix2Array,
//    ShaderArgumentDataTypeMatrix3,
//    ShaderArgumentDataTypeMatrix3Array,
//    ShaderArgumentDataTypeMatrix4,
//    ShaderArgumentDataTypeMatrix4Array,
//    ShaderArgumentDataTypeSampler1D,
//    ShaderArgumentDataTypeSampler1DArray,
//    ShaderArgumentDataTypeSampler2D,
//    ShaderArgumentDataTypeSampler2DMultisample,
//    ShaderArgumentDataTypeSampler2DArray,
//    ShaderArgumentDataTypeSampler2DMultisampleArray,
//    ShaderArgumentDataTypeSamplerCube,
//    ShaderArgumentDataTypeSampler3D,
//};

enum GLESMacro {
    ClearBufferMask,
    LFXOpenGLESBoolean,
    BeginMode,
    Blend,
    TextureMagFilter,
    TextureMinFilter,
    TextureParameterName,
    TextureTarget,
    TextureUnit,
    GLESMacroTexture,
    BufferObjects,
    GLESMacroShaderDataType,
    GLESMacroDataType,
    CullFaceMode,
    DepthFunction,
    ErrorCode,
    LFXOpenGLESParamsName,
    GetTextureParameter,
    HintMode,
    HintTarget,
    GLESMacroPixelFormat,
    PixelType,
    LFXOpenGLESShaderType,
    StencilFunction,
    StencilOp,
    StringName,
    FramebufferObject
};
//
//class Vector3 {
//public:
//    float x, y;
//};
//
//class Vector4 {
//public:
//    float x, y;
//};
//
//extern size_t getShaderArgumentDataTypeSizeInByte(ShaderArgumentDataType type, int elementCount);
//
//extern GLenum toGLESType(ShaderArgumentDataType type);
//extern ShaderArgumentDataType toShaderArgumentDataType(GLenum type);
//
//extern GLint toGLESComponentCount(ShaderArgumentDataType type);
//
//extern std::string toLFXOpenGLESLiteral(GLESMacro type, GLint value);
//extern GLenum toGLESPrimitiveType(GI::PrimitiveType primitiveType);

enum GIBlendFactor {
    GIBlendFactorZero,
    GIBlendFactorOne,
    GIBlendFactorSourceColor,
    GIBlendFactorOneMinusSourceColor,
    GIBlendFactorSourceAlpha,
    GIBlendFactorOneMinusSourceAlpha,
    GIBlendFactorDestinationColor,
    GIBlendFactorOneMinusDestinationColor,
    GIBlendFactorDestinationAlpha,
    GIBlendFactorOneMinusDestinationAlpha,
    GIBlendFactorSourceAlphaSaturated,
    GIBlendFactorBlendColor,
    GIBlendFactorOneMinusBlendColor,
    GIBlendFactorBlendAlpha,
    GIBlendFactorOneMinusBlendAlpha,
    GIBlendFactorSource1Color,              //NS_AVAILABLE(10_12, 10_11) = 15,
    GIBlendFactorOneMinusSource1Color,      //NS_AVAILABLE(10_12, 10_11) = 16,
    GIBlendFactorSource1Alpha,              //NS_AVAILABLE(10_12, 10_11) = 17,
    GIBlendFactorOneMinusSource1Alpha,      //NS_AVAILABLE(10_12, 10_11) = 18,
};

enum GIBlendOperation {
    GIBlendOperationAdd = 0,
    GIBlendOperationSubtract = 1,
    GIBlendOperationReverseSubtract = 2,
    GIBlendOperationMin = 3,
    GIBlendOperationMax = 4,
};

/**
 * A string to help identify object.
 */
#define ConstStringRefLabel const std::string& label

/**
 * Wrapper for OpenGL ES, designed for no status calls, log function calls, parameter check.
 */
class LFXOpenGLES {
public:
    bool enableVerboseOutput = true;

#pragma mark - OpenGL ES 2.0

#pragma mark Texture

    const LFXOpenGLES &
    GenTextures(ConstStringRefLabel, GLsizei n, GLuint *textures) const;

    const LFXOpenGLES &
    BindTexture(ConstStringRefLabel, GLenum target, GLuint texture) const;

    const LFXOpenGLES &
    TexParameterf(ConstStringRefLabel, GLenum target, GLenum pname, GLfloat param) const;

    const LFXOpenGLES &
    TexParameterfv(ConstStringRefLabel, GLenum target, GLenum pname, const GLfloat *params) const;

    const LFXOpenGLES &
    TexParameteri(ConstStringRefLabel, GLenum target, GLenum pname, GLint param) const;

    const LFXOpenGLES &
    TexParameteriv(ConstStringRefLabel, GLenum target, GLenum pname, const GLint *params) const;

    const LFXOpenGLES &
    GetTexParameterfv(ConstStringRefLabel, GLenum target, GLenum pname, GLfloat *params) const;

    const LFXOpenGLES &
    GetTexParameteriv(ConstStringRefLabel, GLenum target, GLenum pname, GLint *params) const;

    const LFXOpenGLES &
    TexImage2D(ConstStringRefLabel, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels) const;

    const LFXOpenGLES &
    TexSubImage2D(ConstStringRefLabel, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels) const;

    const LFXOpenGLES &
    CompressedTexImage2D(ConstStringRefLabel, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data) const;

    const LFXOpenGLES &
    CompressedTexSubImage2D(ConstStringRefLabel, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data) const;

    const LFXOpenGLES &
    ActiveTexture(ConstStringRefLabel, GLenum &texture) const;

    const LFXOpenGLES &
    IsTexture(ConstStringRefLabel, GLuint texture, GLboolean &isTexture) const;

    const LFXOpenGLES &
    DeleteTextures(ConstStringRefLabel, GLsizei n, const GLuint *textures) const;

    const LFXOpenGLES &
    CopyTexImage2D(ConstStringRefLabel, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) const;

    const LFXOpenGLES &
    CopyTexSubImage2D(ConstStringRefLabel, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) const;

    const LFXOpenGLES &
    GenerateMipmap(ConstStringRefLabel, GLenum target) const;

#pragma mark Buffer

    const LFXOpenGLES &
    GenBuffers(ConstStringRefLabel, GLsizei n, GLuint *buffers);

    const LFXOpenGLES &
    BindBuffer(ConstStringRefLabel, GLenum target, GLuint buffer) const;

    const LFXOpenGLES &
    BufferData(ConstStringRefLabel, GLenum target, GLsizeiptr size, const GLvoid *data, GLenum usage);

    const LFXOpenGLES &
    BufferSubData(ConstStringRefLabel, GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid *data) const;

    const LFXOpenGLES &
    DeleteBuffers(ConstStringRefLabel, GLsizei n, const GLuint *buffers) const;

    const LFXOpenGLES &
    IsBuffer(ConstStringRefLabel, GLuint buffer) const;

    const LFXOpenGLES &
    GetBufferParameteriv(ConstStringRefLabel, GLenum target, GLenum pname, GLint *params) const;

#pragma mark Renderbuffer

    const LFXOpenGLES &
    BindRenderbuffer(ConstStringRefLabel, GLenum target, GLuint renderbuffer) const;

    const LFXOpenGLES &
    DeleteRenderbuffers(GLsizei n, const GLuint *renderbuffers) const;

    const LFXOpenGLES &
    GenRenderbuffers(GLsizei n, GLuint *renderbuffers) const;

    const LFXOpenGLES &
    RenderbufferStorage(ConstStringRefLabel, GLenum target, GLenum internalformat, GLsizei width, GLsizei height) const;

    const LFXOpenGLES &
    GetRenderbufferParameteriv(ConstStringRefLabel, GLenum target, GLenum pname, GLint *params) const;

    const LFXOpenGLES &
    IsRenderbuffer(ConstStringRefLabel, GLuint renderbuffer) const;

#pragma mark Framebuffer

    //todo: 日志
    const LFXOpenGLES &
    GenFramebuffers(ConstStringRefLabel, GLsizei n, GLuint *framebuffers) const;

    const LFXOpenGLES &
    BindFramebuffer(ConstStringRefLabel, GLenum target, GLuint framebuffer) const;

    const LFXOpenGLES &
    CheckFramebufferStatus(ConstStringRefLabel, GLenum target, GLenum &status) const;

    const LFXOpenGLES &
    DeleteFramebuffers(GLsizei n, const GLuint *framebuffers) const;

    const LFXOpenGLES &
    FramebufferRenderbuffer(ConstStringRefLabel,
            GLenum target,
            GLenum attachment,
            GLenum renderbuffertarget,
            GLuint renderbuffer) const;

    // todo: label应该在texture创建时调用，不应该在这
    const LFXOpenGLES &
    FramebufferTexture2D(ConstStringRefLabel,
            GLenum target,
            GLenum attachment,
            GLenum textarget,
            GLuint texture,
            GLint level) const;

    const LFXOpenGLES &
    GetFramebufferAttachmentParameteriv(ConstStringRefLabel,
            GLenum target,
            GLenum attachment,
            GLenum pname,
            GLint *params) const;

    const LFXOpenGLES &
    IsFramebuffer(ConstStringRefLabel, GLuint framebuffer) const;

    const LFXOpenGLES &
    ReadPixels(GLint x,
            GLint y,
            GLsizei width,
            GLsizei height,
            GLenum format,
            GLenum type,
            GLvoid *pixels) const;

    const LFXOpenGLES &
    Viewport(GLint x, GLint y, GLsizei width, GLsizei height) const;

#pragma mark shader

    const LFXOpenGLES &
    CreateShader(ConstStringRefLabel, GLenum shaderType, GLuint &shader) const;

    const LFXOpenGLES &
    ShaderSource(ConstStringRefLabel, GLuint shader, GLsizei count, const GLchar *const *string, const GLint *length) const;

    const LFXOpenGLES &
    GetShaderiv(ConstStringRefLabel, GLuint shader, GLenum pname, GLint *params) const;

    const LFXOpenGLES &
    GetShaderInfoLog(ConstStringRefLabel, GLuint shader, GLsizei bufsize, GLsizei *length, GLchar *log) const;

    const LFXOpenGLES &
    DeleteShader(ConstStringRefLabel, GLuint shader) const;

    const LFXOpenGLES &
    IsShader(ConstStringRefLabel, GLuint shader, GLboolean &isShader) const;

    const LFXOpenGLES &
    ShaderBinary(GLsizei n, const GLuint *shaders, GLenum binaryformat, const GLvoid *binary, GLsizei length) const;

    const LFXOpenGLES &
    GetShaderPrecisionFormat(ConstStringRefLabel,
            GLenum shadertype,
            GLenum precisiontype,
            GLint *range,
            GLint *precision) const;

#pragma mark Program

    const LFXOpenGLES &
    CreateProgram(ConstStringRefLabel, GLuint &program) const;

    const LFXOpenGLES &
    AttachShader(ConstStringRefLabel, GLuint program, GLuint shader) const;

    const LFXOpenGLES &
    LinkProgram(ConstStringRefLabel, GLuint program) const;

    const LFXOpenGLES &
    UseProgram(ConstStringRefLabel, GLuint program) const;

    const LFXOpenGLES &
    ValidateProgram(ConstStringRefLabel, GLuint program) const;

    const LFXOpenGLES &
    DeleteProgram(ConstStringRefLabel, GLuint program) const;

    const LFXOpenGLES &
    GetActiveAttrib(ConstStringRefLabel, GLuint program, GLuint index, GLsizei bufsize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) const;

    const LFXOpenGLES &
    GetActiveUniform(ConstStringRefLabel, GLuint program, GLuint index, GLsizei bufsize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) const;

    const LFXOpenGLES &
    GetAttachedShaders(ConstStringRefLabel, GLuint program, GLsizei maxcount, GLsizei *count, GLuint *shaders) const;

    const LFXOpenGLES &
    GetAttribLocation(ConstStringRefLabel, GLuint program, const GLchar *name, int &location) const;

    const LFXOpenGLES &
    GetProgramiv(ConstStringRefLabel, GLuint program, GLenum pname, GLint *params) const;

    const LFXOpenGLES &
    GetProgramInfoLog(ConstStringRefLabel, GLuint program, GLsizei bufsize, GLsizei *length, GLchar *infolog) const;

    const LFXOpenGLES &
    GetShaderSource(ConstStringRefLabel, GLuint shader, GLsizei bufsize, GLsizei *length, GLchar *source) const;

    const LFXOpenGLES &
    Uniform1f(GLint location, GLfloat x) const;

    const LFXOpenGLES &
    Uniform1fv(GLint location, GLsizei count, const GLfloat *v) const;

    const LFXOpenGLES &
    Uniform1i(ConstStringRefLabel, GLint location, GLint value) const;

    const LFXOpenGLES &
    Uniform1iv(const string &label, GLint location, GLsizei count, const GLint *v) const;

    const LFXOpenGLES &
    Uniform2f(GLint location, GLfloat x, GLfloat y) const;

    const LFXOpenGLES &
    Uniform2fv(GLint location, GLsizei count, const GLfloat *v) const;

    const LFXOpenGLES &
    Uniform2i(GLint location, GLint x, GLint y) const;

    const LFXOpenGLES &
    Uniform2iv(GLint location, GLsizei count, const GLint *v) const;

    const LFXOpenGLES &
    Uniform3f(GLint location, GLfloat x, GLfloat y, GLfloat z) const;

    const LFXOpenGLES &
    Uniform3fv(GLint location, GLsizei count, const GLfloat *v) const;

    const LFXOpenGLES &
    Uniform3i(GLint location, GLint x, GLint y, GLint z) const;

    const LFXOpenGLES &
    Uniform3iv(GLint location, GLsizei count, const GLint *v) const;

    const LFXOpenGLES &
    Uniform4f(GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w) const;

    const LFXOpenGLES &
    Uniform4fv(GLint location, GLsizei count, const GLfloat *v) const;

    const LFXOpenGLES &
    Uniform4i(GLint location, GLint x, GLint y, GLint z, GLint w) const;

    const LFXOpenGLES &
    Uniform4iv(GLint location, GLsizei count, const GLint *v) const;

    const LFXOpenGLES &
    UniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) const;

    const LFXOpenGLES &
    UniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) const;

    const LFXOpenGLES &
    UniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) const;

    const LFXOpenGLES &
    VertexAttrib1f(ConstStringRefLabel, GLuint indx, GLfloat x) const;

    const LFXOpenGLES &
    VertexAttrib1fv(ConstStringRefLabel, GLuint indx, const GLfloat *values) const;

    const LFXOpenGLES &
    VertexAttrib2f(ConstStringRefLabel, GLuint indx, GLfloat x, GLfloat y) const;

    const LFXOpenGLES &
    VertexAttrib2fv(ConstStringRefLabel, GLuint indx, const GLfloat *values) const;

    const LFXOpenGLES &
    VertexAttrib3f(ConstStringRefLabel, GLuint indx, GLfloat x, GLfloat y, GLfloat z) const;

    const LFXOpenGLES &
    VertexAttrib3fv(ConstStringRefLabel, GLuint indx, const GLfloat *values) const;

    const LFXOpenGLES &
    VertexAttrib4f(ConstStringRefLabel, GLuint indx, GLfloat x, GLfloat y, GLfloat z, GLfloat w) const;

    const LFXOpenGLES &
    VertexAttrib4fv(ConstStringRefLabel, GLuint indx, const GLfloat *values) const;

    const LFXOpenGLES &
    VertexAttribPointer(ConstStringRefLabel, GLuint location, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *ptr) const;

    const LFXOpenGLES &
    BindAttribLocation(ConstStringRefLabel, GLuint program, GLuint index, const GLchar *name) const;

    const LFXOpenGLES &
    CompileShader(ConstStringRefLabel, GLuint shader) const;

    const LFXOpenGLES &
    DetachShader(ConstStringRefLabel, GLuint program, GLuint shader) const;

    const LFXOpenGLES &
    GetUniformfv(ConstStringRefLabel, GLuint program, GLint location, GLfloat *params) const;

    const LFXOpenGLES &
    GetUniformiv(ConstStringRefLabel, GLuint program, GLint location, GLint *params) const;

    const LFXOpenGLES &
    GetUniformLocation(ConstStringRefLabel, GLuint program, const GLchar *name, int location) const;

    const LFXOpenGLES &
    GetVertexAttribfv(ConstStringRefLabel, GLuint index, GLenum pname, GLfloat *params) const;

    const LFXOpenGLES &
    GetVertexAttribiv(ConstStringRefLabel, GLuint index, GLenum pname, GLint *params) const;

    const LFXOpenGLES &
    GetVertexAttribPointerv(ConstStringRefLabel, GLuint index, GLenum pname, GLvoid **pointer) const;

    const LFXOpenGLES &
    IsProgram(ConstStringRefLabel, GLuint program, GLboolean &isProgram) const;

    const LFXOpenGLES &
    ReleaseShaderCompiler(void) const;

    const LFXOpenGLES &
    EnableVertexAttribArray(ConstStringRefLabel, GLuint location) const;

    const LFXOpenGLES &
    DisableVertexAttribArray(ConstStringRefLabel, GLuint index) const;

#pragma mark Blend

    const LFXOpenGLES &
    BlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) const;

    const LFXOpenGLES &
    BlendEquation(ConstStringRefLabel, GLenum mode) const;

    const LFXOpenGLES &
    BlendEquationSeparate(ConstStringRefLabel, GLenum modeRGB, GLenum modeAlpha) const;

    const LFXOpenGLES &
    BlendFunc(GLenum sfactor, GLenum dfactor) const;

    const LFXOpenGLES &
    BlendFuncSeparate(ConstStringRefLabel, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) const;

#pragma mark Clear

    const LFXOpenGLES &
    Clear(GLbitfield mask) const;

    const LFXOpenGLES &
    ClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) const;

    const LFXOpenGLES &
    ClearDepthf(GLclampf depth) const;

    const LFXOpenGLES &
    ClearStencil(GLint s) const;

    const LFXOpenGLES &
    ColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) const;

    const LFXOpenGLES &
    CullFace(ConstStringRefLabel, GLenum mode) const;

#pragma mark Draw

    const LFXOpenGLES &
    DepthFunc(ConstStringRefLabel, GLenum func) const;

    const LFXOpenGLES &
    DepthMask(GLboolean flag) const;

    const LFXOpenGLES &
    DepthRangef(GLclampf zNear, GLclampf zFar) const;

    const LFXOpenGLES &
    Disable(ConstStringRefLabel, GLenum cap) const;

    const LFXOpenGLES &
    DrawArrays(GLenum mode, GLint first, GLsizei count) const;

    const LFXOpenGLES &
    DrawElements(ConstStringRefLabel, GLenum mode, GLsizei count, GLenum type, const GLvoid *indices) const;

#pragma mark metrics

    //todo: cap转字符串
    const LFXOpenGLES &
    Enable(GLenum cap) const;

    const LFXOpenGLES &
    Finish(void) const;

    const LFXOpenGLES &
    Flush(void) const;

    const LFXOpenGLES &
    FrontFace(ConstStringRefLabel, GLenum mode) const;

    const LFXOpenGLES &
    GetBooleanv(ConstStringRefLabel, GLenum pname, GLboolean *params) const;

    const LFXOpenGLES &
    GetError(GLenum &error) const;

    const LFXOpenGLES &
    GetFloatv(ConstStringRefLabel, GLenum pname, GLfloat *params) const;

    const LFXOpenGLES &
    GetIntegerv(ConstStringRefLabel, GLenum pname, GLint *params) const;

    // todo: 测试是否有效
    const LFXOpenGLES &
    GetString(ConstStringRefLabel, GLenum name, const GLubyte *byte) const;

    const LFXOpenGLES &
    Hint(ConstStringRefLabel, GLenum target, GLenum mode) const;

    const LFXOpenGLES &
    IsEnabled(ConstStringRefLabel, GLenum cap) const;

    const LFXOpenGLES &
    LineWidth(GLfloat width) const;

    const LFXOpenGLES &
    PixelStorei(ConstStringRefLabel, GLenum pname, GLint param) const;

    const LFXOpenGLES &
    PolygonOffset(GLfloat factor, GLfloat units) const;

    const LFXOpenGLES &
    SampleCoverage(GLclampf value, GLboolean invert) const;

    const LFXOpenGLES &
    Scissor(GLint x, GLint y, GLsizei width, GLsizei height) const;

    const LFXOpenGLES &
    StencilFunc(ConstStringRefLabel, GLenum func, GLint ref, GLuint mask) const;

    const LFXOpenGLES &
    StencilFuncSeparate(ConstStringRefLabel, GLenum face, GLenum func, GLint ref, GLuint mask) const;

    const LFXOpenGLES &
    StencilMask(ConstStringRefLabel, GLuint mask) const;

    const LFXOpenGLES &
    StencilMaskSeparate(ConstStringRefLabel, GLenum face, GLuint mask) const;

    const LFXOpenGLES &
    StencilOp(ConstStringRefLabel, GLenum fail, GLenum zfail, GLenum zpass) const;

    const LFXOpenGLES &
    StencilOpSeparate(ConstStringRefLabel, GLenum face, GLenum fail, GLenum zfail, GLenum zpass) const;
};

extern const LFXOpenGLES gl;

#endif // LFXOpenGLES_hpp
