#pragma once
#include "../Particle.h"

struct Index {
	int F, C; //Fila & Columna
};

namespace ClothMesh {
	extern void setupClothMesh();
	extern void cleanupClothMesh();
	extern void updateClothMesh(float* array_data);
	extern void drawClothMesh();
	extern const int numCols; //14
	extern const int numRows; //18
	extern const int numVerts; // 14 * 18 = 252
}

static Index Calculate_Index(int indice) {
	return Index{
		(indice / ClothMesh::numCols),
		(indice % ClothMesh::numCols)
	};
}

static glm::vec3 Apply_Formula(int indice) {
	partArray[indice].forces += -1 * (ke()-L)+kd(v1-v2) * P1-P2/P1-P2) * P1 - P2 / P1 - P2
}

static float Calculate_Structural(Index partIndex) {
	
	
}

static void Calculate_Forces(int indice) {
	
	Index partIndex = Calculate_Index(indice);
	
	//Comprobación de particulas colindantes
	//HORIZONTAL
	if (partIndex.C < (ClothMesh::numCols - 1)) {
		Calculate_Structural






			
	}
	//comprobar particulas colindantes
	//aplicar calculo structural

	//repetir con shear

	//repetir con bend

	
}