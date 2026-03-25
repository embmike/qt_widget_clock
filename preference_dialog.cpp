/**
 * @file preference_dialog.cpp
 * @brief Implementierung des Dialogs zur Auswahl der LCD-Uhrfarbe.
 */
#include "preference_dialog.h"

#include <QComboBox>
#include <QDialogButtonBox>
#include <QVBoxLayout>

PreferenceDialog::PreferenceDialog(ClockSettingsModel::ClockColor initial_color, QWidget *parent)
    : QDialog(parent)
    , _color_box(new QComboBox(this))
{
    setWindowTitle(QString("Preferences"));

    _color_box->addItem(QString("White"), static_cast<int>(ClockSettingsModel::ClockColor::White));
    _color_box->addItem(QString("Green"), static_cast<int>(ClockSettingsModel::ClockColor::Green));
    _color_box->addItem(QString("Red"), static_cast<int>(ClockSettingsModel::ClockColor::Red));
    _color_box->addItem(QString("Black"), static_cast<int>(ClockSettingsModel::ClockColor::Black));
    _color_box->addItem(QString("Dark blue"), static_cast<int>(ClockSettingsModel::ClockColor::Dark_Blue));
    _color_box->setCurrentIndex(static_cast<int>(initial_color));

    QDialogButtonBox *buttons{
        new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this)};
    connect(buttons, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttons, &QDialogButtonBox::rejected, this, &QDialog::reject);

    QVBoxLayout *layout{new QVBoxLayout(this)};
    layout->addWidget(_color_box);
    layout->addWidget(buttons);
}

ClockSettingsModel::ClockColor PreferenceDialog::selectedColor() const
{
    return static_cast<ClockSettingsModel::ClockColor>(_color_box->currentData().toInt());
}
