#ifndef MTEXTURE_H_
#define MTEXTURE_H_
/// @file Texture.h
/// @brief a simple texture wrapper
/// @author Ivans Saponenko
///
///

#include <string>
// has to be included before gl because of glew
#include <ngl/Image.h>

// GL includes
#ifdef __linux__

  // LAB build
  #include <GL/gl.h>

#else
{
// Mac build
#include <OpenGL.h>
}
#endif

// NGL Includes

// Maxtextures idk why i need that
#define MAXTEXTURES 10

///
///
/// @class AbstractTexture
/// \brief The AbstractTexture class, wraps different texture types
/// to work with management class
///
///
class AbstractTexture
{
public:
  AbstractTexture() = default ;
  ~AbstractTexture() = default ;
  virtual bool operator==(const AbstractTexture& other) = 0;
  virtual bool operator!=(const AbstractTexture& other) = 0;



  virtual bool loadImage(const std::string &_file) = 0;
  virtual bool deleteTexture() = 0;
  virtual void bindTexture() = 0;


private:


protected:
  int m_ID;
  bool m_createdFlag;
  GLuint m_glTexID;
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
  SimpleTexture(const std::string &_file);
  bool operator==(const SimpleTexture& other) override;
  bool operator!=(const SimpleTexture& other) override;


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

   CompressedTexture(const std::string &_file);
  bool operator==(const CompressedTexture& other) override;
  bool operator!=(const CompressedTexture& other) ;
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

   MultiTexture(const std::string &_file);
   bool operator==(const MultiTexture& other) override;
   bool operator!=(const MultiTexture& other) override;

  virtual bool deleteTexture() override;
  virtual void bindTexture() override;

private:
  virtual bool loadImage(const std::string &_file) override;
  GLuint m_texNames[MAXTEXTURES];

};


#endif
//----------------------------------------------------------------------------------------------------------------------


