#include "Texture.h"

// --------------------------------------------------------
// SimpleTexture methods
// --------------------------------------------------------
SimpleTexture::SimpleTexture(const std::string &_file)
{
  m_texImage.load(_file);
  m_width = m_texImage.width();
  m_height = m_texImage.height();
}

bool SimpleTexture::operator==(const SimpleTexture& other)
{
  if(m_ID == other.m_ID) return true;
  else return false;
}

bool SimpleTexture::operator!=(const SimpleTexture& other)
{
  if(m_ID != other.m_ID) return true;
  else return false;
}



void SimpleTexture::bindTexture()
{
  glGenTextures(1, &m_glTexID);
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, m_glTexID); // THIS IS WRONG
  glTexImage2D(GL_TEXTURE_2D, 0, m_texImage.format(),
               m_width, m_height, 0, m_texImage.format(),
               GL_UNSIGNED_BYTE, m_texImage.getPixels());

  glGenerateMipmap(GL_TEXTURE_2D);


}
bool SimpleTexture::deleteTexture()
{

//    m_width=m_image.width();
//    m_height=m_image.height();
//    m_channels=m_image.channels();
//    m_format=m_image.format();
}

bool SimpleTexture::loadImage(const std::string &_file)
{
  m_texImage.load(_file);
  m_height = m_texImage.height();
  m_width = m_texImage.width();
}


// --------------------------------------------------------
// MultiTexture Methods
// --------------------------------------------------------

bool MultiTexture::operator==(const MultiTexture& other)
{
  if(m_ID == other.m_ID) return true;
  else return false;
}

bool MultiTexture::operator!=(const MultiTexture& other)
{
  if(m_ID != other.m_ID) return true;
  else return false;
}



MultiTexture::MultiTexture(const std::string &_file)
{
  m_texImage.load(_file);
  m_width = m_texImage.width();
  m_height = m_texImage.height();
}



// --------------------------------------------------------
// CompressedTexture Methods
// --------------------------------------------------------

bool CompressedTexture::operator==(const CompressedTexture& other)
{
  if(m_ID == other.m_ID) return true;
  else return false;
}

bool CompressedTexture::operator!=(const CompressedTexture& other)
{
  if(m_ID != other.m_ID) return true;
  else return false;
}


CompressedTexture::CompressedTexture(const std::string &_file)
{
  m_texImage.load(_file);
  m_width = m_texImage.width();
  m_height = m_texImage.height();
}



