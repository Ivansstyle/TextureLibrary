#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <vector>
#include <string>
#include "Texture.h"
//singlton
typedef enum textureType
{
  MTEX_SIMPLE,
  MTEX_MULTI,
  MTEX_COMPRESSED
} textureType;



class TextureManager
{
public:
TextureManager() = delete;

bool addTexture(std::string const _filepath, textureType _type);
void removeTexture(std::string const _filepath);
bool isLoaded(AbstractTexture & _tex);
void enableTexture();

private:
  std::vector<AbstractTexture> m_Textures;
  std::vector<std::string> m_Paths;

};


#endif // TEXTUREMANAGER_H
