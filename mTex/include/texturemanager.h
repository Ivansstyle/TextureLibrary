#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <vector>
#include <string>
#include "texture.h"
//singlton
class TextureManager
{
public:
bool addTexture(std::string const _filepath);
bool removeTexture(std::string const _filepath);

private:
  std::vector<AbstractTexture> m_Tex;

};





#endif // TEXTUREMANAGER_H
