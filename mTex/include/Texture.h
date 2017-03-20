#ifndef MTEXTURE_H_
#define MTEXTURE_H_
/// @file Texture.h
/// @brief a simple texture wrapper
/// @author Ivans Saponenko
///
///


#include <string>

#ifdef __linux__

  // LAB build
  #include <ngl/Image.h>
  #include <GL/gl.h>

#else
{
// Mac build
//#include <OpenGL.h>
}
#endif


// Maxtextures idk why i need that
#define MAXTEXTURES 10

///
/// \brief The AbstractTexture class
///
///
class AbstractTexture
{
public:
  AbstractTexture() = default ;
  ~AbstractTexture() = default ;




  virtual bool loadImage(const std::string &_file) = 0;
  virtual bool deleteTexture() = 0;
  virtual void bindTexture() = 0;

private:


protected:

  GLuint m_texID;
  ngl::Image m_texImage;
  GLuint m_width, m_height;
  GLuint m_texType;
  std::string m_filePath;

};


///
/// \brief The SimpleTexture class
///
///
class SimpleTexture: public AbstractTexture
{
public:

  SimpleTexture() = default;
  SimpleTexture(std::string &_file);


  virtual bool loadImage(const std::string &_file) override;
  virtual bool deleteTexture() override;
  virtual void bindTexture() override;


  int a;
private:
  int ab;

};

class CompressedTexture: public AbstractTexture
{

public:

  virtual bool loadImage(const std::string &_file) override;
  virtual bool deleteTexture() override;
  virtual void bindTexture() override;

private:
  GLuint smth;
};


///
/// \brief The MultiTexture class
///
///
class MultiTexture: public AbstractTexture
{
public:
  virtual bool loadImage(const std::string &_file) override;
  virtual bool deleteTexture() override;
  virtual void bindTexture() override;

private:
  GLuint m_texNames[MAXTEXTURES];

};


#endif
//----------------------------------------------------------------------------------------------------------------------


