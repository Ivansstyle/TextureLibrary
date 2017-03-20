#include "Texturemanager.h"
#include <algorithm>

bool TextureManager::isLoaded(AbstractTexture &_tex)
{
 return (std::find(m_Textures.begin(), m_Textures.end(), _tex) != m_Textures.end());
}

bool TextureManager::addTexture(std::string _filepath, textureType _type)
{
  auto find = std::find(m_Paths.begin(), m_Paths.end(), _filepath);

  if (find != m_Paths.end())
    {
      return false;
    }
  else
    {
      if (_type == MTEX_SIMPLE)
        {
          SimpleTexture tex = SimpleTexture(_filepath);
          m_Textures.push_back(tex);
        }
      if (_type == MTEX_MULTI)
        {
          MultiTexture tex = MultiTexture(_filepath);
          m_Textures.push_back(tex);
        }
      if (_type == MTEX_COMPRESSED)
        {
          CompressedTexture tex = CompressedTexture(_filepath);
          m_Textures.push_back(tex);
        }


    }
}

