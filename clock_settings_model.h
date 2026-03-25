/**
 * @file clock_settings_model.h
 * @brief Modell für persistente Anzeigeeinstellungen der LCD-Uhr.
 */
#ifndef CLOCK_SETTINGS_MODEL_H
#define CLOCK_SETTINGS_MODEL_H

#include <QObject>

/**
 * @brief Modell zur Verwaltung der auswählbaren Uhrfarben.
 *
 * Die Klasse persistiert die ausgewählte Farbe über @c QSettings und stellt
 * Änderungsbenachrichtigungen für Controller/View bereit.
 */
class ClockSettingsModel : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Verfügbare Farbschemata für die LCD-Anzeige.
     */
    enum class ClockColor
    {
        Black = 0,
        White = 1,
        Green = 2,
        Red = 3
    };
    Q_ENUM(ClockColor)

    /**
     * @brief Erzeugt das Einstellungsmodell und lädt gespeicherte Werte.
     * @param parent Optionales Parent-Objekt.
     */
    explicit ClockSettingsModel(QObject *parent = nullptr);

    /**
     * @brief Liefert die aktuell gesetzte Uhrfarbe.
     * @return Aktuelle Farbauswahl.
     */
    ClockColor color() const;

    /**
     * @brief Setzt eine neue Uhrfarbe und persistiert diese.
     * @param color Neue Farbauswahl.
     */
    void setColor(ClockColor color);

signals:
    /**
     * @brief Signalisiert eine geänderte Uhrfarbe.
     * @param color Neu gesetzte Farbauswahl.
     */
    void colorChanged(ClockSettingsModel::ClockColor color);

private:
    /** @brief Lädt die persistierte Farbauswahl aus den Einstellungen. */
    void load();
    /** @brief Schreibt die Farbauswahl in die Einstellungen. */
    void save() const;
    /** @brief Aktuell selektierte Farbauswahl. */
    ClockColor _color{ClockColor::Green};
};

#endif // CLOCK_SETTINGS_MODEL_H
