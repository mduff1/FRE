
#include "Mesh.h"
#include <iostream>
#include <vector>
#include <cassert>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <string>
#include <cassert>



#define SAFE_DELETE(p) {if(p){delete p;}}

Mesh::Mesh(const std::string& fname)
{
	m_fname = fname;
	
	//importing mesh
	Assimp::Importer importer;

	const aiScene* scene = importer.ReadFile((std::string("Meshes/") + m_fname).c_str(), aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs);

	if (!scene)
	{
		std::cout << "Mesh failed to load!: " << fname << std::endl;
		assert(0 == 0);
	}
		
	const aiMesh* model = scene->mMeshes[0];

	
	//assigning imported data
	const aiVector3D aiZeroVector(0.0f, 0.0f, 0.0f);
	for (unsigned int i = 0; i < model->mNumVertices; i++)
	{
		const aiVector3D* pPos = &(model->mVertices[i]);
		const aiVector3D* pNormal = &(model->mNormals[i]);
		const aiVector3D* pTexCoord = model->HasTextureCoords(0) ? &(model->mTextureCoords[0][i]) : &aiZeroVector;
		
		Vertex vert(glm::vec3(pPos->x, pPos->y, pPos->z), glm::vec2(pTexCoord->x, pTexCoord->y), glm::vec3(pNormal->x, pNormal->y, pNormal->z));
		vertices.push_back(vert);
	}

	for (unsigned int i = 0; i < model->mNumFaces; i++)
	{
		const aiFace& face = model->mFaces[i];
		assert(face.mNumIndices == 3);
		indices.push_back(face.mIndices[0]);
		indices.push_back(face.mIndices[1]);
		indices.push_back(face.mIndices[2]);

	}

	//calculating normals
	for (int i = 0; i < indices.size(); i += 3)
	{
		int i0 = indices[i];
		int i1 = indices[i + int(1)];
		int i2 = indices[i + int(2)];

		glm::vec3 v1 = vertices[i1].pos - vertices[i0].pos;
		glm::vec3 v2 = vertices[i2].pos - vertices[i2].pos;

		glm::vec3 normal = normalize(cross(v1, v2));

		vertices[i0].normal += normal;
		vertices[i1].normal += normal;
		vertices[i2].normal += normal;
	}

	for (int i = 0; i < vertices.size(); i++)
	{
		vertices[i].normal = normalize(vertices[i].normal);
	}



	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	vb = new VertexBuffer(vertices.size() * sizeof(Vertex), vertices.data());
	eb = new ElementBuffer(indices.size() * sizeof(int), indices.data());

	
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &vao);
	SAFE_DELETE(vb);
	SAFE_DELETE(eb);
}

void Mesh::Draw()
{
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, vb->vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)sizeof(glm::vec3));
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(glm::vec3) + sizeof(glm::vec2)));


	if (m_fname == "Skybox.obj")
	{
		//glDisable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eb->ebo);
		glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
		glDepthFunc(GL_LESS);
	}
	else
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eb->ebo);
		glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	}

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
	
	
}

