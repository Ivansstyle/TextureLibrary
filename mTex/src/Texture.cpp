#include "Texture.h"


SimpleTexture::SimpleTexture(std::string &_file)
{
  m_texImage.load(_file);
  m_width = m_texImage.width();
  m_height = m_texImage.height();
}

void SimpleTexture::bindTexture()
{
  glGenTextures(1, &m_texID);
  glActiveTexture(GL_TEXTURE0);

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
  m_width = m_texImage.width();
  m_height = m_texImage.height();
}

