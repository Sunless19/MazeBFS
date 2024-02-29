#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Maze.h"
#include<fstream>
#include<qradiobutton.h>
#include<QPainter>
#include<vector>
#include "MatrixAdj.h"
#include "PBF.h"
#include<QMouseEvent>
#include<qwidget.h>

class Maze : public QMainWindow
{
    Q_OBJECT

public:
    Maze(QWidget *parent = nullptr);
    ~Maze();
    virtual void paintEvent(QPaintEvent* event) override;
    virtual void mouseReleaseEvent(QMouseEvent* event) override;

private:
    void DrawMaze(QPainter& painter);
    static QBrush setBrushColor(const int specifier);

    MatrixAdj m_matrices;
    bool StartProgram;
    Ui::MazeClass ui;
    inline static int squareDimension = 57;
};
