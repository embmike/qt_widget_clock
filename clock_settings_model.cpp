/**
 * @file clock_settings_model.cpp
 * @brief Implementierung des Modells für Anzeigeeinstellungen der LCD-Uhr.
 */
#include "clock_settings_model.h"

#include <QSettings>

const QMap<ClockSettingsModel::ClockColor, QColor> ClockSettingsModel::_color_map{
     {ClockSettingsModel::ClockColor::White, Qt::white}
    ,{ClockSettingsModel::ClockColor::White, Qt::green}
    ,{ClockSettingsModel::ClockColor::White, Qt::red}
    ,{ClockSettingsModel::ClockColor::White, Qt::darkBlue}
    ,{ClockSettingsModel::ClockColor::White, Qt::black}
};


ClockSettingsModel::ClockSettingsModel(QObject *parent)
    : QObject{parent}
{
    load();
}

ClockSettingsModel::ClockColor ClockSettingsModel::color() const
{
    return _color;
}

QColor ClockSettingsModel::getQColor(ClockColor color)
{
    return _color_map.value(color);
}

void ClockSettingsModel::setColor(ClockColor color)
{ 
    if (_color == color)
    {
        return;
    }

    _color = color;
    save();
    emit colorChanged(_color);
}

void ClockSettingsModel::load()
{
    QSettings settings{};

    const int clock_color{settings.value(_color_key, static_cast<int>(ClockColor::Black)).toInt()};
    _color = static_cast<ClockColor>(clock_color);
}

void ClockSettingsModel::save() const
{
    QSettings settings{};
    settings.setValue(_color_key, static_cast<int>(_color));
}
