

#ifndef TEXTURE_H_
#define TEXTURE_H_
/// @file Texture.h
/// @brief a simple texture loader / GL texture object


#include <string>
#include <GL/gl.h>


#define MAXTEXTURES 10


class AbstractTexture:
{
public:
  Texture() = default;
  ~Texture() = default;



  virtual bool loadImage() = 0;
  virtual bool deleteTexture() = 0;
  virtual void bindTexture() = 0;



private:
  GLuint m_width, m_height;
  GLuint m_texType;
  GLbool m_multitex;



};

class simpleTexture: public AbstractTexture
{

};

class MultiTexture: public AbstractTexture


{
public:


private:
  GLuint m_texNames[MAXTEXTURES];

};




    #endif
//----------------------------------------------------------------------------------------------------------------------


