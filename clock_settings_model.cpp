/**
 * @file clock_settings_model.cpp
 * @brief Implementierung des Modells für Anzeigeeinstellungen der LCD-Uhr.
 */
#include "clock_settings_model.h"

#include <QSettings>
#include <algorithm>
#include <array>

namespace
{
constexpr auto kColourKey{"Colour"};
constexpr std::array<ClockSettingsModel::ClockColor, 5> kAvailableColors{
    ClockSettingsModel::ClockColor::White,
    ClockSettingsModel::ClockColor::Green,
    ClockSettingsModel::ClockColor::Red,
    ClockSettingsModel::ClockColor::Dark_Blue,
    ClockSettingsModel::ClockColor::Black,
};
}

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
    const auto persisted_value{
        static_cast<size_t>(settings.value(
            kColourKey,
            static_cast<int>(ClockSettingsModel::ClockColor::Black)).toInt())};
    const auto persisted_color{
        static_cast<ClockSettingsModel::ClockColor>(persisted_value)};

    if (std::find(kAvailableColors.cbegin(), kAvailableColors.cend(), persisted_color)
        != kAvailableColors.cend())
    {
        _color = persisted_color;
        return;
    }

    _color = ClockSettingsModel::ClockColor::Black;
}

void ClockSettingsModel::save() const
{
    QSettings settings{};
    settings.setValue(kColourKey, static_cast<int>(_color));
}
