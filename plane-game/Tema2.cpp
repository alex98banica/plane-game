#include "Tema2.h"

#include <vector>
#include <string>
#include <iostream>

#include <Core/Engine.h>


using namespace std;

Tema2::Tema2()
{
}

Tema2::~Tema2()
{
}

void Tema2::Init()
{



		for (int i = 0;i < 2;i++)
			for (int j = 0;j < 10;j++)
				coliziune_bonus[i][j] = 0;

	camera_view = 0;
	for (int i = 0;i < 6;i++) {
		coliziune_obstacol[i] = 0;
		for (int j = 0;j < 10;j++) {
			rand_obstacol[i][j] = rand() % 90;
			for (int k = 0;k < 4;k++) {
				rot[i][j][k] = rand() % 2;
			}
		}
	}

	move_Y = 0;
	move_X = 0;



	float angle=0;


			rand_puncte[0] = rand() % 8 + 2;
			rand_puncte[1] = rand() % 8 + 2;
			rand_puncte[2] = rand() % 5;
			rand_puncte[3] = rand() % 2;
			rand_puncte[4] = rand() % 8 + 2;
			rand_puncte[5] = rand() % 8 + 2;
			rand_puncte[6] = rand() % 5;
			rand_puncte[7] = rand() % 2;

	{
		vector<VertexFormat> vertices
		{
							
			VertexFormat(glm::vec3(0, 0.25f,  0.4f), glm::vec3(0, 0, 0), glm::vec3(1, 1, 0.4)),
			VertexFormat(glm::vec3(2, 0,  0.5f),  glm::vec3(0, 0, 0),  glm::vec3(1, 1, 1)),
			VertexFormat(glm::vec3(0,  0.5f,  0.4f), glm::vec3(0.4, 0, 0), glm::vec3(0, 0.4, 0)),
			VertexFormat(glm::vec3(2,  0.5f,  0.5f), glm::vec3(0, 0, 0), glm::vec3(0, 0, 0)),
			VertexFormat(glm::vec3(0, 0.25f, 0.1f), glm::vec3(0, 0.4, 0.4), glm::vec3(0.4, 0, 0.4)),
			VertexFormat(glm::vec3(2, 0, 0), glm::vec3(0, 0, 0.4), glm::vec3(0, 0, 0.4)),
			VertexFormat(glm::vec3(0,  0.5f, 0.1f), glm::vec3(0, 0, 0.4), glm::vec3(1, 0.4, 1)),
			VertexFormat(glm::vec3(2,  0.5f, 0), glm::vec3(0, 0, 0.4),  glm::vec3(1, 1, 1)),


			VertexFormat(glm::vec3(1.2f, 0.25f,  1.5f),   glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(1.8f, 0.25f,  1.5f), glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(1.2f,  0.375f,  1.5f),   glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(1.8f,  0.375f,  1.5f),   glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(1.2f, 0.25f, -1), glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(1.8f, 0.25f, -1),  glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(1.2f,  0.375f, -1), glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(1.8f,  0.375f, -1), glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),


			VertexFormat(glm::vec3(1.8f,  0.45f, 0.25f), glm::vec3(0.54, 0.824, 1), glm::vec3(0.54, 0.824, 1)),
			VertexFormat(glm::vec3(1.5f,  0.45f, 0.1f), glm::vec3(0.54, 0.824, 1), glm::vec3(0.54, 0.824, 1)),
			VertexFormat(glm::vec3(1.5f,  0.45f, 0.4f), glm::vec3(0.54, 0.824, 1), glm::vec3(0.54, 0.824, 1)),
			VertexFormat(glm::vec3(1.5f,  0.65f, 0.1f), glm::vec3(0.54, 0.824, 1), glm::vec3(0.54, 0.824, 1)),
			VertexFormat(glm::vec3(1.5f,  0.65f, 0.4f), glm::vec3(0.54, 0.824, 1), glm::vec3(0.54, 0.824, 1)),

			VertexFormat(glm::vec3(0.1f, 0.35f,  0.65f),  glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(0.3f, 0.35f,  0.6f),  glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(0.1f,  0.45f,  0.65f), glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(0.3f,  0.45f,  0.6f),  glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(0.1f, 0.35f, -0.15f), glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(0.3f, 0.35f, -0.1f), glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(0.1f,  0.45f, -0.15f), glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(0.3f,  0.45f, -0.1f), glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),


			VertexFormat(glm::vec3(0.1f, 0.5f,   0.27f), glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(0.3f, 0.5f,   0.27f),   glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(0.1f,  0.65f,  0.27f), glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(0.15f,  0.65f,  0.27f), glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(0.1f, 0.5f,	  0.23f), glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(0.3f, 0.5f,  0.23f), glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(0.1f,  0.65f,  0.23f), glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(0.15f,  0.65f,  0.23f),  glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),


			VertexFormat(glm::vec3(2, 0.2f,  0.3f), glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(2.1f, 0.2f,  0.3f), glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(2,  0.3f,  0.3f),  glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(2.1f,  0.3f,  0.3f), glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(2, 0.2f, 0.2f), glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(2.1f, 0.2f, 0.2f), glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(2,  0.3f, 0.2f), glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(2.1f,  0.3f, 0.2f), glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
		};

		vector<unsigned short> indices =
		{
			0, 1, 2,        1, 3, 2,
			2, 3, 7,        2, 7, 6,
			1, 7, 3,        1, 5, 7,
			6, 7, 4,        7, 5, 4,
			0, 4, 1,        1, 4, 5,
			2, 6, 4,        0, 2, 4,

			 8,  9, 10,        9, 11, 10,
			10, 11, 15,       10, 15, 14,
			 9, 15, 11,        9, 13, 15,
			14, 15, 12,       15, 13, 12,
			 8, 12, 9,         9, 12, 13,
			10, 14, 12,        8, 10, 12,

			16,17,19,		16,19,20,
			16,17,18,       17,18,19,
			19,20,18,		16,18,20,

			21, 22, 23,       22, 24, 23,
			23, 24, 28,       23, 28, 27,
			22, 28, 24,       22, 26, 28,
			27, 28, 25,		  28, 26, 25,
			21, 25, 22,       22, 25, 26,
			23, 27, 25,       21, 23, 25,

			29, 30, 31,		  30, 32, 31,
			31, 32, 36,       31, 36, 35,
			30, 36, 32,       30, 34, 36,
			35, 36, 33,       36, 34, 33,
			29, 33, 30,       30, 33, 34,
			31, 35, 33,       29, 31, 33,

			37, 38, 39,		  38, 40, 39,
			39, 40, 44,		  39, 44, 43,
			38, 44, 40,		  38, 42, 44,
			43, 44, 41,		  44, 42, 41,	
			37, 41, 38,		  38, 41, 42,
			39, 43, 41,		  37, 39, 41,

		};
		vector<VertexFormat> vertices2
		{
			VertexFormat(glm::vec3(2.1f, 0.2f,  1),glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(2.2f, 0.2f,  1),glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(2.1f,  0.3f,  1),glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(2.2f,  0.3f,  1),glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(2.1f, 0.2f, -0.5f),glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(2.2f, 0.2f, -0.5f),glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(2.1f,  0.3f, -0.5f),glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(2.2f,  0.3f, -0.5f),glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),


			VertexFormat(glm::vec3(2.1f, -0.5f,  0.3f),glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(2.2f, -0.5f,  0.3f),glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(2.1f,	1,  0.3f),glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(2.2f,	1,  0.3f),glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(2.1f, -0.5f, 0.2f),glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(2.2f, -0.5f, 0.2f),glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(2.1f,	1, 0.2f), glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
			VertexFormat(glm::vec3(2.2f,	1, 0.2f), glm::vec3(0.39, 0, 0), glm::vec3(0.39, 0, 0)),
		};

		vector<unsigned short> indices2 =
		{
			0, 1, 2,        1, 3, 2,
			2, 3, 7,        2, 7, 6,
			1, 7, 3,        1, 5, 7,
			6, 7, 4,        7, 5, 4,
			0, 4, 1,        1, 4, 5,
			2, 6, 4,        0, 2, 4,

			 8,  9, 10,        9, 11, 10,
			10, 11, 15,       10, 15, 14,
			 9, 15, 11,        9, 13, 15,
			14, 15, 12,       15, 13, 12,
			 8, 12, 9,         9, 12, 13,
			10, 14, 12,        8, 10, 12,
		};

		vector<VertexFormat> vertices3
		{
			VertexFormat(glm::vec3(0.5f,1.0f,0.0f), glm::vec3(0, 1, 1), glm::vec3(0.2, 0.8, 0.2)),
			VertexFormat(glm::vec3(1.0f,0.0f,0.0f), glm::vec3(1, 0, 1), glm::vec3(0.9, 0.4, 0.2)),
			VertexFormat(glm::vec3(0.0f,0.0f,0.0f), glm::vec3(1, 0, 0), glm::vec3(0.7, 0.7, 0.1)),
			VertexFormat(glm::vec3(0.0f,0.0f,1.0f), glm::vec3(0, 1, 0), glm::vec3(0.7, 0.3, 0.7)),
		};

		vector<unsigned short> indices3 =
		{
			3, 2, 1,
			3, 1, 0,
			3 ,0, 2,
			0, 1, 2,
		};




		vector<VertexFormat> vertices4
		{
			VertexFormat(glm::vec3(-1, -1,  1), glm::vec3(0, 1, 1), glm::vec3(0.8f,0.7f,0.4f)),
			VertexFormat(glm::vec3(1, -1,  1), glm::vec3(1, 0, 1), glm::vec3(0.8f,0.7f,0.4f)),
			VertexFormat(glm::vec3(-1,  1,  1), glm::vec3(1, 0, 0), glm::vec3(1,0.93f,0.8f)),
			VertexFormat(glm::vec3(1,  1,  1), glm::vec3(0, 1, 0), glm::vec3(0.8f,0.7f,0.4f)),
			VertexFormat(glm::vec3(-1, -1, -1), glm::vec3(1, 1, 1), glm::vec3(0.8f,0.7f,0.4f)),
			VertexFormat(glm::vec3(1, -1, -1), glm::vec3(0, 1, 1), glm::vec3(1,0.93f,0.8f)),
			VertexFormat(glm::vec3(-1,  1, -1), glm::vec3(1, 1, 0), glm::vec3(0.8f,0.7f,0.4f)),
			VertexFormat(glm::vec3(1,  1, -1), glm::vec3(0, 0, 1), glm::vec3(1,0.93f,0.8f)),
		};

		vector<unsigned short> indices4 =
		{
			0, 1, 2,        1, 3, 2,
			2, 3, 7,        2, 7, 6,
			1, 7, 3,        1, 5, 7,
			6, 7, 4,        7, 5, 4,
			0, 4, 1,        1, 4, 5,
			2, 6, 4,        0, 2, 4,
		};

		vector<VertexFormat> vertices5
		{
			VertexFormat(glm::vec3(0, 0,  1), glm::vec3(1, 1, 1), glm::vec3(1, 1, 1)),
			VertexFormat(glm::vec3(0, 1,  1), glm::vec3(1, 1, 1), glm::vec3(1, 1, 1)),
			VertexFormat(glm::vec3(1,  0,  1), glm::vec3(1, 1, 1), glm::vec3(1, 1, 1)),
			VertexFormat(glm::vec3(1, 1,  1), glm::vec3(1, 1, 1), glm::vec3(1, 1, 1)),
		};

		vector<unsigned short> indices5 =
		{
			0, 1, 2,
			1, 2, 3,
		};

		vector<VertexFormat> vertices6
		{
			VertexFormat(glm::vec3(0, 0,  1), glm::vec3(1, 1, 1), glm::vec3(0,0,0)),
			VertexFormat(glm::vec3(0, 1,  1), glm::vec3(1, 1, 1), glm::vec3(0,0,0)),
			VertexFormat(glm::vec3(1,  0,  1), glm::vec3(1, 1, 1), glm::vec3(0,0,0)),
			VertexFormat(glm::vec3(1, 1,  1), glm::vec3(1, 1, 1), glm::vec3(0,0,0)),
		};

		vector<unsigned short> indices6 =
		{
			0, 1, 2,
			1, 2, 3,
		};

		vector<VertexFormat> vertices7
		{
			VertexFormat(glm::vec3(0, 0,  1), glm::vec3(1, 0, 0), glm::vec3(1, 0, 0)),
			VertexFormat(glm::vec3(-1, 1,  1), glm::vec3(1, 0, 0), glm::vec3(1, 0, 0)),
			VertexFormat(glm::vec3(-0.5f,  1.3f,  1), glm::vec3(1, 0, 0), glm::vec3(1, 0, 0)),
			VertexFormat(glm::vec3(0, 1,  1), glm::vec3(1, 0, 0), glm::vec3(1, 0, 0)),
			VertexFormat(glm::vec3(0.5f,  1.3f,  1), glm::vec3(1, 0, 0), glm::vec3(1, 0, 0)),
			VertexFormat(glm::vec3(1, 1,  1), glm::vec3(1, 0, 0), glm::vec3(1, 0, 0)),
		};

		vector<unsigned short> indices7 =
		{
			0, 1, 5,
			1, 2, 3,
			3, 4, 5,
		};


		//avion
		CreateMesh("plane", vertices, indices);
		//puncte combustibil
		CreateMesh("bonus", vertices3, indices3);
		//elice
		CreateMesh("elice", vertices2, indices2);
		//pnori
		CreateMesh("box", vertices4, indices4);
		//combustibil
		CreateMesh("fuel1", vertices5, indices5);
		CreateMesh("fuel2", vertices6, indices6);
		//marea
		CreateWater("water", 5);
		//obstacol
		CreateSphere("sphere", 1);
		//viata
		CreateMesh("inima", vertices7, indices7);
	}


	{
		Shader* shader = new Shader("Tema2");
		shader->AddShader("Source/Laboratoare/Tema2/Shaders/VertexShader.glsl", GL_VERTEX_SHADER);
		shader->AddShader("Source/Laboratoare/Tema2/Shaders/FragmentShader.glsl", GL_FRAGMENT_SHADER);
		shader->CreateAndLink();
		shaders[shader->GetName()] = shader;

	}
}

//sfera obstacol
Mesh* Tema2::CreateSphere(std::string name, float length)
{
	int i, j;
	vector<VertexFormat> vertices = {};
	vector<unsigned short> indices = {};
	int indicator = 0;
	glm::vec3 color = glm::vec3(1, 0, 0);
	for (i = 0; i <= 10; i++) {
		double lat0 = glm::pi<double>() * (-0.5 + (double)(i - 1) / 10);
		double z0 = sin(lat0);
		double zr0 = cos(lat0);

		double lat1 = glm::pi<double>() * (-0.5 + (double)i / 10);
		double z1 = sin(lat1);
		double zr1 = cos(lat1);

		for (j = 0; j <= 10; j++) {
			double lng = 2 * glm::pi<double>() * (double)(j - 1) /10;
			double x = cos(lng);
			double y = sin(lng);

			vertices.push_back(VertexFormat(glm::vec3(x * zr0, y * zr0,z0), color, color));
			indices.push_back(indicator);
			indicator++;

			vertices.push_back(VertexFormat(glm::vec3(x * zr1, y * zr1, z1), color, color));
			indices.push_back(indicator);
			indicator++;
		}
		indices.push_back(GL_PRIMITIVE_RESTART_FIXED_INDEX);
	}
	return CreateMesh("sphere", vertices, indices);
}


//creare mare
Mesh* Tema2::CreateWater(std::string name, float length)
{

	vector<VertexFormat> vertices = {};
	vector<unsigned short> indices = {};

	glm::vec3 color = glm::vec3(0.6f, 0.9f, 1);



	float radius = 1.0f;
	float angle = M_PI / 58;

	for (int j = 0; j < 500; j += 125) {
		int circle_index = j / 125;
		int circle_distance = length / 5;

		vertices.push_back(VertexFormat(glm::vec3(0, 0, circle_index * circle_distance),color, color));
		vertices.push_back(VertexFormat(glm::vec3(radius, 0, circle_index * circle_distance), color,color));

		for (int i = j; i < j + 119; i++) {
			float X = radius * sin(angle * (i - j));
			float Y = radius * cos(angle * (i - j));
			vertices.push_back(VertexFormat(glm::vec3(X, Y, circle_index * circle_distance),color, color));
			indices.push_back(j);
			indices.push_back(i);
			indices.push_back(i + 1);
		}
	}

	for (int j = 0; j < vertices.size(); j += 121) {
		for (int i = j + 1; i < j + 119; i++) {
			indices.push_back(i);
			indices.push_back(i + 121);
			indices.push_back(i + 121 + 1);

			indices.push_back(i + 121 + 1);
			indices.push_back(i + 1);
			indices.push_back(i);
		}
	}

	return CreateMesh("water", vertices, indices);
}

Mesh* Tema2::CreateMesh(const char* name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned short>& indices)
{
	unsigned int VAO = 0;
	// TODO: Create the VAO and bind it
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	// TODO: Create the VBO and bind it
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// TODO: Send vertices data into the VBO buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

	// TODO: Crete the IBO and bind it
	unsigned int IBO;
	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

	// TODO: Send indices data into the IBO buffer
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * indices.size(), &indices[0], GL_STATIC_DRAW);

	// ========================================================================
	// This section describes how the GPU Shader Vertex Shader program receives data

	// set vertex position attribute
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), 0);

	// set vertex normal attribute
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(sizeof(glm::vec3)));

	// set texture coordinate attribute
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(2 * sizeof(glm::vec3)));

	// set vertex color attribute
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(2 * sizeof(glm::vec3) + sizeof(glm::vec2)));

	// set elapsed time attribute
	glEnableVertexAttribArray(4);
	glVertexAttribPointer(4, 1, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(3 * sizeof(glm::vec3) + sizeof(glm::vec2)));
	//printf("%f\n", Engine::GetElapsedTime());
	// Unbind the VAO
	glBindVertexArray(0);

	// Check for OpenGL errors
	CheckOpenGLError();

	// Mesh information is saved into a Mesh object
	meshes[name] = new Mesh(name);
	meshes[name]->InitFromBuffer(VAO, static_cast<unsigned short>(indices.size()));
	meshes[name]->vertices = vertices;
	meshes[name]->indices = indices;
	return meshes[name];
}

void Tema2::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor( 1, 0.9, 0.5f,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);
}

void Tema2::Update(float deltaTimeSeconds)
{
	//inceperea jocului
	if (screen == 1)
	{
		score += deltaTimeSeconds/2.0f;
		if (fuel > -1.8f && fuel <= 0)
			fuel -= deltaTimeSeconds / 10;
		else if (fuel > 0)
			fuel = 0;
		else
			fuel = -1.8f;

		//initializare camera,combustibil si vieti
		auto camera = GetSceneCamera();
		if (camera_view != 0) {
			camera->SetRotation(glm::vec3(2.4, -1.5, -2.9));
			camera->SetPosition(glm::vec3(-13, 41, -1.2));
			camera->Update();

			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix = glm::translate(modelMatrix, glm::vec3(2, 40, 9));
			modelMatrix = glm::rotate(modelMatrix, RADIANS(80.0f), glm::vec3(0, 1, 0));
			modelMatrix = glm::scale(modelMatrix, glm::vec3(-2, 0.6f, 0.6f));
			RenderSimpleMesh(meshes["fuel1"], shaders["VertexNormal"], modelMatrix);
			glm::mat4 modelMatrix2 = glm::mat4(1);
			modelMatrix2 = glm::translate(modelMatrix2, glm::vec3(2, 40.0f, 9));
			modelMatrix2 = glm::rotate(modelMatrix2, RADIANS(80.0f), glm::vec3(0, 1, 0));
			modelMatrix2 = glm::scale(modelMatrix2, glm::vec3(-1.8f - fuel, 0.4f, 0.4f));
			RenderSimpleMesh(meshes["fuel2"], shaders["VertexNormal"], modelMatrix2);

			for (float j = 0;j < moare;j++) {
				glm::mat4 modelMatrix3 = glm::mat4(1);
				modelMatrix3 = glm::translate(modelMatrix3, glm::vec3(-3.3f + j * 2.0f, 40.32f, -8.3f));
				modelMatrix3 = glm::scale(modelMatrix3, glm::vec3(0.5f, 0.5f, 0.5f));
				modelMatrix3 = glm::rotate(modelMatrix3, RADIANS(100.0f), glm::vec3(0, 1, 0));
				RenderSimpleMesh(meshes["inima"], shaders["VertexNormal"], modelMatrix3);
			}

		}
		else
		{
			camera->SetRotation(glm::vec3(-0.1, -0.14, 8e-09));
			camera->SetPosition(glm::vec3(0.62, 32, 15));
			camera->Update();

			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix = glm::translate(modelMatrix, glm::vec3(4, 33, 10));
			modelMatrix = glm::scale(modelMatrix, glm::vec3(2, 0.6f, 0.6f));
			RenderSimpleMesh(meshes["fuel1"], shaders["VertexNormal"], modelMatrix);
			glm::mat4 modelMatrix2 = glm::mat4(1);
			modelMatrix2 = glm::translate(modelMatrix2, glm::vec3(4, 33.02f, 10.3f));
			modelMatrix2 = glm::scale(modelMatrix2, glm::vec3(1.8f + fuel, 0.4f, 0.4f));
			RenderSimpleMesh(meshes["fuel2"], shaders["VertexNormal"], modelMatrix2);

			for (float j = 0;j < moare;j++) {
				glm::mat4 modelMatrix3 = glm::mat4(1);
				modelMatrix3 = glm::translate(modelMatrix3, glm::vec3(-2.3f + j / 1.5f, 33.32f, 10.3f));
				modelMatrix3 = glm::scale(modelMatrix3, glm::vec3(0.3f, 0.3f, 0.3f));
				RenderSimpleMesh(meshes["inima"], shaders["VertexNormal"], modelMatrix3);
			}
		}


		angle -= 12.6 * deltaTimeSeconds;
		for (int i = 0;i < 5;i++) {
			x[i] += deltaTimeSeconds / 3;

		}
		viteza += deltaTimeSeconds/200.0f;
		end[0] -= 10 * deltaTimeSeconds+viteza;
		end[1] -= 10 * deltaTimeSeconds+viteza;
		for (int i = 0;i < 5;i++) {
			end2[i] -= 10 * deltaTimeSeconds+viteza;
		}

		//generare avion
		{
			glm::mat4 modelMatrix = glm::mat4(1);
			if (game_over == 1 && end_game <= 3.8f)
			{
				if (end_game < 3.6f)
				{
					modelMatrix = glm::translate(modelMatrix, glm::vec3(-1 + move_X, 30 + last_poz - end_game * 5.0f, -1));
					modelMatrix = glm::rotate(modelMatrix, RADIANS(-5.0f - end_game * 2.0f), glm::vec3(0, -1, -1));
					modelMatrix = glm::translate(modelMatrix, glm::vec3(-0.5f, -0.5f, -0.3f));
					RenderSimpleMesh(meshes["plane"], shaders["VertexNormal"], modelMatrix);
				}
			}
			else
			{

				modelMatrix = glm::translate(modelMatrix, glm::vec3(-1 + move_X, 30 + move_Y, -1));

				if (rotate_back > 0 && stabilizare >= 3.0f)
				{
					rotate_plane = 0;
					modelMatrix = glm::rotate(modelMatrix, RADIANS(-(rotate_back * 20.0f)), glm::vec3(0, 0, 1));
					rotate_back -= 1.0f / 30.0f;
					if (rotate_back <= 0) {
						rotate_back = 0;
						stabilizare = 0;

					}
	

				}
				if (rotate_back < 0 && stabilizare >= 3.0f)
				{
					rotate_plane = 0;
					modelMatrix = glm::rotate(modelMatrix, RADIANS(-(rotate_back * 20.0f)), glm::vec3(0, 0, 1));
					rotate_back += 1.0f / 20.0f;
					if (rotate_back >= 0) {
						rotate_back = 0;
						stabilizare = 0;
					}
				}
				if (rotate_plane < 0 && stabilizare < 3.0f) {
					modelMatrix = glm::rotate(modelMatrix, RADIANS(20.0f), glm::vec3(0, 0, 1));
					rotate_back = -1.0f;
					stabilizare++;
				}
				if (rotate_plane > 0 && stabilizare < 3.0f) {
					modelMatrix = glm::rotate(modelMatrix, RADIANS(-20.0f), glm::vec3(0, 0, 1));
					rotate_back = 1.0f;
					stabilizare++;
			}

			modelMatrix = glm::translate(modelMatrix, glm::vec3(-0.5f, -0.5f, -0.3f));
			RenderSimpleMesh(meshes["plane"], shaders["VertexNormal"], modelMatrix);
			}
		}

		//generare elice
		{
			glm::mat4 modelMatrix = glm::mat4(1);
			if (fuel == -1.8f || moare <= 0 && game_over == 0)
			{
				last_poz = move_Y;
				game_over = 1;
			}
			if (game_over == 1 && end_game <= 3.8f)
			{
				if (end_game < 3.6f)
				{
					modelMatrix = glm::translate(modelMatrix, glm::vec3(-1 + move_X, 30 + last_poz - end_game *5.0f, -1));
					modelMatrix = glm::rotate(modelMatrix, RADIANS(-5.0f-end_game*2.0f), glm::vec3(0, -1, -1));
					modelMatrix = glm::translate(modelMatrix, glm::vec3(+2.15f - 0.5f, +0.25f - 0.5f, +0.25f - 0.3f));
					modelMatrix = glm::rotate(modelMatrix, angle, glm::vec3(1, 0, 0));
					modelMatrix = glm::translate(modelMatrix, glm::vec3(-2.15f, -0.25f, -0.25f));
					RenderSimpleMesh(meshes["elice"], shaders["VertexNormal"], modelMatrix);

					
				}
				else
				{
					screen = 2;
				}
				end_game += 0.01f;
			}
			
			else
			{
				modelMatrix = glm::translate(modelMatrix, glm::vec3(-1 + move_X, 30 + move_Y, -1));
				if (rotate_plane > 0 && stabilizare < 3.0f) {
					modelMatrix = glm::rotate(modelMatrix, RADIANS(-20.0f), glm::vec3(0, 0, 1));
					rotate_back = 1.0f;
					stabilizare++;
				}

				if (rotate_back > 0 && stabilizare >= 3.0f)
				{
					rotate_plane = 0;
					modelMatrix = glm::rotate(modelMatrix, RADIANS(-(rotate_back * 20.0f)), glm::vec3(0, 0, 1));
					rotate_back -= 1.0f / 20.0f;
					if (rotate_back <= 0) {
						rotate_back = 0;
						stabilizare = 0;

					}


				}
				if (rotate_back < 0 && stabilizare >= 3.0f)
				{
					rotate_plane = 0;
					modelMatrix = glm::rotate(modelMatrix, RADIANS(-(rotate_back * 20.0f)), glm::vec3(0, 0, 1));
					rotate_back += 1.0f / 20.0f;
					if (rotate_back >= 0) {
						rotate_back = 0;
						stabilizare = 0;
					}
				}
				if (rotate_plane < 0 && stabilizare < 3.0f) {
					modelMatrix = glm::rotate(modelMatrix, RADIANS(20.0f), glm::vec3(0, 0, 1));
					rotate_back = -1.0f;
					stabilizare++;
				}
				modelMatrix = glm::translate(modelMatrix, glm::vec3(+2.15f - 0.5f, +0.25f - 0.5f, +0.25f - 0.3f));
				modelMatrix = glm::rotate(modelMatrix, angle, glm::vec3(1, 0, 0));
				modelMatrix = glm::translate(modelMatrix, glm::vec3(-2.15f, -0.25f, -0.25f));
				RenderSimpleMesh(meshes["elice"], shaders["VertexNormal"], modelMatrix);
			}
		}

		//generare mare
		{
			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix = glm::scale(modelMatrix, glm::vec3(25, 25, 25));
			modelMatrix = glm::rotate(modelMatrix, angle / 10, glm::vec3(0, 0, 1));
			modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 0, -2));
			RenderSimpleMesh(meshes["water"], shaders["Tema2"], modelMatrix);
		}

		for (int j = 0;j <= rand_puncte[0];j++)
			if ((start[0] + end[0] + j) < 1.3f && (start[0] + end[0] + j) > -2 && 29.25f + rand_puncte[1] + j / 3 > 28 + move_Y && 29.25f + rand_puncte[1] + j / 3 + 1 < 28 + move_Y + 4) {
				coliziune_bonus[0][j] = 1;
				fuel += 0.005f;
			}


		for (int j = 0;j <= rand_puncte[4];j++) {
			if ((start[1] + end[1] + j) < 1.3f && (start[1] + end[1] + j) > -2 && 29.25f + rand_puncte[5] + j / 3 > 28 + move_Y && 29.25f + rand_puncte[5] + j / 3 + 1 < 28 + move_Y + 4) {
				coliziune_bonus[1][j] = 1;
				fuel += 0.005f;
			}
		}


		if (start[0] + end[0] < -25)
		{
			end[0] = 0;
			start[0] = 25;
			rand_puncte[0] = rand() % 5 + 2;
			rand_puncte[1] = rand() % 3 + 1;
			rand_puncte[2] = rand() % 5;
			for (int j = 0;j < 10;j++)
				coliziune_bonus[0][j] = 0;
		}
		if (start[1] + end[1] < -25)
		{
			end[1] = 0;
			start[1] = 25;
			rand_puncte[4] = rand() % 5 + 2;
			rand_puncte[5] = rand() % 3 + 1;
			rand_puncte[6] = rand() % 5;
			for (int j = 0;j < 10;j++)
				coliziune_bonus[1][j] = 0;
		}

		for (int j = 0;j <= rand_puncte[0];j++)
		{
			glm::mat4 modelMatrix = glm::mat4(1);
			{
				if (coliziune_bonus[0][j] == 0) {
					modelMatrix = glm::translate(modelMatrix, glm::vec3(start[0] + end[0] + j, 29.25f + rand_puncte[1] + float(j / 3), -1.0f));
					modelMatrix = glm::rotate(modelMatrix, angle, glm::vec3(-1 + j, 2 - j, 5 - j));
					modelMatrix = glm::translate(modelMatrix, glm::vec3(-0.25f, -0.3, -0.3f));
					RenderSimpleMesh(meshes["bonus"], shaders["VertexNormal"], modelMatrix);
				}
			}

		}

		//generare bonus combustibil
		for (int k = 0;k <= rand_puncte[4];k++)
		{
			glm::mat4 modelMatrix = glm::mat4(1);
			{
				if (coliziune_bonus[1][k] == 0)
				{
					modelMatrix = glm::translate(modelMatrix, glm::vec3(start[1] + end[1] + k, 29.25f + rand_puncte[5] + float(k / 3), -1.0f));
					modelMatrix = glm::rotate(modelMatrix, angle, glm::vec3(-1 + k, 2 - k, 5 - k));
					modelMatrix = glm::translate(modelMatrix, glm::vec3(-0.25f, -0.3, -0.3f));
					RenderSimpleMesh(meshes["bonus"], shaders["VertexNormal"], modelMatrix);
				}
			}

		}

		//generare obstacol
		if (start2[0] + end2[0] < -20) {
			start2[0] = 40;
			end2[0] = 0;
			rand_obstacol[2][0] = rand() % 90;
			if (coliziune_obstacol[0] == 1)
				moare2--;
			coliziune_obstacol[0] = 0;
		}
		if (start2[1] + end2[1] < -20) {
			start2[1] = 40;
			end2[1] = 0;
			rand_obstacol[2][1] = rand() % 90;
			if (coliziune_obstacol[1] == 1)
				moare2--;
			coliziune_obstacol[1] = 0;
		}
		if (start2[2] + end2[2] < -20) {
			start2[2] = 40;
			end2[2] = 0;
			rand_obstacol[2][2] = rand() % 90;
			if (coliziune_obstacol[2] == 1)
				moare2--;
			coliziune_obstacol[2] = 0;
		}
		if (start2[3] + end2[3] < -20) {
			start2[3] = 40;
			end2[3] = 0;
			rand_obstacol[2][3] = rand() % 90;
			if (coliziune_obstacol[3] == 1)
				moare2--;
			coliziune_obstacol[3] = 0;
		}
		if (start2[4] + end2[4] < -20) {
			start2[4] = 40;
			end2[4] = 0;
			rand_obstacol[2][4] = rand() % 90;
			if (coliziune_obstacol[4] == 1)
				moare2--;
			coliziune_obstacol[4] = 0;
		}

		for (int j = 0;j < 5;j++)
			if ((start2[j] + end2[j]) < 1.5f && (start2[j] + end2[j]) > -1.5f && 30.0f + rand_obstacol[2][j] / 10.0f > 28 + move_Y && 29.25f + rand_obstacol[2][j] / 10.0f + 1 < 28 + move_Y + 4) {
				coliziune_obstacol[j] = 1;
			}
		moare = moare2;
		for (int i = 0;i < 5;i++) {

			if (coliziune_obstacol[i] == 1)
				if (moare > 0) {
					moare--;
				}
		}

		for (int j = 0;j < 5;j++)
		{
			if (coliziune_obstacol[j] == 0)
			{
				glm::mat4 modelMatrix = glm::mat4(1);
				modelMatrix = glm::translate(modelMatrix, glm::vec3(start2[j] + end2[j], 30.0f + rand_obstacol[2][j] / 10.0f, -1.0f));
				RenderSimpleMesh(meshes["sphere"], shaders["VertexNormal"], modelMatrix);
			}
		}


		//generare nori
		if ((50.25f) * cos(x[0]) < -50) {
			rand_nori1[0] = rand() % 5 + 2;
			x[0] = 30;
			for (int k = 0;k <= rand_nori1[0];k++) {
				rand_nori2[0][k] = rand() % 3 + 2;
			}
			for (int i = 0;i < 10;i++)
				for (int j = 0;j < 4;j++)
					rot[0][i][j] = rand() % 2;
		}
		if ((50.25f) * cos(x[1]) < -50) {
			rand_nori1[1] = rand() % 5 + 2;
			x[1] = 30;
			for (int k = 0;k <= rand_nori1[1];k++) {
				rand_nori2[1][k] = rand() % 3 + 2;
			}
			for (int i = 0;i < 10;i++)
				for (int j = 0;j < 4;j++)
					rot[1][i][j] = rand() % 2;
		}
		if ((50.25f) * cos(x[2]) < -50) {
			rand_nori1[2] = rand() % 5 + 2;
			x[2] = 30;
			for (int k = 0;k <= rand_nori1[2];k++) {
				rand_nori2[2][k] = rand() % 3 + 2;
			}
			for (int i = 0;i < 10;i++)
				for (int j = 0;j < 4;j++)
					rot[2][i][j] = rand() % 2;
		}

		if ((50.25f) * cos(x[3]) < -50) {
			rand_nori1[3] = rand() % 5 + 2;
			x[3] = 30;
			for (int k = 0;k <= rand_nori1[3];k++) {
				rand_nori2[3][k] = rand() % 3 + 2;
			}
			for (int i = 0;i < 10;i++)
				for (int j = 0;j < 4;j++)
					rot[3][i][j] = rand() % 2;
		}
		for (int j = 0;j < rand_nori1[0];j++) {
			{
				y = j;
				z = rand_nori2[0][j];
				glm::mat4 modelMatrix = glm::mat4(1);
				modelMatrix = glm::translate(modelMatrix, glm::vec3((50.25f) * cos(x[0] + y / (10.0f - z / 5.0f)), (50.25f) * sin(x[0] + y / (10.0f - z / 5.0f)), -70));
				modelMatrix = glm::scale(modelMatrix, glm::vec3(rand_nori2[0][j], rand_nori2[0][j], rand_nori2[0][j]));
				modelMatrix = glm::rotate(modelMatrix, angle / 10, glm::vec3(rot[0][j][0], rot[0][j][1], rot[0][j][2]));
				modelMatrix = glm::translate(modelMatrix, glm::vec3(-0.5f, -0.3f, -0.2f));
				RenderSimpleMesh(meshes["box"], shaders["VertexNormal"], modelMatrix);
			}
		}
		for (int j = 0;j < rand_nori1[1];j++) {
			{
				y = j;
				z = rand_nori2[1][j];
				glm::mat4 modelMatrix = glm::mat4(1);
				modelMatrix = glm::translate(modelMatrix, glm::vec3((50.25f) * cos(x[1] + y / (10.0f - z / 5.0f)), (50.25f) * sin(x[1] + y / (10.0f - z / 5.0f)), -70));
				modelMatrix = glm::scale(modelMatrix, glm::vec3(rand_nori2[1][j], rand_nori2[1][j], rand_nori2[1][j]));
				modelMatrix = glm::rotate(modelMatrix, angle / 10, glm::vec3(rot[1][j][0], rot[1][j][1], rot[1][j][2]));
				modelMatrix = glm::translate(modelMatrix, glm::vec3(-0.5f, -0.3f, -0.2f));
				RenderSimpleMesh(meshes["box"], shaders["VertexNormal"], modelMatrix);
			}
		}
		for (int j = 0;j < rand_nori1[2];j++) {
			{
				y = j;
				z = rand_nori2[2][j];
				glm::mat4 modelMatrix = glm::mat4(1);
				modelMatrix = glm::translate(modelMatrix, glm::vec3((50.25f) * cos(x[2] + y / (10.0f - z / 5.0f)), (50.25f) * sin(x[2] + y / (10.0f - z / 5.0f)), -70));
				modelMatrix = glm::scale(modelMatrix, glm::vec3(rand_nori2[2][j], rand_nori2[2][j], rand_nori2[2][j]));
				modelMatrix = glm::rotate(modelMatrix, angle / 10, glm::vec3(rot[2][j][0], rot[2][j][1], rot[2][j][2]));
				modelMatrix = glm::translate(modelMatrix, glm::vec3(-0.5f, -0.3f, -0.2f));
				RenderSimpleMesh(meshes["box"], shaders["VertexNormal"], modelMatrix);
			}
		}
		for (int j = 0;j < rand_nori1[3];j++) {
			{
				y = j;
				z = rand_nori2[3][j];
				glm::mat4 modelMatrix = glm::mat4(1);
				modelMatrix = glm::translate(modelMatrix, glm::vec3((50.25f) * cos(x[3] + y / (10.0f - z / 5.0f)), (50.25f) * sin(x[3] + y / (10.0f - z / 5.0f)), -70));
				modelMatrix = glm::scale(modelMatrix, glm::vec3(rand_nori2[3][j], rand_nori2[3][j], rand_nori2[3][j]));
				modelMatrix = glm::rotate(modelMatrix, angle / 10, glm::vec3(rot[3][j][0], rot[3][j][1], rot[3][j][2]));
				modelMatrix = glm::translate(modelMatrix, glm::vec3(-0.5f, -0.3f, -0.2f));
				RenderSimpleMesh(meshes["box"], shaders["VertexNormal"], modelMatrix);
			}
		}
	}

	//game over screen si scor
	if (screen == 2) {

		if (score_afisaj == 0) {
			printf("Scorul tau este: %f\n", score);
			score_afisaj = 1;
		}

		//resetare joc
		x[0] = 0;x[1] = -30;x[2] = -40;x[3] = -70;
		rand_nori1[0] = 5;rand_nori1[1] = 4;rand_nori1[2] = 6;rand_nori1[3] = 5;rand_nori1[4] = 4;
		for(int i=0;i<3;i++)
			for (int k = 0;k <= rand_nori1[2];k++) 
				rand_nori2[i][k] = rand() % 3 + 2;
		start[0] = 40;start[1] = 70;start[2] = 80;start[3] = 100;start[4] = 160;
		end[0] = 0;end[1] = 0;end[2] = 0;end[3] = 0;
		move_Y = 0;
		rotate_plane, rotate_back = 0;
		stabilizare = 0;
		camera_view = 0;
		moare = 3;
		moare2 = 3;
		start2[0] = 0;start2[1] = 18;start2[2] = 35;start2[3] = 48;start2[4] = 67;
		end2[0] = 0;end2[1] = 0;end2[2] = 0;end2[3] = 0;end2[4] = 0;
		end_game = 0.0f;
		game_over = 0;
		score = 0.0f;


		for (int i = 0;i < 2;i++)
			for (int j = 0;j < 10;j++)
				coliziune_bonus[i][j] = 0;

		camera_view = 0;
		for (int i = 0;i < 6;i++) {
			coliziune_obstacol[i] = 0;
			for (int j = 0;j < 10;j++) {
				rand_obstacol[i][j] = rand() % 90;
				for (int k = 0;k < 4;k++) {
					rot[i][j][k] = rand() % 2;
				}
			}
		}

		move_Y = 0;
		move_X = 0;

		viteza = 0.0f;

		float angle = 0;
		fuel = 0;
		{
			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix = glm::translate(modelMatrix, glm::vec3(-1 + move_X, 30 , -1));
			modelMatrix = glm::scale(modelMatrix, glm::vec3(5, 5, 5));
			modelMatrix = glm::translate(modelMatrix, glm::vec3(-0.5f, -0.5f, -0.3f));
			RenderSimpleMesh(meshes["plane"], shaders["VertexNormal"], modelMatrix);

		} 
		{
			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix = glm::translate(modelMatrix, glm::vec3(5.4f,29.2f, -1));
			modelMatrix = glm::translate(modelMatrix, glm::vec3(+2.15f - 0.5f, +0.25f - 0.5f, +0.25f - 0.3f));
			modelMatrix = glm::scale(modelMatrix, glm::vec3(5, 5, 5));
			modelMatrix = glm::translate(modelMatrix, glm::vec3(-2.15f, -0.25f, -0.25f));
			RenderSimpleMesh(meshes["elice"], shaders["VertexNormal"], modelMatrix);
		
		}
		{
			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix = glm::translate(modelMatrix, glm::vec3(35.4f, 30.2f, -15));
			modelMatrix = glm::translate(modelMatrix, glm::vec3(+2.15f - 0.5f, +0.25f - 0.5f, +0.25f - 0.3f));
			modelMatrix = glm::scale(modelMatrix, glm::vec3(15, 15, 15));
			modelMatrix = glm::translate(modelMatrix, glm::vec3(-2.15f, -0.25f, -0.25f));
			RenderSimpleMesh(meshes["sphere"], shaders["VertexNormal"], modelMatrix);
		}
	}
}

void Tema2::FrameEnd()
{
}

void Tema2::RenderSimpleMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix)
{
	if (!mesh || !shader || !shader->GetProgramID())
		return;

	// render an object using the specified shader and the specified position
	glUseProgram(shader->program);

	// TODO : get shader location for uniform mat4 "Model"
	int location = glGetUniformLocation(shader->GetProgramID(), "Model");
	// TODO : set shader uniform "Model" to modelMatrix
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(modelMatrix));

	// TODO : get shader location for uniform mat4 "View"
	location = glGetUniformLocation(shader->GetProgramID(), "View");
	// TODO : set shader uniform "View" to viewMatrix
	glm::mat4 viewMatrix = GetSceneCamera()->GetViewMatrix();

	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(viewMatrix));
	// TODO : get shader location for uniform mat4 "Projection"
	location = glGetUniformLocation(shader->GetProgramID(), "Projection");
	// TODO : set shader uniform "Projection" to projectionMatrix
	glm::mat4 projectionMatrix = GetSceneCamera()->GetProjectionMatrix();
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

	// TODO : get shader location for float  "Projection"
	location = glGetUniformLocation(shader->GetProgramID(), "Time");
	glUniform1f(location, Engine::GetElapsedTime());

	// Draw the object
	glBindVertexArray(mesh->GetBuffers()->VAO);
	glDrawElements(mesh->GetDrawMode(), static_cast<int>(mesh->indices.size()), GL_UNSIGNED_SHORT, 0);
}

// Documentation for the input functions can be found in: "/Source/Core/Window/InputController.h" or
// https://github.com/UPB-Graphics/Framework-EGC/blob/master/Source/Core/Window/InputController.h

void Tema2::OnInputUpdate(float deltaTime, int mods)
{
	// add key press event
}

void Tema2::OnKeyPress(int key, int mods)
{
	if (key == GLFW_KEY_V)
		if (camera_view == 0)
			camera_view = 1;
		else
			camera_view = 0;
	if (key == GLFW_KEY_R)
		if (screen == 2) {
			screen = 1;
			score_afisaj = 0;
		}
}

void Tema2::OnKeyRelease(int key, int mods)
{
	// add key release event
}

void Tema2::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	if(move_Y- deltaY / 50.0f >-2.0f && move_Y- deltaY / 50.0f <8.5f)
		move_Y -= deltaY/50.0f;
	if (deltaY != 0) {
		rotate_plane = deltaY;
		stabilizare = 0;
	}
}

void Tema2::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button press event
}

void Tema2::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button release event
}

void Tema2::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Tema2::OnWindowResize(int width, int height)
{
}