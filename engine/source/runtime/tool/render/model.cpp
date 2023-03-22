#include <iostream>

#include "stb_image.h"

#include "runtime/core/math.h"
#include "runtime/tool/render/model.h"

namespace std
{
    template<> struct hash<Smooth::Vertex>
    {
        size_t operator()(Smooth::Vertex const& vertex) const
        {
            return ((hash<vec3>()(vertex.Position)^
                    (hash<vec3>()(vertex.Normal) << 1)) >> 1) ^
                    (hash<vec2>()(vertex.TexCoords) << 1);
        }
    };
}

namespace Smooth
{
    Model::Model(const std::string ObjName)
    {
        path                          = "../assert/model/"+ObjName;
        reader_config.mtl_search_path = "./";

        if(!reader.ParseFromFile(path, reader_config))
        {
            if(!reader.Error().empty())
            {
                std::cerr << "TinyObjReader:" << reader.Error() << std::endl;
            }
        }

        exit(1);

        if(!reader.Warning().empty())
        {
            std::cout << "TinyObjReader: " << reader.Warning() << std::endl;
        }

        directory = path.substr(0,path.find_last_of('/'));

        processMesh(ObjName);
    }

    void Model::Draw(Shader &shader, vec3 camera_pos, mat4 projection, mat4 view, vec3 position)
    {
        shader.use();
        shader.setVec3("viewPos",camera_pos);
        shader.setMat4("projection", projection);
        shader.setMat4("view", view);

        // render the loaded model
        mat4 model = mat4(1.0f);

        model = translate(model, position); // translate it down so it's at the center of the scene
        model = scale(model, vec3(10.0f, 8.0f, 10.0f));	// it's a bit too big for our scene, so scale it down
        
        shader.setMat4("model", model);


        for(unsigned int i=0;i<meshes.size();i++)
        {
            meshes[i].Draw(shader);
        }
    }

    void Model::processMesh(const std::string ObjName)
    {
        tinyobj::attrib_t                attrib = reader.GetAttrib();
        std::vector<tinyobj::shape_t>    shapes = reader.GetShapes();
        std::vector<tinyobj::material_t> materials = reader.GetMaterials();

        std::vector<Vertex>                     vertices;
        std::vector<unsigned int>               indices;
        std::vector<Textures>                   textures;
        std::unordered_map<Vertex,unsigned int> uniqueVertices;

        unsigned int id = TextureFromFile(ObjName,directory, true);

        // Loop over shapes
        for (size_t s = 0; s < shapes.size(); s++)
        {
            // Loop over faces(polygon)
            size_t index_offset = 0;
            for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++)
            {
                size_t fv = size_t(shapes[s].mesh.num_face_vertices[f]);

                // Loop over vertices in the face.
                for (size_t v = 0; v < fv; v++)
                {
                    // access to vertex
                    Vertex vertex;
                    tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];

                    vertex.Position= 
                    {
                            attrib.vertices[3*size_t(idx.vertex_index)+0],
                            attrib.vertices[3*size_t(idx.vertex_index)+1],
                            attrib.vertices[3*size_t(idx.vertex_index)+2]
                    };

                    // Check if `normal_index` is zero or positive. negative = no normal data
                    vertex.Normal=
                    {
                        attrib.normals[3*size_t(idx.normal_index)+0],
                        attrib.normals[3*size_t(idx.normal_index)+1],
                        attrib.normals[3*size_t(idx.normal_index)+2]
                    };

                    // Check if `texcoord_index` is zero or positive. negative = no texcoord data
                    vertex.TexCoords=
                    {
                        attrib.texcoords[2*size_t(idx.texcoord_index)+0],
                        attrib.texcoords[2*size_t(idx.texcoord_index)+1]
                    };

                    if(uniqueVertices.count(vertex)==0)
                    {
                        uniqueVertices[vertex]=static_cast<unsigned int>(vertices.size());
                        vertices.push_back(vertex);
                    }

                    indices.push_back(uniqueVertices[vertex]);
                }
                index_offset += fv;
            }
            meshes.push_back(Mesh(vertices, indices, textures));
        }
    }

    unsigned int Model::TextureFromFile(const std::string ObjName, const std::string &directory, bool gamma)
    {
        std::string filename = ObjName;
        filename = directory + '/' +filename+".png";

        unsigned int textureID;
        glGenTextures(1, &textureID);

        int width, height, nrComponents;
        unsigned char *data = stbi_load(filename.c_str(), &width, &height, &nrComponents, 0);
        if (data)
        {
            std::cout<<"Texture load successful!"<<std::endl;

            GLenum format;
            if (nrComponents == 1)
                format = GL_RED;
            else if (nrComponents == 3)
                format = GL_RGB;
            else if (nrComponents == 4)
                format = GL_RGBA;

            glBindTexture(GL_TEXTURE_2D, textureID);
            glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

            stbi_image_free(data);
        }
        else
        {
            std::cout << "Texture failed to load at path: " << path << std::endl;
            stbi_image_free(data);
        }

        return textureID;
    }

}