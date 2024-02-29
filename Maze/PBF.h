#pragma once
#include <vector>
#include "MatrixAdj.h"

class PBF
{
public:
	static void createPathsToExits(MatrixAdj& matrix);

private:
	static void createParentNodes(const std::vector<std::vector<int>>& adjacencyMatrix, const int startNode);
	static std::vector<std::vector<int>> createPaths(const std::vector<int>& exitNodes, const int startNode);
	static void alterInputMatrix(MatrixAdj& matrix, const std::vector<std::vector<int>>& paths);

	static std::vector<int> m_fatherNodeVector;
};