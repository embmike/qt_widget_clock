/**
 * @file main_window.cpp
 * @brief Implementierung des MainWindow.
 */
#include "main_window.h"
#include "lcd_clock.h"
#include "./ui_main_window.h"

#include <QMouseEvent>
#include <QMenu>
#include <QAction>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , _ui(new Ui::MainWindow)
    , _lcd_clock(nullptr)
{
    _ui->setupUi(this);
    _lcd_clock = new LcdClock(_ui->_lcd_number, this);

    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | windowFlags());

    connect(this, &MainWindow::customContextMenuRequested, this, &MainWindow::showContextMenu);
    _ui->_lcd_number->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(_ui->_lcd_number, &QLCDNumber::customContextMenuRequested, this, [this](const QPoint &pos)
    {
        showContextMenu(_ui->_lcd_number->mapTo(this, pos));
    });
}

MainWindow::~MainWindow()
{
    delete _ui;
}

void MainWindow::showContextMenu(const QPoint &pos)
{
    QMenu context_menu{};

    context_menu.addAction(QString("Exit"), this, SLOT(close()));
    context_menu.exec(mapToGlobal(pos));
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    _mouse_pos = e->pos();
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    this->move(e->globalPosition().toPoint() - _mouse_pos);
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->button() == Qt::RightButton)
    {
        emit customContextMenuRequested(e->pos());
    }
    else
    {
        QMainWindow::mouseReleaseEvent(e);
    }
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    e->accept();
}
