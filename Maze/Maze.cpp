#include "Maze.h"

Maze::Maze(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.startButton->setCheckable(true);
	std::ifstream file("inputMatrix.txt");
	MatrixAdj auxMatrix(file);
	m_matrices = auxMatrix;
	StartProgram = false;
	update();
}

Maze::~Maze()
{}

void Maze::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	DrawMaze(painter);
}

void Maze::mouseReleaseEvent(QMouseEvent* event)
{
	if (ui.startButton->isChecked())
	{
		StartProgram = true;
		update();
		StartProgram = false;
		ui.startButton->setEnabled(false);
		PBF::createPathsToExits(m_matrices);
		update();
	}
}

void Maze::DrawMaze(QPainter& painter)
{
	int yIt = 0;
	for (const auto& aux1 : m_matrices.getInputMatrix())
	{
		int xIt = 0;
		for (const auto aux2 : aux1)
		{
			painter.setBrush(setBrushColor(aux2.first)); painter.drawRect(0 + xIt * squareDimension, yIt * squareDimension, squareDimension, squareDimension);
			xIt++;
		}
		yIt++;
	}
	painter.setBrush(Qt::white);
}

QBrush Maze::setBrushColor(const int value)
{
	switch (value)
	{
	case 0:
	{
		return Qt::black;

	}
	case 1:
	{
		return Qt::gray;
	}
	case 2:
	{
		return Qt::red;
	}
	case 4:
	{
		return Qt::green;
	}
	default:
	{
		return Qt::blue;
	}
	}
}
