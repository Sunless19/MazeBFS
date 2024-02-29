#pragma once
#include<vector>
#include<string>
#include<fstream>

class MatrixAdj 
{
public:
	MatrixAdj() = default;
	MatrixAdj(std::ifstream& file);

	std::vector<std::vector<int>> getAdMatrix() const;
	std::vector<std::vector<std::pair<int, int>>> &getInputMatrix();
	int getStartNode() const;
	std::vector<int> getExitNodes() const;

private:
	void setAdMatrix();
	void initAdMatrix();
	void setInputMatrix(std::ifstream& file);

	int m_startNode;
	int m_numberNodes;
	std::vector<int> m_exitNodes;
	std::vector<std::vector<std::pair<int, int>>> m_inputMatrix;
	std::vector<std::vector<int>> m_adjacencyMatrix;
};