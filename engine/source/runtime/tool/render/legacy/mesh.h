#include <string>
#include <vector>

#include "runtime/core/math.h"
#include "runtime/tool/render/legacy/shader.h"

namespace Smooth
{
    struct Vertex
    {
        vec3 Position;
        vec3 Normal;
        vec2 TexCoords;

        bool operator==(const Vertex& other) const 
        {
            return Position == other.Position 
            && Normal == other.Normal 
            && TexCoords == other.TexCoords;
        }
    };

    struct Textures
    {
        unsigned int id;
        std::string  type;
        std::string  path;
    };
    
    class Mesh
    {
    public:
        std::vector<Vertex>       m_vertices;
        std::vector<unsigned int> m_indices;
        std::vector<Textures>     m_textures;
        unsigned int              VAO;

        Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Textures> textures);

        void Draw(Shader &shader);

    private:
        unsigned int VBO,EBO;

        void setupMesh();
    };
    
}