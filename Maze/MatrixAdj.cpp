#include "MatrixAdj.h"
#include<algorithm>

int MatrixAdj::getStartNode() const
{
	return m_startNode;
}

std::vector<int> MatrixAdj::getExitNodes() const
{
	return m_exitNodes;
}

void MatrixAdj::setAdMatrix()
{
	for (int i = 1; i <= m_numberNodes; i++)
	{
		std::pair<bool, int> target(0, i);
		int rowPosition = 0;
		for (auto& row : m_inputMatrix)
		{

			const auto it = std::find_if(row.begin(), row.end(),
				[target](const std::pair<int, int>& element) {
					return element.second == target.second;
				});
			const int columnPosition = std::distance(row.begin(), it);
			if (it != row.end())
			{
				if (rowPosition + 1 < m_inputMatrix.size() && m_inputMatrix[rowPosition + 1][columnPosition].second)
				{
					m_adjacencyMatrix[i - 1][m_inputMatrix[rowPosition + 1][columnPosition].second - 1] = 1;
					m_adjacencyMatrix[m_inputMatrix[rowPosition + 1][columnPosition].second - 1][i - 1] = 1;
				}
				if (rowPosition - 1 >= 0 && m_inputMatrix[rowPosition - 1][columnPosition].second)
				{
					m_adjacencyMatrix[i - 1][m_inputMatrix[rowPosition - 1][columnPosition].second - 1] = 1;
					m_adjacencyMatrix[m_inputMatrix[rowPosition - 1][columnPosition].second - 1][i - 1] = 1;
				}
				if (columnPosition + 1 < row.size() && m_inputMatrix[rowPosition][columnPosition + 1].second)
				{
					m_adjacencyMatrix[i - 1][m_inputMatrix[rowPosition][columnPosition + 1].second - 1] = 1;
					m_adjacencyMatrix[m_inputMatrix[rowPosition][columnPosition + 1].second - 1][i - 1] = 1;
				}
				if (columnPosition - 1 >= 0 && m_inputMatrix[rowPosition][columnPosition - 1].second)
				{
					m_adjacencyMatrix[i - 1][m_inputMatrix[rowPosition][columnPosition - 1].second - 1] = 1;
					m_adjacencyMatrix[m_inputMatrix[rowPosition][columnPosition - 1].second - 1][i - 1] = 1;
				}
				break;
			}
			rowPosition++;
		}
	}
}

void MatrixAdj::initAdMatrix()
{
	for (int i = 0; i < m_numberNodes; i++) {
		std::vector<int> row(m_numberNodes, 0);
		m_adjacencyMatrix.push_back(row);
	}
}

void MatrixAdj::setInputMatrix(std::ifstream& file)
{
	std::string row;
	for (int i = 0; std::getline(file, row); i++)
	{
		std::vector<std::pair<int, int>> aux;
		for (const auto& it : row)
		{
			if (it != 32)
			{
				aux.emplace_back(it - '0', 0);
				if (it != '0')
				{
					m_numberNodes++;
					aux[aux.size() - 1].second = m_numberNodes;
				}
				if (it == '3')
				{
					m_startNode = m_numberNodes - 1;
				}
				else if (it == '2')
				{
					m_exitNodes.push_back(m_numberNodes - 1);
				}
			}

		}
		m_inputMatrix.push_back(aux);
	}
}


MatrixAdj::MatrixAdj(std::ifstream& file) :
	m_numberNodes{0}
{
	setInputMatrix(file);
	initAdMatrix();
	setAdMatrix();
}

std::vector<std::vector<int>> MatrixAdj::getAdMatrix() const
{
	return m_adjacencyMatrix;
}

std::vector<std::vector<std::pair<int, int>>>& MatrixAdj::getInputMatrix()
{
	return m_inputMatrix;
}