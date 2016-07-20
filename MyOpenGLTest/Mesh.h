#pragma once
#ifndef MESH_H
#define MESH_H
//Std.Includes
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;
//GL Includes
#include <glew.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
//Assimp Includes
#ifndef ASSIMP_H
#define ASSIMP_H
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#endif

#include "Shader.h"

struct Vertex
{
	//Position
	glm::vec3 Position;
	//Normal
	glm::vec3 Normal;
	//TexCoords
	glm::vec2 TexCoords;
};

struct Texture
{
	GLuint id;
	string type;
	aiString path;
};

class Mesh
{
public:
	/* Mesh Data */
	vector<Vertex> vertices;
	vector<GLuint> indices;
	vector<Texture> textures;

	/* Functions */
	//Constructor
	Mesh();
	Mesh(vector<Vertex> vertices, vector<GLuint> indices, vector<Texture> textures);
	~Mesh();
	//Render the mesh
	void Draw(Shader shader);
private:
	/* Render data */
	GLuint VAO, VBO, EBO;

	/* Functions  */
	//Initialize all the buffer objects / arrays
	void setupMesh();	
};

#endif