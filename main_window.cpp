/**
 * @file main_window.cpp
 * @brief Implementierung des MainWindow.
 */
#include "main_window.h"
#include "./ui_main_window.h"

#include <QTimer>
#include <QTime>
#include <QMouseEvent>
#include <QMenu>
#include <QAction>
#include <QSettings>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);

    QSettings sts{};
    restoreGeometry(sts.value("main_geometry").toByteArray());
    restoreState(sts.value("main_state").toByteArray());

    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | windowFlags());

    connect(this, &MainWindow::customContextMenuRequested, this, &MainWindow::showContextMenu);
    _ui->_lcd_number->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(_ui->_lcd_number, &QLCDNumber::customContextMenuRequested, this, [this](const QPoint &pos)
    {
        showContextMenu(_ui->_lcd_number->mapTo(this, pos));
    });

    QTimer *timer{new QTimer(this)};

    connect(timer, &QTimer::timeout, this, &MainWindow::updateTime);

    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete _ui;
}

void MainWindow::updateTime()
{
    QTime current_time{QTime::currentTime()};
    QString current_time_text{current_time.toString("hh:mm")};

    if (current_time.second() % 2 == 0)
    {
        current_time_text[2] = ' ';
    }

    _ui->_lcd_number->display(current_time_text);
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
    QSettings  sts{};

    sts.setValue("main_geometry", saveGeometry());
    sts.setValue("main_state", saveState());

    e->accept();
}
