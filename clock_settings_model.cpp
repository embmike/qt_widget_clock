/**
 * @file clock_settings_model.cpp
 * @brief Implementierung des Modells für Anzeigeeinstellungen der LCD-Uhr.
 */
#include "clock_settings_model.h"

#include <QSettings>

#include "enum_index.h"

namespace
{
constexpr auto kColourKey{"Colour"};
}

const QMap<size_t, QColor> ClockSettingsModel::_color_map{
     {enum_index(ClockSettingsModel::ClockColor::White), Qt::white}
    ,{enum_index(ClockSettingsModel::ClockColor::White), Qt::green}
    ,{enum_index(ClockSettingsModel::ClockColor::White), Qt::red}
    ,{enum_index(ClockSettingsModel::ClockColor::White), Qt::darkBlue}
    ,{enum_index(ClockSettingsModel::ClockColor::White), Qt::black}
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
    QSettings settings{};

    //const size_t persisted_value{static_cast<size_t>(settings.value(kColourKey, _color).toInt())};

    _color = settings.value(kColourKey, _color); // Stelle korregieren
}

void ClockSettingsModel::save() const
{
    QSettings settings{};
    settings.setValue(kColourKey, static_cast<int>(_color));
}
