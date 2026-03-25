/**
 * @file lcd_clock.cpp
 * @brief Implementierung der Logikkomponente für die LCD-Uhr.
 */
#include "lcd_clock.h"
#include "preference_dialog.h"

#include <QLCDNumber>
#include <QPalette>
#include <QTime>
#include <QTimer>

LcdClock::LcdClock(QLCDNumber *display, ClockSettingsModel *settings, QObject *parent)
    : QObject(parent)
    , _display(display)
    , _settings(settings)
    , _timer(new QTimer(this))
{
    connect(_timer, &QTimer::timeout, this, &LcdClock::updateDisplay);
    connect(_settings, &ClockSettingsModel::colorChanged, this, &LcdClock::applyColor);
    _timer->start(1000);
    applyColor(_settings->color());
    updateDisplay();
}

void LcdClock::showPreferencesDialog(QWidget *parent)
{
    PreferenceDialog dialog(_settings->color(), parent);
    if (dialog.exec() == QDialog::Accepted)
    {
        _settings->setColor(dialog.selectedColor());
    }
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

void LcdClock::applyColor(ClockSettingsModel::ClockColor color)
{
    QPalette palette{};
    switch (color)
    {
    case ClockSettingsModel::ClockColor::Black:
        palette.setColor(QPalette::WindowText, Qt::black);
        break;
    case ClockSettingsModel::ClockColor::White:
        palette.setColor(QPalette::WindowText, Qt::white);
        break;
    case ClockSettingsModel::ClockColor::Red:
        palette.setColor(QPalette::WindowText, Qt::red);
        break;
    case ClockSettingsModel::ClockColor::Green:
    default:
        palette.setColor(QPalette::WindowText, Qt::green);
        break;
    }

    _display->setPalette(palette);
}
