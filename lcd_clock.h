/**
 * @file lcd_clock.h
 * @brief Deklaration der Logikkomponente für die LCD-Uhr.
 */
#ifndef LCD_CLOCK_H
#define LCD_CLOCK_H

#include "clock_settings_model.h"

#include <QObject>

class QLCDNumber;
class QTimer;
class QWidget;

/**
 * @brief Controller für die LCD-Uhr.
 *
 * @details Die Klasse verbindet Clock-Model und LCD-View:
 * - zyklische Zeitaktualisierung
 * - Anwenden der konfigurierten Textfarbe
 * - Öffnen des Präferenzdialogs und Rückschreiben ins Modell
 */
class LcdClock : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Erstellt den Controller für die übergebene LCD-Anzeige.
     * @param display Zielanzeige.
     * @param settings Modell mit persistierten Anzeigeeinstellungen.
     * @param parent Optionales Parent-Objekt.
     */
    explicit LcdClock(QLCDNumber *display, ClockSettingsModel *settings, QObject *parent = nullptr);

    /**
     * @brief Öffnet den Präferenzdialog zur Farbauswahl.
     * @param parent Parent-Widget für den modalen Dialog.
     */
    void showPreferencesDialog(QWidget *parent);

private slots:
    /** @brief Aktualisiert die Zeitdarstellung (blinkender Doppelpunkt). */
    void updateDisplay();

    /**
     * @brief Wendet die im Modell gewählte Farbe auf die Anzeige an.
     * @param color Neue Farbauswahl.
     */
    void applyColor(ClockSettingsModel::ClockColor color);

private:
    /** @brief Referenz auf die zu aktualisierende LCD-Anzeige. */
    QLCDNumber *_display{nullptr};

    /** @brief Modell mit persistierten Anzeigeeinstellungen. */
    ClockSettingsModel *_settings{nullptr};

    /** @brief Taktgeber für periodische Aktualisierungen. */
    QTimer *_timer{nullptr};
};

#endif // LCD_CLOCK_H
