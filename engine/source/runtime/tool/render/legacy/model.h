#include <string>

#include "tiny_obj_loader.h"

#include "runtime/tool/render/legacy/mesh.h"
#include "runtime/tool/render/legacy/shader.h"

namespace Smooth
{
    class Model
    {
    public:
        std::vector<Mesh> meshes;

        Model(const std::string ObjName);

        void                  Draw(Shader &shader, vec3 camera_pos, mat4 projection, mat4 view, vec3 postion);
        void                  processMesh(const std::string path);
        unsigned int          TextureFromFile(const std::string ObjName, const std::string &directory, bool gamma);
	    std::vector<Textures> loadMaterialTextures(std::vector<tinyobj::material_t> *mat,std::string type ,std::string typeName);
    
    private:
        tinyobj::ObjReaderConfig reader_config;
        tinyobj::ObjReader       reader;
        std::string              directory;
        std::string              path;
    };
    
}