#include "glad/glad.h"

namespace Smooth
{
    class Texture
    {
    public:
        Texture(const char *fileName, int format);
        ~Texture();
        const GLuint getID()const;
    private:
        GLuint m_id;
    };
}