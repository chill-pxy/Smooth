#include <iostream>

#include "stb_image.h"

#include "runtime/tool/render/texture.h"

namespace Smooth
{
    Texture::Texture(const char *fileName, int format)
    {
        glGenTextures(1,&m_id);
        glBindTexture(GL_TEXTURE_2D, m_id);

        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        int width,height,nrChannels;
        unsigned char *data = stbi_load(fileName, &width, &height, &nrChannels, 0);
        if(data!= nullptr)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);//‰º†ÈÄÅÊï∞Êç?
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
            std::cout<<"Ã˘Õºº”‘ÿ ß∞‹";
        stbi_image_free(data);
    }

    Texture::~Texture()
    {
        glDeleteTextures(1,&m_id);
    }

    const GLuint Texture::getID() const
    {
        return m_id;
    }
}