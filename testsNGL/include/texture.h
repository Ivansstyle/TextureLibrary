

#ifndef TEXTURE_H_
#define TEXTURE_H_
/// @file Texture.h
/// @brief a simple texture loader / GL texture object


#include <string>
#include <GL/gl.h>


#define MAXTEXTURES 10


class AbstractTexture
{
public:
  AbstractTexture() = default ;
  ~AbstractTexture() = default ;



  virtual bool loadImage() = 0;
  virtual bool deleteTexture() = 0;
  virtual void bindTexture() = 0;



private:
  GLuint m_width, m_height;
  GLuint m_texType;
  bool m_multitex;



};

class SimpleTexture: public AbstractTexture
{
public:
 virtual bool loadImage() override;
 virtual bool deleteTexture() override;
 virtual void bindTexture() override;


  int a;
private:
  int ab;

};



class MultiTexture: public AbstractTexture
{
public:
  virtual bool loadImage() override;
  virtual bool deleteTexture() override;
  virtual void bindTexture() override;

private:
  GLuint m_texNames[MAXTEXTURES];

};




    #endif
//----------------------------------------------------------------------------------------------------------------------


