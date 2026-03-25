/**
 * @file lcd_clock.cpp
 * @brief Implementierung der Logikkomponente für die LCD-Uhr.
 */
#include "lcd_clock.h"

#include <QLCDNumber>
#include <QTime>
#include <QTimer>

LcdClock::LcdClock(QLCDNumber *display, QObject *parent)
    : QObject(parent)
    , _display(display)
    , _timer(new QTimer(this))
{
    connect(_timer, &QTimer::timeout, this, &LcdClock::updateDisplay);
    _timer->start(1000);
    updateDisplay();
}

void LcdClock::updateDisplay()
{
    QTime current_time{QTime::currentTime()};
    QString current_time_text{current_time.toString("hh:mm")};

    if (current_time.second() % 2 == 0)
    {
        current_time_text[2] = ' ';
    }

    _display->display(current_time_text);
}
