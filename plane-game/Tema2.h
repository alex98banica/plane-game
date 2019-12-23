#pragma once
#include <Component/SimpleScene.h>
#include <Core/GPU/Mesh.h>

class Tema2 : public SimpleScene
{
	public:
		Tema2();
		~Tema2();

		void Init() override;

		Mesh * CreateMesh(const char * name, const std::vector<VertexFormat> &vertices, const std::vector<unsigned short> &indices);
		//Mesh* CreateCircle(std::string name, glm::vec3 leftBottomCorner, float radius, glm::vec3 color, bool fill);
		Mesh* Tema2::CreateWater(std::string name, float length);
		Mesh* Tema2::CreateSphere(std::string name, float length);

	private:
		void FrameStart() override;
		void Update(float deltaTimeSeconds) override;
		void FrameEnd() override;

		void RenderSimpleMesh(Mesh *mesh, Shader *shader, const glm::mat4 &modelMatrix);

		void OnInputUpdate(float deltaTime, int mods) override;
		void OnKeyPress(int key, int mods) override;
		void OnKeyRelease(int key, int mods) override;
		void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
		void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
		void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
		void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
		void OnWindowResize(int width, int height) override;
		float angle;
		float dist_i, dist_f;
		float y,z;
		float x[10] = { 0,-30,-40,-70,100,120,160 };
		int rand_nori1[10] = {5,4,6,5,4};
		int rand_nori2[10][10] = { {4,5,5,6},{6,5,4,4}, {4,5,4,6} };
		int rand_puncte[10];
		float start[10] = { 40,70,80,100,160 };
		float end[10] = { 0,0,0,0 };
		int rot[6][10][3];
		float move_Y=0,move_X;
		float rotate_plane,rotate_back=0;
		float stabilizare = 0;
		int camera_view = 0;
		int coliziune_bonus[2][10] ;
		int coliziune_obstacol[10];
		float fuel;
		int moare=3,moare2=3;
		float rand_obstacol[10][10];
		float start2[10] = { 0,18,35,48,67 }, end2[10] = { 0,0,0,0,0 };
		float end_game = 0.0f;
		int screen=1;
		float last_poz,game_over=0;
		float viteza = 0.0f;
		float score = 0.0f;
		int score_afisaj=0;
};
