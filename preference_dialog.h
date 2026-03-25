/**
 * @file preference_dialog.h
 * @brief Dialog-View zur Auswahl der LCD-Uhrfarbe.
 */
#ifndef PREFERENCE_DIALOG_H
#define PREFERENCE_DIALOG_H

#include "clock_settings_model.h"

#include <QDialog>

class QComboBox;

/**
 * @brief Einfache View für die Auswahl der Uhrfarbe.
 */
class PreferenceDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Erzeugt den Einstellungsdialog mit vorausgewählter Farbe.
     * @param initial_color Initial ausgewählte Farbe.
     * @param parent Optionales Parent-Widget.
     */
    explicit PreferenceDialog(ClockSettingsModel::ClockColor initial_color, QWidget *parent = nullptr);

    /**
     * @brief Liefert die im Dialog gewählte Farbe.
     * @return Gewählte Farbauswahl.
     */
    ClockSettingsModel::ClockColor selectedColor() const;

private:
    /** @brief Auswahlliste für verfügbare Farben. */
    QComboBox *_color_box{nullptr};
};

#endif // PREFERENCE_DIALOG_H
