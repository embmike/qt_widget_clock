/**
 * @file clock_settings_model.cpp
 * @brief Implementierung des Modells für Anzeigeeinstellungen der LCD-Uhr.
 */
#include "clock_settings_model.h"

#include <QSettings>

namespace
{
constexpr auto kColourKey{"Colour"};
}

ClockSettingsModel::ClockSettingsModel(QObject *parent)
    : QObject(parent)
{
    load();
}

ClockSettingsModel::ClockColor ClockSettingsModel::color() const
{
    return _color;
}

void ClockSettingsModel::setColor(ClockSettingsModel::ClockColor color)
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
    QSettings settings;
    const int persisted_value{settings.value(kColourKey, static_cast<int>(ClockColor::Green)).toInt()};
    switch (persisted_value)
    {
    case static_cast<int>(ClockColor::Black):
        _color = ClockColor::Black;
        break;
    case static_cast<int>(ClockColor::White):
        _color = ClockColor::White;
        break;
    case static_cast<int>(ClockColor::Red):
        _color = ClockColor::Red;
        break;
    case static_cast<int>(ClockColor::Green):
    default:
        _color = ClockColor::Green;
        break;
    }
}

void ClockSettingsModel::save() const
{
    QSettings settings;
    settings.setValue(kColourKey, static_cast<int>(_color));
}
