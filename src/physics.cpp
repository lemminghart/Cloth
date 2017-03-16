#include <imgui\imgui.h>
#include <imgui\imgui_impl_glfw_gl3.h>

#include "../Particle.h"
#include "../Solvers.h"
#include "../Collision.h"

namespace ClothMesh {
	extern void setupClothMesh();
	extern void cleanupClothMesh();
	extern void updateClothMesh(float* array_data);
	extern void drawClothMesh();
	extern const int numCols; //14
	extern const int numRows; //18
	extern const int numVerts; // 14 * 18 = 252
}

//Namespace para manejar variables propias del sistema
namespace Utils { 
	//time
	int time = 0;
	float percent = 0.f;
	//solver
	int solver = EULER; //CAN BE EULER or VERLET
	//position of first particle
	Coord pos{ -3.5f, 9.75f, -4.75f };
	//separation between particles
	float part_separation = 0.5f;
}

bool show_test_window = false;
void GUI() {
	{	//FrameRate
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

		//TODO
	}

	// ImGui test window. Most of the sample code is in ImGui::ShowTestWindow()
	if(show_test_window) {
		ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiSetCond_FirstUseEver);
		ImGui::ShowTestWindow(&show_test_window);
	}
}

void PhysicsInit() {
	//TODO

	//we will set up a first particle and then build the mesh from that particle
	//set up the first particle

	Particle temp(true, Utils::pos); //the first particle is fixed
	
	//we initialite the following particles in base of the first particle
	for (int i = 1; i <= ClothMesh::numRows; i++) {
		for (int j = 1; j <= ClothMesh::numCols; j++) {
			Particle temp2(&temp, Utils::part_separation * j, Utils::part_separation * i);
			partArray.push_back(temp2);
		}
	}

	//fijamos las particulas en el techo
	partArray[0].fixed = true;
	partArray[ClothMesh::numCols - 1].fixed = true;

}
void PhysicsUpdate(float dt) {
	//TODO

	if (Utils::solver == EULER) {
		for (int i = 0; i < ClothMesh::numVerts; i++) {
			if (!partArray[i].fixed) {
				Euler_Solver(&partArray[i], dt);
				Collision_Manager(&partArray[i], Utils::solver);
			}
		}
	}

	//Update de las particulas
	float *partVerts = new float[ClothMesh::numVerts * 3];
	for (int i = 0; i < ClothMesh::numVerts; ++i) {
			partVerts[i * 3 + 0] = partArray[i].currentPos.x;
			partVerts[i * 3 + 1] = partArray[i].currentPos.y;
			partVerts[i * 3 + 2] = partArray[i].currentPos.z;
	}
	ClothMesh::updateClothMesh(partVerts);
}
void PhysicsCleanup() {
	//TODO
}